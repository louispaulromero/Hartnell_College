/*	NAME: Louis Paul Romero
 *	DATE CREATED: 23 April 2016
 *	DESCRIPTION: grid.h for Minesweeper
 *	CSS2A Section 9010 Final Project
 * 	Due Date: 13 May 2016
 *	Group Members: Chanel Aquino, Sam Sanchez
 *  Modifications: Added textures and sprites for the dimension
 *  choice, window border, and the game tiles.Also implemented the
 *  checkHasWon(), dimension choice window, and game window
 */

#ifndef GRID_H
#define GRID_H

#include "tiles.h"

class Grid
{
	private:
		Tiles tiles[30][30];

		sf::RenderWindow gamespace;
		sf::RenderWindow dimensionChoice;
		sf::Sprite game_tile;
		sf::Texture borderTexture;
		sf::Sprite borderTile;
		sf::Texture headerTexture;
		sf::Sprite headerTile;
		sf::Texture dimensionTexture;
		sf::Sprite dimensionTile;

		unsigned int rowsPrivate,
					 colsPrivate,
					 widthBorder,
					 heightBorder,
					 unexploredTiles;

		bool isGameOver,
			 firstClick,
			 hasWon;
	public:
//CONSTRUCTORS
		//*************************************
		Grid();
		// Summary: Assigns default values to member variables.
		//
		//*************************************
		//

		//*************************************
		Grid(unsigned int rows, unsigned int cols);
		// Summary: Initializes this->rowsPrivate and this->colsPrivate.
		//		Creates a grid with dimensions (rows x cols).
		//		Place random number of mines at random locations of
		//		tiles array.
		//		Initializes tile_icon of individual tiles.
		//
		//*************************************
		//


//MEMBER METHODS
		//*******************************************************
		void revealAllTiles();
		// Summary: Will load all appropiate textures for each tile
		// Texture will depend on tile_icon value of each Tiles object
		// Precondition: The bool value isGameOver must be true
		// Postcondition: User cannot click on the grid.
		//*******************************************************
		void makeOneTileVisible(int row, int col);
		// Summary: sets the attribute is_tile_visible of a Tiles
		// object to true
		// Precondition: row and col must be equivalent to a valid
		// position on the 2d array of Tiles objects
		//*******************************************************
		bool checkAllNeighbors(int row, int col);
		// Summary: Recurssive search to reveal all adjacent tiles
		// with an adjacent mine count of 0
		// Precondition: row and col must be in the range of rowsPrivate
		// and colsPrivate. 
		// Postcondition: Changes the texture of a tile depending
		// on adajcentMines value
		//*******************************************************
		void countAdjacentMines();
		// Summary: Counts the adjacentMines of each tile in the game board.
		// Postcondition: Assigns values to each Tiles object
		//*******************************************************
		void calculateWindowDimensions(int& height, int& width);
		// Summary: Returns two integer values to help create a 
		// proportionally aesthetic window to hold the gamespace.
		//*******************************************************
		void resetGame(const int& rows, const int& cols);
		// Summary: Resets all variable in Grid and Tiles class
		// to their default values
		// Precondition: Player clicks on the reset tile of the game.
		// Postcondition: User is taken back to the menu to select the
		// dimensions of the new grid.
		//*******************************************************
		void runGame();
		// Summary: Builds the necessary windows for the dimension choice
		// menu and the gamespace.
		//*******************************************************
		bool checkIfWon();
		// Summary: Checks if the player has won the game
		// Precondition: All Tiles objects with isMine = true
		// and Tiles objects with isMine = false have is_tile_visible
		// set to true
		// Postcondition: User can no longer click on the grid and
		// must restart the game
		//*******************************************************


//ACCESSOR METHODS (getters)
		//*******************************************************
		unsigned int getRowsPrivate()const {return rowsPrivate;}
		// Summary: Returns an unsinged int
		//*******************************************************
		unsigned int getColsPrivate()const {return colsPrivate;}
		// Summary: Returns an unsigned int
		//*******************************************************

//MUTATOR METHODS (setters)
		//*******************************************************
		void setRowsPrivate(unsigned int rowsPrivate) {this->rowsPrivate = rowsPrivate;}
		// Summary: Sets the variable rowsPrivate to
		// the value of the arguement
		//*******************************************************
		void setColsPrivate(unsigned int colsPrivate) {this->colsPrivate = colsPrivate;}
		// Summary: Sets the variable colsPrivate to
		// the value of the arguement
		//*******************************************************
};
#endif
