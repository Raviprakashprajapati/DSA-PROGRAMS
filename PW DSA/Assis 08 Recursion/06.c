// <aside>
// 💡 **Question 6**

// Given two strings s and p, return *an array of all the start indices of* p*'s anagrams in* s. You may return the answer in **any order**.

// An **Anagram** is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

// **Example 1:**

// **Input:** s = "cbaebabacd", p = "abc"

// **Output:** [0,6]

// **Explanation:**

// The substring with start index = 0 is "cba", which is an anagram of "abc".

// The substring with start index = 6 is "bac", which is an anagram of "abc".
#include <stdio.h>
#include <stdlib.h>

int main() {
  char *s = "cbaebabacd";
  char *p = "abc";
  int n = strlen(s);
  int m = strlen(p);
  int *indices = malloc(sizeof(int) * n);
  int i, j, count, found;

  for (i = 0; i < n; i++) {
    count = 0;
    found = 1;
    for (j = 0; j < m; j++) {
      if (s[i + j] != p[j]) {
        count++;
      }
      if (count > 1) {
        found = 0;
        break;
      }
    }
    if (found) {
      indices[i] = i;
    }
  }

  int size = 0;
  for (i = 0; i < n; i++) {
    if (indices[i] != 0) {
      size++;
    }
  }

  int *result = malloc(sizeof(int) * size);
  for (i = 0, j = 0; i < n; i++) {
    if (indices[i] != 0) {
      result[j++] = indices[i];
    }
  }

  for (i = 0; i < size; i++) {
    printf("%d ", result[i]);
  }
  printf("\n");
  free(indices);
  free(result);
  return 0;
}
