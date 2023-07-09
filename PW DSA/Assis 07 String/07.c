// <aside>
// 💡 **Question 7**

// Given two strings s and t, return true *if they are equal when both are typed into empty text editors*. '#' means a backspace character.

// Note that after backspacing an empty text, the text will continue empty.

// **Example 1:**

// **Input:** s = "ab#c", t = "ad#c"

// **Output:** true

// **Explanation:**

// Both s and t become "ac".
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool backspaceCompare(char* s, char* t) {
    int len1 = strlen(s);
    int len2 = strlen(t);
    int i = len1 - 1;
    int j = len2 - 1;
    int backspaceCountS = 0;
    int backspaceCountT = 0;

    while (i >= 0 || j >= 0) {
        // Find the position of the next valid character in s
        while (i >= 0) {
            if (s[i] == '#') {
                backspaceCountS++;
                i--;
            } else if (backspaceCountS > 0) {
                backspaceCountS--;
                i--;
            } else {
                break;
            }
        }

        // Find the position of the next valid character in t
        while (j >= 0) {
            if (t[j] == '#') {
                backspaceCountT++;
                j--;
            } else if (backspaceCountT > 0) {
                backspaceCountT--;
                j--;
            } else {
                break;
            }
        }

        // Compare the characters at the current positions
        if (i >= 0 && j >= 0 && s[i] != t[j]) {
            return false;
        }

        // If one string reaches the beginning while the other hasn't, they are not equal
        if ((i >= 0 && j < 0) || (i < 0 && j >= 0)) {
            return false;
        }

        i--;
        j--;
    }

    // Both strings have been processed completely and are equal
    return true;
}

int main() {
    char s[] = "ab#c";
    char t[] = "ad#c";

    if (backspaceCompare(s, t)) {
        printf("The strings are equal.\n");
    } else {
        printf("The strings are not equal.\n");
    }

    return 0;
}
