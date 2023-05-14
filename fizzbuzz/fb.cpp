#include <iostream>
using namespace std;

int main(){
   int max = 100;
   // get input from user? unclear instructions
   // cout << "Enter a number to stop at: ";
   // cin >> max;
   for (int i = 1; i <= max; i++){
      if (i % 3 == 0){
         cout << "Fizz";
      }
      if (i % 5 == 0){
         cout << "Buzz";
      }
      if (i % 5 != 0 )
      cout << endl;
   }
   return 0;
}