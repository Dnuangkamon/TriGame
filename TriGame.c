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
		printf("You want to play Tic Tac Toe right? (y/n) : ");
		scanf(" %s", confirm);
		(strcmp(confirm, "y") == 0) ? TicTacToe() : main();
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

int TicTacToe() {
	char board[3][3], player, computer, winner, playAgain, command;
	int row, column, spaces;

	printf("\e[1;1H\e[2J"); // Clear screen terminal

	// player choose side
	printf("Which side do you want to play? (X/O): ");
	scanf(" %c", &player);
	player = toupper(player);
	if (player == 'X') {
		computer = 'O';
	}
	else {
		computer = 'X';
	}

	do {
		// reset board
		for(int i=0; i<3; i++) {
	    	for(int j=0; j<3; j++) {
	        	board[i][j] = ' ';
	    	}
		}
		winner = ' ';
		playAgain = ' ';

		while(winner == ' ' && spaces != 0) {
			// check board spaces
			spaces = 9;
			for(int i = 0; i < 3; i++) {
		    	for(int j = 0; j < 3; j++) {
		        	if(board[i][j] != ' ') {
		        		spaces -= 1;
		        	}
		    	}
			}

			// print board
        	printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
			printf("\n---|---|---\n");
			printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
			printf("\n---|---|---\n");
			printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
			printf("\n");

        	// player move
        	while(1) {
				printf("Enter row #(1-3): ");
				scanf("%d", &row);
				row -= 1;

				printf("Enter column #(1-3): ");
				scanf("%d", &column);
				column -= 1;

				if(board[row][column] != ' ') {
					printf("ERROR : Invalid move ; Please try again.\n");
				}
				else {
					board[row][column] = player;
					break;
				}
			}

			// check winner on board
        	for(int i=0; i<3; i++) {
				if((board[i][0] == board[i][1]) && (board[i][0] == board[i][2])) {
		        	winner = board[i][0];
		    	}
		    	else if((board[0][i] == board[1][i]) && (board[0][i] == board[2][i])) {
		        	winner = board[0][i];
		    	}
		    	else if(((board[0][0] == board[1][1]) && (board[0][0] == board[2][2])) || ((board[0][2] == board[1][1]) && (board[0][2] == board[2][0]))) {
			    	winner = board[1][1];
				}
			}
        	if(winner != ' ' || spaces == 0) {
        		break;
    		}

			// computer move
			srand(time(0));
			if(spaces > 0) {
		    	while(1) {
		        	row = rand() % 3;
		        	column = rand() % 3;
		        	if (board[row][column] == ' ') {
		        		board[row][column] = computer;
		        		break;
					}
				}
			}

			// check winner on board
        	for(int i=0; i<3; i++) {
				if((board[i][0] == board[i][1]) && (board[i][0] == board[i][2])) {
		        	winner = board[i][0];
		    	}
		    	else if((board[0][i] == board[1][i]) && (board[0][i] == board[2][i])) {
		        	winner = board[0][i];
		    	}
		    	else if(((board[0][0] == board[1][1]) && (board[0][0] == board[2][2])) || ((board[0][2] == board[1][1]) && (board[0][2] == board[2][0]))) {
			    	winner = board[1][1];
				}
			}
			if(winner != ' ' || spaces == 0) {
        		break;
        	}
    	}

		// print final board
		printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
		printf("\n---|---|---\n");
		printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
		printf("\n---|---|---\n");
		printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
		printf("\n");

		if(winner == player) {
			printf("Congratulations! You win!");
		}
		else if(winner == computer) {
    		printf("Game over! Computer win!");
		}
		else {
			printf("Neck and neck! Game draw!");
		}

		do  {
			printf("\nWould you like to play this game again? (Y/N): ");
			scanf(" %c", &playAgain);
			playAgain = toupper(playAgain);
			if (playAgain != 'N' && playAgain != 'Y') {
				printf("Error : Invalid command ; Please try again.\n");
			}
		} while (playAgain != 'N' && playAgain != 'Y');
	} while (playAgain == 'Y');

	main();
}
