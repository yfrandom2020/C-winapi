#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

DWORD WINAPI bla(LPVOID lparam)
{

    int id = *(int*)lparam;

    for (INT i = 0; i <= 100; i++)
    {
        printf("Thread: %d, var: %d \n", id, i);
        Sleep(10000);
    }
    return 1;
}

int nnn()
{
    // create four threads that each runs a a loop - printing it's own id and loop number
    // have an array of handles
    HANDLE*  ThreadHandlers;
    ThreadHandlers  =   (HANDLE*)malloc(sizeof(HANDLE) * 4);
    for (int i = 0; i < 4; i++)
    {
        LPVOID pstruct = malloc(sizeof(int));
        *(int*)pstruct = i;
        HANDLE hthread = CreateThread(NULL,0,bla,pstruct,0,NULL);
        Sleep(10000);
        ThreadHandlers[i] = hthread;

    }
    WaitForMultipleObjects(4,ThreadHandlers, 1,INFINITE);
    return 0;

}
