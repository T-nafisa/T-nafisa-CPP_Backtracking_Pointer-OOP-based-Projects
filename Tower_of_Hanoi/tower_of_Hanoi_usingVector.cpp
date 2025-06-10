#include <iostream>
#include <vector>
using namespace std;

int main() {
	// Create 3 towers using an array of vectors. Each tower will store rings.
	vector<int> t[3];  // t[0] for Tower A, t[1] for Tower B, t[2] for Tower C

	int n;
	cout << "Please enter the total number of rings you want to move: ";
	cin >> n; 
	cout << endl;

	// Need to decide which towers will be priority to make as "to" towers
	// This decision depends on whether the number of rings,n, is even or odd.
	int firstPriority=0, secondPriority=0;

	// If n is even, we will move the rings counter-clockwise
	if (n % 2 == 0){  
		firstPriority = 2;  // So, TowerC (index 2) will be 1st priority
		secondPriority = 1; // TowerB (index 1) 2nd priority
	}
	else {   // If n is odd, move the rings clockwise
		firstPriority = 1;  // TowerB (index 1) will be 1st priority,
		secondPriority = 2; // TowerC (index 2) 2nd priority.
	}

	// Initialize the 'from' tower, 'to' tower, candidate ring, and move counter
	int from = 0;            // start with Tower A (t[0]) as the starting point
	int to = firstPriority; // First move will be to the tower we decided based on priority (either B or C)
	int candidate = 1;     // The smallest ring (ring 1) will always be the first one to move
	int move = 0;         // This will count how many moves we make

	// Initialize the towers with the rings. 
	for (int i = n + 1; i >= 1; --i)
		t[0].push_back(i);  // Place all rings into Tower A (t[0])

	// Add a padding ring to Tower B (t[1]) & Tower C (t[2]) to help with the movement logic. 
	t[1].push_back(n + 1); 
	t[2].push_back(n + 1);  

	// Keep moving the rings until all rings are in Tower B (towers[1]) meaning the solution is found
	while (t[1].size() < n + 1) {
		cout << "Move #" << ++move << ": Transfer ring " << candidate
			<< " from tower " << char(from + 'A') << " to tower " << char(to + 'A') << "\n"; 
		//char (0 + 'A') prints "A", char (1 + 'A') prints "B."
		//This was used here to represent the 3 towers as tower "A", "B" and "C." 

		// Move the candidate ring from the 'from' tower to the 'to' tower
		t[to].push_back(t[from].back()); // Move the top ring from the 'from' tower to the 'to' tower
		t[from].pop_back();     // Remove that ring from the 'from' tower after moving it

		// Now decide which tower will be the next 'from' tower.
		// It will be the tower with the smallest ring that has not yet been moved.
		if (t[(to + 1) % 3].back() < t[(to + 2) % 3].back()) {
			from = (to + 1) % 3; 
		} else {
			from = (to + 2) % 3; 
		}

		// The next candidate ring will be the smallest ring on top of the 'from' tower.
		candidate = t[from].back();

		// Now, we need to figure out where the candidate ring should move.
		// first check if the 'to' tower with the 1st priority can take the candidate ring.
		if (t[(from + firstPriority) % 3].back() > candidate) {
			to = (from + firstPriority) % 3; // Then move the ring there
		} else {
			to = (from + secondPriority) % 3; //  move the ring to 2nd priority tower
		}
	}

	return 0; 
}

