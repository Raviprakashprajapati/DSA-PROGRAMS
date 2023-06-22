
// 💡 **Q4.** You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.

// Increment the large integer by one and return the resulting array of digits.
// **Example 1:**
// Input: digits = [1,2,3]
// Output: [1,2,4]
// **Explanation:** The array represents the integer 123.

// Incrementing by one gives 123 + 1 = 124.
// Thus, the result should be [1,2,4].



int main() {
    int digits[] = {1, 9, 9,9};
    int size = sizeof(digits) / sizeof(digits[0]);
    int newSize = size;
    if (digits[size-1]<9)
    {
         for (int i = 0; i <= size; i++)
    {
        if (i==size)
        {
            digits[i-1] =digits[i-1]+1;
        }
        
    }
    }
    else
    {
        int carry = 1;
        for (int i =size-1; i>=0; i--)
        {
            int digitSum = digits[i]+carry;
            digits[i]  =digitSum%10;
            carry = digitSum/10;
             
        }
        

    }
    
   

    for (int i = 0; i < size; i++)
    {
        printf("%d  ",digits[i]);
    }
    
    
    
   
    
    return 0;
}
