
 /**
 * Created CS50 Week1.
 * Problem Set 3
 * fifteen.c
 * User: Evgeniy Ryzhyk
 * Date: 07.09.2016
 */
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX]; 

// dimensions
int d;  

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);

int main(int argc, string argv[])
{
    if (argc != 2) {         // ensure proper usage
        printf("Usage: fifteen d\n");
        return 1;
    }
    d = atoi(argv[1]);       // ensure valid dimensions
    if (d < DIM_MIN || d > DIM_MAX) {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }
    FILE *file = fopen("log.txt", "w"); // open log
    if (file == NULL) {
        return 3;
    }
    greet();        // greet user with instructions
    init();      
    while (true) {   
        clear();     
        draw();  // draw the current state of the board
        for (int i = 0; i < d; i++) {  // log the current state of the board (for testing)
            for (int j = 0; j < d; j++) {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1) {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);
        if (won()) {          
        
            printf("ftw!\n");
            break;
        }
        printf("Tile to move: ");      // prompt for move
        int tile = get_int();
        if (tile == 0)  {      // quit if user inputs 0 (for testing)
            break;
        }
        fprintf(file, "%i\n", tile);     // log move (for testing)
        fflush(file);
        if (!move(tile)) {   // move if possible, else report illegality
            printf("\nIllegal move.\n");
            usleep(500000);
        }
        usleep(500000);   // sleep thread for animation's sake
    }
    fclose(file);    // close log
    return 0;        // success
}

void clear(void)  {      // Clears screen using ANSI escape sequences.
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

void greet(void) {     //Greets player.
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}
 // Initializes the game's board with tiles numbered 1 through d*d - 1
  
void init(void) {
    int value = (d * d) - 1;  
    for (int i = 0; i < d; i++)         
        for (int j = 0; j < d; j++)
            board[i][j] = value--;
    board[d-1][d-1] = 0; //print 0 for empty tile
    if ( d == 4 ) {   //swap tiles if value is even
        int tmp = board[d-1][d-2];
        board[d-1][d-2] = board[d-1][d-3];
        board[d-1][d-3] = tmp;
    }  
}

void draw(void) {   //Prints the board in its current state.
    for (int i = 0; i < d; i++)  {    // iterate over board
        for (int j = 0; j < d; j++) {
            if (board[i][j] == 0) {  // print 0 for blank 
                printf(" 0 ");
            }
            else {    // otherwise print its value
                printf("%2d ", board[i][j]);
            }
        }
    printf("\n");    
    }
}

bool move(int tile) { 
   for(int i = 0; i < d; i++)
		for(int j = 0; j < d; j++) // going over the entire board
			if(board[i][j] == tile) { //if tile is near an empty tile == 0 it can swap with this tile
				if((i + 1 < d) && (board[i + 1][j] == 0)) {  //  // vertical movement downwards
					board[i + 1][j] = board[i][j];
					board[i][j] = 0;
					return true;
				}
				else if((i - 1 >= 0) && (board[i - 1][j] == 0)) { // vertical movement to the upwards
					board[i - 1][j] = board[i][j];
					board[i][j] = 0;
					return true;
				}
				else if((j + 1 < d) && (board[i][j + 1] == 0)) { // horizontal movement to the right
					board[i][j + 1] = board[i][j];
					board[i][j] = 0;
					return true;
				}
				else if((j - 1 >= 0) && (board[i][j - 1] == 0)) { // horizontal movement to the left
					board[i][j - 1] = board[i][j];
					board[i][j] = 0;
					return true;
				}
			}
    return false;

}

bool won(void) { // Returns true if game is ended
    int position = 1; // position counter
    for (int i = 0; i < d; i++) //iterating the entire board
        for (int j = 0; j < d; j++) 
            if (board[i][j] == position) { // make sure that tile matches to it right position
                position++;
                if (position == d*d && board[d-1][d-1] == 0) // make sure that the last position is blank or "0"
                    return true;
            }
    return false;
}
