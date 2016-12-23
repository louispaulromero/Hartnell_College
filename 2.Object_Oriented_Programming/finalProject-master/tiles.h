/*	NAME: Chanel Aquino
 *	DATE CREATED: 8 April 2016
 *	DESCRIPTION: Tiles Header File for Minesweeper
 *	CSS2A Section 9010 Final Project
 * 	Due Date: 13 May 2016
 *	Group Members: Louis Romero, Sam Sanchez
 */

#ifndef Tiles_H
#define Tiles_H

#include <SFML/Graphics.hpp>

class Tiles
{
	private:
		static unsigned int total_mines;
		// Keep track of the total number of mines throughout all Tiles objects.
		int adjacentMines;

		char tile_icon;
		// #: unexplored 
		// 0-9: explored; number of mines nearby
		// *: mine
		// F: flag

		bool is_mine,		
			 is_tile_visible,
			 isDigit, 
			 isZero,
			 isFlag,
			 allSidesChecked;

	public:
		sf::Texture tileTexture; // Used to hold the texture
								 // of a Tiles object
//CONSTRUCTORS
		//*************************************
		Tiles();
		// Summary: Assigns default values to member variables.
		// total_mines = 0
		// tile_icon = #
		// is_mine = false
		// is_tile_visible = false
		//
		//*************************************
		//

		//*************************************
		Tiles(unsigned int total_mines);
		// Summary: Initializes this->total_mines and this->is_mine.
		// Also initializes remaining member variables to default values.
		//
		//*************************************
		//


//MEMBER METHODS
		//*************************************
		bool exploreTiles();
		// Summary: Explores the value of the Tiles object.
		// Postcondition: If the Tiles is a mine (is_mine = true), 
		// 		then set is_tile_visible to true and set the tile_icon to *.
		//		else, set the tile_icon to X.
		//
		//*************************************
		//

		//*************************************
		void resetTiles();
		// Summary: Resets all the values in the Tiles to the specifications of the default constructor.
		// Postcondition: If the original Tiles was a mine (is_mine = true), then decrement total_mines by 1.
		//	If total_mines = 0, do not subtract.
		//
		//*************************************
		//

//ACCESSOR METHODS (getters)
		//*************************************
		char getTilesIcon();
		// Summary: If the Tiles is a mine (is_mine = true)
		//	and the mine is not visible (is_tile_visible = false), 
		//	then return #.
		//	else, return value of tile_icon.
		//
		//*************************************
		//

		//*************************************
		unsigned int getTotalMines() const {return total_mines;}
		// Summary: Returns the total number of mines 
		// regardless of the value. Return type is of
		// type unsigned int.
		//*************************************
		//

		//*************************************
		bool getIsMine() const {return is_mine;}
		// Summary: Returns a boolean value that
		// dictates if a tile object has a mine or
		// not.
		//*************************************
		//

		//*************************************	
		bool getIsTileVisible() {return is_tile_visible;}
		// Summary: Returns a boolean value that 
		// dictates if the tile object is now visible
		//*************************************
		//

		//*************************************
		bool getIsDigit() const {return isDigit;}
		// Summary: Returns a boolean value that 
		// dictates if the tile object has an
		// adjacent mine count of a number other
		// than 0
		//*************************************
		//

		//*************************************
		bool getIsZero() const {return isZero;}
		// Summary: Returns a boolean value that 
		// dictates if the tile object has an
		// adjacent mine count of 0
		//*************************************
		//

		//*************************************
		bool getIsFlag() const {return isFlag;}
		// Summary: Returns a boolean value that 
		// dictates if the tile object is flagged or not
		//*************************************
		//

		//*************************************
		bool getAllSidesChecked() const {return allSidesChecked;}
		// Summary: Returns a boolean value that 
		// dictates if the tile object has all
		// it's sides checked in order for proper
		// revealing and counting of adjacent mines
		//*************************************
		//

		//*************************************
		int getAdjacentMines() const {return adjacentMines;}
		// Summary: Returns a integer that 
		// represents the number of adjacent mines per tile object
		//*************************************
		//

//MUTATOR METHODS (setters)
		//*************************************
		void setIsMine(bool mine);
		// Summary: Assigns value to object's is_mine.
		// Postcondition: If is_mine is true, increment total_mines by 1,
		//	set tile_icon to '*' and set is_tile_visible to false. 
		//
		//*************************************
		//

		//*************************************
		void setIsDigit(int digit);
		// Summary: Sets isDigit to true if digit is >= 1 && <= 8.
		//		Also sets tile icon to character representation
		//		of the integer.
		//
		//*************************************
		//
		//*************************************
		void setFlag();
		// Summary: Sets the isFlag bool to true or false
		// depending on the current value of isFlag
		// Precondition: Tile object must be initialized
		// Postcondition: isFlag set to true or false
		//*************************************
		//
		//*************************************
		void setTotalMines(unsigned int total_mines) {this->total_mines = total_mines;}
		// Summary: Sets the value of the total_mines variable
		// Postcondition: total_mines is reassigned
		//*************************************
		//
		//*************************************
		void setTilesIcon(char tile_icon) {this->tile_icon = tile_icon;}
		// Summary: Sets the value of the tile_icon variable
		// Precondition: arguement must be an integer in range(0,9), *,
		// or F
		// Postcondition: tile_icon is reassigned
		//*************************************
		void setIsTilesVisible(bool is_tile_visible);
		// Summary: Sets is_tile_visible to the value 
		// of the arguement (true/false)
		//*************************************
		void setIsZero(bool isZero) {this->isZero = isZero; this->tile_icon = '0';}
		// Summary: Sets isZero to the value 
		// of the arguement (true/false). Tile_icon is
		// also set to '0'
		//*************************************
		void setIsFlag(bool isFlag) {this->isFlag = isFlag; this->tile_icon = 'F';}
		// Summary: Sets isFlag to the value 
		// of the arguement (true/false). Tile_icon is
		// also set to 'F'
		//*************************************
		void setAllSidesChecked(bool allSidesChecked) {this->allSidesChecked = allSidesChecked;}
		// Summary: Sets allSidesChecked to the value 
		// of the arguement (true/false).
		//*************************************
		void setAdjacentMines(int adjacentMines) {this->adjacentMines = adjacentMines;}
		// Summary: adjacentMines is set to the
		// value of the arguement.
		//*************************************
};
#endif
