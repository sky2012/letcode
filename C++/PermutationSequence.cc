class Solution {
public:
    string getPermutation(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> vect;
        
        for (int i = 1; i <= n; i++)
        {
            vect.push_back(i);
        }
        
        for (int i = 1; i < k; i++)
        {
            getNextPermuation(vect);
        }
        
        string result = "";
        
        for (int i = 0; i < vect.size(); i++)
        {
            result.push_back(vect[i] + '0');
        }
        
        return result;
    }
    
    void getNextPermuation(vector<int>& vect)
    {
        int len = vect.size();
        
        if (len == 0)
        {
            return;
        }
        
        sort(vect.begin(), vect.end());
        
        int i = len - 2;
        while (i >= 0)
        {
            if (vect[i] < vect[i + 1])
            {
                break;
            }
            i--;
        }
        if (i == -1)
        {
            reverse(vect.begin(), vect.end());
            return;
        }
        
        int j = len - 1;
        
        while (j > i)
        {
            if (vect[j] > vect[i])
            {
                break;
            }
            j--;
        }
        
        swap(vect[j], vect[i]);
        reverse(vect.begin() + i + 1, vect.end());
    }
};