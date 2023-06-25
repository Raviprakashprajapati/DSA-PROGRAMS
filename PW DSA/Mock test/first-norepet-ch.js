// First Unique Character in a String

// Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

function findUnique(s) {
    const charCount = new Map();
  
    for (let i = 0; i < s.length; i++) {
      const char = s[i];
      charCount.set(char, (charCount.get(char) || 0) + 1);
    }
  
    for (let i = 0; i < s.length; i++) {
      const char = s[i];
      if (charCount.get(char) === 1) {
        return i;
      }
    }
  
    return -1;
  }
  const str = "leetcode";
  const index = findUnique(str);
  console.log(index); 
  