#include <iostream> //Baljinder Singh
using namespace std;

int count = 0;
bool ok(int q[])
{
    bool test = true;
    for (int i = 7; i > 0; i--)
    {
        int j = q[i];
        for (int k = 1; k <= i; k++)
        {
            if (q[i - k] == j)
                test = false; // row test
            // diagonal tests
            else if (q[i - k] == j - k)
                test = false;
            else if (q[i - k] == j + k)
                test = false;
        }
    }
    return test;
}
// making sure the code runs good with the test and returns the test being done
void print(int q[])
{
    int i, j, k, l;
    typedef char box[5][7];
    box bb, wb, *board[8][8];

    // fill in bb=black box and wb=whitebox
    for (i = 0; i < 5; i++)
    {
        for (k = 0; k < 7; j++)
        {
            wb[i][j] = ' ';
            bb[i][j] = char(219);
        }
    }
    static box bq = {
        {char(219), char(219), char(219), char(219), char(219), char(219), char(219)},
        {char(219), ' ', char(219), ' ', char(219), ' ', char(219)},
        {char(219), ' ', ' ', ' ', ' ', ' ', char(219)},
        {char(219), ' ', ' ', ' ', ' ', ' ', char(219)},
        {char(219), char(219), char(219), char(219), char(219), char(219), char(219)}};

    static box wq = {
        {' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', char(219), ' ', char(219), ' ', char(219), ' '},
        {' ', char(219), char(219), char(219), char(219), char(219), ' '},
        {' ', char(219), char(219), char(219), char(219), char(219), ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' '}};
    // fill board with pointers to bb and wb in alternate positions.
    for (i = 0; i < 8; i++)
        for (j = 0; j < 8; j++)
            if ((i + j) % 2 == 0)
                board[i][j] = &wb;
            else
                board[i][j] = &bb;

    // upper border
    for (i = 0; i < 7 * 8; i++)
        cout << '_';
    cout << "\n";

    // print board
    for (i = 0; i < 8; i++)
        for (k = 0; k < 5; k++)
        {
            cout << "   " << char(179); // left border
            for (j = 0; j < 8; j++)
                for (l = 0; l < 7; l++)
                    cout << (*board[i][j])[k][l];
            cout << char(179) << endl; // end of line print bar then newline
        }
    // Print lower border
    cout << " ";
    for (i = 0; i < 7 * 8; i++)
        cout << char(196);
    cout << "\n\n";

    cout << "\nSolution " << ++count << endl;
    for (int i = 0; i < 8; i++)
    { // declaring variables and substitutes
        for (int j = 0; j < 8; j++)
        {
            if (j == q[i])
                cout << "1 ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
}
int main()
{

    int q[8];

    for (int i0 = 0; i0 < 8; i0++) // checking each substitutes and row making
        for (int i1 = 0; i1 < 8; i1++)
            for (int i2 = 0; i2 < 8; i2++)
                for (int i3 = 0; i3 < 8; i3++)
                    for (int i4 = 0; i4 < 8; i4++)
                        for (int i5 = 0; i5 < 8; i5++)
                            for (int i6 = 0; i6 < 8; i6++)
                                for (int i7 = 0; i7 < 8; i7++)
                                {
                                    q[0] = i0;
                                    q[1] = i1;
                                    q[2] = i2;
                                    q[3] = i3;
                                    q[4] = i4;
                                    q[5] = i5;
                                    q[6] = i6;
                                    q[7] = i7;
                                    if (ok(q))
                                        print(q); // making sure everything runs well without errors and the steps said to do
                                }
    return 0;
} // run the code and loops the code