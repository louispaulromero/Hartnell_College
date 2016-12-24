//Description:  This program computes the Force and Average Thrust of a rocet motor given the weight, average velocity, and a time interval.
	
void inputFunction(float *W, float *V, float *t);
float computeForce(float W, float V, float t);
float computeThrust(float F, float W);
void outputFunction(float W, float V, float t, float F, float T);

#include <stdio.h>

int main()
{
	float Weight, Velocity, time, Force, Thrust;
	inputFunction(&Weight, &Velocity, &time);
	Force = computeForce(Weight, Velocity, time);
	Thrust = computeThrust(Force, Weight);
	outputFunction(Weight, Velocity, time, Force, Thrust);
	return 0;
}

void inputFunction(float *W, float *V, float *t)
{	
	float weight, velocity, time;

	printf("Please enter weight of the rocket: ");
	scanf("%f", &weight);
	printf("Please enter velocity: ");
	scanf("%f", &velocity);
	printf("Please enter time: ");
	scanf("%f", &time);
	*W = weight;
	*V = velocity;
	*t = time;
}

float computeForce(float W, float V, float t)
{
	return (W * V) / (32.2 * t); 
}

float computeThrust(float F, float W)
{
	return F + W;
}

void outputFunction(float W, float V, float t, float F, float T)
{
	printf("Weight = %.2f\n", W);
	printf("Velocity = %.2f\n", V);
	printf("time = %.2f\n", t);
	printf("Force = %.2f\n", F);
	printf("Thrust = %.2f\n", T);
}


/*
Output:
Please enter weight of the rocket: 1
Please enter velocity: 2
Please enter time: 3
Weight = 1.00
Velocity = 2.00
time = 3.00
Force = 0.02
Thrust = 1.02
*/


