#include <iostream>
using namespace std;

int main()
{
   int solutionCounter = 0;
   int b[8][8] = {0}, r, c = -1;

// new column
nc:
   c++;
   if (c == 8)
   {
      goto print;
   }
   r = -1;

// new row
nr:
   r++;
   if (r == 8)
   {
      goto backtrack;
   }
   // row test
   for (int i = 0; i < c; i++)
   {
      if (b[r][i] == 1)
      {
         goto nr;
      }
   }
   // up diagonal test
   for (int i = 1; (r - i) >= 0 && (c - i) >= 0; i++)
   {
      if (b[r - i][c - i] == 1)
      {
         goto nr;
      }
   }
   // down diagonal test
   for (int i = 1; (r + i) < 8 && (c - i) >= 0; i++)
   {
      if (b[r + i][c - i] == 1)
      {
         goto nr;
      }
   }

   b[r][c] = 1;
   goto nc;

// backtrack 
backtrack:
   c--;
   if (c == -1)
   {
      return 0;
   }
   r = 0;
   while (b[r][c] != 1)
      r++;
   b[r][c] = 0;
   goto nr;


// print statement
print:
   // counter for each solution
   solutionCounter++;
   cout << "Solution " << solutionCounter << endl;

   // print board
   for (int x = 0; x < 8; x++)
   {
      for (int y = 0; y < 8; y++)
      {
         cout << b[x][y] << " ";
      }

      cout << "\n";
   }

   cout << "\n";
   goto backtrack;
}