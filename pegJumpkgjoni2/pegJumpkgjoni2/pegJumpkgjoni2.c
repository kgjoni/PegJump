/* -----------------------------------------------------------------------------------------------------------------------
* pegJumpkgjoni2.c
*
* Class: Program #2 for CS 141, Spring 2017.  Tues 11am lab.
* System: Windows 7
* Author: Kristi Gjoni
* ------------------------------------------------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//-------------------------------------------------------------------------------------------------------------------------
// Display ID info
void displayIdInfo()
{
	printf("\n");
	printf("Author: Kristi Gjoni    \n");
	printf("Program #2: Peg Jump   \n");
	printf("TA: Moumita Samanta, Tuesday 11 AM     \n");
	printf("February 8, 2017 ");
	printf("\n");
}//end displayIDInfo()

 //------------------------------------------------------------------------------------------------------------------------
 // Display Instructions
void displayInstructions()
{
	printf("\n");
	printf("This program represents the peg jumping puzzle.\n");
	printf("\n");
	printf("The board starts out with a single blank position, represented by\n");
	printf("the 'O'.  To make a move, select the letter of the peg to be moved,\n");
	printf("then the letter of the destination position. (e.g. the first move\n");
	printf("might be: d a, meaning we move peg ‘d’ into blank position ‘a’.)\n");
	printf("A peg must be able to jump over an adjacent peg into a blank for a\n");
	printf("move to be valid.  The jumped peg is then removed from the board.\n");
	printf("The game is over when there are no valid moves left to be made, or\n");
	printf("when there is a single peg left.\n");
	printf("\n");
	printf("At any point enter 'x' to exit the program.\n");
	printf("\n");
}//end displayInstructions()

//--------------------------------------------------------------------------------------------------------------------------
// Display board and positions
void displayBoard(char p1, char p2, char p3, char p4, char p5, char p6, char p7,
	char p8, char p9, char p10, char p11, char p12, char p13, char p14, char p15)
{
	printf("--------------------------\n");
	printf("  Board         Positions		\n");
	printf("    %c               A		\n", p1);
	printf("   %c %c		   B C      \n", p2, p3);
	printf("  %c %c %c		  D E F     \n", p4, p5, p6);
	printf(" %c %c %c %c	 G H I J    \n", p7, p8, p9, p10);
	printf("%c %c %c %c %c	K L M N O   \n", p11, p12, p13, p14, p15);
	printf("\n");
}// end displayBoard()

//-------------------------------------------------------------------------------------------------------------------------
// Move pegs according to the user input
void makeMove(char sourcePiece, char destinationPiece, 
	char *p1, char *p2, char *p3, char *p4, char *p5, char *p6, char *p7,
	char *p8, char *p9, char *p10, char *p11, char *p12, char *p13, char *p14, char *p15)
{
	// All possible moves for 'A' including the middle piece (jumped)
	if (sourcePiece == 'A' && destinationPiece == 'D') { *p1 = 'o'; *p2 = 'o'; *p4 = '+'; }
	else if (sourcePiece == 'A' && destinationPiece == 'F') { *p1 = 'o'; *p3 = 'o'; *p6 = '+'; }
	// All possible moves for 'B' including the middle piece (jumped)
	else if (sourcePiece == 'B' && destinationPiece == 'G') { *p2 = 'o'; *p4 = 'o'; *p7 = '+'; }
	else if (sourcePiece == 'B' && destinationPiece == 'I') { *p2 = 'o'; *p5 = 'o'; *p9 = '+'; }
	// All possible moves for 'C' including the middle piece (jumped)
	else if (sourcePiece == 'C' && destinationPiece == 'H') { *p3 = 'o'; *p5 = 'o'; *p8 = '+'; }
	else if (sourcePiece == 'C' && destinationPiece == 'J') { *p3 = 'o'; *p6 = 'o'; *p10 = '+'; }
	// All possible moves for 'D' including the middle piece (jumped)
	else if (sourcePiece == 'D' && destinationPiece == 'A') { *p4 = 'o'; *p2 = 'o'; *p1 = '+'; }
	else if (sourcePiece == 'D' && destinationPiece == 'F') { *p4 = 'o'; *p5 = 'o'; *p6 = '+'; }
	else if (sourcePiece == 'D' && destinationPiece == 'K') { *p4 = 'o'; *p7 = 'o'; *p11 = '+'; }
	else if (sourcePiece == 'D' && destinationPiece == 'M') { *p4 = 'o'; *p8 = 'o'; *p13 = '+'; }
	// All possible moves for 'E' including the middle piece (jumped)
	else if (sourcePiece == 'E' && destinationPiece == 'L') { *p5 = 'o'; *p8 = 'o'; *p12 = '+'; }
	else if (sourcePiece == 'E' && destinationPiece == 'N') { *p5 = 'o'; *p9 = 'o'; *p14 = '+'; }
	// All possible moves for 'F' including the middle piece (jumped)
	else if (sourcePiece == 'F' && destinationPiece == 'A') { *p6 = 'o'; *p3 = 'o'; *p1 = '+'; }
	else if (sourcePiece == 'F' && destinationPiece == 'D') { *p6 = 'o'; *p5 = 'o'; *p4 = '+'; }
	else if (sourcePiece == 'F' && destinationPiece == 'M') { *p6 = 'o'; *p9 = 'o'; *p13 = '+'; }
	else if (sourcePiece == 'F' && destinationPiece == 'O') { *p6 = 'o'; *p10 = 'o'; *p15 = '+'; }
	// All possible moves for 'G' including the middle piece (jumped)
	else if (sourcePiece == 'G' && destinationPiece == 'B') { *p7 = 'o'; *p4 = 'o'; *p2 = '+'; }
	else if (sourcePiece == 'G' && destinationPiece == 'I') { *p7 = 'o'; *p8 = 'o'; *p9 = '+'; }
	// All possible moves for 'H' including the middle piece (jumped)
	else if (sourcePiece == 'H' && destinationPiece == 'C') { *p8 = 'o'; *p5 = 'o'; *p3 = '+'; }
	else if (sourcePiece == 'H' && destinationPiece == 'J') { *p8 = 'o'; *p9 = 'o'; *p10 = '+'; }
	// All possible moves for 'I' including the middle piece (jumped)
	else if (sourcePiece == 'I' && destinationPiece == 'G') { *p9 = 'o'; *p8 = 'o'; *p7 = '+'; }
	else if (sourcePiece == 'I' && destinationPiece == 'B') { *p9 = 'o'; *p5 = 'o'; *p2 = '+'; }
	// All possible moves for 'J' including the middle piece (jumped)
	else if (sourcePiece == 'J' && destinationPiece == 'C') { *p10 = 'o'; *p6 = 'o'; *p3 = '+'; }
	else if (sourcePiece == 'J' && destinationPiece == 'H') { *p10 = 'o'; *p9 = 'o'; *p8 = '+'; }
	// All possible moves for 'K' including the middle piece (jumped)
	else if (sourcePiece == 'K' && destinationPiece == 'D') { *p11 = 'o'; *p7 = 'o'; *p4 = '+'; }
	else if (sourcePiece == 'K' && destinationPiece == 'M') { *p11 = 'o'; *p12 = 'o'; *p13 = '+'; }
	// All possible moves for 'L' including the middle piece (jumped)
	else if (sourcePiece == 'L' && destinationPiece == 'E') { *p12 = 'o'; *p8 = 'o'; *p5 = '+'; }
	else if (sourcePiece == 'L' && destinationPiece == 'N') { *p12 = 'o'; *p13 = 'o'; *p14 = '+'; }
	// All possible moves for 'M' including the middle piece (jumped)
	else if (sourcePiece == 'M' && destinationPiece == 'D') { *p13 = 'o'; *p8 = 'o'; *p4 = '+'; }
	else if (sourcePiece == 'M' && destinationPiece == 'F') { *p13 = 'o'; *p9 = 'o'; *p6 = '+'; }
	else if (sourcePiece == 'M' && destinationPiece == 'K') { *p13 = 'o'; *p12 = 'o'; *p11 = '+'; }
	else if (sourcePiece == 'M' && destinationPiece == 'O') { *p13 = 'o'; *p14 = 'o'; *p15 = '+'; }
	// All possible moves for 'N' including the middle piece (jumped)
	else if (sourcePiece == 'N' && destinationPiece == 'E') { *p14 = 'o'; *p9 = 'o'; *p5 = '+'; }
	else if (sourcePiece == 'N' && destinationPiece == 'L') { *p14 = 'o'; *p13 = 'o'; *p12 = '+'; }
	// All possible moves for 'O' including the middle piece (jumped)
	else if (sourcePiece == 'O' && destinationPiece == 'F') { *p15 = 'o'; *p10 = 'o'; *p6 = '+'; }
	else if (sourcePiece == 'O' && destinationPiece == 'M') { *p15 = 'o'; *p14 = 'o'; *p13 = '+'; }
}// end of makeMove()

//-------------------------------------------------------------------------------------------------------------------------
// beginnig of main()
int main() 
{
	displayIdInfo();																	// Display ID info
	displayInstructions();																// Display game instructions

	// Declare and initialize the board pieces
	char p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15;				// The board pieces
	p1 = 'o';																			// Initial piece values
	p2 = p3 = p4 = p5 = p6 = p7 = p8 = p9 = p10 = p11 = p12 = p13 = p14 = p15 = '+';	// Initial pieces values
	char sourcePiece = ' ';                                                             // Where we move from			
	char destinationPiece = ' ';														// Where we move to
	int remainingPiece = 14;															// Count remaining pieces														
																			
	displayBoard(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15);		// Display board at beginnig of game 

	while (remainingPiece > 1) 
	{
		printf("Enter your move: ");													// Ask user to enter moves
		scanf(" %c", &sourcePiece);														// Store first user input
		if (sourcePiece == 'x' || sourcePiece == 'X') {
			printf("* * * Exiting the program... * * *\n");
			break;																		// Exit program if user choice is 'x' or 'X'
		}
		scanf(" %c", &destinationPiece);												// Store second user input
		sourcePiece = toupper(sourcePiece);												// Convert to uppercase
		destinationPiece = toupper(destinationPiece);									// Convert to uppercase

		// Check for invalid moves (errors)
		while (1)
		{
			// Check for invalid detination
			if (destinationPiece > 'O' && destinationPiece <= 'Z') {					// Between O and Z
				printf("*** Invalid destination.  Please retry ****\n");
				break;
			}
			// Check for invalid source
			else if (sourcePiece > 'O' && sourcePiece <= 'Z') {							// Between O and Z
				printf("*** Invalid source.  Please retry ****\n");
				break;
			}
			// Check that middle piece cannot be empty for all possible combinations
			else if ((sourcePiece == 'A' && destinationPiece == 'D' && p2 == 'o') || (sourcePiece == 'A' && destinationPiece == 'F' && p3 == 'o') || 
				(sourcePiece == 'B' && destinationPiece == 'G' && p4 == 'o') || (sourcePiece == 'B' && destinationPiece == 'I' && p5 == 'o') || 
				(sourcePiece == 'C' && destinationPiece == 'H' && p5 == 'o') || (sourcePiece == 'C' && destinationPiece == 'J' && p6 == 'o') || 
				(sourcePiece == 'D' && destinationPiece == 'A' && p2 == 'o') || (sourcePiece == 'D' && destinationPiece == 'F' && p5 == 'o') || 
				(sourcePiece == 'D' && destinationPiece == 'K' && p7 == 'o') || (sourcePiece == 'D' && destinationPiece == 'M' && p8 == 'o') || 
				(sourcePiece == 'E' && destinationPiece == 'L' && p8 == 'o') || (sourcePiece == 'E' && destinationPiece == 'N' && p9 == 'o') ||
				(sourcePiece == 'F' && destinationPiece == 'A' && p3 == 'o') || (sourcePiece == 'F' && destinationPiece == 'D' && p5 == 'o') || 
				(sourcePiece == 'F' && destinationPiece == 'M' && p9 == 'o') || (sourcePiece == 'F' && destinationPiece == 'O' && p10 == 'o') || 
				(sourcePiece == 'G' && destinationPiece == 'B' && p4 == 'o') || (sourcePiece == 'G' && destinationPiece == 'I' && p8 == 'o') ||
				(sourcePiece == 'H' && destinationPiece == 'C' && p5 == 'o') || (sourcePiece == 'H' && destinationPiece == 'J' && p9 == 'o') || 
				(sourcePiece == 'I' && destinationPiece == 'G' && p8 == 'o') || (sourcePiece == 'I' && destinationPiece == 'B' && p5 == 'o') || 
				(sourcePiece == 'J' && destinationPiece == 'C' && p6 == 'o') || (sourcePiece == 'J' && destinationPiece == 'H' && p9 == 'o') ||
				(sourcePiece == 'K' && destinationPiece == 'D' && p7 == 'o') || (sourcePiece == 'K' && destinationPiece == 'M' && p12 == 'o') || 
				(sourcePiece == 'L' && destinationPiece == 'E' && p8 == 'o') || (sourcePiece == 'L' && destinationPiece == 'N' && p13 == 'o') ||
				(sourcePiece == 'M' && destinationPiece == 'D' && p8 == 'o') || (sourcePiece == 'M' && destinationPiece == 'F' && p9 == 'o') ||
				(sourcePiece == 'M' && destinationPiece == 'K' && p12 == 'o') || (sourcePiece == 'M' && destinationPiece == 'O' && p14 == 'o') || 
				(sourcePiece == 'N' && destinationPiece == 'E' && p9 == 'o') || (sourcePiece == 'N' && destinationPiece == 'L' && p13 == 'o') || 
				(sourcePiece == 'O' && destinationPiece == 'F' && p10 == 'o') || (sourcePiece == 'O' && destinationPiece == 'M' && p14 == 'o')) {
				printf("*** Must jump a piece.  Please retry. ***\n");
				break;
			}
			// Check source piece must contain a piece
			else if ((sourcePiece == 'A' && p1 == 'o') || (sourcePiece == 'B' && p2 == 'o') || (sourcePiece == 'C' && p3 == 'o') || 
				(sourcePiece == 'D' && p4 == 'o') || (sourcePiece == 'E' && p5 == 'o') || (sourcePiece == 'F' && p6 == 'o') || 
				(sourcePiece == 'G' && p7 == 'o') || (sourcePiece == 'H' && p8 == 'o') || (sourcePiece == 'I' && p9 == 'o') || 
				(sourcePiece == 'J' && p10 == 'o') || (sourcePiece == 'K' && p11 == 'o') || (sourcePiece == 'L' && p12 == 'o') ||
				(sourcePiece == 'M' && p13 == 'o') || (sourcePiece == 'N' && p14 == 'o') || (sourcePiece == 'O' && p15 == 'o')) {
				printf("*** Source must have a piece.  Please retry. ***\n");
				break;
			}
			// Check destination piece must be empty
			else if ((destinationPiece == 'A' && p1 == '+') || (destinationPiece == 'B' && p2 == '+') || (destinationPiece == 'C' && p3 == '+') ||
				(destinationPiece == 'D' && p4 == '+') || (destinationPiece == 'E' && p5 == '+') || (destinationPiece == 'F' && p6 == '+') ||
				(destinationPiece == 'G' && p7 == '+') || (destinationPiece == 'H' && p8 == '+') || (destinationPiece == 'I' && p9 == '+') ||
				(destinationPiece == 'J' && p10 == '+') || (destinationPiece == 'K' && p11 == '+') || (destinationPiece == 'L' && p12 == '+') ||
				(destinationPiece == 'M' && p13 == '+') || (destinationPiece == 'N' && p14 == '+') || (destinationPiece == 'O' && p15 == '+')) {
				printf("*** Destination must be empty.  Please retry. ***\n");
				break;
			}
			else {
				// Call function to move pegs
				makeMove(sourcePiece, destinationPiece, &p1, &p2, &p3, &p4, &p5, &p6, &p7, &p8, &p9, &p10, &p11, &p12, &p13, &p14, &p15);

				// Call function to display the board
				displayBoard(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15);

				remainingPiece = remainingPiece - 1;								// Decrease by 1 after each iteration

				break;
			}
		}
	}

	// Display final message to user
	printf("# left		Rating\n");
	printf("------		---------------\n");
	printf(" >4		Dufus\n");
	printf(" 4		Poor\n");
	printf(" 3		Mediocre\n");
	printf(" 2		Good Job\n");
	printf(" 1		Awesome Genius!\n");

	// More than 4 pieces left
	if (remainingPiece > 4) {
		printf("You had >4 left. Dufus\n");
		printf("Thanks for playing. Exiting...");
	}
	// 4 pieces left
	else if (remainingPiece == 4) {
		printf("You had 4 left. Poor\n");
		printf("Thanks for playing. Exiting...");
	}
	// 3 pieces left
	else if (remainingPiece == 3) {
		printf("You had 3 left. Mediocre\n");
		printf("Thanks for playing. Exiting...");
	}
	// 2 pieces left
	else if (remainingPiece == 2) {
		printf("You had 2 left. Glood Job\n");
		printf("Thanks for playing. Exiting...");
	}
	// 1 piece left
	else if (remainingPiece == 1) {
		printf("You had 1 left. Awesome Genius!\n");
		printf("Thanks for playing. Exiting...");
	}

	return 0;
}// end of main()