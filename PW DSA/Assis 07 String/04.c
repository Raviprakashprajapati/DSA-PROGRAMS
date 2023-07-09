// <aside>
// 💡 **Question 4**

// Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

// **Example 1:**

// **Input:** s = "Let's take LeetCode contest"

// **Output:** "s'teL ekat edoCteeL tsetnoc"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverseWords(char* s) {
    int len = strlen(s);
    int start = 0;
    int end = 0;

    // Iterate through each character in the string
    while (end <= len) {
        if (s[end] == ' ' || s[end] == '\0') {
            // Found a word boundary or end of string
            int i = start;
            int j = end - 1;

            // Reverse the characters within the word
            while (i < j) {
                char temp = s[i];
                s[i] = s[j];
                s[j] = temp;
                i++;
                j--;
            }

            // Move to the next word
            start = end + 1;
        }

        end++;
    }
}

int main() {
    char s[] = "Let's take LeetCode contest";

    printf("Original string: %s\n", s);
    reverseWords(s);
    printf("Reversed string: %s\n", s);

    return 0;
}
