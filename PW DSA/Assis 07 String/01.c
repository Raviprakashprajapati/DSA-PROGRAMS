
// 💡 **Question 1**

// Given two strings s and t, *determine if they are isomorphic*.

// Two strings s and t are isomorphic if the characters in s can be replaced to get t.

// All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

// **Example 1:**

// **Input:** s = "egg", t = "add"

// **Output:** true


#include <stdio.h>
#include <stdbool.h>

#define MAX_CHARS 256

bool areIsomorphic(char* s, char* t) {
    int map_s[MAX_CHARS] = { 0 }; // To store mapping from s to t
    int map_t[MAX_CHARS] = { 0 }; // To store mapping from t to s

    for (int i = 0; s[i] != '\0'; i++) {
        char ch_s = s[i];
        char ch_t = t[i];

        // If the characters are already mapped differently
        if (map_s[ch_s] != map_t[ch_t]) {
            return false;
        }

        // If the characters are not mapped yet
        if (map_s[ch_s] == 0 && map_t[ch_t] == 0) {
            map_s[ch_s] = ch_t;
            map_t[ch_t] = ch_s;
        }
    }

    return true;
}

int main() {
    char s[] = "egg";
    char t[] = "add";

    if (areIsomorphic(s, t)) {
        printf("The strings are isomorphic.\n");
    } else {
        printf("The strings are not isomorphic.\n");
    }

    return 0;
}

