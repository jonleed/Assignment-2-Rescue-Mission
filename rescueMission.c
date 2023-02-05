#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 23

int binSearch(int * values, int target, int size);

int main () {
    int S = 0; // Max starting speed
    int L = 0; // Max x Length
    int curRange = 0, index = 0, result = 0;
    int ocean[L];
    
    scanf("%d %d", &S, &L);
    
    printf("%d %d\n", S, L);

    curRange=S*index;

    printf("%d\n", binSearch(ocean, S, L));

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