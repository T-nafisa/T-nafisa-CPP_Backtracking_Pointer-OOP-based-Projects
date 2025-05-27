#include <iostream>
using namespace std;

// Function to check if placing a queen in column c is valid
bool ok(int q[], int c) {
	for (int i = 0; i < c; i++) {
		// Checks if any other queen is in the same row or up/down diagonal 
		if (q[i] == q[c] || (c - i) == abs(q[c] - q[i]))  
			// If any conflict found, it will return false value
			return false; 
	}
	// If no conflicts, then queens positions are valid and return true 
	return true; 
}

// Function to print the solutions in 2D chessboard format
void print(int q[]){
	static int SolCounter = 0;  // Keeps counting the number of solutions
	// Increment numSolutions first(cause initialized to 0) and then print the solution number
	cout << "Solution #" << ++SolCounter << endl; 

	// Use a nested loop to print the chessboard
	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++) {
			// If a queen is in this position, print "1"
			if (q[j] == i) 
				cout << "1 ";
			// Otherwise, print "0".
			else  
				cout << "0 "; 
		}
		cout << endl;  // Move to the next row.
	}
	cout << endl;
}


int main() {
	int q[8] = {}; // Initialize the chessboard array to 0 
	int c = 0;  // Start on the first column
	q[c] = 0;  // Place the first queen at row 0, column 0

	// This condition will end the loop if it backtrack from the first column
	while (c >= 0) { 
		c++;  // Move to the next column.

		// If we've placed a queen in all 8 columns, we found a solution
		if (c == 8) {
			print(q);  // Print the solution
			c--;  // Backtrack to find more solutions
		}

		// Otherwise, move to one before the first row of the next column
		// Reset the current column's row to -1
		else {              
			q[c] = -1; 
		}

		// Try finding a valid row for the queen in the current column
		while (c >= 0) {
			q[c]++;  // Move to the next row.

			// If we have passed the last row, backtrack
			if (q[c] == 8) {
				c--;  
			}
			// Else, if the current position is valid, break
			// Exit the inner loop (go back to the beginning of the outer loop) to continue placing the next queen
			else if (ok(q, c)) {
				break;  
			}
		}
	}

	return 0; 
}

