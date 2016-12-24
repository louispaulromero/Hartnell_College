//Description:  Midterm

#include <stdio.h>
#include <stdbool.h>

void identifyShape(int s[], int a[]);
int main()
{
	const int SIZE = 4;
	int sides[SIZE];
	int angles[SIZE];
	int sumOfAngles;
	bool keepGoing = true;
	char userChoice = 'x';

	while(keepGoing)
	{
		sumOfAngles = 360;
		for(int ix = 0; ix < 4; ix++)
		{	
			sides[ix] = -1;
			
			while(sides[ix] <= 0)
			{
				printf("PLEASE ENTER SIDE %i: ", ix+1);
				scanf("%i", &sides[ix]);
			}
		}

		for(int jx = 0; jx < 4; jx++)
		{
			angles[jx]=-1;

			if(jx != 3)
			{	
				printf("PLEASE ENTER ANGLE %i: ", jx+1);
				scanf("%i", &angles[jx]);
				while(angles[jx] <= 0)
				{
					printf("ANGLE MUST BE GREATER THAN 0:\n");
					printf("PLEASE RE-ENTER ANGLE %i: ", jx+1);
					scanf("%i", &angles[jx]);
				}
				sumOfAngles-= angles[jx];
			}
			else
			{
				printf("FINAL ANGLE MUST BE %i:\n", sumOfAngles);
				while(angles[jx] <= 0)
				{
					printf("PLEASE ENTER ANGLE %i: ", jx+1);
					scanf("%i", &angles[jx]);
			
					while(angles[jx] > sumOfAngles || angles[jx] < sumOfAngles)
					{
						printf("PLEASE RE-ENTER ANGLE %i: ", jx+1);
						scanf("%i", &angles[jx]);
					}
				}
			}
		}

		identifyShape(sides, angles);

		while(keepGoing)
		{
			printf("WOULD YOU LIKE TO DO THIS AGAIN?[Y/N]\n");
			scanf(" %c", &userChoice);

			if(userChoice == 'Y'|| userChoice == 'y'||userChoice == 'N' || userChoice == 'n')
			{
				keepGoing = false;
			}
		}
		keepGoing=true;
		if(userChoice == 'Y'|| userChoice == 'y')
		{
			keepGoing = true;
		}
		else if(userChoice == 'N' || userChoice == 'n')
		{
			keepGoing = false;
		}
	}
	printf("END OF PROGRAM\n");

	return 0;
}

void identifyShape(int s[], int a[])
{
	
	//ALL SIDES EQUAL
	if((s[0] == s[1]) && (s[0] == s[2]) && (s[0]== s[3]))
	{	
		//SQUARE
		if((a[0] == a[1]) && (a[0] == a[2]) && (a[0]== a[3]))
		{
			printf("THIS IS A SQUARE\n");
		}
		//RHOMBUS
		else if ((a[0] == a[2]) &&  (a[1]==a[3]))
		{
			printf("THIS IS A RHOMBUS\n");
		}
		else
		{
			printf("SHAPE CANNOT BE DETERMINED\n");
		}
	}
	else if ((s[0] == s[2]) &&  (s[1]==s[3]))
	{
		//ALL ANGLES EQUAL
		if((a[0] == a[1]) && (a[0] == a[2]) && (a[0]== a[3]))
		{
			printf("THIS IS A RECTANGLE\n");
		}
		else
		{
			printf("SHAPE CANNOT BE DETERMINED\n");
		}
	}
	else
	{
		printf("SHAPE CANNOT BE DETERMINED\n");
	}
	printf("\n");
}
/*
OUTPUT:
PLEASE ENTER SIDE 1: 1
PLEASE ENTER SIDE 2: 1
PLEASE ENTER SIDE 3: 1
PLEASE ENTER SIDE 4: 1
PLEASE ENTER ANGLE 1: 91
PLEASE ENTER ANGLE 2: 89
PLEASE ENTER ANGLE 3: 91
FINAL ANGLE MUST BE 89:
PLEASE ENTER ANGLE 4: 89
THIS IS A RHOMBUS

WOULD YOU LIKE TO DO THIS AGAIN?[Y/N]
y
PLEASE ENTER SIDE 1: 1
PLEASE ENTER SIDE 2: 1
PLEASE ENTER SIDE 3: 1
PLEASE ENTER SIDE 4: 1
PLEASE ENTER ANGLE 1: 90
PLEASE ENTER ANGLE 2: 90
PLEASE ENTER ANGLE 3: 90
FINAL ANGLE MUST BE 90:
PLEASE ENTER ANGLE 4: 90
THIS IS A SQUARE

WOULD YOU LIKE TO DO THIS AGAIN?[Y/N]
y
PLEASE ENTER SIDE 1: 1
PLEASE ENTER SIDE 2: 2
PLEASE ENTER SIDE 3: 1
PLEASE ENTER SIDE 4: 2
PLEASE ENTER ANGLE 1: 90
PLEASE ENTER ANGLE 2: 90
PLEASE ENTER ANGLE 3: 90
FINAL ANGLE MUST BE 90:
PLEASE ENTER ANGLE 4: 90
THIS IS A RECTANGLE

WOULD YOU LIKE TO DO THIS AGAIN?[Y/N]
Y
PLEASE ENTER SIDE 1: 1
PLEASE ENTER SIDE 2: 2
PLEASE ENTER SIDE 3: 3
PLEASE ENTER SIDE 4: 4
PLEASE ENTER ANGLE 1: 4
PLEASE ENTER ANGLE 2: 2
PLEASE ENTER ANGLE 3: 3
FINAL ANGLE MUST BE 351:
PLEASE ENTER ANGLE 4: 351
SHAPE CANNOT BE DETERMINED

WOULD YOU LIKE TO DO THIS AGAIN?[Y/N]
n
END OF PROGRAM
*/
