class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (start == end)
        {
            return 0;
        }
        
        queue<pair<string, int> > wordQueue;
        wordQueue.push(make_pair(start, 1));
        dict.insert(end);
        
        while (!wordQueue.empty())
        {
            pair<string, int> current = wordQueue.front();
            wordQueue.pop();
            
            if (current.first == end)
            {
                return current.second;
            }
            
            vector<string> neighbor = wordNeighbor(current.first, dict);
            vector<string>::iterator it;
            
            for (it = neighbor.begin(); it != neighbor.end(); it++)
            {
                wordQueue.push(make_pair(*it, current.second + 1));
            }
            
        }
        
        return 0;
    }
    
    vector<string> wordNeighbor(const string &str, unordered_set<string> &dict)
    {
        vector<string> result;
        
        for (int i = 0; i < str.length(); i++)
        {
            string temp(str);
            
            for (int j = 0; j < 26; j++)
            {
                temp[i] = 'a' + j;
            
                if (dict.find(temp) != dict.end())
                {
                    result.push_back(temp);
                    dict.erase(temp);
                }
            }
        }
        
        return result;
    }
};