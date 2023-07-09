// <aside>
// 💡 **Question 7**

// Given an encoded string, return its decoded string.

// The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

// You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there will not be input like 3a or 2[4].

// The test cases are generated so that the length of the output will never exceed 105.

// **Example 1:**

// **Input:** s = "3[a]2[bc]"

// **Output:** "aaabcbc"

#include <stdio.h>
#include <stdlib.h>

char *decode_string(char *s) {
  char *result = malloc(sizeof(char) * 105);
  int i, j, count, n;

  i = 0;
  j = 0;
  while (s[i] != '\0') {
    if (s[i] >= '0' && s[i] <= '9') {
      count = 0;
      while (s[i] >= '0' && s[i] <= '9') {
        count = count * 10 + (s[i] - '0');
        i++;
      }
      for (n = 0; n < count; n++) {
        result[j++] = s[i++];
      }
    } else {
      result[j++] = s[i++];
    }
  }

  result[j] = '\0';
  return result;
}

int main() {
  char *s = "3[a]2[bc]";
  char *result = decode_string(s);
  printf("Decoded string: %s\n", result);
  free(result);
  return 0;
}
