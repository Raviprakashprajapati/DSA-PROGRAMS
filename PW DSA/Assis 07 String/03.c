// <aside>
// 💡 **Question 3**

// Given two non-negative integers, num1 and num2 represented as string, return *the sum of* num1 *and* num2 *as a string*.

// You must solve the problem without using any built-in library for handling large integers (such as BigInteger). You must also not convert the inputs to integers directly.

// **Example 1:**

// **Input:** num1 = "11", num2 = "123"

// **Output:**

// "134"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* addStrings(char* num1, char* num2) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int maxSize = (len1 > len2) ? len1 : len2;
    int sumSize = maxSize + 1;  // Extra space for carry
    int* sum = (int*)malloc(sizeof(int) * sumSize);  // Array to store sum
    int carry = 0;  // Carry from previous digit
    int i, j, k;
  
    // Initialize the sum array with zeros
    for (i = 0; i < sumSize; i++) {
        sum[i] = 0;
    }

    // Perform digit-wise addition
    i = len1 - 1;
    j = len2 - 1;
    k = sumSize - 1;
    while (i >= 0 || j >= 0) {
        int digit1 = (i >= 0) ? num1[i] - '0' : 0;
        int digit2 = (j >= 0) ? num2[j] - '0' : 0;
        int digitSum = digit1 + digit2 + carry;
        sum[k] = digitSum % 10;
        carry = digitSum / 10;
        i--;
        j--;
        k--;
    }
  
    // Handle remaining carry, if any
    if (carry > 0) {
        sum[k] = carry;
    } else {
        // Shift the array to remove leading zeros
        for (i = 0; i < sumSize - 1; i++) {
            sum[i] = sum[i + 1];
        }
        sumSize--;
    }
  
    // Create a string to store the result
    char* result = (char*)malloc(sizeof(char) * (sumSize + 1));
  
    // Convert each digit to its character representation
    for (i = 0; i < sumSize; i++) {
        result[i] = sum[i] + '0';
    }
    result[sumSize] = '\0';  // Add null terminator to the string
  
    free(sum);  // Free the memory allocated for sum array
  
    return result;
}

int main() {
    char num1[] = "11";
    char num2[] = "123";

    char* sum = addStrings(num1, num2);
    printf("The sum is: %s\n", sum);

    free(sum);  // Free the memory allocated for the sum string

    return 0;
}
