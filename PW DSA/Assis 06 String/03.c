// <aside>
// 💡 **Question 3**

// Given an array of integers arr, return *true if and only if it is a valid mountain array*.

// Recall that arr is a mountain array if and only if:

// - arr.length >= 3
// - There exists some i with 0 < i < arr.length - 1 such that:
//     - arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
//     - arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
// **Example 1:**

// **Input:** arr = [2,1]

// **Output:**

// false

#include <stdbool.h>
#include <stdio.h>

bool validMountainArray(int* arr, int arrSize) {
    if (arrSize < 3) {
        return false;
    }
    
    int i = 0;
    
    // Check the increasing part of the array
    while (i < arrSize - 1 && arr[i] < arr[i + 1]) {
        i++;
    }
    
    // If the peak is the first or last element, it's not a valid mountain
    if (i == 0 || i == arrSize - 1) {
        return false;
    }
    
    // Check the decreasing part of the array
    while (i < arrSize - 1 && arr[i] > arr[i + 1]) {
        i++;
    }
    
    // If we reached the end of the array, it's a valid mountain
    return i == arrSize - 1;
}

int main() {
    int arr[] = {2, 1};
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    
    bool result = validMountainArray(arr, arrSize);
    
    printf("Output: %s\n", result ? "true" : "false");
    
    return 0;
}
