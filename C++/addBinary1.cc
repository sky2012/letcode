class Solution {
public:
    string addBinary(string a, string b) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len1 = a.size();
        int len2 = b.size();
        
        string result;
        result.clear();
        int carry = 0;
        int sum = 0;
        int digit = 0;
        
        while (len1 > 0 || len2 > 0)
        {
            int value1 = (len1 > 0 ? a[len1-1] - '0' : 0);
            int value2 = (len2 > 0 ? b[len2-1] - '0' : 0);
            
            len1--;
            len2--;
            
            sum = value1 + value2 + carry;
            digit = sum % 2;
            carry = sum / 2;
            
            result.push_back(digit + '0');
        }
        
        if (carry == 1)
        {
            result.push_back('1');
        }
        
        reverse(result.begin(), result.end());
        
        return result;
    }
};