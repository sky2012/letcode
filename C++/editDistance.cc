class Solution {
public:
    int minDistance(string word1, string word2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len1 = word1.length();
        int len2 = word2.length();
        
        int dp[len1 + 1][len2 + 1];
        dp[0][0] = 0;
        
        for (int i = 1; i <= len1; i++)
        {
            dp[i][0] = i;
        }
        
        for (int j = 1; j <= len2; j++)
        {
            dp[0][j] = j;
        }
        
        for (int i = 1; i <= len1; i++)
        {
            for (int j = 1; j <= len2; j++)
            {
                dp[i][j] = min(min(dp[i - 1][j] + 1, dp[i][j - 1] + 1), dp[i - 1][j - 1] + (word1[i - 1] != word2[j - 1])); 
            }
        }
        
        return dp[len1][len2];   
    }
};