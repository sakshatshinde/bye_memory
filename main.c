#include <stdio.h>
#include <stdlib.h>

// Checking OS
#ifdef _WIN32

#include <windows.h>
        //-----
        unsigned long long getTotalSystemMemory(){
            MEMORYSTATUSEX status;
            status.dwLength = sizeof(status);
            GlobalMemoryStatusEx(&status);
            return status.ullTotalPhys;
        }
        //-----
        
        unsigned long long getUsedSystemMemory(){
            MEMORYSTATUSEX memInfo;
			memInfo.dwLength = sizeof(MEMORYSTATUSEX);
			GlobalMemoryStatusEx(&memInfo);
			DWORDLONG physMemUsed = memInfo.ullTotalPhys - memInfo.ullAvailPhys;
			return physMemUsed;
        }
        
		
#define TOTAL_MEMORY getTotalSystemMemory()
#define USED_MEMORY getUsedSystemMemory()

#endif

#ifdef __linux__

#include <unistd.h>
        //-----
        unsigned long long getTotalSystemMemory(){
            long pages = sysconf(_SC_PHYS_PAGES);
            long page_size = sysconf(_SC_PAGE_SIZE);
            return pages * page_size;
        }
        //-----
#define TOTAL_MEMORY getTotalSystemMemory()

#endif

int main(int argc, char** argv){

//long long -> ll and unsigned -> u
printf("This is the Total Memory: %llu\n", TOTAL_MEMORY);
long long* flood = NULL;
float flood_percentage;

printf("Input the flood percentage :");
scanf("%f", &flood_percentage);
unsigned long long LIMIT =  ((unsigned long long) TOTAL_MEMORY * (flood_percentage / 100));
printf("Current limit : %llu\n", LIMIT);
printf("Used memory : %llu", USED_MEMORY);


// int i = 0;
while(USED_MEMORY < LIMIT){	// This while condition is meaningless atm, always true
    //printf("Total memory: %llu", TOTAL_MEMORY);
    flood = malloc(sizeof(flood));
//    i = i + sizeof(flood);
    // sleep(1);
}

// If memeAlloc fails
if (flood == NULL) {
	printf("Couldn't allocate memory");
}

free(flood);
printf("Flooding Done!");
return 0;
}
