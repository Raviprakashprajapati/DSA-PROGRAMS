// Given an array of meeting time intervals where intervals[i] = [starti, endi],
// determine if a person could attend all meetings.

// Example 1:
// Input: intervals = [[0,30],[5,10],[15,20]]
// Output: false

#include <stdio.h>
#include <stdbool.h>

// Definition of meeting time interval structure
typedef struct {
    int start;
    int end;
} Interval;

bool canAttendMeetings(Interval* intervals, int intervalsSize) {
    // Sort the intervals based on the start time
    for (int i = 0; i < intervalsSize - 1; i++) {
        for (int j = i + 1; j < intervalsSize; j++) {
            if (intervals[i].start > intervals[j].start) {
                Interval temp = intervals[i];
                intervals[i] = intervals[j];
                intervals[j] = temp;
            }
        }
    }

    // Check for overlapping intervals
    for (int i = 0; i < intervalsSize - 1; i++) {
        if (intervals[i].end > intervals[i + 1].start) {
            return false;
        }
    }

    return true;
}

int main() {
    Interval intervals[] = {{0, 30}, {5, 10}, {15, 20}};
    int intervalsSize = sizeof(intervals) / sizeof(intervals[0]);

    bool result = canAttendMeetings(intervals, intervalsSize);

    printf("Output: %s\n", result ? "true" : "false");

    return 0;
}
