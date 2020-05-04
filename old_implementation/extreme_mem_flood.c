#include <stdio.h>
#include <stdlib.h>
#include "./os_check/os_check.h" // Checking OS + getting Memory Usage

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

    while(USED_MEMORY < LIMIT){				// Loops till the USED_MEMORY == LIMIT 
        flood = malloc(sizeof(flood));
    }

    // If memeAlloc fails
    if (flood == NULL) {
        printf("\nCouldn't allocate memory");
    }

    // free the allocated memory
    free(flood);
    printf("\nFlooding Done!");
    return 0;
}

