#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int DEBUG_COMPAREGREATER(int value1, int value2)
{
	return value1 > value2;
}

int DEBUG_COMPARELESSER(int value1, int value2)
{
	return value1 < value2;
}

int randRange(int min, int max)
{
	return rand() % (max + 1 - min) + min;
}

void numberFinderBot(int numberChoosen)
{
	int max = 32767, min = 0, picked;
	
	int seed = (int)time(0) + 615;
	
	srand(seed);
	
	while (1)
	{
		picked = randRange(min, max);
		
		//printf("DEBUG : %d\n", picked);
		
		if (picked == numberChoosen)
		{
			printf("Found The Number. It's : %d.\n", picked);
			
			break;
		}
		
		if (picked > numberChoosen)
		{
			printf("The number %d that i picked was higher than the number choosen. Trying a lower number.\n", picked);
			max = picked;
		}
		
		if (picked < numberChoosen)
		{
			printf("The number %d that i picked was lower than the number choosen. Trying a higher number.\n", picked);
			min = picked;
		}
	}
}

int main()
{
	printf("=======================================================\n");
	printf("		Number Guessing Game\n");
	printf("=======================================================\n");
	printf("\n");

	srand((int)time(0));

	int randomNumber = rand() % 200;
	int inputNumber;
	int guessCount;

	printf("The number had been choosen. Try to pick a number.\n");

	//cout << "DEBUG : " << randomNumber << endl;
	
	/*
	This function was made just for fun. 
	The function mainly made of two parts. The guesser and the checker.
	The value passed to the function passed to the checker, and the guesser tries to guess the number.
	Of course the number to guess isn't given to the guesser directly. The guesser needs to ask the checker. 
	The checker will never give the actual number, rather it gives the answer yes, higher, or lower.
	The Guesser first tries to guess the number randomly through the maximum and minimux the randomizer function capable of.
	Then the Guesser will adjust the minimum or maximum range depending the answer from The Checker.
	After that, the guesser will keep guessing, adjusting, guessing, adjusting until the Checker says yes.
	*/
	//numberFinderBot(randomNumber);

	while (1)
	{
		scanf("%d", &inputNumber);

		//cout << "DEBUG : " << inputNumber << endl;

		//cout << "DEBUG : " << DEBUG_COMPAREGREATER(inputNumber, randomNumber) << endl;
		//cout << "DEBUG : " << DEBUG_COMPARELESSER(inputNumber, randomNumber) << endl;

		if (inputNumber == randomNumber)
		{
			printf("Yay! You've picked the right one!. You've guessed the number in %d guess.\n", guessCount);

			break;
		}

		if (inputNumber < randomNumber)
		{
			printf("The number you picked was lower than the number choosen. Try a higher number.\n");
			guessCount++;
		}

		if (inputNumber > randomNumber)
		{
			printf("The number you picked was higher than the number choosen. Try a lower number.\n");
			guessCount++;
		}
	}
	
	
	_getch();

}
