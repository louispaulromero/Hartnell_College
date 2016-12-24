//Description:  This program finds and prints all prime numbers between 3 to 100.

#include <stdio.h> // printf() scanf()

int main()
{	
	int isPrime = 1;

	printf("The prime number between 3 and 100 are: ");
	for(int ix = 4; ix < 100; ix++)
	{
		isPrime = 1;

		for(int jx = 2; jx < ix-1; jx++)
		{
			if(ix%jx == 0)
			{
				isPrime = 0;
			}
		}

		if(isPrime)
		{
			printf("%i ", ix);
		}
	}
	printf("\n");

	return 0;
}

/*
The prime number between 3 and 100 are: 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97 
*/
