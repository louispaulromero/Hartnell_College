//Description: Lockers.  This program finds out which exact lockers are open, and how many lockers total are open out of 1000.

#include <stdio.h>
#include <stdbool.h>

int main()
{
	const int SIZE = 1000;
	bool array[SIZE];
	int counter=0;
	int target = 2;
	int sum = 0;
	//0 means locked
	//1 means open

	//ALL LOCKERS ARE INITILLY LOCKED
	for(int ix = 0; ix < SIZE; ix++)
	{
		array[ix]=false;
	}

	//1ST STUDENT OPENS EVERY LOCKER
	for(int ix = 0; ix < SIZE; ix++)
	{
		array[ix]=true;
	}
	//2ND STUDENT CLOSES EVERY OTHER LOCKER
	for(int ix = 0; ix < SIZE; ix++)
	{
		if((ix+1) % target != 1)
		{	
			array[ix]= false;
		}
	}
	target++;

	//x STUDENT OPENS (IF CLOSED) OR CLOSES (IF OPENED) EVERY x LOCKER
	while(target !=1000)
	{
		for(int ix = 0; ix < SIZE; ix++)
		{
			counter++;
			if(counter == target)
			{
				if(array[ix]== true)//if open
				{
					array[ix] = false;//close
				}
				else if(array[ix]==false)//if closed
				{
					array[ix] = true;//open
				}
				counter = 0;
			}
		}
		counter = 0;
		target++;
		//printf("target is %i\n", target);
	}

	//PRINT WHICH LOCKERS ARE OPEN AND COUNT
	for(int ix = 0; ix < SIZE; ix++)
	{
		sum+=array[ix];
		if(array[ix]==1)
		{
			printf("LOCKER # %i is OPEN\n", ix+1 );
		}
	}
	printf("TOTAL OPEN LOCKERS: %i\n", sum);

	//PRINT
	/*for(int ix = 0; ix < SIZE; ix++)
	{
		printf("%i", array[ix]);
	}*/


	return 0;
}

/*
Output:
LOCKER # 1 is OPEN
LOCKER # 4 is OPEN
LOCKER # 9 is OPEN
LOCKER # 16 is OPEN
LOCKER # 25 is OPEN
LOCKER # 36 is OPEN
LOCKER # 49 is OPEN
LOCKER # 64 is OPEN
LOCKER # 81 is OPEN
LOCKER # 100 is OPEN
LOCKER # 121 is OPEN
LOCKER # 144 is OPEN
LOCKER # 169 is OPEN
LOCKER # 196 is OPEN
LOCKER # 225 is OPEN
LOCKER # 256 is OPEN
LOCKER # 289 is OPEN
LOCKER # 324 is OPEN
LOCKER # 361 is OPEN
LOCKER # 400 is OPEN
LOCKER # 441 is OPEN
LOCKER # 484 is OPEN
LOCKER # 529 is OPEN
LOCKER # 576 is OPEN
LOCKER # 625 is OPEN
LOCKER # 676 is OPEN
LOCKER # 729 is OPEN
LOCKER # 784 is OPEN
LOCKER # 841 is OPEN
LOCKER # 900 is OPEN
LOCKER # 961 is OPEN
LOCKER # 1000 is OPEN
TOTAL OPEN LOCKERS: 32
*/
