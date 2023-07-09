// <aside>
// 💡 **Question 3**

// Given two strings word1 and word2, return *the minimum number of **steps** required to make* word1 *and* word2 *the same*.

// In one **step**, you can delete exactly one character in either string.

// **Example 1:**

// **Input:** word1 = "sea", word2 = "eat"

// **Output:** 2

// **Explanation:** You need one step to make "sea" to "ea" and another step to make "eat" to "ea".


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int minDistance(char *word1, char *word2) {
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    
    // Create a 2D array to store the minimum number of steps
    int dp[len1+1][len2+1];
    
    // Initialize the first row and column
    for (int i = 0; i <= len1; i++) {
        dp[i][0] = i;
    }
    for (int j = 0; j <= len2; j++) {
        dp[0][j] = j;
    }
    
    // Calculate the minimum number of steps
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (word1[i-1] == word2[j-1]) {
                dp[i][j] = dp[i-1][j-1];  // Characters are equal, no deletion required
            } else {
                dp[i][j] = 1 + fmin(dp[i-1][j], dp[i][j-1]);
                // Choose the minimum steps between deleting from word1 or word2
            }
        }
    }
    
    return dp[len1][len2];  // Return the minimum number of steps
}

int main() {
    char word1[] = "sea";
    char word2[] = "eat";
    
    int result = minDistance(word1, word2);
    printf("The minimum number of steps required is: %d\n", result);
    
    return 0;
}
