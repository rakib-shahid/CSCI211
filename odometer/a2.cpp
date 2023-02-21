// Rakib Shahid CSCI211 Section 22
#include <iostream>
using namespace std;

int main()
{
   // create array
   int win[6] = {};

   for (int i0 = 0; i0 <= 9; i0++)
   {
      // update 1st window
      win[0] = i0;
      for (int i1 = 0; i1 <= 9; i1++)
      {
         // update 2nd window
         win[1] = i1;
         for (int i2 = 0; i2 <= 9; i2++)
         {
            // update 3rd window
            win[2] = i2;
            for (int i3 = 0; i3 <= 9; i3++)
            {
               // update 4th window
               win[3] = i3;
               for (int i4 = 0; i4 <= 9; i4++)
               {
                  // update 5th window
                  win[4] = i4;
                  for (int i5 = 0; i5 <= 9; i5++)
                  {
                     // update 6th window
                     win[5] = i5;

                     // Print odometer
                     for (int x : win)
                     {
                        cout << x;
                     }
                     cout << endl;
                  }
               }
            }
         }
      }
   }

   return 0;
}
