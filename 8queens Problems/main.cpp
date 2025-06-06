#include <iostream>
#include <cmath>
#include <fstream> // for writing to solution.txt
#include <ctime>
using namespace std;

// This function checks if the current queen placement is safe
bool ok(int q[], int c)
{
    for (int i = 0; i < c; ++i)
    {
        if (q[i] == q[c] || abs(q[i] - q[c]) == c - i)
            return false;
    }
    return true;
}

// This function writes the solution to solution.txt and prints it in the terminal
void print(int q[])
{
    // Output to file
    ofstream fout("solution.txt");
    for (int i = 0; i < 8; ++i)
    {
        fout << q[i];
        if (i < 7)
            fout << " ";
    }
    fout << endl;
    fout.close();

    // print to terminal for testing
    cout << "Generated 8-Queens Solution: ";
    for (int i = 0; i < 8; ++i)
    {
        cout << q[i] << " ";
    }
    cout << endl;
}

int main()
{
    srand(time(0)); // Set randomness

    int q[8] = {}; // q[c] = row where queen is placed in column c
    int c = 0;

    q[0] = rand() % 8; // Randomize the starting row of column 0

    while (c >= 0)
    {
        c++;
        if (c > 7)
        {
            // Found a full solution
            print(q);
            break;
        }

        q[c] = -1; // Reset this column

        while (c >= 0)
        {
            q[c]++; // Try next row
            if (q[c] > 7)
            {
                c--; // Backtrack
            }
            else if (ok(q, c))
            {
                break; // Valid position found
            }
        }
    }

    return 0;
}
