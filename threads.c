#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <mem.h>
// single thread file
struct MyStruct
{
 INT a;
 INT b;
};

DWORD WINAPI blabla(LPVOID lparam)
{
    struct MyStruct *nums = (struct MyStruct*)lparam;
    INT count = nums->a + nums->b;
    for (INT i = 1; i <= count; i++)
    {
        printf("bla\n");
        Sleep(20000);
    }
    return 1;
}


int a()
{
    struct MyStruct *my_struct = (struct MyStruct*)malloc(sizeof(struct MyStruct));
    my_struct->a = 3;
    my_struct->b = 4;
    LPVOID pstruct = my_struct;
    HANDLE hthread = CreateThread(NULL,0,blabla,pstruct,0,NULL);
    WaitForSingleObject(hthread, INFINITE);
    return 0;
}
