#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int checkGameValue(int value);
int rockPaperScissor();
int hangMan();
int ticTacToe();

int main()
{
	int selectedGameValue;
	printf("\e[1;1H\e[2J"); // Clear screen terminal
	printf("===== Welcome To TriGame Project =====\n");
	printf("\nChoose gameyou want to play from below.\n");
	printf("1. Hangman\n");
	printf("2. Tic Tac Toe\n");
	printf("3. Rock Paper Scissor\n");

	printf("\nYour answer (Integer ex. 1): ");
	scanf(" %d", &selectedGameValue);
	checkGameValue(selectedGameValue);
}

int checkGameValue(int value)
{
	char confirm[3];
	switch (value)
	{
	case 1:
		printf("You want to play Hangman right? (y/n) : ");
		scanf(" %s", confirm);
		(strcmp(confirm, "y") == 0) ? hangMan() : main();
		break;

	case 2:
		printf("You want to play Tic Tic Toe right? (y/n) : ");
		scanf(" %s", confirm);
		(strcmp(confirm, "y") == 0) ? ticTacToe() : main();
		break;

	case 3:
		printf("You want to play Rock Paper Scissor right? (y/n) : ");
		scanf(" %s", confirm);
		(strcmp(confirm, "y") == 0) ? rockPaperScissor() : main();
		break;

	default:
		main();
	}
}

int hangMan()
{
	printf("\e[1;1H\e[2J"); // Clear screen terminal
}

int ticTacToe()
{
	printf("\e[1;1H\e[2J"); // Clear screen terminal
}

int rockPaperScissor()
{
	printf("\e[1;1H\e[2J"); // Clear screen terminal

	int numberRandom, result;
	char you, computer, command;

	srand(time(NULL));
	numberRandom = rand() % 100;
	if (numberRandom < 33)
		computer = 'r';
	else if (numberRandom > 33 && numberRandom < 66)
		computer = 'p';
	else
		computer = 's';

	printf("Enter r for Rock, p for Paper and s for Scissor : ");
	scanf(" %c", &you);

	if (you == computer)
		result = -1;
	if (you == 'r' && computer == 'p')
		result = 0;
	else if (you == 'p' && computer == 'r')
		result = 1;
	if (you == 'r' && computer == 's')
		result = 1;
	else if (you == 's' && computer == 'r')
		result = 0;
	if (you == 'p' && computer == 's')
		result = 0;
	else if (you == 's' && computer == 'p')
		result = 1;

	printf("== Result =====================\n\n");
	if (result == -1)
	{
		printf("Game Draw!\n\n");
	}
	else if (result == 1)
	{
		printf("Wow! You have won the game!\n\n");
	}
	else
	{
		printf("Oh! You have lost the game!\n\n");
	}
	printf("-----------------------------\n");
	printf("You choose : %c\n", you);
	printf("Computer choose : %c\n", computer);
	printf("-----------------------------\n");
	printf("Play Again press 'a' button.\n");
	printf("Select Game press 's' button.\n");
	scanf(" %c", &command);
	if (command == 'a')
	{
		rockPaperScissor();
	}
	else if (command == 's')
	{
		main();
	}

	return 0;
}
