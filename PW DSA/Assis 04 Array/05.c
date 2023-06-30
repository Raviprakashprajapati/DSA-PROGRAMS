
// 💡 **Question 5**
// You have n coins and you want to build a staircase with these coins. The staircase consists of k rows where the ith row has exactly i coins. The last row of the staircase **may be** incomplete.

// Given the integer n, return *the number of **complete rows** of the staircase you will build*.

// **Example 1:**

// []()

// ![v2.jpg](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/4bd91cfa-d2b1-47b3-8197-a72e8dcfff4b/v2.jpg)

// **Input:** n = 5

// **Output:** 2

// **Explanation:** Because the 3rd row is incomplete, we return 2.


#include <stdio.h>
#include <math.h>

int arrangeCoins(int n) {
    int k = (int)(sqrt(2 * (long)n + 0.25) - 0.5);
    return k;
}

int main() {
    int n = 5;

    int completeRows = arrangeCoins(n);

    printf("Output: %d\n", completeRows);

    return 0;
}
