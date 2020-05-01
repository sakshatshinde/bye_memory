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