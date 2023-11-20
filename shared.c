#include <stdio.h>
#include <stdlib.h>
#include <windows.h>



// three things: 1) father process 2) two son processes that the father calls
// the father only calls the son
// the two sons are identical, but will have if conditions that will make differernt actions
// first son: a) open the file b) create the file mapping c) read the data into the shared memory
// second son: a) read the data to itself b) change the first letter c) write back and close all handles and free the space


int main()
{

    return 1;
}
