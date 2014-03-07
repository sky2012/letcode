class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        int len1 = s1.size();
        int len2 = s2.size();
        int len3 = s3.size();
        
        if (len1 + len2 != len3)
        {
            return false;
        }
        
        int dp[len1+1][len2+1];
        
        dp[0][0] = true;
        
        for (int i = 1; i <= len1; i++)
        {
            dp[i][0] = ((s1[i-1] == s3[i-1]) ? true : false);
        }
        
        for (int j = 1; j <= len2; j++)
        {
            dp[0][j] = ((s2[j-1] == s3[j-1]) ? true: false);
        }
        
        for (int i = 1; i <= len1; i++)
        {
            for (int j = 1; j <= len2; j++)
            {
                dp[i][j] = (((dp[i-1][j] && s1[i-1] == s3[i+j-1])
                        || (dp[i][j-1] && s2[j-1] == s3[i+j-1]))
                        ? true : false);
            }
        }
        
        return dp[len1][len2];
    }
};