#include <stdio.h>
#include <stdlib.h>

// Checking OS
#ifdef _WIN32

#include <windows.h>
//-----
unsigned long long getTotalSystemMemory()
{
    MEMORYSTATUSEX status;
    status.dwLength = sizeof(status);
    GlobalMemoryStatusEx(&status);
    return status.ullTotalPhys;
}
//-----
#define TOTAL_MEMORY getTotalSystemMemory()

#endif

#ifdef __linux__

#include <unistd.h>
//-----
unsigned long long getTotalSystemMemory()
{
    long pages = sysconf(_SC_PHYS_PAGES);
    long page_size = sysconf(_SC_PAGE_SIZE);
    return pages * page_size;
}
//-----
#define TOTAL_MEMORY getTotalSystemMemory()

#endif

int main(int argc, char** argv){


//long long -> ll and unsigned -> u
printf("%llu\n", TOTAL_MEMORY);
long long* flood = NULL;
unsigned long long LIMIT =  ((unsigned long long) TOTAL_MEMORY * 0.3);

int i = 0;
while(i < (TOTAL_MEMORY * 0.3)){	// This while condition is meaningless atm, always true
    //printf("Total memory: %llu", TOTAL_MEMORY);
    flood = malloc(sizeof(flood));
    i++;
    // sleep(1);
}

// If memeAlloc fails
if (flood == NULL) {
	printf("Couldn't allocate memory");
}

free(flood);
return 0;
}
