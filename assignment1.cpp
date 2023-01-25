#include <iostream>
using namespace std;

int main(){
    int x = 4;
    int y = x * x;
    int tens = y % 100 / 10;
    int ones = y % 10;
    while ((tens % 2 == 0) || (ones % 2 == 0)){
        x++;
        y = x * x;
        tens = y % 100 / 10;
        ones = y % 10;
    }
    cout << "x = " << x << "\nx*x = " << y << endl;
    cout << tens << "\n" << ones << endl;
    return y;
}