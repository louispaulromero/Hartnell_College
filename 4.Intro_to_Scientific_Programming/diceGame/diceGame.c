//Description:  This program is a Dice game where the computer and player has two dice.
//Each die has a value in between 1-6 that is randomly generated.  The player can roll
//his or her dice as many times as needed until a comfortable sum of the two dice is 
//achieved.  The player with the highest sum wins.

#include <stdio.h> // printf() scanf()
#include <time.h> // time(NULL)
#include <stdlib.h> // srand() rand()

int main()
{
	int ix = 0;

	unsigned int iseed = (unsigned int)time(NULL);
	srand (iseed);
	int playerDieOne = (rand() % 6)+ 1; //((rand() % range) + startAtThisNumber)
	int playerDieTwo = (rand() % 6)+ 1;
	int computerDieOne = (rand() % 6) + 1;
	int computerDieTwo = (rand() % 6) + 1;
	int playerDiceSum;
	int computerDiceSum = computerDieOne + computerDieTwo;
	int playerChoice = 1;
	char loopController = 'T';

	printf("Beat the computer!\n");

	while(loopController == 'T')
	{
		playerDieOne = (rand() % 6)+ 1;
		playerDieTwo = (rand() % 6)+ 1;
		playerDiceSum = playerDieOne + playerDieTwo;
		

		printf("You rolled a %i and a %i (total = %i)\n", playerDieOne, playerDieTwo, playerDiceSum);
		printf("Do you want to keep those? (Yes(1) or No(2))\n");
		scanf("%i", &playerChoice);

		while(playerChoice == 2)
		{
			printf("Roll again...\n");
			playerDieOne = (rand() % 6)+ 1;
			playerDieTwo = (rand() % 6)+ 1;
			playerDiceSum = playerDieOne + playerDieTwo;
			printf("You rolled a %i and a %i (total = %i)\n", playerDieOne, playerDieTwo, playerDiceSum);
			printf("Do you want to keep those? (Yes(1) or No(2))\n");
			scanf("%i", &playerChoice);
		}
		break;
	}

	printf("The computer rolled %i and %i (total = %i)\n", computerDieOne, computerDieTwo, computerDiceSum);

	if(playerDiceSum > computerDiceSum)
	{
		printf("You beat the computer!\n");
	}
	else
	{
		printf("You lose.\n");
	}

	return 0;
}
/*
The program's output:
Beat the computer!
You rolled a 1 and a 3 (total = 4)
Do you want to keep those? (Yes(1) or No(2))
2
Roll again...
You rolled a 3 and a 6 (total = 9)
Do you want to keep those? (Yes(1) or No(2))
2
Roll again...
You rolled a 4 and a 6 (total = 10)
Do you want to keep those? (Yes(1) or No(2))
1
The computer rolled 1 and 6 (total = 7)
You beat the computer!
*/
