//Description: This programs takes a user's birth month and birth day and informs the user
//which zodiac signs they are compatible with.

#include <stdio.h>

int main()
{	
	int monthOfBirth,
		dayOfBirth;

	printf("Please enter month of birth: " );
	scanf("%i", &monthOfBirth );

	printf("Please enter day of birth: ");
	scanf("%i", &dayOfBirth);

	//Mar. 21–Apr. 19	
	if( ((monthOfBirth == 3) && (dayOfBirth >= 21 && dayOfBirth <= 31))  || 
		((monthOfBirth == 4) && (dayOfBirth >= 1 && dayOfBirth <= 19)) )
	{
		printf("A birthday of %i / %i has the zodiac Taurus\n", monthOfBirth, dayOfBirth);
		printf("Taurus is compatible with: Taurus, Virgo, Capricorn\n");
	}
	//Apr. 20–May 20
	else if( ((monthOfBirth == 4) && (dayOfBirth >= 20 && dayOfBirth <= 30))  || 
		((monthOfBirth == 5) && (dayOfBirth >= 1 && dayOfBirth <= 20)) )
	{
		printf("A birthday of %i / %i has the zodiac Aries\n", monthOfBirth, dayOfBirth);
		printf("Aries is compatible with: Aries, Leo, Sagittarius\n");
	}
	//May 21–June 21
	else if( ((monthOfBirth == 5) && (dayOfBirth >= 21 && dayOfBirth <= 31))  || 
		((monthOfBirth == 6) && (dayOfBirth >= 1 && dayOfBirth <= 21)) )
	{
		printf("A birthday of %i / %i has the zodiac Gemini\n", monthOfBirth, dayOfBirth);
		printf("Gemini is compatible with: Gemini, Libra, Aquarius\n");
	}
	//June 22–July 22
	else if( ((monthOfBirth == 6) && (dayOfBirth >= 22 && dayOfBirth <= 30))  || 
		((monthOfBirth == 7) && (dayOfBirth >= 1 && dayOfBirth <= 22)) )
	{
		printf("A birthday of %i / %i has the zodiac Cancer\n", monthOfBirth, dayOfBirth);
		printf("Cancer is compatible with: Cancer, Scorpio, Pisces\n");
	}
	//July 23–Aug. 22
	else if( ((monthOfBirth == 7) && (dayOfBirth >= 23 && dayOfBirth <= 31))  || 
		((monthOfBirth == 8) && (dayOfBirth >= 1 && dayOfBirth <= 22)) )
	{
		printf("A birthday of %i / %i has the zodiac Leo\n", monthOfBirth, dayOfBirth);
		printf("Leo is compatible with: Aries, Leo, Sagittarius\n");
	}
	//Aug. 23–Sept. 22
	else if( ((monthOfBirth == 8) && (dayOfBirth >= 23 && dayOfBirth <= 31))  || 
		((monthOfBirth == 9) && (dayOfBirth >= 1 && dayOfBirth <= 22)) )
	{
		printf("A birthday of %i / %i has the zodiac Virgo\n", monthOfBirth, dayOfBirth);
		printf("Virgo is compatible with: Taurus, Virgo, Capricorn\n");
	}
	//Sept. 23–Oct. 23
	else if( ((monthOfBirth == 9) && (dayOfBirth >= 23 && dayOfBirth <= 30))  || 
		((monthOfBirth == 10) && (dayOfBirth >= 1 && dayOfBirth <= 23)) )
	{
		printf("A birthday of %i / %i has the zodiac Libra\n", monthOfBirth, dayOfBirth);
		printf("Libra is compatible with: Gemini, Libra, Aquarius\n");
	}
	// Oct. 24–Nov. 21
	else if( ((monthOfBirth == 10) && (dayOfBirth >= 24 && dayOfBirth <= 31))  || 
		((monthOfBirth == 11) && (dayOfBirth >= 1 && dayOfBirth <= 21)) )
	{
		printf("A birthday of %i / %i has the zodiac Scorpio\n", monthOfBirth, dayOfBirth);
		printf("Scropio is compatible with: Cancer, Scorpio, Pisces\n");
	}
	//Nov. 22–Dec. 21
	else if( ((monthOfBirth == 11) && (dayOfBirth >= 22 && dayOfBirth <= 30))  || 
		((monthOfBirth == 12) && (dayOfBirth >= 1 && dayOfBirth <= 21)) )
	{
		printf("A birthday of %i / %i has the zodiac Sagittarius\n", monthOfBirth, dayOfBirth);
		printf("Sagittarius is compatible with: Aries, Leo, Sagittarius\n");
	}
	//Dec. 22–Jan. 19
	else if( ((monthOfBirth == 12) && (dayOfBirth >= 22 && dayOfBirth <= 31))  || 
		((monthOfBirth == 1) && (dayOfBirth >= 1 && dayOfBirth <= 19)) )
	{
		printf("A birthday of %i / %i has the zodiac Capricorn\n", monthOfBirth, dayOfBirth);
		printf("Capricorn is compatible with: Taurus, Virgo, Capricorn\n");
	}
	//Jan. 20–Feb. 18
	else if( ((monthOfBirth == 1) && (dayOfBirth >= 20 && dayOfBirth <= 31))  || 
		((monthOfBirth == 02) && (dayOfBirth >= 1 && dayOfBirth <= 18)) )
	{
		printf("A birthday of %i / %i has the zodiac Aquarius\n", monthOfBirth, dayOfBirth);
		printf("Aquarius is compatible with: Gemini, Libra, Aquarius\n");
	}
	//Feb. 19–Mar. 20
	else if( ((monthOfBirth == 2) && (dayOfBirth >= 19 && dayOfBirth <= 29))  || 
		((monthOfBirth == 9) && (dayOfBirth >= 1 && dayOfBirth <= 22)) )
	{
		printf("A birthday of %i / %i has the zodiac Pisces\n", monthOfBirth, dayOfBirth);
		printf("Pisces is compatible with: Cancer, Scorpio, Pisces\n");
	}
	else
	{
		printf("INVALID INPUT\n");
	}

	return 0;
}

/*
The program's output:Please enter month of birth: 06
Please enter day of birth: 23
A birthday of 6 / 23 has the zodiac Cancer
Cancer is compatible with: Cancer, Scorpio, Pisces
*/
