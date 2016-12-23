/*	NAME: Chanel Aquino
 *	DATE CREATED: 8 April 2016
 *	DESCRIPTION: Tiles Class Definition File for Minesweeper
 *	CSS2A Section 9010 Final Project
 * 	Due Date: 13 May 2016
 *	Group Members: Louis Romero, Sam Sanchez
 */

#include "tiles.h"
#include <iostream>
using namespace std;


unsigned int Tiles::total_mines = 0;

//*************************************
// Tiles() default
Tiles::Tiles()
{
	adjacentMines = 0;
	tile_icon = '#';
	is_mine = false;
	is_tile_visible = false;
	isDigit = false;
	isZero = false;
	isFlag = false;
	allSidesChecked = false;
	tileTexture.loadFromFile("textures/tileUnknown.png");
}
//
//*************************************
//


//*************************************
// Tiles() overloaded
Tiles::Tiles(unsigned int total_mines)
{
	this->total_mines = total_mines;
	tile_icon = '#';
	is_mine = false;
	is_tile_visible = false;
	isDigit = false;
	isZero = false;
	isFlag = false;
	allSidesChecked = false;
	tileTexture.loadFromFile("textures/tileUnknown.png");
}
//
//*************************************
//


//*************************************
// getTilesIcon()
char Tiles::getTilesIcon()
{
	if(!is_tile_visible)
		return '#';
	return tile_icon;
}
//
//*************************************
//


//*************************************
// setIsDigit()
void Tiles::setIsDigit(int digit)
{
	switch(digit)
	{
		case 0:
			setIsZero(true);
			setTilesIcon(48); // char representation of 0
			setIsTilesVisible(false);
			break;
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
			setIsDigit(true);
			setTilesIcon(digit + 48); // convert interger to char
			setIsTilesVisible(false);
			break;
		default:
			cout << "setIsDigit()" << endl;
			break;
	}
}
//
//*************************************
//


//*************************************
// setIsMine()
void Tiles::setIsMine(bool mine)
{
	is_mine = mine;
	if(is_mine)
	{
		total_mines++;
		setTilesIcon('*');
	}
}
//
//*************************************
//

//*************************************
// exploreTiles()
bool Tiles::exploreTiles()
{
	// TODO: need to change 
	if(!isFlag)
	{
		if(is_mine)
		{
			setTilesIcon('*'); 
			setIsTilesVisible(true);
			tileTexture.loadFromFile("textures/mineClicked.png");
			//cout << endl << "GAME OVER!!!!" << endl;
			return true;
		}
		
		else
		{
			setIsTilesVisible(true);
			cout << "Adjacent Mines = " << adjacentMines << endl;
			switch(adjacentMines)
			{
				case 0:
					tileTexture.loadFromFile("textures/tileNothing.png");
					setTilesIcon('0');
					break;
				case 1:
					tileTexture.loadFromFile("textures/1.png");
					setTilesIcon('1');
					break;
				case 2:
					tileTexture.loadFromFile("textures/2.png");
					setTilesIcon('2');
					break;
				case 3:
					tileTexture.loadFromFile("textures/3.png");
					setTilesIcon('3');
					break;
				case 4:
					tileTexture.loadFromFile("textures/4.png");
					setTilesIcon('4');
					break;
				case 5:
					tileTexture.loadFromFile("textures/5.png");
					setTilesIcon('5');
					break;
				case 6:
					tileTexture.loadFromFile("textures/6.png");
					setTilesIcon('6');
					break;
				case 7:
					tileTexture.loadFromFile("textures/7.png");
					setTilesIcon('7');
					break;
				case 8:
					tileTexture.loadFromFile("textures/8.png");
					setTilesIcon('8');
					break;
				default:
					break;
			}

			return false;
		}
	}

	return false;
}
//
//*************************************
//

//*************************************
void Tiles::resetTiles()
{
	if(is_mine && total_mines != 0)
		total_mines--;

	setTilesIcon('#');
	setIsMine(false);
	setIsTilesVisible(false);
	setIsDigit(false);
	setIsZero(false);
	setIsFlag(false);
	setAllSidesChecked(false);
	tileTexture.loadFromFile("textures/tileUnknown.png");
}
//
//*************************************
//
//*************************************
void Tiles::setFlag()
{
	if(!is_tile_visible)
	{
		if(!getIsFlag())
		{
			setIsFlag(true);
			setTilesIcon('F');
			tileTexture.loadFromFile("textures/flag.png");
		}

		else if(getIsFlag())
		{
			setIsFlag(false);
			setTilesIcon('#');
			tileTexture.loadFromFile("textures/tileUnknown.png");
		}
	}
}
//
//*************************************
//
void Tiles::setIsTilesVisible(bool is_tile_visible)
{
	this->is_tile_visible = is_tile_visible;

	return;
}