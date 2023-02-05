
// This program demonstrates the speed up for using binary search over 
// linear search

// Include header files that might be useful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The array size
#define SIZE 100000

// The number of look up queries on the array
#define LOOK_UPS 100000

// Binary Search function
int binSearch(int * values, int target, int size) {
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

// Linear search function
int linSearch(int * values, int target, int size) {
    // Check every value in the array list
    for (int i = 0; i < size; i++)
        if (values[i] == target)
            return i;
            
    // The value was not conatined
    return -1;
}

// The main function
int main() {
    // Create a sorted array of integers
    int values[SIZE];
    values[0] = 0;
    for (int i = 1; i < SIZE; i++) {
        values[i] = values[i - 1] + // Add the previous value
                    rand() % 10 + // Add some randomness
                    1; // Ensures distinct values
    }    
    printf("The array is completed\n");

    // Binary search the array 
    // (multiple times)
    for (int i = 0; i < LOOK_UPS; i++)
    {
        int target = 
            rand() % 
            (values[SIZE - 1] + 1);
        binSearch(values, target, SIZE);
    }
    printf(
        "The binary search is done.\n");

    // Linear search the array
    for (int i = 0; i < LOOK_UPS; i++)
    {
        int target = 
            rand() % 
            (values[SIZE - 1] + 1);
        linSearch(values, target, SIZE);
    }
    printf(
        "The linear search is done.\n");

    // Exit
    return 0;
}

