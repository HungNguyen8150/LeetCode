#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void* a, const void* b) {
    char* string1 = *(char**)a;
    char* string2 = *(char**)b;

    char ab[25];
    char ba[25];

    // form ab
    strcpy(ab, string1);
    strcat(ab, string2);

    // form ba
    strcpy(ba, string2);
    strcat(ba, string1);

    // sort in descending order
    return strcmp(ba, ab);
}

char* largestNumber(int* nums, int numsSize) {
    // Allocate array of string pointers
    char** arr = malloc(numsSize * sizeof(char*));

    // Convert integers to strings
    for (int i = 0; i < numsSize; i++) {
        arr[i] = malloc(12);  // max 10 digits + null
        sprintf(arr[i], "%d", nums[i]);
    }

    // Sort using custom comparator
    qsort(arr, numsSize, sizeof(char*), compare);

    // Edge case: if largest element is "0"
    if (strcmp(arr[0], "0") == 0) {
        char* result = malloc(2);
        strcpy(result, "0");
        return result;
    }

    // Allocate enough space for final result
    char* result = malloc(numsSize * 12);
    result[0] = '\0';

    // Concatenate all strings
    for (int i = 0; i < numsSize; i++) {
        strcat(result, arr[i]);
    }

    return result;
}
