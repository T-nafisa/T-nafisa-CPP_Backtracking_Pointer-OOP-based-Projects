#include <iostream>
using namespace std;

// Function to check if the current placement of queens is valid
// It will take the 1D array to test
bool ok(int q[]) {
	// Start from the last column and keep checking backwards
	for (int col = 7; col > 0; col--) {  
		// Compare the current queen with all previous ones
		for (int i = 0; i < col; i++) { 
			// check if there is any queen in the same row OR up/ down diagonal
			if (q[i] == q[col] || abs(q[col] - q[i]) == (col - i)) 
				// If it detect any queen, it will return false value
				return false;  
		}             
	}
	// If no conflicts found, then queens positions are valid and will return true.
	return true;  
}


// Function to print the solutions in 2D chessboard format
void printSolution(int q[8], int solutionCount) {  
	cout << "Solution #" << solutionCount << ":\n";
	// Print the 2D chessboard representation
	for (int row = 0; row < 8; row++) {  // Go through each row
		for (int col = 0; col < 8; col++) {  // Go through each column
			// If the queen is in this row for this column, print 1 (placed Queen)
			// otherwise print 0
			if (q[col] == row) {  
				cout << "1 "; 
			} else {
				cout << "0 ";  
			}
		}
		cout << endl; // next row

	}
	cout << endl;
}


int main() {
	int q[8] = {0};  // 1D array to store queen positions
	int solutionCount = 0;  // Initialize the number of valid solutions 

	// Brute-force approach- Try all possible configuration of 8 queens
	for (int i0 = 0; i0 < 8; i0++) {
		for (int i1 = 0; i1 < 8; i1++) {
			for (int i2 = 0; i2 < 8; i2++) {
				for (int i3 = 0; i3 < 8; i3++) {
					for (int i4 = 0; i4 < 8; i4++) {
						for (int i5 = 0; i5 < 8; i5++) {
							for (int i6 = 0; i6 < 8; i6++) {
								for (int i7 = 0; i7 < 8; i7++){
									// Assign the queens to each column
									// The outer most for loop,i0 represents left most array element 
									// and the inner most for loop,i7 represents the right most array element 
									q[0] = i0;
									q[1] = i1;
									q[2] = i2;
									q[3] = i3;
									q[4] = i4;
									q[5] = i5;
									q[6] = i6;
									q[7] = i7;

									// Check if the placement is valid
									if (ok(q)) {  
										// If the ok function returns true, print the output of the chessboard
										printSolution(q, ++solutionCount);  // increment count of solutions
									}
								}
							}
						}
					}
				}
			}
		}
	}

	return 0;  // End program
}



