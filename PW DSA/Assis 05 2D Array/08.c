// <aside>
// 💡 **Question 8**

// An integer array original is transformed into a **doubled** array changed by appending **twice the value** of every element in original, and then randomly **shuffling** the resulting array.

// Given an array changed, return original *if* changed *is a **doubled** array. If* changed *is not a **doubled** array, return an empty array. The elements in* original *may be returned in **any** order*.

// **Example 1:**

// **Input:** changed = [1,3,4,2,6,8]

// **Output:** [1,3,4]

// **Explanation:** One possible original array could be [1,3,4]:

// - Twice the value of 1 is 1 * 2 = 2.
// - Twice the value of 3 is 3 * 2 = 6.
// - Twice the value of 4 is 4 * 2 = 8.

// Other original arrays could be [4,3,1] or [3,1,4].


#include <stdio.h>
#include <stdlib.h>

int* findOriginalArray(int* changed, int changedSize, int* returnSize) {
    // Create a dictionary to store the count of each number
    int* numCounts = (int*) calloc(changedSize * 2, sizeof(int));
    
    // Iterate over the changed array
    for (int i = 0; i < changedSize; i++) {
        int num = changed[i];
        
        // Check if num is already present or num/2 is missing or num is odd
        if (numCounts[num] > 0 || numCounts[num / 2] == 0 || num % 2 != 0) {
            free(numCounts);
            *returnSize = 0;
            return NULL;
        }
        
        // Decrement the count of num/2
        numCounts[num / 2]--;
    }
    
    // Calculate the size of the original array
    *returnSize = 0;
    for (int i = 0; i < changedSize * 2; i++) {
        *returnSize += numCounts[i];
    }
    
    // Create the original array
    int* original = (int*) malloc(*returnSize * sizeof(int));
    int index = 0;
    
    // Fill the original array
    for (int i = 0; i < changedSize * 2; i++) {
        while (numCounts[i] > 0) {
            original[index] = i;
            index++;
            numCounts[i]--;
        }
    }
    
    free(numCounts);
    return original;
}

int main() {
    int changed[] = {1, 3, 4, 2, 6, 8};
    int changedSize = sizeof(changed) / sizeof(changed[0]);
    int returnSize;
    int* original = findOriginalArray(changed, changedSize, &returnSize);
    
    if (original != NULL) {
        printf("Original Array: ");
        for (int i = 0; i < returnSize; i++) {
            printf("%d ", original[i]);
        }
        printf("\n");
        
        free(original);
    } else {
        printf("Changed array is not a doubled array.\n");
    }
    
    return 0;
}



