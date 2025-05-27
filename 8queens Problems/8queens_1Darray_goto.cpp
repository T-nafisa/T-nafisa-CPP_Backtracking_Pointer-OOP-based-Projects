#include <iostream>
#include <cmath>  // Need for absolute value using abs ()
using namespace std;

int main() {
	int numSolutions=0; //Initialize the number of solutions 
	int q[8]; // q[] stores queen positions
	int c=0; // Start in 1st column
	q[0]= 0; // place the first queen at 1st column's left-most corner

nextCol:
	// Move to the next column
	c++;
	// If passed the last column (placed all 8 queens)
	if(c==8) goto print;

	// q[c] represents row
	// Initialize row to -1 so that the nextRow step begin at row 0
	q[c]=-1;

nextRow:
	// Move to next row in this column
	q[c]++;
	// If all rows are checked in this column and no safe place is found, do backtracking
	if(q[c]==8) goto backtrack;

	// Test for safe position
	// Check each column to the left of the current column
	for(int i=0; i<c; i++)
		// (i) Row test: Check if another queen is in the same row	
		// (ii) Diagonal test: Check if another queen is on the same diagonal
		if(q[i]==q[c] || (c-i)==abs(q[c]-q[i]) ) goto nextRow;

	// Move to next column to continue placing more queens
	goto nextCol;

backtrack:
	// Move to the previous column to try other possibilities
	c--;
	// If you have moved to the left of the chessboard (no more solutions to explore)
	if(c==-1) return 0; // Exit the program
	// Try the next row in the same column
	goto nextRow;

print:
	// Print the current solution when all 8 queens are placed
	// Increment numSolutions first(cause initialized to 0) and then print the solution number
	numSolutions++;
	cout<< "Solution #" << numSolutions << ": " << endl;

	// Use a nested loop to print the chessboard
	for (int i=0; i <8; i++){  // Loop through each columns
		for(int j=0; j<8; j++){ // Loop through each rows
			// If the queen is in this row for this column, print 1
			// otherwise print 0
			if(q[i]==j) cout<< 1;
			else cout << 0;
		}
		cout<< endl; // Print a new line for the next row

	}
	cout<< endl; // Add a space between solutions

	// After printing the solution, continue searching for other solutions
	goto backtrack;
}
