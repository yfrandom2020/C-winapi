#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define SEARCH_LETTER "A"

// winapi read file
int CountChar(PCHAR pBuf, int buff_size, LPCSTR letter);
int main()
{
    int counter = 0;
    HANDLE hfile;

    INT num_bytes = 1000;
    CHAR data[1000];

    LPVOID pbuffer = data;
    DWORD amount_read = 1000;

    // get system memory alignment granularity (usually 65536)
    SYSTEM_INFO sys_info;
    GetSystemInfo(&sys_info);
    int mem_buffer_size = sys_info.dwAllocationGranularity;

    hfile = CreateFileA("D:\\gibrish.bin", GENERIC_READ, 0, NULL, 3, FILE_ATTRIBUTE_NORMAL, NULL);
    DWORD file_size = GetFileSize(hfile, NULL);

    if (hfile == INVALID_HANDLE_VALUE)
    {
        printf("error \n");
        printf("%d", GetLastError());
        return 0;
    }
    HANDLE hmap;
    hmap = CreateFileMapping(hfile, NULL, PAGE_READONLY, 0, 0, "myfile");

    if (hmap == INVALID_HANDLE_VALUE)
    {
        printf("error \n");
        printf("%d", GetLastError());
        return 0;
    };
    // an infinite loop that reads the file and only stops when an error is raised
    int file_location = 0;
    //char letter = "A";
    int buffer_number = 0;
    LPSTR pbuf;
    LPCSTR letter = SEARCH_LETTER;
    int count = 0;
    while (file_location <= (file_size - mem_buffer_size))
    {
        pbuf = MapViewOfFile(hmap, FILE_MAP_READ, file_location, 0, mem_buffer_size); // # an infinite loop that reads the file and only stops when an error is raised

        count += CountChar(pbuf, mem_buffer_size, letter);
        printf("%d\n", count);
        buffer_number++;
        file_location = mem_buffer_size * buffer_number;
        UnmapViewOfFile(pbuf);
        Sleep(10000);
    }

    int reminder = file_size - file_location;
     pbuf = (LPSTR)MapViewOfFile(
     hmap, // handle to map object
     FILE_MAP_READ, // read/write permission
     0, // start point (upper word)
     file_location, // start point (lower word)
     reminder); // how many bytes to read
     count += CountChar(pbuf, reminder, letter);
     printf("%d\n", count);
     UnmapViewOfFile(pbuf);


    printf("\n");
    printf("counter %d", counter);

    CloseHandle(hmap);
    CloseHandle(hfile);
    return 0;

}


int CountChar(PCHAR pBuf, int buff_size, LPCSTR letter) {
 static int count = 0;
 for (int i = 0; i < buff_size; i++) {
 if (pBuf[i] == *letter) count++;
 }
 return count;
}
