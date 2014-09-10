class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        map<string, list<string> > dict;
        vector<string> result;
        
        for (vector<string>::iterator it = strs.begin(); it != strs.end(); it++)
        {
            string sortedStr(*it);
            sort(sortedStr.begin(), sortedStr.end());
            dict[sortedStr].push_back(*it);
        }
    
        for (map<string, list<string> >::iterator mapIt = dict.begin(); mapIt != dict.end(); mapIt++)
        {
            if ((mapIt->second).size() > 1)
            {
                for (list<string>::iterator it = mapIt->second.begin(); it != mapIt->second.end(); it++)
                {
                    result.push_back(*it);
                }
            }
        }
        
        return result;
    }
};
