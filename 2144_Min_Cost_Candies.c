#include <stdlib.h>

int compare(const void* a, const void* b) {
    // Cast the void pointers to integer pointers and dereference them
    int int_a = *((int*)a);
    int int_b = *((int*)b);

    // Return a negative value if the first argument is greater than the second
    // Return 0 if they are equal
    // Return a positive value if the first argument is less than the second
    if (int_a > int_b) return -1;
    else if (int_a < int_b) return 1;
    else return 0;
}

int minimumCost(int* cost, int costSize) {
    qsort(cost, costSize, sizeof(int), compare);
    
    int total = 0;
    
    for (int i = 0; i < costSize; i++) {
        // Skip every 3rd candy
        if ((i + 1) % 3 != 0) {
            total += cost[i];
        }
    }
    
    return total;
}
