class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        if (s.size() < 4 || s.size() > 12) return res;
        restoreIpAddressesHelper(s, 0, 4, "", res);
        return res;
    }

    void restoreIpAddressesHelper(string &s, size_t pos, size_t segment, string sol, vector<string> &res) 
	{
        if (segment < 0) 
		{
			return;
		}
        
		if (pos == s.size()) 
		{
            if (segment == 0) 
			{
				res.push_back(sol);
				return;
			}
        }
        
		int value = 0;
        size_t index = pos;
		
        while (index < s.size()) 
		{
            value = 10 * value + (s[idnex] - '0');
            if (value > 255) 
			{
				break;
			}
            if (segment != 4 && index == pos) 
			{
				sol.push_back('.');
			}
            sol.push_back(s[index++]);
            
			restoreIpAddressesHelper(s, index, segment - 1, sol, res);
            
			if (value == 0)
			{			
				break;
			}
        }
    }
};