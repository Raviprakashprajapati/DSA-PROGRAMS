
// 💡 **Question 8**

// You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. Check if these points make a straight line in the XY plane.

// **Example 1:**
// **Input:** coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]

// **Output:** true

#include <stdio.h>
#include <stdbool.h>

bool checkStraightLine(int** coordinates, int coordinatesSize, int* coordinatesColSize) {
    if (coordinatesSize <= 2) {
        return true;
    }

    int x0 = coordinates[0][0];
    int y0 = coordinates[0][1];
    int x1 = coordinates[1][0];
    int y1 = coordinates[1][1];

    for (int i = 2; i < coordinatesSize; i++) {
        int x = coordinates[i][0];
        int y = coordinates[i][1];

        if ((y1 - y0) * (x - x0) != (y - y0) * (x1 - x0)) {
            return false;
        }
    }

    return true;
}

int main() {
    int coordinates[][2] = {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}, {6, 7}};
    int coordinatesSize = sizeof(coordinates) / sizeof(coordinates[0]);
    int coordinatesColSize = sizeof(coordinates[0]) / sizeof(int);

    if (checkStraightLine(coordinates, coordinatesSize, &coordinatesColSize)) {
        printf("The points form a straight line.\n");
    } else {
        printf("The points do not form a straight line.\n");
    }

    return 0;
}
