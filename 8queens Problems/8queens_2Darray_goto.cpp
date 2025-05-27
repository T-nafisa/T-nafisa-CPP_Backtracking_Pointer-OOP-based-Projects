#include <iostream>
using namespace std;

int main() {
	int numSolutions = 0; // Initialize the number of solutions
	int b[8][8] = {0};  // Initialize the board to 0 (no queens placed)
	int c = 0, r;       // Start in the 1st column
	b[0][0] = 1;        // Place the 1st queen at the top-left corner

nextCol:
	// Move to the next column
	c++;
	// If you passed the last column (placed all 8 queens)
	if (c == 8) goto print;
	// Otherwise, start at the TOP of the new column

	// Initialize row to -1 so that the nextRow step begin at row 0
	r = -1;

nextRow:
	// Move to the next row
	r++;
	// If all rows are checked in this column and no safe spot is found, need to do backtracking
	if (r == 8) goto backtrack;

	// (i) row test
	// Check every square to the left of the current square in the same row
	for (int i = 0; i < c; i++) 
		// If there is a queen on that square in the same row, go to next row
		if (b[r][i] == 1) goto nextRow;

	// (ii) upper-left diagonal test
	// Check the upper-left diagonal for any queens
	// End the loop when you are above or left of the chessboard
	for (int i = 1; (c - i) >= 0 && (r - i) >= 0; i++) 
		// If there is a queen i spots above and left of the current square
		if (b[r - i][c - i] == 1) goto nextRow;

	// (iii) lower-left diagonal test
	// Check the lower-left diagonal for any queens
	// End the loop when you are below or left of the chessboard
	for (int i = 1; (c - i) >= 0 && (r + i) < 8; i++) 
		// If there is a queen i spots below and left of the current square
		if (b[r + i][c - i] == 1) goto nextRow;

	// Assign this current position to a queen
	b[r][c] = 1;
	// Move to the next column to continue placing more queens
	goto nextCol;

backtrack:
	// Move to the previous column to try other possibilities
	c--;
	// If you have moved to the left of the chessboard (no more solutions to explore)
	if (c == -1) return 0;  // Exit the program

	// Find the square in the column with a queen in it
	r = 0;
	while (b[r][c] != 1) r++;  // Find the row with the queen
	// Remove the queen from the current square
	b[r][c] = 0;
	// Try the next row in the same column
	goto nextRow;

print:
	// Print the current solution when all 8 queens are placed
	// Increment numSolutions first(cause initialiezed to 0) and then print the solution number
	cout << "Solution #" << ++numSolutions << ":\n";

	// Use a nested loop to print the chessboard
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cout << b[i][j] << " ";  // Print each cell (0 or 1)
		}
		cout << endl;  // Print a new line for the next row
	}
	cout << endl;  // Add a space between solutions

	// After printing the solution, continue searching for other solutions
	goto backtrack;
}

