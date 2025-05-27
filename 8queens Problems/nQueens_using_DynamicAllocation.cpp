#include <iostream>
#include <cmath>  // for abs()
using namespace std;

// This function checks if the queen at column c is safe
bool ok(int q[], int c) {
	for (int i = 0; i < c; i++) {
		// check if they are in the same row or diagonal
		if (q[i] == q[c] || (c - i) == abs(q[c] - q[i]))
			return false;
	}
	return true;
}

// This function returns number of solutions to n-queens problem
int nqueens(int n) {
	int* q = new int[n];  // dynamically allocate a 1D array of size n
		              // using the "new" operator to request the heap to dynamically allocate the memory. 
	int c = 0;            // start at column 0
	q[0] = 0;             // place first queen in row 0
	int solutions = 0;    // counter to keep track of valid solutions

	// This condition will end the loop if it backtrack from the first column (Finding all solutions)
	while (c >= 0) {      // backtracking loop
		c++;              // move to next column
		if (c == n) {     // placed all queens
			solutions++;  // count this as a valid solution
			c--;          // backtrack
		} else {
			q[c] = -1;    // reset current column's row to before first row
		}

		// Try finding a valid row for the queen in the current column
		while (c >= 0) {
			q[c]++;       // try next row
			if (q[c] == n) {
				c--;      // tried all rows, backtrack
			} else if (ok(q, c)) {
				break;    // found a valid spot, go to next column
			}
		}
	}

	delete[] q;      // deallocate the memory. It deletes the array,q[] & allows to free up memory making it available for future use.
	return solutions;  // return the number of solution
}

// This is the main program that tests the nqueens function
int main() {
	int n;
	cout << "Enter a number n: ";
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		cout << i << ". There are " << nqueens(i)
			<< " solutions to the " << i << " queens problem." << endl;
	}

	return 0;
}

