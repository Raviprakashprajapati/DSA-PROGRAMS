// <aside>
// 💡 **Question 5**

// Given a string s and an integer k, reverse the first k characters for every 2k characters counting from the start of the string.

// If there are fewer than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and leave the other as original.

// **Example 1:**

// **Input:** s = "abcdefg", k = 2

// **Output:**

// "bacdfeg"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverseStr(char* str, int start, int end) {
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

char* reverseStrEveryK(char* s, int k) {
    int len = strlen(s);

    for (int i = 0; i < len; i += 2 * k) {
        int start = i;
        int end = (i + k - 1 < len) ? i + k - 1 : len - 1;
        reverseStr(s, start, end);
    }

    return s;
}

int main() {
    char s[] = "abcdefg";
    int k = 2;

    printf("Original string: %s\n", s);
    char* reversed = reverseStrEveryK(s, k);
    printf("Reversed string: %s\n", reversed);

    return 0;
}
