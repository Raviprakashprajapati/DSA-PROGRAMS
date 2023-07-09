// <aside>
// 💡 **Question 2**

// Given a string num which represents an integer, return true *if* num *is a **strobogrammatic number***.

// A **strobogrammatic number** is a number that looks the same when rotated 180 degrees (looked at upside down).

// **Example 1:**

// **Input:** num = "69"

// **Output:**

// true

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isStrobogrammatic(char* num) {
    int len = strlen(num);

    for (int i = 0; i <= len / 2; i++) {
        char left = num[i];
        char right = num[len - 1 - i];

        // Check for invalid pairs
        if ((left == '6' && right != '9') || (left == '9' && right != '6') ||
            (left == '0' && right != '0') || (left == '1' && right != '1') ||
            (left == '8' && right != '8')) {
            return false;
        }
    }

    return true;
}

int main() {
    char num[] = "69";

    if (isStrobogrammatic(num)) {
        printf("The number is strobogrammatic.\n");
    } else {
        printf("The number is not strobogrammatic.\n");
    }

    return 0;
}
