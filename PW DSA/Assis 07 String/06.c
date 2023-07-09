// <aside>
// 💡 **Question 6**

// Given two strings s and goal, return true *if and only if* s *can become* goal *after some number of **shifts** on* s.

// A **shift** on s consists of moving the leftmost character of s to the rightmost position.

// - For example, if s = "abcde", then it will be "bcdea" after one shift.

// **Example 1:**

// **Input:** s = "abcde", goal = "cdeab"

// **Output:**

// true
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool rotateString(char* s, char* goal) {
    int len = strlen(s);

    // Return true if the strings have the same length and are equal
    if (len == strlen(goal) && strcmp(s, goal) == 0) {
        return true;
    }

    // Perform rotations and check if s becomes equal to goal
    for (int i = 0; i < len; i++) {
        char temp = s[0];  // Store the leftmost character

        // Shift the characters to the left
        for (int j = 0; j < len - 1; j++) {
            s[j] = s[j + 1];
        }

        s[len - 1] = temp;  // Place the leftmost character at the rightmost position

        // Check if s becomes equal to goal
        if (strcmp(s, goal) == 0) {
            return true;
        }
    }

    return false;
}

int main() {
    char s[] = "abcde";
    char goal[] = "cdeab";

    if (rotateString(s, goal)) {
        printf("String s can become goal after some number of shifts.\n");
    } else {
        printf("String s cannot become goal after any number of shifts.\n");
    }

    return 0;
}
