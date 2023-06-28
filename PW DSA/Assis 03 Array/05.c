// <aside>
// 💡 **Question 5**
// You are given a large integer represented as an integer array digits, where each
// digits[i] is the ith digit of the integer. The digits are ordered from most significant
// to least significant in left-to-right order. The large integer does not contain any
// leading 0's.

// Increment the large integer by one and return the resulting array of digits.

// **Example 1:**
// Input: digits = [1,2,3]
// Output: [1,2,4]

// **Explanation:** The array represents the integer 123.
// Incrementing by one gives 123 + 1 = 124.
// Thus, the result should be [1,2,4].

// </aside>



#include <stdio.h>
#include <stdlib.h>

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    // Check if the last digit is less than 9
    if (digits[digitsSize - 1] < 9) {
        digits[digitsSize - 1]++;
        *returnSize = digitsSize;
        return digits;
    }

    int carry = 1;
    for (int i = digitsSize - 1; i >= 0; i--) {
        if (digits[i] + carry > 9) {
            digits[i] = 0;
            carry = 1;
        } else {
            digits[i]++;
            carry = 0;
            break;
        }
    }

    // If carry is still 1, we need to create a new array with an additional digit
    if (carry == 1) {
        int* result = (int*)malloc((digitsSize + 1) * sizeof(int));
        result[0] = 1;
        for (int i = 1; i <= digitsSize; i++) {
            result[i] = digits[i - 1];
        }
        *returnSize = digitsSize + 1;
        return result;
    } else {
        *returnSize = digitsSize;
        return digits;
    }
}

void printArray(int* digits, int digitsSize) {
    printf("[");
    for (int i = 0; i < digitsSize; i++) {
        printf("%d", digits[i]);
        if (i != digitsSize - 1)
            printf(", ");
    }
    printf("]\n");
}

int main() {
    int digits[] = {1, 2, 3};
    int digitsSize = sizeof(digits) / sizeof(digits[0]);

    printf("Input: ");
    printArray(digits, digitsSize);

    int returnSize;
    int* result = plusOne(digits, digitsSize, &returnSize);

    printf("Output: ");
    printArray(result, returnSize);

    free(result);

    return 0;
}
