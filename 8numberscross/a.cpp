#include <cmath>
#include <iostream>
using namespace std;

int main() {
  int counter = 1;
  int q[8], c = 0;
  q[0] = 1;
  int helper[8][5] = {
      // helper array
      {-1},            // index 0
      {0, -1},         // index 1
      {0, -1},         // index 2
      {0, 1, 2, -1},   // index 3
      {0, 1, 3, -1},   // index 4
      {1, 4, -1},      // index 5
      {2, 3, 4, -1},   // index 6
      {3, 4, 5, 6, -1} // index 7
  };
nc:
  c++;
  if (c == 8)
    goto print;
  q[c] = 0;
nr:
  q[c]++;
  if (q[c] == 9)
    goto backtrack;
  // check if value has been used before
  for (int i = 0; i < c; i++) {
    if (q[c] == q[i]) {
      goto nr;
    }
  }
  // check each index in helper array
  for (int i = 0; helper[c][i] != -1; i++) {
    // if absolute val == 1, consecutive numbers are adjacent
    if (abs(q[helper[c][i]] - q[c]) == 1)
      goto nr;
  }
  goto nc;
backtrack:
  q[c] = 0;
  c--;
  goto nr;
  if (c == -1)
    return 0;
print:
  cout << "Solution " << counter << ": \n" << endl;
  counter++;
  cout << " " << q[0] << q[1] << "\n"
       << q[2] << q[3] << q[4] << q[5] << "\n " << q[6] << q[7] << "\n"
       << endl;
  cout << endl;
  goto backtrack;
}