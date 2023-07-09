// <aside>
// 💡 **Question 5**

// Given an array of characters chars, compress it using the following algorithm:

// Begin with an empty string s. For each group of **consecutive repeating characters** in chars:

// - If the group's length is 1, append the character to s.
// - Otherwise, append the character followed by the group's length.

// The compressed string s **should not be returned separately**, but instead, be stored **in the input character array chars**. Note that group lengths that are 10 or longer will be split into multiple characters in chars.

// After you are done **modifying the input array,** return *the new length of the array*.

// You must write an algorithm that uses only constant extra space.

// **Example 1:**

// **Input:** chars = ["a","a","b","b","c","c","c"]

// **Output:** Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]

// **Explanation:**

// The groups are "aa", "bb", and "ccc". This compresses to "a2b2c3".
#include <stdio.h>
#include <stdlib.h>

int compress(char *chars, int length) {
    int compressedIndex = 0;
    int currentCharIndex = 0;
    
    while (currentCharIndex < length) {
        char currentChar = chars[currentCharIndex];
        int count = 0;
        
        // Count the number of consecutive repeating characters
        while (currentCharIndex < length && chars[currentCharIndex] == currentChar) {
            count++;
            currentCharIndex++;
        }
        
        // Update the compressed string in-place
        chars[compressedIndex++] = currentChar;
        
        if (count > 1) {
            // Convert the count into characters
            char countStr[5];
            int countLen = sprintf(countStr, "%d", count);
            
            // Add the count to the compressed string in-place
            for (int i = 0; i < countLen; i++) {
                chars[compressedIndex++] = countStr[i];
            }
        }
    }
    
    return compressedIndex;  // Return the new length of the array
}

int main() {
    char chars[] = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    int length = sizeof(chars) / sizeof(chars[0]);
    
    int newLength = compress(chars, length);
    
    printf("The new length of the array is: %d\n", newLength);
    printf("The modified array is: [");
    for (int i = 0; i < newLength; i++) {
        printf("\"%c\"", chars[i]);
        if (i != newLength - 1) {
            printf(",");
        }
    }
    printf("]\n");
    
    return 0;
}
