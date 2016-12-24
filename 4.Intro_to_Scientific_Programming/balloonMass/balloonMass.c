//Description:  This program calculates a balloon's mass.

#include <stdio.h> // printf() scanf()

void inputFunction(float *volume, float *pressure, float *temperature);
float calcMassFunction(float volume, float pressure, float temperature);
void ouputFunction(float volume, float pressure, float temperature, float mass);

int main()
{
	float V,
		  P,
		  T,
		  M;
		  
	inputFunction(&V, &P, &T);
	M = calcMassFunction(V, P, T);
	ouputFunction(V,P,T,M);

	return 0;
}

void inputFunction(float *volume, float *pressure, float *temperature)
{
	printf("Input (V, P, T)\n");
	scanf("%f %f %f", volume, pressure, temperature);
}

float calcMassFunction(float volume, float pressure, float temperature)
{
	float M;

	M = (pressure * volume) / (0.42 * (temperature + 460));

	return M;
}

void ouputFunction(float volume, float pressure, float temperature, float mass)
{
	printf("Volume: %.2f \nPressure: %.2f \nTemperature: %.2f \nMass: %.2f \n", volume, pressure, temperature, mass);
}

/*
Input (V, P, T)
1
2
3
Volume: 1.00 
Pressure: 2.00 
Temperature: 3.00 
Mass: 0.01 
*/
