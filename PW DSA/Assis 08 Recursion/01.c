// <aside>
// 💡 **Question 1**

// Given two strings s1 and s2, return *the lowest **ASCII** sum of deleted characters to make two strings equal*.

// **Example 1:**

// **Input:** s1 = "sea", s2 = "eat"

// **Output:** 231

// **Explanation:** Deleting "s" from "sea" adds the ASCII value of "s" (115) to the sum.

// Deleting "t" from "eat" adds 116 to the sum.

// At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum possible to achieve this.

// </aside>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int minimumDeleteSum(char *s1, char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    
    // Create a 2D array to store the minimum ASCII sum of deleted characters
    int dp[len1+1][len2+1];
    
    // Initialize the first row and column with cumulative ASCII sum
    dp[0][0] = 0;
    for (int i = 1; i <= len1; i++) {
        dp[i][0] = dp[i-1][0] + s1[i-1];
    }
    for (int j = 1; j <= len2; j++) {
        dp[0][j] = dp[0][j-1] + s2[j-1];
    }
    
    // Calculate the minimum ASCII sum of deleted characters
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1];  // Characters are equal, no deletion required
            } else {
                dp[i][j] = fmin(dp[i-1][j] + s1[i-1], dp[i][j-1] + s2[j-1]);
                // Choose the minimum sum between deleting from s1 or s2
            }
        }
    }
    
    return dp[len1][len2];  // Return the lowest ASCII sum
}

int main() {
    char s1[] = "sea";
    char s2[] = "eat";
    
    int result = minimumDeleteSum(s1, s2);
    printf("The lowest ASCII sum of deleted characters is: %d\n", result);
    
    return 0;
}
