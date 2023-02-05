#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSTARTINGSPEED 100
#define MAXSTARTINGLENGTH 100

int binSearch(int * values, int target, int size);
void printArray (int **ocean, int maxSpeed, int maxLoc);

int main () {
    int maxSpeed = 0, maxLoc = 0, curLoc = 0; // Max starting speed and Max x Length

    
    
    scanf("%d %d", &maxSpeed, &maxLoc);
    
    //printf("%d %d\n", maxSpeed, maxLoc); //Test

    //Initalize and fill array of all possible starting speeds and locations. 
    int **ocean;
    ocean = malloc((maxSpeed+1) * sizeof *ocean);
    for (int i = 0; i <= maxSpeed; i++){
        ocean[i] = malloc((maxLoc+1) * sizeof *ocean[i]);
    }
    for (int i = 0; i <= maxSpeed; i++){
        for (int j=0; j <= maxLoc; j++) {
        ocean[i][j]=1;
        }
    }

    printf("intailization working :)\n"); //Test
    

    printArray (ocean, maxSpeed, maxLoc);

    return 1;
}

int binSearch(int * values, int target, int size)   {
    // Initialize the search
    int lo = 0;
    int hi = size; // this value is not 
                   // in the search range
    
    while (lo < hi) {
        // find the mid point
        int mid = (lo + hi) / 2;
        
        // Compare the value at mid
        // against the target
        if (values[mid] == target)
            return mid;
        if (values[mid] < target) {
            lo = mid + 1;
        }
        if (values[mid] > target) {
            hi = mid;
        }
    }

    // What happened?
    // The value was not in the array
    return -1; // Invalid index
}

void printArray (int **ocean, int maxSpeed, int maxLoc)   {
    for (int i = 0; i <= maxSpeed; i++){
        for (int j=0; j <= maxLoc; j++) {
        printf("%d ", ocean[i][j]);
        }
        printf("\n");
    }
}