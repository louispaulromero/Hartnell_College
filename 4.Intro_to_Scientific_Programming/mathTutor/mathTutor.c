//Description:  This program is a math tutor program where the user can practice addition, subtraction, and multiplication.

#include <stdio.h> // printf() scanf()
#include <time.h> // time(NULL)
#include <stdlib.h> // srand() rand()
int main()
{
	unsigned int iseed = (unsigned int)time(NULL);
	srand(iseed);

	int randomNumberOne,
	    randomNumberTwo, 
	    userChoice,
	    keepDoingMath,
	    userAnswer,
	    correctAnswer;
	int counter = 0;

	printf("Please make your choice: \n");
	printf("addition(1) subtraction(2) multiplication(3)\n");
	scanf("%i", &userChoice);

	if(userChoice == 1)
	{
		while(1)
		{
			randomNumberOne = (rand() % 9);
			randomNumberTwo = (rand() % 9);
			correctAnswer = randomNumberOne + randomNumberTwo;
			if(counter == 0)
			{
				printf("What is %i + %i equal to: ", randomNumberOne, randomNumberTwo);
			}
			else
			{
				printf("what is %i + %i equal to: ", randomNumberOne, randomNumberTwo);
			}
			scanf("%i", &userAnswer);
			counter++;

			if(userAnswer == correctAnswer)
			{
				printf("Correct! Would you like to try again? (1 for Yes, 2 for No): ");
				scanf("%i", &keepDoingMath);
				counter = 0;
			}
			else
			{
				printf("That is incorrect, ");
			}

			if(keepDoingMath == 2)
			{
				break;
			}
		}

	}
	else if(userChoice == 2)
	{
		while(1)
		{
			randomNumberOne = (rand() % 9);
			randomNumberTwo = (rand() % 9);
			correctAnswer = randomNumberOne - randomNumberTwo;
			if(counter == 0)
			{
				printf("What is %i - %i equal to: ", randomNumberOne, randomNumberTwo);
			}
			else
			{
				printf("what is %i - %i equal to: ", randomNumberOne, randomNumberTwo);
			}
			scanf("%i", &userAnswer);
			counter++;

			if(userAnswer == correctAnswer)
			{
				printf("Correct! Would you like to try again? (1 for Yes, 2 for No): ");
				scanf("%i", &keepDoingMath);
				counter = 0;
			}
			else
			{
				printf("That is incorrect, ");
			}

			if(keepDoingMath == 2)
			{
				break;
			}
		}

	}
	else if(userChoice == 3)
	{
		while(1)
		{
			randomNumberOne = (rand() % 9);
			randomNumberTwo = (rand() % 9);
			correctAnswer = randomNumberOne * randomNumberTwo;
			if(counter == 0)
			{
				printf("What is %i * %i equal to: ", randomNumberOne, randomNumberTwo);
			}
			else
			{
				printf("what is %i * %i equal to: ", randomNumberOne, randomNumberTwo);
			}
			scanf("%i", &userAnswer);
			counter++;

			if(userAnswer == correctAnswer)
			{
				printf("Correct! Would you like to try again? (1 for Yes, 2 for No): ");
				scanf("%i", &keepDoingMath);
				counter = 0;
			}
			else
			{
				printf("That is incorrect, ");
			}

			if(keepDoingMath == 2)
			{
				break;
			}
		}

	}
	else
	{
		printf("INVALID INPUT!\n");
	}

	printf("Thank you for playing!\n");

	return 0;
}
/*
The program's output:
Please make your choice: 
addition(1) subtraction(2) multiplication(3)
1
What is 4 + 2 equal to: 1
That is incorrect, what is 6 + 0 equal to: 6
Correct! Would you like to try again? (1 for Yes, 2 for No): 2
Thank you for playing!

Please make your choice: 
addition(1) subtraction(2) multiplication(3)
2
What is 7 - 4 equal to: 1
That is incorrect, what is 4 - 7 equal to: -3
Correct! Would you like to try again? (1 for Yes, 2 for No): 2
Thank you for playing!

Please make your choice: 
addition(1) subtraction(2) multiplication(3)
3
What is 0 * 8 equal to: 1
That is incorrect, what is 5 * 3 equal to: 15
Correct! Would you like to try again? (1 for Yes, 2 for No): 2
Thank you for playing!
*/
