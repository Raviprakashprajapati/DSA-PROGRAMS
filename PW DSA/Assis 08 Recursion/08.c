// <aside>
// 💡 **Question 8**

// Given two strings s and goal, return true *if you can swap two letters in* s *so the result is equal to* goal*, otherwise, return* false*.*

// Swapping letters is defined as taking two indices i and j (0-indexed) such that i != j and swapping the characters at s[i] and s[j].

// - For example, swapping at indices 0 and 2 in "abcd" results in "cbad".

// **Example 1:**

// **Input:** s = "ab", goal = "ba"

// **Output:** true

// **Explanation:** You can swap s[0] = 'a' and s[1] = 'b' to get "ba", which is equal to goal.

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool buddyStrings(char *s, char *goal) {
    int lenS = strlen(s);
    int lenGoal = strlen(goal);
    
    // Lengths should be equal for a valid swap
    if (lenS != lenGoal) {
        return false;
    }
    
    // Check for identical strings and possible swaps
    if (strcmp(s, goal) == 0) {
        // Check if there are at least two identical characters
        int count[26] = {0};  // Assuming lowercase alphabets
        for (int i = 0; i < lenS; i++) {
            count[s[i] - 'a']++;
        }
        
        for (int i = 0; i < 26; i++) {
            if (count[i] > 1) {
                return true;
            }
        }
        
        return false;
    } else {
        // Check for potential swap positions
        int firstIndex = -1;
        int secondIndex = -1;
        
        for (int i = 0; i < lenS; i++) {
            if (s[i] != goal[i]) {
                if (firstIndex == -1) {
                    firstIndex = i;
                } else if (secondIndex == -1) {
                    secondIndex = i;
                } else {
                    return false;  // More than two differences, cannot be made equal by swapping
                }
            }
        }
        
        // Check if the characters at the swap positions are equal after swapping
        return (secondIndex != -1 && s[firstIndex] == goal[secondIndex] && s[secondIndex] == goal[firstIndex]);
    }
}

int main() {
    char s[] = "ab";
    char goal[] = "ba";
    
    bool result = buddyStrings(s, goal);
    
    if (result) {
        printf("You can swap two letters to make the strings equal.\n");
    } else {
        printf("You cannot make the strings equal by swapping two letters.\n");
    }
    
    return 0;
}
