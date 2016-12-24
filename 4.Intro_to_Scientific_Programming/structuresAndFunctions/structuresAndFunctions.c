//Louis Paul Romero
//11/12/2016
//p56.c
//Structures and Functions

#include <stdio.h>
#include <math.h>

struct strength
{
	float d, p, strain, stress;
};
typedef struct strength STRENGTH;
void funcInputS(STRENGTH *);
void funcOutputS(STRENGTH);
STRENGTH funcCalcS(STRENGTH);


int main()
{	
	int userChoice;
	struct strength s1;
	funcInputS(&s1);
	s1 = funcCalcS(s1);
	funcOutputS(s1);
	return 0; 
}

void funcInputS(STRENGTH *s)
{
	printf("Please enter diameter: ");
	scanf("%f", &s->d);
	printf("Please enter load: ");
	scanf("%f", &s->p);
}

STRENGTH funcCalcS(STRENGTH s)
{
	float area;
	area = (3.1415 * (s.d * s.d))/4;
	s.stress = s.p/area;
	float E = 30000000;
	s.strain = s.stress/E;
	return s;
}

void funcOutputS(STRENGTH s)
{
	printf("Diameter: %.2f \n", s.d);
	printf("Load: %.2f \n", s.p);
	printf("Strain: %.20f \n", s.strain);
	printf("Stress: %.2f \n", s.stress);
}

/*
Output:
Please enter diameter: 1
Please enter load: 2
Diameter: 1.00 
Load: 2.00 
Strain: 0.00000008488513714155 
Stress: 2.55 
*/




