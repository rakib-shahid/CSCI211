// Rakib Shahid CSCI211 Section 22
#include <iostream>
using namespace std;

// last two digits means: square % 100 -> last two digits
// therefore after 100, all squares repeat
// for example,
// 1*1=1, 101*101 ends in 01
// 2*2=4, 102*102 ends in 04
// 3*3=9, 103*103 ends in 09
// 5*5=25, 105*105 ends in 25
// therefore we only need to check squares from 0 to 100

int main()
{
    // print above to command line ^
    cout << "last two digits means: square % 100 -> last two digits \ntherefore after 100, all squares repeat \nfor example, \n1*1=1, 101*101 ends in 01\n2*2=4, 102*102 ends in 04\n3*3=9, 103*103 ends in 09\n5*5=25, 105*105 ends in 25\ntherefore we only need to check squares from 0 to 100"
         << endl;

    // variables for the perfect square and its roots
    int x = 0;
    int square = x * x;
    // variables for tens and ones digits
    int tens = square % 100 / 10;
    int ones = square % 10;
    // loop while the tens and ones digits are even
    while ((tens % 2 == 0) || (ones % 2 == 0))
    {
        // once we reach 100, stop since roots repeat
        if (x >= 100)
        {
            break;
        }
        x++;
        square = x * x;
        tens = square % 100 / 10;
        ones = square % 10;
    }
    
    // print results
    if ((tens % 2 == 0) || (ones % 2 == 0)) cout << "\nno such perfect square was found";
    else cout << "the perfect square is " + square;

    return square;

}