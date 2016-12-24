//Description:  This program computes the amount of steel and concrete required for he construction of a series of cooling tanks for a power plant.

#include <stdio.h> // printf() scanf()

void getInput(float *L, float *W, float *H, float *Tw, float *Tf);
float computeConcrete(float L, float W, float H, float Tw, float Tf);
float computeSteel(float c);
void printOutput(float L, float W, float H, float Tw, float Tf, float ac, float as);

int main()
{	
	float length, width, height, tw, tf, amountConcrete, amountSteel;
	getInput(&length, &width, &height, &tw, &tf);
	amountConcrete = computeConcrete(length, width, height, tw, tf);
	amountSteel = computeSteel(amountConcrete);
	printOutput(length, width, height, tw, tf, amountConcrete, amountSteel);
	return 0;
}

void getInput(float *L, float *W, float *H, float *Tw, float *Tf)
{
	float tempLength, tempWidth, tempHeight, tempTw, tempTf;
	printf("Please enter length: ");
	scanf("%f", &tempLength);
	printf("Please enter width: ");
	scanf("%f", &tempWidth);
	printf("Please enter height: ");
	scanf("%f", &tempHeight);
	printf("Please enter wall thickness: ");
	scanf("%f", &tempTw);
	printf("Please enter floor thickness: ");
	scanf("%f", &tempTf);
	*L = tempLength;
	*W = tempWidth;
	*H = tempHeight;
	*Tw = tempTw;
	*Tf = tempTf;
}

float computeConcrete(float L, float W, float H, float Tw, float Tf)
{
	return (2*(L*W*Tw)) + (2*(W*H*Tw)) + (L*W*Tf);
}

float computeSteel(float c)
{
	return c * 0.25;
}

void printOutput(float L, float W, float H, float Tw, float Tf, float ac, float as)
{
	printf("A tane with dimensions: \nL=%.2f \nW=%.2f \nH=%.2f \nWT=%.2f\nFT=%.2f \nRequires %.2f ft^3 Steel and %.2f, ft^3 Concrete \n", L, W, H, Tw, Tf, as, ac);
}
/*
Output:
Please enter length: 1
Please enter width: 2
Please enter height: 3
Please enter wall thickness: 4
Please enter floor thickness: 5
A tane with dimensions: 
L=1.00 
W=2.00 
H=3.00 
WT=4.00
FT=5.00 
Requires 18.50 ft^3 Steel and 74.00, ft^3 Concrete 
*/
