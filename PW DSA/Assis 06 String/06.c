// <aside>
// 💡 **Question 6**

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
#include <stdbool.h>
#include <stdlib.h>

bool checkIfDoubled(int* original, int originalSize, int* changed, int changedSize) {
    int count[100001] = {0};
    
    for (int i = 0; i < changedSize; i++) {
        count[changed[i]]++;
    }
    
    for (int i = 0; i < changedSize; i++) {
        if (count[changed[i]] == 0) {
            continue;
        }
        
        if (changed[i] % 2 != 0 || count[changed[i] / 2] == 0) {
            return false;
        }
        
        count[changed[i]]--;
        count[changed[i] / 2]--;
    }
    
    return true;
}

int* findOriginalArray(int* changed, int changedSize, int* returnSize) {
    int* original = NULL;
    int originalSize = 0;
    
    if (!checkIfDoubled(original, originalSize, changed, changedSize)) {
        *returnSize = 0;
        return original;
    }
    
    int count[100001] = {0};
    
    for (int i = 0; i < changedSize; i++) {
        count[changed[i]]++;
    }
    
    original = (int*)malloc((changedSize / 2) * sizeof(int));
    originalSize = 0;
    
    for (int i = 0; i < changedSize; i++) {
        if (count[changed[i]] == 0) {
            continue;
        }
        
        original[originalSize++] = changed[i] / 2;
        count[changed[i]]--;
        count[changed[i] / 2]--;
    }
    
    *returnSize = originalSize;
    return original;
}

int main() {
    int changed[] = {1, 3, 4, 2, 6, 8};
    int changedSize = sizeof(changed) / sizeof(changed[0]);
    
    int* original;
    int originalSize;
    
    original = findOriginalArray(changed, changedSize, &originalSize);
    
    printf("Output: ");
    for (int i = 0; i < originalSize; i++) {
        printf("%d ", original[i]);
    }
    printf("\n");
    
    free(original);
    
    return 0;
}
