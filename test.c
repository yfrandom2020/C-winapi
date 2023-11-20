
// criticalsection file
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>


#define NUM_THREADS 2
#define MAX 10000
CRITICAL_SECTION ghCriticalSection;

VOID inc(PINT param) {
 INT temp = *param;
 temp++;
 *param = temp;
}
DWORD WINAPI thread_func(LPVOID param) {
 EnterCriticalSection(&ghCriticalSection);
 for (INT i = 0; i < MAX; i++) {
 inc((PINT)param);
 }
 LeaveCriticalSection(&ghCriticalSection);
 return 1;
}
int blalba()
{
 InitializeCriticalSection(&ghCriticalSection);
 INT val = 0;
 LPVOID param = &val;
 HANDLE hThread[NUM_THREADS];
 for (INT i = 0; i < NUM_THREADS; i++) {
 hThread[i] = CreateThread(
 NULL, //default security attributes
 0, //default stack size
 thread_func,//thread function
 param, //thread param
 0, //default creation flags
 NULL //return thread identifier
 );
 }
 WaitForMultipleObjects(NUM_THREADS, hThread, TRUE, INFINITE);
 DeleteCriticalSection(&ghCriticalSection);
 printf("Param value: %d\n", *(PINT)param);
}
