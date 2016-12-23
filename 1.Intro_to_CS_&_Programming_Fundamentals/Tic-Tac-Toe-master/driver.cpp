//Tic Tac Toe

#include <iostream>
#include <cctype> 
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

void printWelcome();
void userCharSelection(char& playerOneChar, char& playerTwoChar);
void printStartGameBoard();
void gameBoard(int playersMove, string userIdentifier, char marker, char movesLeft[], char movesTracker[]);
void printInstructions();
void playerCharChoice();
void playerOneMove(char marker, char movesLeft[], char movesTracker[]);
void playerTwoMove(char marker, char movesLeft[], char movesTracker[]);
bool validMoveChecker(char moveToCheck, char movesTracker[], string userIdentifier);
int winnerChecker(char movesTracker[]);
int winnerMessage(int isWinner);
void restartGame(bool& uCController, char& uc, char playersML[], char moveR[], char movesM[], bool& control);
void playTwoPlayerGame();
void playOnePlayerGame();
void playerComputerMove(char marker, char movesLeft[], char movesTracker[]);
void startGame();

enum Menu{ONEPLAYERGAME=1, TWOPLAYERGAME};
int displayMenu();

int main()
{	
	startGame();
	return 0;
}

void printWelcome()
{
	cout << "WELCOME TO TIC-TAC-TOE" << endl;
}

void userCharSelection(char& playerOneChar, char& playerTwoChar)
{
	bool controller = true;
	while(controller)
	{
		cout << "PLAYER ONE Xs or Os: ";
		cin >> playerOneChar;
		playerOneChar = toupper(playerOneChar);
		if(playerOneChar == 'X' || playerOneChar =='O')
		{
			controller = false;
		}
	}

	if(playerOneChar == 'X')
	{
		playerTwoChar = 'O';
	}
	else
	{
		playerTwoChar = 'X';
	}

	cout << endl;
	cout << "PLAYER ONE is " << playerOneChar << endl;
	cout << "PLAYER TWO is " << playerTwoChar << endl;
}

void printStartGameBoard()
{
	cout << endl;
	cout << "     " << "|" << "     " << "|" << "     " << endl;
	cout << "  1  " << "|" << "  2  " << "|" << "  3  " << endl;
	cout << "     " << "|" << "     " << "|" << "     " << endl;
	cout << "------------------" << endl;
	cout << "     " << "|" << "     " << "|" << "     " << endl;
	cout << "  4  " << "|" << "  5  " << "|" << "  6  " << endl;
	cout << "     " << "|" << "     " << "|" << "     " << endl;
	cout << "------------------" << endl;
	cout << "     " << "|" << "     " << "|" << "     " << endl;
	cout << "  7  " << "|" << "  8  " << "|" << "  9  " << endl;
	cout << "     " << "|" << "     " << "|" << "     " << endl;
	cout << endl;
}

void printInstructions()
{	
	cout << "*************INSTRUCTIONS*************" << endl;
	cout << "HOW TO MAKE A MOVE: Enter 1 through 9." << endl;
	cout << endl;
}

void gameBoard(int playersMove, string userIdentifier, char marker, char movesLeft[], char movesTracker[])
{	
	const int SIZE = 9;

	if(userIdentifier == "P1" && marker == 'X')
	{
		
			movesLeft[playersMove] = 'X';
	}

	else if (userIdentifier == "P1" && marker == 'O')
	{
			movesLeft[playersMove] = 'O';
	}


	if(userIdentifier == "P2" && marker == 'X')
	{
		
			movesLeft[playersMove] = 'X';
	}

	else if (userIdentifier == "P2" && marker == 'O')
	{
			movesLeft[playersMove] = 'O';
	}

	if (userIdentifier == "PC" && marker == 'O')
	{
			movesLeft[playersMove] = 'O';
	}

	cout << endl;
	cout << "     " << "|" << "     " << "|" << "     " << endl;
	cout << "  " << movesLeft[0] << "  " << "|" << "  " << movesLeft[1] << "  " << "|" << "  " << movesLeft[2] << "  " << endl;
	cout << "     " << "|" << "     " << "|" << "     " << endl;
	cout << "------------------" << endl;
	cout << "     " << "|" << "     " << "|" << "     " << endl;
	cout << "  " << movesLeft[3] << "  " << "|" << "  " << movesLeft[4] << "  " << "|" << "  " << movesLeft[5] << "  " << endl;
	cout << "     " << "|" << "     " << "|" << "     " << endl;
	cout << "------------------" << endl;
	cout << "     " << "|" << "     " << "|" << "     " << endl;
	cout << "  " << movesLeft[6] << "  " << "|" << "  " << movesLeft[7] << "  " << "|" << "  " << movesLeft[8] << "  " << endl;
	cout << "     " << "|" << "     " << "|" << "     " << endl;
	cout << endl;
}

void playerOneMove(char marker, char movesLeft[], char movesTracker[])
{
	bool controller = true;
	char playerOneChoice;
	int boardChanger;
	bool playerOneChoiceController = true;
	string playerID = "P1";

	while(controller)
	{
		while(playerOneChoiceController == true)
		{
			cout << "PLAYER ONE make your move: " << endl;
			cin >> playerOneChoice;
			playerOneChoiceController = validMoveChecker(playerOneChoice, movesTracker, playerID);
		}

		playerOneChoiceController = true;

		if(playerOneChoice == '1' || playerOneChoice == '2' || playerOneChoice == '3' || playerOneChoice == '4' || playerOneChoice == '5' || playerOneChoice == '6' || playerOneChoice == '7' || playerOneChoice == '8' || playerOneChoice == '9')
		{
			controller = false;
		}
	}

	switch(playerOneChoice)
	{
		case '1':
			boardChanger = 0;
			movesTracker[boardChanger] == '1';
			break;
		case '2':
			boardChanger = 1;
			movesTracker[boardChanger] == '1';
			break;
		case '3':
			boardChanger = 2;
			movesTracker[boardChanger] == '1';
			break;
		case '4':
			boardChanger = 3;
			movesTracker[boardChanger] == '1';
			break;
		case '5':
			boardChanger = 4;
			movesTracker[boardChanger] == '1';
			break;
		case '6':
			boardChanger = 5;
			movesTracker[boardChanger] == '1';
			break;
		case '7':
			boardChanger = 6;
			movesTracker[boardChanger] == '1';
			break;
		case '8':
			boardChanger = 7;
			movesTracker[boardChanger] == '1';
			break;
		case '9':
			boardChanger = 8;
			movesTracker[boardChanger] == '1';
			break;
		default: 
			cout << "INVALID INPUT" << endl;
	}

	gameBoard(boardChanger, playerID, marker, movesLeft, movesTracker);
}

void playerTwoMove(char marker, char movesLeft[], char movesTracker[])
{
	bool controller = true;
	char playerTwoChoice;
	int boardChanger;
	string playerID = "P2";
	bool playerTwoChoiceController = true;

	while(controller)
	{

		while(playerTwoChoiceController == true)
		{
			cout << "PLAYER TWO make your move: " << endl;
			cin >> playerTwoChoice;
			playerTwoChoiceController = validMoveChecker(playerTwoChoice, movesTracker, playerID);
		}

		if(playerTwoChoice == '1' || playerTwoChoice == '2' || playerTwoChoice == '3' || playerTwoChoice == '4' || playerTwoChoice == '5' || playerTwoChoice == '6' || playerTwoChoice == '7' || playerTwoChoice == '8' || playerTwoChoice == '9')
		{
			controller = false;
		}
	}

	switch(playerTwoChoice)
	{
		case '1':
			boardChanger = 0;
			break;
		case '2':
			boardChanger = 1;
			break;
		case '3':
			boardChanger = 2;
			break;
		case '4':
			boardChanger = 3;
			break;
		case '5':
			boardChanger = 4;
			break;
		case '6':
			boardChanger = 5;
			break;
		case '7':
			boardChanger = 6;
			break;
		case '8':
			boardChanger = 7;
			break;
		case '9':
			boardChanger = 8;
			break;
		default: 
			cout << "INVALID INPUT" << endl;
	}

	gameBoard(boardChanger, playerID, marker, movesLeft, movesTracker);
}

bool validMoveChecker(char moveToCheck, char movesTracker[], string userIdentifier)
{
	int indexOfArray;

	switch(moveToCheck)
	{
		case '1':
			indexOfArray = 0;
			break;
		case '2':
			indexOfArray = 1;
			break;
		case '3':
			indexOfArray = 2;
			break;
		case '4':
			indexOfArray = 3;
			break;
		case '5':
			indexOfArray = 4;
			break;
		case '6':
			indexOfArray = 5;
			break;
		case '7':
			indexOfArray = 6;
			break;
		case '8':
			indexOfArray = 7;
			break;
		case '9':
			indexOfArray = 8;
			break;
		default:
			cout << "INVALID INPUT" << endl;
	}

	if(movesTracker[indexOfArray] == '0' && userIdentifier == "P1")
	{
		movesTracker[indexOfArray] = '1';
		return false;
	}
	else if(movesTracker[indexOfArray] == '0' && userIdentifier == "P2")
	{
		movesTracker[indexOfArray] = '2';
		return false;
	}
	else if(movesTracker[indexOfArray] == '0' && userIdentifier == "PC")
	{
		movesTracker[indexOfArray] = '2';
		return false;
	}
	else
	{
		return true;
	}
}

int winnerChecker(char movesTracker[])
{
	if( movesTracker[0] == '1' && movesTracker[1] == '1' && movesTracker[2] == '1')
	{
		return 1;
	}
	if( movesTracker[3] == '1' && movesTracker[4] == '1' && movesTracker[5] == '1')
	{
		return 1;
	}
	if( movesTracker[6] == '1' && movesTracker[7] == '1' && movesTracker[8] == '1')
	{
		return 1;
	}
	if( movesTracker[0] == '1' && movesTracker[3] == '1' && movesTracker[6] == '1')
	{
		return 1;
	}
	if( movesTracker[1] == '1' && movesTracker[4] == '1' && movesTracker[7] == '1')
	{
		return 1;
	}
	if( movesTracker[2] == '1' && movesTracker[5] == '1' && movesTracker[8] == '1')
	{
		return 1;
	}
	if( movesTracker[2] == '1' && movesTracker[4] == '1' && movesTracker[6] == '1')
	{
		return 1;
	}
	if( movesTracker[0] == '1' && movesTracker[4] == '1' && movesTracker[8] == '1')
	{
		return 1;
	}


	if( movesTracker[0] == '2' && movesTracker[4] == '2' && movesTracker[8] == '2')
	{
		return 2;
	}
	if( movesTracker[0] == '2' && movesTracker[1] == '2' && movesTracker[2] == '2')
	{
		return 2;
	}
	if( movesTracker[3] == '2' && movesTracker[4] == '2' && movesTracker[5] == '2')
	{
		return 2;
	}
	if( movesTracker[6] == '2' && movesTracker[7] == '2' && movesTracker[8] == '2')
	{
		return 2;
	}
	if( movesTracker[0] == '2' && movesTracker[3] == '2' && movesTracker[6] == '2')
	{
		return 2;
	}
	if( movesTracker[1] == '2' && movesTracker[4] == '2' && movesTracker[7] == '2')
	{
		return 2;
	}
	if( movesTracker[2] == '2' && movesTracker[5] == '2' && movesTracker[8] == '2')
	{
		return 2;
	}
	if( movesTracker[2] == '2' && movesTracker[4] == '2' && movesTracker[6] == '2')
	{
		return 2;
	}
}

int winnerMessage(int isWinner)
{
	char userChoice;
	bool controller = true;

	if(isWinner == 1)
	{
		cout << "PLAYER ONE WINS" << endl;
		while(controller == true)
		{
			cout << "Would you like to play again?" << endl;
			cin >> userChoice;
			userChoice = toupper(userChoice);
			if(userChoice == 'Y')
			{
				int menuChoice;
				menuChoice = displayMenu();

				if(menuChoice == ONEPLAYERGAME)
				{
					playOnePlayerGame();
				}
				else if (menuChoice == TWOPLAYERGAME)
				{
					playTwoPlayerGame();
				}
			}
			if(userChoice == 'N')
			{
				cout << "END OF GAME" << endl;
				exit(1);
			}
		}

	}

	if(isWinner == 2)
	{
		cout << "PLAYER TWO WINS" << endl;
		while(controller == true)
		{
			cout << "Would you like to play again?" << endl;
			cin >> userChoice;
			userChoice = toupper(userChoice);
			if(userChoice == 'Y')
			{
				int menuChoice;
				menuChoice = displayMenu();

				if(menuChoice == ONEPLAYERGAME)
				{
					playOnePlayerGame();
				}
				else if (menuChoice == TWOPLAYERGAME)
				{
					playTwoPlayerGame();
				}
			}
			if(userChoice == 'N')
			{
				cout << "END OF GAME" << endl;
				exit(1);
			}
		}
	}
	
}

void restartGame(bool& uCController, char& uc, char playersML[], char moveR[], char movesM[], bool& control)
{
	while(uCController == true)
	{
		cout << "Would you like to play again?" << endl;
		cin >> uc;
		uc = toupper(uc);
		if(uc == 'Y')
		{
			uCController = false;
		}
		if(uc == 'N')
		{
			uCController = false;
		}
	}

	uCController = true;

	if(uc == 'Y')
	{
		for(int jx = 0; jx < 9; jx++)
		{
			playersML[jx] = moveR[jx];
			movesM[jx] = '0';
		}
	}
	if(uc == 'N')
	{
		control = false;
	}

}

void playTwoPlayerGame()
{
	const int SIZE = 9;
	char playersMovesLeft[SIZE] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
	char moveRestarter[SIZE] = {'1','2','3','4','5','6','7','8','9'};
	char movesMade[SIZE] = {'0','0','0','0','0','0','0','0','0'};
	char playerOneMarker, playerTwoMarker;
	bool controller = true;
	char userChoice;
	bool userChoiceController = true;
	int winnerOrNot; 

	while(controller == true)
	{
		printWelcome();
		userCharSelection(playerOneMarker, playerTwoMarker);
		printStartGameBoard();
		printInstructions();

		for(int ix = 0; ix < 4; ix++)
		{
			playerOneMove(playerOneMarker, playersMovesLeft, movesMade);
			winnerOrNot = winnerChecker(movesMade);
			winnerMessage(winnerOrNot);

			playerTwoMove(playerTwoMarker, playersMovesLeft, movesMade);
			winnerOrNot = winnerChecker(movesMade);
			winnerMessage(winnerOrNot);
		}
		playerOneMove(playerOneMarker, playersMovesLeft, movesMade);
		winnerOrNot = winnerChecker(movesMade);
		winnerMessage(winnerOrNot);

		cout << "GAME IS A DRAW" << endl;

		restartGame(userChoiceController, userChoice, playersMovesLeft, moveRestarter, movesMade, controller);
	}
	cout << "END OF GAME" << endl;

}

// PLAYER VS COMPUTER FUNCTIONS
void playOnePlayerGame()
{
	const int SIZE = 9;
	char playersMovesLeft[SIZE] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
	char moveRestarter[SIZE] = {'1','2','3','4','5','6','7','8','9'};
	char movesMade[SIZE] = {'0','0','0','0','0','0','0','0','0'};
	bool controller = true;
	char userChoice;
	bool userChoiceController = true;
	int winnerOrNot; 
	char playerOneMarker = 'X'; 
	char playerComputerMarker = 'O';

	while(controller == true)
	{
		printWelcome();
		printStartGameBoard();
		printInstructions();

		for(int ix = 0; ix < 4; ix++)
		{
			playerOneMove(playerOneMarker, playersMovesLeft, movesMade);
			winnerOrNot = winnerChecker(movesMade);
			winnerMessage(winnerOrNot);

			playerComputerMove(playerComputerMarker, playersMovesLeft, movesMade);
			winnerOrNot = winnerChecker(movesMade);
			winnerMessage(winnerOrNot);
		}
		playerOneMove(playerOneMarker, playersMovesLeft, movesMade);
		winnerOrNot = winnerChecker(movesMade);
		winnerMessage(winnerOrNot);

		cout << "GAME IS A DRAW" << endl;

		restartGame(userChoiceController, userChoice, playersMovesLeft, moveRestarter, movesMade, controller);

	}
}

//PLAY ONE PLAYER GAME
void playerComputerMove(char marker, char movesLeft[], char movesTracker[])
{
	srand(time(0)); 
	bool controller = true;
	char playerComputerChoice;
	int boardChanger;
	string playerID = "PC";
	bool playerComputerChoiceController = true;
	int playerComputerChoiceNumber;

	while(controller)
	{

		while(playerComputerChoiceController == true)
		{	
			
			playerComputerChoiceNumber = (rand() % 9) + 1;
			
			switch(playerComputerChoiceNumber)
			{
				case 1:
					 playerComputerChoice = '1';
					 break;
				case 2:
					playerComputerChoice = '2';
					break;
				case 3:
					playerComputerChoice = '3';
					break;
				case 4:
					playerComputerChoice = '4';
					break;
				case 5:
					playerComputerChoice = '5';
					break;
				case 6:
					playerComputerChoice = '6';
					break;
				case 7:
					playerComputerChoice = '7';
					break;
				case 8:
					playerComputerChoice = '8';
					break;
				case 9:
					playerComputerChoice = '9';
					break;
				default: 
					cout << "INVALID INPUT" << endl;
			}
			playerComputerChoiceController = validMoveChecker(playerComputerChoice, movesTracker, playerID);
		}

		if(playerComputerChoice == '1' || playerComputerChoice == '2' || playerComputerChoice == '3' || playerComputerChoice == '4' || playerComputerChoice == '5' || playerComputerChoice == '6' || playerComputerChoice == '7' || playerComputerChoice == '8' || playerComputerChoice == '9')
		{
			controller = false;
		}

		switch(playerComputerChoice)
		{
				case '1':
					boardChanger = 0;
					break;
				case '2':
					boardChanger = 1;
					break;
				case '3':
					boardChanger = 2;
					break;
				case '4':
					boardChanger = 3;
					break;
				case '5':
					boardChanger = 4;
					break;
				case '6':
					boardChanger = 5;
					break;
				case '7':
					boardChanger = 6;
					break;
				case '8':
					boardChanger = 7;
					break;
				case '9':
					boardChanger = 8;
					break;
				default:
					cout << "INVALID INPUT" << endl;
		}

	}
	gameBoard(boardChanger, playerID, marker, movesLeft, movesTracker);
	cout << "COMPUTER COMPLETED MOVE" << endl;
	cout << endl;
	
}

int displayMenu()
{
	int menu = ONEPLAYERGAME;
	cout << "Enter 1 for ONE PLAYER\n"
	<< "Enter 2 FOR TWO PLAYERS\n";
	cin >> menu;
	return menu;
}

void startGame()
{
	int menuChoice;
	cout << "TIC-TAC-TOE" << endl;
	menuChoice = displayMenu();
	if(menuChoice == ONEPLAYERGAME)
	{
		playOnePlayerGame();
	}
	else if (menuChoice == TWOPLAYERGAME)
	{
		playTwoPlayerGame();
	}
}
