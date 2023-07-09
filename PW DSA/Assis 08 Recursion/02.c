
// <aside>
// 💡 **Question 2**

// Given a string s containing only three types of characters: '(', ')' and '*', return true *if* s *is **valid***.

// The following rules define a **valid** string:

// - Any left parenthesis '(' must have a corresponding right parenthesis ')'.
// - Any right parenthesis ')' must have a corresponding left parenthesis '('.
// - Left parenthesis '(' must go before the corresponding right parenthesis ')'.
// - '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".

// **Example 1:**

// **Input:** s = "()"

// **Output:**

// true

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isValid(char *s) {
    int len = strlen(s);
    int openCount = 0;
    int starCount = 0;
    
    // Traverse the string from left to right
    for (int i = 0; i < len; i++) {
        if (s[i] == '(') {
            openCount++;
        } else if (s[i] == '*') {
            starCount++;
        } else {
            if (openCount > 0) {
                openCount--;
            } else if (starCount > 0) {
                starCount--;
            } else {
                return false;
            }
        }
    }
    
    // Traverse the string from right to left
    int closeCount = 0;
    starCount = 0;
    for (int i = len - 1; i >= 0; i--) {
        if (s[i] == ')') {
            closeCount++;
        } else if (s[i] == '*') {
            starCount++;
        } else {
            if (closeCount > 0) {
                closeCount--;
            } else if (starCount > 0) {
                starCount--;
            } else {
                return false;
            }
        }
    }
    
    return true;
}

int main() {
    char s[] = "()";
    
    bool result = isValid(s);
    
    if (result) {
        printf("The string is valid.\n");
    } else {
        printf("The string is not valid.\n");
    }
    
    return 0;
}
