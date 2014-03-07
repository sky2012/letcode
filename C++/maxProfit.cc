class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (prices.empty() || prices.size() == 1)
        {
            return 0;
        }
        
        
        int low = prices[0];
        int profit = 0;
        int maxProfit = 0;
        
        vector<int>::iterator it;
        
        for (it = prices.begin() + 1; it != prices.end(); it++)
        {
            if (*it < low)
            {
                low = *it;
            }
            
            profit = *it - low;
               
            if (profit > maxProfit)
            {
                maxProfit = profit;
            }
        }
        
        return maxProfit;
    }
};

// test cases

input	output	expected	
[]	0	0	
   
[1]	0	0	
   
[1,2]	1	1	
   
[2,1]	0	0	
   
[3,3]	0	0	
   
[1,2,4]	3	3	
   
[1,4,2]	3	3	
   
[2,1,4]	3	3	
   
[2,4,1]	2	2	
   
[4,1,2]	1	1	
   
[4,2,1]	0	0	
   
[2,2,5]	3	3	
   
[1,1,0]	0	0	
   
[2,1,2,0,1]	1	1	
   
[3,2,6,5,0,3]	4	4	
   
[6,1,3,2,4,7]	6	6	
   
[2,1,4,5,2,9,7]	8	8	
   
[2,1,2,1,0,0,1]	1	1	
   
[2,1,2,1,0,1,2]	2	2	
   
[3,3,5,0,0,3,1,4]	4	4	
   
[1,2,4,2,5,7,2,4,9,0]	8	8	
   
[1,2,4,2,5,7,2,4,9,0,9]	9	9	
   
Run Status: Accepted!