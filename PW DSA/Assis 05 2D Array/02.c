// <aside>
// 💡 **Question 2**

// You have n coins and you want to build a staircase with these coins. The staircase consists of k rows where the ith row has exactly i coins. The last row of the staircase **may be** incomplete.

// Given the integer n, return *the number of **complete rows** of the staircase you will build*.

// **Example 1:**

// **Input:** n = 5

// **Output:** 2

// **Explanation:** Because the 3rd row is incomplete, we return 2.
#include <stdio.h>

int arrangeCoins(int n) {
    long long left = 0;
    long long right = n;
    long long mid, curr;

    while (left <= right) {
        mid = left + (right - left) / 2;
        curr = mid * (mid + 1) / 2;

        if (curr == n) {
            return mid;
        } else if (curr < n) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return right;
}

int main() {
    int n = 5;
    int completeRows = arrangeCoins(n);

    printf("Question 2: The number of complete rows in the staircase: %d\n", completeRows);

    return 0;
}
