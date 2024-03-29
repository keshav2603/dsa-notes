#include <iostream>
using namespace std;
int main()
{
    int a[3][4]; // method one to declare 2d array

    int *b[3]; // second method of declare 2d array
    b[0] = new int[4];
    b[1] = new int[4];
    b[2] = new int[4];

    int **c; // third mwthod
    c = new int *[3];
    c[0] = new int[4];
    c[1] = new int[4];
    c[2] = new int[4];
    delete[] b[0];
    delete[] b[1];
    delete[] b[2];
    delete[] c[0];
    delete[] c[1];
    delete[] c[2];

    return 0;
}
