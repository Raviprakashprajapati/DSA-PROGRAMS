// Question 2
// Alice has n candies, where the ith candy is of type candyType[i]. Alice noticed that she started to gain weight, so she visited a doctor. 

// The doctor advised Alice to only eat n / 2 of the candies she has (n is always even). Alice likes her candies very much, and she wants to eat the maximum number of different types of candies while still following the doctor's advice. 

// Given the integer array candyType of length n, return the maximum number of different types of candies she can eat if she only eats n / 2 of them.

// Example 1:
// Input: candyType = [1,1,2,2,3,3]
// Output: 3

// Explanation: Alice can only eat 6 / 2 = 3 candies. Since there are only 3 types, she can eat one of each type.


#include <stdio.h>
#include <stdlib.h>

int distributeCandies(int* candyType, int candyCount) {
    // Initialize a set to store the different types of candies
    int* candiesSet = (int*)calloc(200001, sizeof(int));
    int uniqueCandies = 0;

    // Iterate through the candyType array
    for (int i = 0; i < candyCount; i++) {
        int candy = candyType[i];
        
        // If the candy type is not already in the set, increment the uniqueCandies count
        if (candiesSet[candy + 100000] == 0) {
            uniqueCandies++;
            candiesSet[candy + 100000] = 1;
        }
    }
    
    // Calculate the maximum number of different types of candies Alice can eat
    int maxCandies = uniqueCandies < candyCount / 2 ? uniqueCandies : candyCount / 2;
    
    // Free the memory allocated for the candiesSet
    free(candiesSet);

    return maxCandies;
}

int main() {
    int candyType[] = {1, 1, 2, 2, 4,4,3,3,10,10,11,12};
    int candyCount = sizeof(candyType) / sizeof(candyType[0]);

    int maxCandies = distributeCandies(candyType, candyCount);
    printf("Maximum number of different types of candies Alice can eat: %d\n", maxCandies);

    return 0;
}
