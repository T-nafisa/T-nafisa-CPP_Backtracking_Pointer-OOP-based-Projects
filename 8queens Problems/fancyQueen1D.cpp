#include <iostream>
#include <cmath>
using namespace std;

// Bool function "ok" checks if a certain position (column c) is safe to place a quuen
bool ok(int q[], int c){
   for (int i = 0; i < c; ++i)
     // Checks if any other queen is in the same row or up/down diagonal 
      if (q[i] == q[c] || abs(q[i] - q[c]) == c - i)  
         // If any conflict found, it will return false value
         return false;  
   // If no conflicts, then queens positions are valid and return true 
   return true;                                        
}


// This function is used in the main function to print the solved result with fancy chessboard and fancy (black and white) queens. 
void print(int q[]){         
   static int solution = 0;  // Counts the number of solutions.
   int i, j, k, l;
   // Define a new type called "box" which is a 5x7 2D array of characters (used for each square)
   typedef char box[5][7];   
   box bb, wb, *board[8][8]; // "bb"= black box, "wb"=white box (5x7 arrays). "Board" is an 8x8 array of pointers to boxes.
                             //  everytime when call this function they'll be reinitialized as they're not static 

   // "bb" represents black box and "wb" represents white box. They each represent a square of the chessboard.
   // We only need to create one of each, since the chessboard can contain many pointers to the same box.
   for (i=0; i<5; i++)
      for (j=0; j<7; j++) 
      {
         wb[i][j] = ' ';
         bb[i][j] = char(219);
      }
   
   // Create 2 more boxes to represent the black and white queens, by drawing a picture of each queen in the 2D array.
  static box bq = {
		{' ', ' '      , ' '      , ' '      , ' '      , ' '      , ' '},
		{' ', char(219), ' '      , char(219), ' '      , char(219) , ' '},
		{' ', char(219), char(219), char(219), char(219), char(219), ' '},
		{' ', char(219), char(219), char(219), char(219), char(219), ' '},
		{' ', ' '      , ' '      , ' '      , ' '      , ' '      , ' '}
	};
               
   static box wq = { 
        {char(219), char(219),char(219), char(219), char(219), char(219), char(219)},
		{char(219), ' '      , char(219), ' '     , char(219), ' '      , char(219)},
		{char(219), ' '      , ' '      , ' '     , ' '      , ' '      , char(219)},
		{char(219), ' '      , ' '      , ' '     , ' '      , char(219), char(219)},
		{char(219), char(219),char(219), char(219), char(219), char(219), char(219)}
				};

   // Fill board with pointers to bb and wb in alternate positions.
   for(i=0; i<8; i++)
      for(j=0; j<8; j++)
         if((i+j)%2 == 0)      
            // if the sum of row and column is even, that position (box) will be a white box. 
            board[i][j] = &wb; 
         // If it is odd, then the box will be a black box.
         else
            board[i][j] = &bb;  
   

   // Set up the current solution on the chessboard by placing pointers to bq and wq in the appropriate squares & connecting solutions q[] with fancy queens (bq/wq) via pointer board.

   for(i=0; i<8; i++)
      if((i+q[i])%2 == 0) // if true --> then it's white box
         board[q[i]][i] = &bq; // Then place black queen there
      else
         board[q[i]][i] = &wq;  // Otherwise, it's black box-->place a black queen there.

   cout << "Solution #" << ++solution << ":\n ";

   cout << "\n2D fancy chessboard with fancy black and white queens for the 1D solution: \n";
   
   // Printing upper border
   for (i=0; i<7*8; i++)
      cout << '_';
   cout << "\n";

   // Print each row of 2D fancy chessboard
   for (i=0; i<8; i++)                        // for each board row
      for (k=0; k<5; k++){                    // for each box row
         cout << char(179);
         for (j=0; j<8; j++)                  // for each board column
            for (l=0; l<7; l++)               // for each box column
                                              // board[i][j] is the box pointer in the ith row, jth column of the board.
                                              // *board[i][j] is the box being pointed to.
                                              // (*board[i][j])[k][l] is the kth row, lth column of the box.
               cout << (*board[i][j])[k][l];
         cout << char(179) << "\n";    // Right border
      }

   // Printing bottom border
   cout << " ";
   for (i=0; i<7*8; i++)
      cout << char(196);
   cout << "\n\n";
}


int main(){
   int q[8] = {};   // Initializes the array q to 0
   int c = 0;    // initializes c(column) to 0 
   q[0] = 0;    // q[c]= row of chessboard. Starts from 1st row & 1st column.

  // This condition will end the loop when it backtracks from the first column.
   while (c >= 0){
      c++;                 // Move to the next column
      // If we've placed a queen in all 8 columns, we found a solution
      if (c > 7){ 
         // Call print function to print the found solution
         print(q);        
         c--;              // Backtracks to find more solutions
      }
      
      // Otherwise, move to one before the first row of the next column
      // Reset the current column's row to -1
      else q[c] = -1; 
      
      // Try finding a valid row for the queen in the current column
      while (c >= 0){  
         q[c]++;           // Move to the next row
         if (q[c] > 7) 
            c--;          // If we have passed the last row, backtrack

         else              // Otherwise, we'd need to call the ok function.
            if (ok(q, c))  // If the ok function returns true, it means that certain row of the column is suitable to place queen.
               break;      // As it returns true,the current position is valid, break
      }

   }

   return 0;               // When outer while loop ends, that means we found all the possible solutions and printed fancy output of them. So, the program ends here.
}