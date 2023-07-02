// <aside>
// 💡 **Question 1**

// A permutation perm of n + 1 integers of all the integers in the range [0, n] can be represented as a string s of length n where:

// - s[i] == 'I' if perm[i] < perm[i + 1], and
// - s[i] == 'D' if perm[i] > perm[i + 1].

// Given a string s, reconstruct the permutation perm and return it. If there are multiple valid permutations perm, return **any of them**.

// **Example 1:**

// **Input:** s = "IDID"

// **Output:**

// [0,4,1,3,2]

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* findPermutation(char* s, int n, int* returnSize) {
    int* perm = (int*)malloc((n + 1) * sizeof(int));
    *returnSize = n + 1;
    
    int left = 0, right = n;
    
    for (int i = 0; i < n; i++) {
        if (s[i] == 'I') {
            perm[i] = left++;
        } else {
            perm[i] = right--;
        }
    }
    
    perm[n] = left;
    
    return perm;
}

int main() {
    char s[] = "IDID";
    int n = strlen(s);
    int* perm;
    int permSize;
    
    perm = findPermutation(s, n, &permSize);
    
    printf("Output: ");
    for (int i = 0; i < permSize; i++) {
        printf("%d ", perm[i]);
    }
    
    free(perm);
    
    return 0;
}
