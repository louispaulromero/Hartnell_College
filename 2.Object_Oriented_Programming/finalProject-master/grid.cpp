/*	NAME: Louis Paul Romero
 *	DATE CREATED: 23 April 2016
 *	DESCRIPTION: grid.cpp for Minesweeper
 *	CSS2A Section 9010 Final Project
 * 	Due Date: 13 May 2016
 *	Group Members: Chanel Aquino, Sam Sanchez
 *	Modified by Samuel Sanchez 17 May 2016:
 		Added SFML graphics and windows to the class in order to display the minesweeper game in
 		a rendered window fully equipped with resizing, and clickable tiles.
 */

#include "grid.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int displayMovementChoices();

//*************************************
// Grid() default
Grid::Grid()
{
	double percentage_of_mines;

	isGameOver = false;
	firstClick = true;
	hasWon = false;
	bool allowGameToRun = true;

	widthBorder = 16; // Default size of the textures used for the game
	heightBorder = 16;

	int minimumWindowWidth = 0;
	int minimumWindowHeight = 0;
	int modifiedBorderWidth = widthBorder;
	int modifiedBorderHeight = heightBorder;
	int heightDifference = 0;
	int widthDifference = 0;

	minimumWindowHeight = heightBorder * 20;
	minimumWindowWidth = widthBorder * 20;

	sf::RenderWindow dimensionChoice(sf::VideoMode(minimumWindowWidth, minimumWindowHeight), "Minesweeper");
	while(dimensionChoice.isOpen())
	{
		sf::Event event;
		while (dimensionChoice.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
			{
				dimensionChoice.close();
				allowGameToRun = false;
			}
			
			else if(event.type == sf::Event::MouseButtonPressed)
			{
				if(event.mouseButton.button == sf::Mouse::Left)
				{
					//cout << "\n\nmouse x: " << event.mouseButton.x << endl;
					//cout << "mouse y: " << event.mouseButton.y << endl;
					//cout << "Width Difference: " << widthDifference << endl;
					//cout << "Height Difference: " << heightDifference << endl;
					//cout << "Modified Width Border = " << modifiedBorderWidth << endl;
					//cout << "Modified Height Border = " << modifiedBorderHeight << endl;
					if(event.mouseButton.x >= modifiedBorderWidth && event.mouseButton.x < (minimumWindowWidth + widthDifference) / 2)
					{
						if(event.mouseButton.y >= modifiedBorderHeight && event.mouseButton.y < (minimumWindowHeight + heightDifference) / 2)
						{
							setRowsPrivate(8);
							setColsPrivate(8);
							percentage_of_mines = 0.15625;
							dimensionChoice.close();
						}
						
						else if((event.mouseButton.y >= (minimumWindowHeight + heightDifference) / 2) && (event.mouseButton.y < (minimumWindowHeight + heightDifference) - modifiedBorderHeight))
						{
							//cout << "HARD MAX BOUNDARY MET\n";
							setRowsPrivate(16);
							setColsPrivate(30);
							percentage_of_mines = 0.20625;
							dimensionChoice.close();
						}
					}
					
					else if(event.mouseButton.x >= (minimumWindowWidth + widthDifference) / 2 && event.mouseButton.x < (minimumWindowWidth + widthDifference) - modifiedBorderWidth)
					{
						//cout << "MEDIUM MIN BOUNDARY MET\n";
						if(event.mouseButton.y >= modifiedBorderHeight && event.mouseButton.y < (minimumWindowHeight + heightDifference) / 2)
						{
							//cout << "MEDIUM MAX BOUNDARY MET\n";
							setRowsPrivate(16);
							setColsPrivate(16);
							percentage_of_mines = 0.15625;
							dimensionChoice.close();
						}
					}

				}
			}

			else if(event.type == sf::Event::Resized) // Prevents window from being resized any smaller than dimension of grid
			{
				if(event.size.width < minimumWindowWidth || event.size.height < minimumWindowHeight)
				{
					// Window cannot be smaller than default pixel values of the tile textures
					gamespace.create(sf::VideoMode(minimumWindowWidth, minimumWindowHeight, 16), "Minesweeper");
				}
				else
				{
					//cout << "Else ran\n";
					//cout << "Window Width: " << event.size.width << endl;
					//cout << "Widnow Height: " << event.size.height << endl;
					widthDifference = event.size.width - minimumWindowWidth;
					heightDifference = event.size.height - minimumWindowHeight;
					//cout << "Differences set\n";
				
					modifiedBorderWidth = (widthBorder * event.size.width) / minimumWindowWidth;
					modifiedBorderHeight = (heightBorder * event.size.height) / minimumWindowHeight;
				}
			}
		}

		dimensionChoice.clear(sf::Color(220,220,220,255));

		//*******************************************************************************************
		// Border Tiles (non game necessary tiles for aesthetic purposes)
		// Top Wall
		for(int ix = 0; ix < (minimumWindowWidth / 16) - 2; ix++)
		{
			borderTexture.loadFromFile("textures/minesweeperUpperBorder.png");
			borderTile.setTexture(borderTexture);
			borderTile.setPosition((ix + 1) * 16, 0);
			dimensionChoice.draw(borderTile);
		}

		// Left Wall
		for(int ix = 0; ix < (minimumWindowHeight / 16) - 2; ix++)
		{
			borderTexture.loadFromFile("textures/minesweeperLeftWallBorder.png");
			borderTile.setTexture(borderTexture);
			borderTile.setPosition(0, (ix + 1) * 16);
			dimensionChoice.draw(borderTile);
		}

		// Right Wall
		for(int ix = 0; ix < (minimumWindowHeight / 16) - 2; ix++)
		{
			borderTexture.loadFromFile("textures/minesweeperRightWall.png");
			borderTile.setTexture(borderTexture);
			borderTile.setPosition(minimumWindowWidth - widthBorder, (ix + 1) * 16);
			dimensionChoice.draw(borderTile);
		}

		// Bottom Wall
		for(int ix = 0; ix < (minimumWindowWidth / 16) - 2; ix++)
		{
			borderTexture.loadFromFile("textures/minesweeperBottomWall.png");
			borderTile.setTexture(borderTexture);
			borderTile.setPosition((ix + 1) * 16, minimumWindowHeight - 16);
			dimensionChoice.draw(borderTile);
		}

		// Upper Right Corner
		borderTexture.loadFromFile("textures/minesweeperUpperRightCorner.png");
		borderTile.setTexture(borderTexture);
		borderTile.setPosition(minimumWindowHeight - heightBorder, 0);
		dimensionChoice.draw(borderTile);

		// Upper Left Corner
		borderTexture.loadFromFile("textures/minesweeperUpperLeftCorner.png");
		borderTile.setTexture(borderTexture);
		borderTile.setPosition(0, 0);
		dimensionChoice.draw(borderTile);

		// Bottom Left Corner
		borderTexture.loadFromFile("textures/minesweeperBottomLeftCorner.png");
		borderTile.setTexture(borderTexture);
		borderTile.setPosition(0, minimumWindowHeight - heightBorder);
		dimensionChoice.draw(borderTile);

		// Bottom Right Corner
		borderTexture.loadFromFile("textures/minesweeperBottomRightCorner.png");
		borderTile.setTexture(borderTexture);
		borderTile.setPosition(minimumWindowWidth - widthBorder, minimumWindowHeight - heightBorder);
		dimensionChoice.draw(borderTile);

		// Easy Box
		dimensionTexture.loadFromFile("textures/minesweeperEasyBox.png");
		dimensionTile.setTexture(dimensionTexture);
		dimensionTile.setPosition(widthBorder, heightBorder);
		dimensionChoice.draw(dimensionTile);

		// Medium Box
		dimensionTexture.loadFromFile("textures/minesweeperMediumBox.png");
		dimensionTile.setTexture(dimensionTexture);
		dimensionTile.setPosition((minimumWindowWidth / 2), heightBorder);
		dimensionChoice.draw(dimensionTile);

		// Hard Box
		dimensionTexture.loadFromFile("textures/minesweeperHardBox.png");
		dimensionTile.setTexture(dimensionTexture);
		dimensionTile.setPosition(widthBorder, (minimumWindowHeight / 2));
		dimensionChoice.draw(dimensionTile);

		// Custom Box
		dimensionTexture.loadFromFile("textures/minesweeperCustomBox.png");
		dimensionTile.setTexture(dimensionTexture);
		dimensionTile.setPosition((minimumWindowWidth / 2), (minimumWindowHeight / 2));
		dimensionChoice.draw(dimensionTile);

		//*****************************************************************************************

		dimensionChoice.display();
	}

	if(allowGameToRun)
	{
		int numberOfMines = (rowsPrivate * colsPrivate) * percentage_of_mines;

		srand(time(0));
		//cout << "This is the number of mines that will be set " << numberOfMines << endl;
		int ix, jx;
		for(int i = 0; i < numberOfMines; i++)
		{

			ix = rand() % rowsPrivate;
			jx = rand() % colsPrivate;
			//cout << "(" << ix << "," << jx << ")" << endl;

			if(!tiles[ix][jx].getIsMine())
			{
				tiles[ix][jx].setIsMine(true);
				tiles[ix][jx].setIsTilesVisible(false);
			}
			else
			{
				i--;
			}
		}

		countAdjacentMines();
		runGame();
	}
}
//
//*************************************
//


//*************************************
// Grid() overloaded
Grid::Grid(unsigned int rows, unsigned int cols)
{	
	double percentage_of_mines = 0.15;

	hasWon = false;
	isGameOver = false;
	firstClick = true;
	bool allowGameToRun = true;

	widthBorder = 16; // Default size of the textures used for the game
	heightBorder = 16;

	setRowsPrivate(rows);
	setColsPrivate(cols);

	int numberOfMines = (rowsPrivate * colsPrivate) * percentage_of_mines;

	srand(time(0));
	//cout << "This is the number of mines that will be set " << numberOfMines << endl;
	int ix, jx;
	for(int i = 0; i < numberOfMines; i++)
	{
		ix = rand() % rows;
		jx = rand() % cols;
		//cout << "(" << ix << "," << jx << ")" << endl;
		if(!tiles[ix][jx].getIsMine())
		{
			tiles[ix][jx].setIsMine(true);
			tiles[ix][jx].setIsTilesVisible(false);
		}
		else
		{
			i--;
		}
	}

	countAdjacentMines();
	runGame();
}
//
//*************************************
//

//*************************************
// makeAllTilesVisible()
void Grid::revealAllTiles()
{
	for(int ix = 0; ix < rowsPrivate; ix++)
	{
		for(int jx = 0; jx < colsPrivate; jx++)
		{	
			//tiles[ix][jx].setIsTilesVisible(true);
			if(!tiles[ix][jx].getIsTileVisible()) // Makes sure current tile is not visible
			{
				//cout << "IT\'S NOT VISIBLE!\n";
				if(!tiles[ix][jx].getIsMine() && !tiles[ix][jx].getIsFlag())
				{
					switch(tiles[ix][jx].getAdjacentMines())
					{
						case 0:
							tiles[ix][jx].tileTexture.loadFromFile("textures/tileNothing.png");
							tiles[ix][jx].setTilesIcon('0');
							break;
						case 1:
							tiles[ix][jx].tileTexture.loadFromFile("textures/1.png");
							tiles[ix][jx].setTilesIcon('1');
							break;
						case 2:
							tiles[ix][jx].tileTexture.loadFromFile("textures/2.png");
							tiles[ix][jx].setTilesIcon('2');
							break;
						case 3:
							tiles[ix][jx].tileTexture.loadFromFile("textures/3.png");
							tiles[ix][jx].setTilesIcon('3');
							break;
						case 4:
							tiles[ix][jx].tileTexture.loadFromFile("textures/4.png");
							tiles[ix][jx].setTilesIcon('4');
							break;
						case 5:
							tiles[ix][jx].tileTexture.loadFromFile("textures/5.png");
							tiles[ix][jx].setTilesIcon('5');
							break;
						case 6:
							tiles[ix][jx].tileTexture.loadFromFile("textures/6.png");
							tiles[ix][jx].setTilesIcon('6');
							break;
						case 7:
							tiles[ix][jx].tileTexture.loadFromFile("textures/7.png");
							tiles[ix][jx].setTilesIcon('7');
							break;
						case 8:
							tiles[ix][jx].tileTexture.loadFromFile("textures/8.png");
							tiles[ix][jx].setTilesIcon('8');
							break;
						default:
							break;
					}
				}

				else if(tiles[ix][jx].getIsMine() && tiles[ix][jx].getIsFlag())
				{
					tiles[ix][jx].tileTexture.loadFromFile("textures/flag.png");
					tiles[ix][jx].setTilesIcon('F');
				}

				else if(!tiles[ix][jx].getIsMine() && tiles[ix][jx].getIsFlag())
				{
					tiles[ix][jx].tileTexture.loadFromFile("textures/falseMine.png");
					tiles[ix][jx].setTilesIcon('X');
				}

				else if(tiles[ix][jx].getIsMine() && !tiles[ix][jx].getIsFlag())
				{
					tiles[ix][jx].tileTexture.loadFromFile("textures/mineNotClicked.png");
					tiles[ix][jx].setTilesIcon('O');
				}
			}
			tiles[ix][jx].setIsTilesVisible(true);
		}
	}
}
//
//*************************************
//


//*************************************
// makeOneTileVisible()
void Grid::makeOneTileVisible(int row, int col)
{
	tiles[row][col].setIsTilesVisible(true);
}
//
//*************************************
//


//*************************************
// checkAllNeighbors()
bool Grid::checkAllNeighbors(int row, int col)
{
	//checking inner stuff
	if(row > rowsPrivate || col > colsPrivate || col < 0 || row < 0)
	{
		//cout << "OUT OF RANGE!\n";
		return false;
	}
	/*
	Error Checking
	if(tiles[row][col].getIsTileVisible())
		cout << "IT\'S VISIBLE!\n";
	if(tiles[row][col].getIsFlag())
		cout << "IT\'S A FLAG\n";
	if(tiles[row][col].getIsMine())
		cout << "IT\'S A MINE\n";
	*/

	else if(!tiles[row][col].getIsTileVisible() && !tiles[row][col].getIsFlag() && !tiles[row][col].getIsMine())
	{
		//makeOneTileVisible(row,col);
		tiles[row][col].exploreTiles();

		if(tiles[row][col].getAdjacentMines() != 0)
		{
			//cout << "IT\'S NOT A ZERO!!!!\n";
			return false;
		}

		else
		{
			checkAllNeighbors(row + 1, col + 1); // First 4 check diagonals
			checkAllNeighbors(row + 1, col - 1);
			checkAllNeighbors(row - 1, col + 1);
			checkAllNeighbors(row - 1, col - 1);
			checkAllNeighbors(row, col + 1); // These 4 check 
			checkAllNeighbors(row, col - 1);
			checkAllNeighbors(row + 1, col);
			checkAllNeighbors(row - 1, col);

			return true;
		}

		return false;
	}

	return false;
}
//
//*************************************
//

//*************************************
// countAdjacentMines()

void Grid::countAdjacentMines()
{
for(int ix = 0; ix < rowsPrivate; ix++)
	{
		for(int jx = 0; jx < colsPrivate; jx++)
		{
			if(!(tiles[ix][jx].getIsMine()))
			{
				//N tiles[ix-1][jx]
				//S tiles[ix+1][jx]
				//E tiles[ix][jx+1]
				//W tiles[ix][jx-1]
				//NE tiles[ix-1][jx+1]
				//NW tiles[ix-1][jx-1]
				//SE tiles[ix+1][jx+1]
				//SW tiles[ix+1][jx-1]
				int counter = 0;
				if(ix == 0 && jx == 0 )//Top left corner
				{
					//E S SE
					if(tiles[ix][jx+1].getIsMine())
					{
						counter++;
					}
					if(tiles[ix+1][jx].getIsMine())
					{
						counter++;
					}
					if(tiles[ix+1][jx+1].getIsMine())
					{
						counter++;
					}

					tiles[ix][jx].setAdjacentMines(counter);

				}

				else if(ix == 0 && (jx == colsPrivate - 1))//Top right corner
				{
					// W S SW
					if(tiles[ix][jx-1].getIsMine()) 
					{
						counter++;
					}
					if(tiles[ix+1][jx].getIsMine()) 
					{
						counter++;
					}
					if(tiles[ix+1][jx-1].getIsMine()) 
					{
						counter++;
					}
					tiles[ix][jx].setAdjacentMines(counter);

				}

				else if( (ix == rowsPrivate - 1) && jx == 0 )//Bottom left corner
				{
					//N E NE
					if(tiles[ix-1][jx].getIsMine())
					{
						counter++;
					}
					if(tiles[ix][jx+1].getIsMine())
					{
						counter++;
					}
					if(tiles[ix-1][jx+1].getIsMine())
					{
						counter++;
					}
					tiles[ix][jx].setAdjacentMines(counter);
				}

				else if(ix == (rowsPrivate - 1) && jx == (colsPrivate - 1))//Bottom right corner
				{
					//N W NW
					if(tiles[ix-1][jx].getIsMine())
					{
						counter++;
					}
					if(tiles[ix][jx-1].getIsMine())
					{
						counter++;
					}
					if(tiles[ix-1][jx-1].getIsMine())
					{
						counter++;
					}
					tiles[ix][jx].setAdjacentMines(counter);

				}

				else if(ix == 0 )//Top wall
				{
					//E S W SE SW
					if(tiles[ix][jx+1].getIsMine()) 
					{
						counter++;
					}
					if(tiles[ix+1][jx].getIsMine()) 
					{
						counter++;
					}
					if(tiles[ix][jx-1].getIsMine())
					{
						counter++;
					}
					if(tiles[ix+1][jx+1].getIsMine())
					{
						counter++;
					}
					if(tiles[ix+1][jx-1].getIsMine())
					{
						counter++;
					}
					tiles[ix][jx].setAdjacentMines(counter);
				}

				else if(jx == 0)//Left wall
				{
					// N E S NE SE
					if(tiles[ix-1][jx].getIsMine()) 
					{
						counter++;
					}
					if(tiles[ix][jx+1].getIsMine()) 
					{
						counter++;
					}
					if(tiles[ix+1][jx].getIsMine())
					{
						counter++;
					}
					if(tiles[ix-1][jx+1].getIsMine())
					{
						counter++;
					}
					if(tiles[ix+1][jx+1].getIsMine())
					{
						counter++;
					}

					tiles[ix][jx].setAdjacentMines(counter);

				}

				else if(jx == (colsPrivate - 1))//Right wall
				{
					//N S W SW NW
					if(tiles[ix-1][jx].getIsMine())
					{
						counter++;
					}
					if(tiles[ix+1][jx].getIsMine())
					{
						counter++;
					}
					if(tiles[ix][jx-1].getIsMine())
					{
						counter++;
					}
					if(tiles[ix+1][jx-1].getIsMine())
					{
						counter++;
					}
					if(tiles[ix-1][jx-1].getIsMine())
					{
						counter++;
					}

					tiles[ix][jx].setAdjacentMines(counter);
				}

				else if(ix == (rowsPrivate - 1))//Bottom wall
				{
					//N E W NE NW
					if(tiles[ix-1][jx].getIsMine())
					{
						counter++;
					}
					if(tiles[ix][jx+1].getIsMine()) 
					{
						counter++;
					}
					if(tiles[ix][jx-1].getIsMine())
					{
						counter++;
					}
					if(tiles[ix-1][jx+1].getIsMine())
					{
						counter++;
					}
					if(tiles[ix-1][jx-1].getIsMine()) 
					{
						counter++;
					}

					tiles[ix][jx].setAdjacentMines(counter);

				}

				else//All 8 positions
				{
					// N E S W NE SE SW NW
					if(tiles[ix-1][jx].getIsMine()) 
					{
						counter++;
					}
					if(tiles[ix][jx+1].getIsMine())
					{
						counter++;
					}
					if(tiles[ix+1][jx].getIsMine())
					{
						counter++;
					} 
					if(tiles[ix][jx-1].getIsMine())
					{
						counter++;
					}
					if(tiles[ix-1][jx+1].getIsMine())
					{
						counter++;
					}
					if(tiles[ix+1][jx+1].getIsMine()) 
					{
						counter++;
					}
					if(tiles[ix+1][jx-1].getIsMine())
					{
						counter++;
					}
					if(tiles[ix-1][jx-1].getIsMine()) 
					{
						counter++;
					}

					tiles[ix][jx].setAdjacentMines(counter);
				}

			}//end of if

		}//end of inner for loop

	}//end of outer for loop
}

//
//*************************************
//



//*************************************
// runGame()
void Grid::runGame()
{

	int minimumWindowWidth = 0;
	int minimumWindowHeight = 0;
	int modifiedBorderWidth = widthBorder;
	int modifiedBorderHeight = heightBorder;
	int heightDifference = 0;
	int widthDifference = 0;

	calculateWindowDimensions(minimumWindowHeight, minimumWindowWidth); // Calculates minimum requirements needed to form the map

	sf::RenderWindow gamespace(sf::VideoMode(minimumWindowWidth,minimumWindowHeight,16), "Minesweeper");

	//sf::Sprite game_tile;
	//sf::Texture borderTexture;
	//sf::Sprite borderTile;
	//bool isGameOver = false;
	while(gamespace.isOpen())
	{	
		sf::Event event;
		while(gamespace.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
			{
				//isGameOver = true;
				//firstClick = true;
				gamespace.close();
			}

			else if(event.type == sf::Event::MouseButtonPressed)
			{
				//**********************************************************************4
				// Error Checking
				/*
				cout << "\n\nmouse x: " << event.mouseButton.x << endl;
				cout << "mouse y: " << event.mouseButton.y << endl;
				cout << "Width Difference: " << widthDifference << endl;
				cout << "Height Difference: " << heightDifference << endl;
				cout << "Modified Width Border = " << modifiedBorderWidth << endl;
				cout << "Modified Height Border = " << modifiedBorderHeight << endl;
				*/
				//**********************************************************************
				if(event.mouseButton.x >= modifiedBorderWidth && event.mouseButton.y >= modifiedBorderHeight * 3) // Represents Pixel area of grid
				{
					//cout << "Passed Upper and Lower Left Boundaries\n";
					//cout << "Right Most boundary: " << (minimumWindowWidth + widthDifference) - modifiedBorderWidth << endl;
					//cout << "Height Boundary Check: " << ((minimumWindowHeight + heightDifference) - modifiedTopBorder) << endl;
					if(event.mouseButton.x < ((minimumWindowWidth + widthDifference) - modifiedBorderWidth) && event.mouseButton.y < ((minimumWindowHeight + heightDifference) - modifiedBorderHeight))
					{
						//cout << "Passed Upper Right Lower Right boundaries\n";
						//cout << "Y for col in array: " << ((event.mouseButton.y - modifiedBorderHeight) / modifiedBorderHeight) << endl;
						firstClick = false;
						if(event.mouseButton.button == sf::Mouse::Left && (!isGameOver && !hasWon))
						{
							//isGameOver = tiles[((event.mouseButton.x - modifiedBorderWidth) / modifiedBorderWidth)][((event.mouseButton.y - modifiedBorderHeight) / modifiedBorderHeight)].exploreTiles();
							if(tiles[(event.mouseButton.y - modifiedBorderHeight)/ modifiedBorderHeight - 2][(event.mouseButton.x - modifiedBorderWidth) / modifiedBorderWidth].exploreTiles())
							{
								isGameOver = true;
								revealAllTiles();
							}
							else
							{
								tiles[(event.mouseButton.y - modifiedBorderHeight)/ modifiedBorderHeight - 2][(event.mouseButton.x - modifiedBorderWidth) / modifiedBorderWidth].setIsTilesVisible(false);
								checkAllNeighbors(((event.mouseButton.y - modifiedBorderHeight)/ modifiedBorderHeight - 2), ((event.mouseButton.x - modifiedBorderWidth) / modifiedBorderWidth));
								hasWon = checkIfWon();
							}
						}
						else if(event.mouseButton.button == sf::Mouse::Right && (!isGameOver && !hasWon))
						{
							tiles[((event.mouseButton.y - modifiedBorderHeight)/ modifiedBorderHeight) - 2][((event.mouseButton.x - modifiedBorderWidth) / modifiedBorderWidth)].setFlag();
							hasWon = checkIfWon();
						}
					}	
				}

				else if(event.mouseButton.x >= modifiedBorderWidth + 6 && event.mouseButton.x < modifiedBorderWidth * 3 + 6)
				{
					if(event.mouseButton.y >= modifiedBorderHeight && event.mouseButton.y < modifiedBorderHeight * 3)
					{
						gamespace.close();
						resetGame(rowsPrivate, colsPrivate);
					}
				}
			}

			else if(event.type == sf::Event::Resized) // Prevents window from being resized any smaller than dimension of grid
			{
				if(event.size.width < minimumWindowWidth || event.size.height < minimumWindowHeight)
				{
					// Window cannot be smaller than default pixel values of the tile textures
					gamespace.create(sf::VideoMode(minimumWindowWidth, minimumWindowHeight, 16), "Minesweeper");
				}
				else
				{
					//cout << "Else ran\n";
					//cout << "Window Width: " << event.size.width << endl;
					//cout << "Widnow Height: " << event.size.height << endl;
					widthDifference = event.size.width - minimumWindowWidth;
					heightDifference = event.size.height - minimumWindowHeight;
					//cout << "Differences set\n";
				
					modifiedBorderWidth = (widthBorder * event.size.width) / minimumWindowWidth;
					modifiedBorderHeight = (heightBorder * event.size.height) / minimumWindowHeight;
				}
			}
		}	
		gamespace.clear(sf::Color(220,220,220,255)); // Sets color of the window

		for(int ix = 0; ix < rowsPrivate; ix++) // Laying the tiles to be revealed by the player (i.e. game tiles)
		{
			for(int jx = 0; jx < colsPrivate; jx++)
			{
				game_tile.setTexture(tiles[ix][jx].tileTexture);
				game_tile.setPosition((jx + 1) * 16,(ix + 3) * 16);
				gamespace.draw(game_tile);
			}
		}

		//*******************************************************************************************
		// Border Tiles (non game necessary tiles for aesthetic purposes)
		// Header Bar
		for(int ix = 0; ix < colsPrivate - 1; ix++)
		{
			headerTexture.loadFromFile("textures/minesweeperHeaderBarTile.png");
			headerTile.setTexture(headerTexture);
			headerTile.setPosition(((ix + 3) * 16), heightBorder);
			gamespace.draw(headerTile);
		}
		// Top Wall
		for(int ix = 0; ix < colsPrivate; ix++)
		{
			borderTexture.loadFromFile("textures/minesweeperUpperBorder.png");
			borderTile.setTexture(borderTexture);
			borderTile.setPosition((ix + 1) * 16, 0);
			gamespace.draw(borderTile);
		}

		// Left Wall
		for(int ix = 0; ix < rowsPrivate + 2; ix++)
		{
			borderTexture.loadFromFile("textures/minesweeperLeftWallBorder.png");
			borderTile.setTexture(borderTexture);
			borderTile.setPosition(0, (ix + 1) * 16);
			gamespace.draw(borderTile);
		}

		// Right Wall
		for(int ix = 0; ix < rowsPrivate + 2; ix++)
		{
			borderTexture.loadFromFile("textures/minesweeperRightWall.png");
			borderTile.setTexture(borderTexture);
			borderTile.setPosition(widthBorder * (colsPrivate + 1), (ix + 1) * 16);
			gamespace.draw(borderTile);
		}

		// Bottom Wall
		for(int ix = 0; ix < colsPrivate; ix++)
		{
			borderTexture.loadFromFile("textures/minesweeperBottomWall.png");
			borderTile.setTexture(borderTexture);
			borderTile.setPosition(((ix + 1) * 16), (rowsPrivate + 3) * heightBorder);
			gamespace.draw(borderTile);
		}

		// Upper Right Corner
		borderTexture.loadFromFile("textures/minesweeperUpperRightCorner.png");
		borderTile.setTexture(borderTexture);
		borderTile.setPosition((widthBorder * (colsPrivate + 1)), 0);
		gamespace.draw(borderTile);

		// Upper Left Corner
		borderTexture.loadFromFile("textures/minesweeperUpperLeftCorner.png");
		borderTile.setTexture(borderTexture);
		borderTile.setPosition(0, 0);
		gamespace.draw(borderTile);

		// Bottom Left Corner
		borderTexture.loadFromFile("textures/minesweeperBottomLeftCorner.png");
		borderTile.setTexture(borderTexture);
		borderTile.setPosition(0, (heightBorder * (rowsPrivate + 3)));
		gamespace.draw(borderTile);

		// Bottom Right Corner
		borderTexture.loadFromFile("textures/minesweeperBottomRightCorner.png");
		borderTile.setTexture(borderTexture);
		borderTile.setPosition((widthBorder * (colsPrivate + 1)), (heightBorder * (rowsPrivate + 3)));
		gamespace.draw(borderTile);

		// Face/Reset Tile
		if(firstClick || (!isGameOver && hasWon))
			headerTexture.loadFromFile("textures/minesweeperHappyFace.png");
		else if(!firstClick && !isGameOver)
			headerTexture.loadFromFile("textures/minesweeperInPlay.png");
		else if(isGameOver)
			headerTexture.loadFromFile("textures/minesweeperSadFace.png");
		else
			headerTexture.loadFromFile("textures/minesweeperHappyFace.png");

		headerTile.setTexture(headerTexture);
		headerTile.setPosition(widthBorder, heightBorder);
		gamespace.draw(headerTile);

		//*****************************************************************************************

		gamespace.display();
	}	

}
//
//*************************************
//


//*************************************

void Grid::calculateWindowDimensions(int& height, int& width)
{
	height = rowsPrivate * 16 + (heightBorder * 4);
	width = colsPrivate * 16 + (widthBorder * 2);

	return;
}

void Grid::resetGame(const int& rows, const int& cols)
{
	hasWon = false;
	firstClick = true;
	isGameOver = false;
	bool allowGameToRun = true;
	double percentage_of_mines;

	widthBorder = 16; // Default size of the textures used for the game
	heightBorder = 16;

	int minimumWindowWidth = 0;
	int minimumWindowHeight = 0;
	int modifiedBorderWidth = widthBorder;
	int modifiedBorderHeight = heightBorder;
	int heightDifference = 0;
	int widthDifference = 0;

	minimumWindowHeight = heightBorder * 20;
	minimumWindowWidth = widthBorder * 20;

	sf::RenderWindow dimensionChoice(sf::VideoMode(minimumWindowWidth, minimumWindowHeight), "Minesweeper");
	while(dimensionChoice.isOpen())
	{
		sf::Event event;
		while (dimensionChoice.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
			{
				dimensionChoice.close();
				allowGameToRun = false;
			}
			
			else if(event.type == sf::Event::MouseButtonPressed)
			{
				if(event.mouseButton.button == sf::Mouse::Left)
				{
					//cout << "\n\nmouse x: " << event.mouseButton.x << endl;
					//cout << "mouse y: " << event.mouseButton.y << endl;
					//cout << "Width Difference: " << widthDifference << endl;
					//cout << "Height Difference: " << heightDifference << endl;
					//cout << "Modified Width Border = " << modifiedBorderWidth << endl;
					//cout << "Modified Height Border = " << modifiedBorderHeight << endl;
					if(event.mouseButton.x >= modifiedBorderWidth && event.mouseButton.x < (minimumWindowWidth + widthDifference) / 2)
					{
						if(event.mouseButton.y >= modifiedBorderHeight && event.mouseButton.y < (minimumWindowHeight + heightDifference) / 2)
						{
							setRowsPrivate(8);
							setColsPrivate(8);
							percentage_of_mines = 0.15625;
							dimensionChoice.close();
						}
						
						else if((event.mouseButton.y >= (minimumWindowHeight + heightDifference) / 2) && (event.mouseButton.y < (minimumWindowHeight + heightDifference) - modifiedBorderHeight))
						{
							//cout << "HARD MAX BOUNDARY MET\n";
							setRowsPrivate(16);
							setColsPrivate(30);
							percentage_of_mines = 0.20625;
							dimensionChoice.close();
						}
					}
					
					else if(event.mouseButton.x >= (minimumWindowWidth + widthDifference) / 2 && event.mouseButton.x < (minimumWindowWidth + widthDifference) - modifiedBorderWidth)
					{
						//cout << "MEDIUM MIN BOUNDARY MET\n";
						if(event.mouseButton.y >= modifiedBorderHeight && event.mouseButton.y < (minimumWindowHeight + heightDifference) / 2)
						{
							//cout << "MEDIUM MAX BOUNDARY MET\n";
							setRowsPrivate(16);
							setColsPrivate(16);
							percentage_of_mines = 0.15625;
							dimensionChoice.close();
						}
					}

				}
			}

			else if(event.type == sf::Event::Resized) // Prevents window from being resized any smaller than dimension of grid
			{
				if(event.size.width < minimumWindowWidth || event.size.height < minimumWindowHeight)
				{
					// Window cannot be smaller than default pixel values of the tile textures
					gamespace.create(sf::VideoMode(minimumWindowWidth, minimumWindowHeight, 16), "Minesweeper");
				}
				else
				{
					//cout << "Else ran\n";
					//cout << "Window Width: " << event.size.width << endl;
					//cout << "Widnow Height: " << event.size.height << endl;
					widthDifference = event.size.width - minimumWindowWidth;
					heightDifference = event.size.height - minimumWindowHeight;
					//cout << "Differences set\n";
				
					modifiedBorderWidth = (widthBorder * event.size.width) / minimumWindowWidth;
					modifiedBorderHeight = (heightBorder * event.size.height) / minimumWindowHeight;
				}
			}
		}

		dimensionChoice.clear(sf::Color(220,220,220,255));

		//*******************************************************************************************
		// Border Tiles (non game necessary tiles for aesthetic purposes)
		// Top Wall
		for(int ix = 0; ix < (minimumWindowWidth / 16) - 2; ix++)
		{
			borderTexture.loadFromFile("textures/minesweeperUpperBorder.png");
			borderTile.setTexture(borderTexture);
			borderTile.setPosition((ix + 1) * 16, 0);
			dimensionChoice.draw(borderTile);
		}

		// Left Wall
		for(int ix = 0; ix < (minimumWindowHeight / 16) - 2; ix++)
		{
			borderTexture.loadFromFile("textures/minesweeperLeftWallBorder.png");
			borderTile.setTexture(borderTexture);
			borderTile.setPosition(0, (ix + 1) * 16);
			dimensionChoice.draw(borderTile);
		}

		// Right Wall
		for(int ix = 0; ix < (minimumWindowHeight / 16) - 2; ix++)
		{
			borderTexture.loadFromFile("textures/minesweeperRightWall.png");
			borderTile.setTexture(borderTexture);
			borderTile.setPosition(minimumWindowWidth - widthBorder, (ix + 1) * 16);
			dimensionChoice.draw(borderTile);
		}

		// Bottom Wall
		for(int ix = 0; ix < (minimumWindowWidth / 16) - 2; ix++)
		{
			borderTexture.loadFromFile("textures/minesweeperBottomWall.png");
			borderTile.setTexture(borderTexture);
			borderTile.setPosition((ix + 1) * 16, minimumWindowHeight - 16);
			dimensionChoice.draw(borderTile);
		}

		// Upper Right Corner
		borderTexture.loadFromFile("textures/minesweeperUpperRightCorner.png");
		borderTile.setTexture(borderTexture);
		borderTile.setPosition(minimumWindowHeight - heightBorder, 0);
		dimensionChoice.draw(borderTile);

		// Upper Left Corner
		borderTexture.loadFromFile("textures/minesweeperUpperLeftCorner.png");
		borderTile.setTexture(borderTexture);
		borderTile.setPosition(0, 0);
		dimensionChoice.draw(borderTile);

		// Bottom Left Corner
		borderTexture.loadFromFile("textures/minesweeperBottomLeftCorner.png");
		borderTile.setTexture(borderTexture);
		borderTile.setPosition(0, minimumWindowHeight - heightBorder);
		dimensionChoice.draw(borderTile);

		// Bottom Right Corner
		borderTexture.loadFromFile("textures/minesweeperBottomRightCorner.png");
		borderTile.setTexture(borderTexture);
		borderTile.setPosition(minimumWindowWidth - widthBorder, minimumWindowHeight - heightBorder);
		dimensionChoice.draw(borderTile);

		// Easy Box
		dimensionTexture.loadFromFile("textures/minesweeperEasyBox.png");
		dimensionTile.setTexture(dimensionTexture);
		dimensionTile.setPosition(widthBorder, heightBorder);
		dimensionChoice.draw(dimensionTile);

		// Medium Box
		dimensionTexture.loadFromFile("textures/minesweeperMediumBox.png");
		dimensionTile.setTexture(dimensionTexture);
		dimensionTile.setPosition((minimumWindowWidth / 2), heightBorder);
		dimensionChoice.draw(dimensionTile);

		// Hard Box
		dimensionTexture.loadFromFile("textures/minesweeperHardBox.png");
		dimensionTile.setTexture(dimensionTexture);
		dimensionTile.setPosition(widthBorder, (minimumWindowHeight / 2));
		dimensionChoice.draw(dimensionTile);

		// Custom Box
		dimensionTexture.loadFromFile("textures/minesweeperCustomBox.png");
		dimensionTile.setTexture(dimensionTexture);
		dimensionTile.setPosition((minimumWindowWidth / 2), (minimumWindowHeight / 2));
		dimensionChoice.draw(dimensionTile);

		//*****************************************************************************************

		dimensionChoice.display();
	}

	if(allowGameToRun)
	{
		for(int ix = 0; ix < rowsPrivate; ix++)
		{
			for( int jx = 0; jx < colsPrivate; jx++)
			{
				tiles[ix][jx].resetTiles();
			}
		}
		
		int numberOfMines = (rowsPrivate * colsPrivate) * percentage_of_mines;

		srand(time(0));
		//cout << "This is the number of mines that will be set " << numberOfMines << endl;
		int ix, jx;
		for(int i = 0; i < numberOfMines; i++)
		{

			ix = rand() % rowsPrivate;
			jx = rand() % colsPrivate;
			//cout << "(" << ix << "," << jx << ")" << endl;

			if(!tiles[ix][jx].getIsMine())
			{
				tiles[ix][jx].setIsMine(true);
				tiles[ix][jx].setIsTilesVisible(false);
			}
			else
			{
				i--;
			}
		}

		countAdjacentMines();
		runGame();
	}
}

bool Grid::checkIfWon()
{
	int unexplored = 0;
	int minesCovered = 0;
	for(int ix = 0; ix < rowsPrivate; ix++)
	{
		cout << ix << "|\t";
		for(int jx = 0; jx < colsPrivate; jx++)
		{	
			if(tiles[ix][jx].getTilesIcon() == '#')
				unexplored++;
			if(tiles[ix][jx].getIsMine() && tiles[ix][jx].getIsFlag())
			{
				minesCovered++;
			}
		}
		cout << endl;
	}

	unexplored -= minesCovered;
	
	if(unexplored == 0 && minesCovered == tiles[0][0].getTotalMines())
		return true;

	return false;
}