class Solution {
public:
    int getSum(int a, int b) {
        int sum = a ^ b;
        unsigned int carry = a & b; // Keeps compiler happy for negative numbers
        
        while(carry != 0) {
            // 1. Shift the carry to its proper column
            unsigned int shifted_carry = carry << 1; 
            
            // 2. Save the old sum so we can check it for overlaps
            int temp = sum;
            
            // 3. Add them together
            sum ^= shifted_carry;
            
            // 4. THE FIX: Check for overlaps using the SHIFTED carry!
            carry = temp & shifted_carry; 
        }
        
        return sum;
    }
};