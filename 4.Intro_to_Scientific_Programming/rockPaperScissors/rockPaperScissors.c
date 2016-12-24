//Description:  This program is a game of rock paper and scissors.

#include <stdio.h>

int main()
{
	int playerOneChoice,
		 playerTwoChoice;

	printf("Enter 1 for ROCK Enter 2 for PAPER Enter 3 for SCISSORS\n");

	printf("Player 1 enter your choice: \n");
	scanf("%i", &playerOneChoice);

	printf("Player 2 enter your choice: \n");
	scanf("%i", &playerTwoChoice);

	//Player One Move
	if(playerOneChoice == 1)//Rock
	{
		printf("Player 1 chose ROCK\n");
		//Player Two Move
		if(playerTwoChoice == 2)//Paper
		{
			printf("Player 2 chose PAPER\n");
			printf("PAPER covers ROCK\nPlayer 2 wins! \n");
		}
		else if(playerTwoChoice == 3) // Scissors
		{
			printf("Player 2 chose SCISSORS\n");
			printf("ROCK breaks SCISSORS\nPlayer 1 wins!\n");
		}
		else//Rock
		{
			printf("Player 2 chose ROCK\n");
			printf("IT'S A DRAW!\n");
		}
	}
	//Player One Move
	else if(playerOneChoice == 2)//Paper
	{
		printf("Player 1 chose PAPER\n");
		//Player Two Move
		if(playerTwoChoice == 1)//Rock
		{
			printf("Player 2 chose ROCK\n");
			printf("PAPER covers ROCK\nPlayer 1 wins! \n");
		}
		else if(playerTwoChoice == 3)//Scissors
		{
			printf("Player 2 chose SCISSORS\n");
			printf("SCISSORS cuts PAPER\nPlayer 2 wins!\n");
		}
		else//Paper
		{
			printf("Player 2 chose PAPER\n");
			printf("IT'S A DRAW!\n");
		}
	}
	//Player One Move
	else if(playerOneChoice == 3)//Scissors
	{	printf("Player 1 chose SCISSORS\n");
		//Player Two Move
		if(playerTwoChoice == 1)//Rock
		{
			printf("Player 2 chose ROCK\n");
			printf("ROCK breaks SCISSORS\nPlayer 2 wins!\n");
		}
		else if(playerTwoChoice == 2)//Paper
		{
			printf("Player 2 chose PAPER\n");
			printf("SCISSORS cuts PAPER\nPlayer 1 wins!\n");
		}
		else//Scissors
		{
			printf("Player 2 chose SCISSORS\n");
			printf("IT'S A DRAW!\n");
		}
	}
	else// Invalid input
	{
		printf("INVALID INPUT\n");
	}

	return 0;
}

/*
The program's output:
Enter 1 for ROCK Enter 2 for PAPER Enter 3 for SCISSORS
Player 1 enter your choice: 
1
Player 2 enter your choice: 
2
Player 1 chose ROCK
Player 2 chose PAPER
PAPER covers ROCK
Player 2 wins!
*/
