#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>

#define WORDS 15
#define WORDLEN 40
#define MISS 6

int checkGameValue(int value);
int rockPaperScissor();
int hangman();
int TicTacToe();

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

int playAgain(){
	char command;
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

}

int checkGameValue(int value)
{
	char confirm[3];
	switch (value)
	{
	case 1:
		printf("You want to play Hangman right? (y/n) : ");
		scanf(" %s", confirm);
		(strcmp(confirm, "y") == 0) ? hangman() : main();
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

int rockPaperScissor()
{
	printf("\e[1;1H\e[2J"); // Clear screen terminal

	int numberRandom, result;
	char you, computer;

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
	playAgain();

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

bool srand_called = false;
// function random number
int num_rmd(int i) {
    if (!srand_called) {
        srand(time(NULL) << 15);
        srand_called = true;
    }
    return rand() % i;
}

//function print hungbody
void printhang(int mistakes, char* body) {
    printf("\tMistakes :%d\n", mistakes);
    switch(mistakes) {
        case 6: body[6] = '\\'; break;
        case 5: body[5] = '/'; break;
        case 4: body[4] = '\\'; break;
        case 3: body[3] = '|'; break;
        case 2: body[2] = '/'; break;
        case 1: body[1] = ')', body[0] = '('; break;
        default: break;
    }
    printf("\t _________\n"
       "\t|         |\n"
       "\t|        %c %c\n"
       "\t|        %c%c%c\n"
       "\t|        %c %c\n"
       "\t|             \n"
       "\t| ", body[0], body[1], body[2],
       body[3], body[4], body[5], body[6]);
}

// function print word
void printtext(char* player, int len) {
    printf("\t");
    for (int i = 0; i < len; ++i){
        printf("%c ", player[i]);
    }
    printf("\n\n");
}
 
int hangman() {
    printf("\n\t Make sure before you put word you can be hanged!!.");
    printf("\n\n\t Rules : ");
    printf("\n\t -> Up to 6 mistakes are allowed.");
    printf("\n\t -> All alphabet are in 'LOWER CASE'.");
    printf("\n\t -> All words are name of -- IT category --");
    printf("\n\t -> :) Enjoy your playing!! .");
    printf("\n\t Syntax : Alphabet");
    printf("\n\t Example : a \n\n");
    char text[WORDS][WORDLEN] = {"bandwidth", "appication", "buffer", "database", "directory", "domain", "harddisk", "firewall", "malware", "network",
	"cache", "encryption", "ethernet", "hardware", "software"};
    char *body = malloc(MISS+1);
    int id = num_rmd(WORDS);
    char *word = (text[id]);
    int len = strlen(word);
    char *guessed = malloc(len);
    char falseWord[MISS];
    memset(body, ' ', MISS+1);
    memset(guessed, '_', len);
    char player;
    bool found;
    char* win;
    int mistakes = 0;
    setvbuf(stdin, NULL, _IONBF, 0);
 
    do {
        found = false;
        printf("\n\n");
        printhang(mistakes, body);
        printf("\n\n");
        printf("\tFalse Letters : ");
        if(mistakes == 0) printf("None\n");
        for (int i = 0; i < mistakes; ++i){
            printf("%c ", falseWord[i]);
        }
        printf("\n\n");
        printtext(guessed, len);
        printf("\tGive me a alphabet in lower case : ");
        do {
            scanf("%c",&player);
        } 
        while ( getchar() != '\n' );
        for (int i = 0; i < len; ++i){
            if(word[i] == player) {
                found = true;
                guessed[i] = player;
            }
        }
        if(!found) {
            falseWord[mistakes] = player;
            mistakes += 1;
        }
        win = strchr(guessed, '_');
    }

    while(mistakes < MISS && win != NULL);
    if(win == NULL){
        printf("\n");
        printtext(guessed, len);
        printf("\n\tCongrats! You have won : %s\n\n", word);
    }
    else {
        printf("\n");
        printhang(mistakes, body);
        printf("FAIL!! ;-;");
        printf("\n\n\tBetter try next time. Word was --> %s\n\n", word);
    }
    free(body);
    free(word);
    free(guessed);
    return EXIT_SUCCESS;
}
