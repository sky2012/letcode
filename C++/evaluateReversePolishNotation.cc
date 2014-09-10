class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> vals;
        set<string> ops;
        ops.insert("+");
        ops.insert("-");
        ops.insert("*");
        ops.insert("/");
        
        for (vector<string>::iterator it = tokens.begin(); it != tokens.end(); it++)
        {
            if (ops.find(*it) != ops.end())
            {
                int a = vals.top();
                vals.pop();
                int b = vals.top();
                vals.pop();
                
                switch (it->at(0))
                {
                    case '+':
                        vals.push(b + a);
                        break;
                    case '-':
                        vals.push(b - a);
                        break;
                    case '*':
                        vals.push(b * a);
                        break;
                    case '/':
                        vals.push(b / a);
                        break;
                }
            }
            else
            {
                int val = atoi(*it);
                vals.push(val);
            }
        }
        
        return vals.top();
    }
    
    int atoi(string str)
    {
        int len = str.size();
        int value = 0;
        int sign = 1;
        
        int i = 0;
        if (str[i] == '-')
        {
            sign = -1;
        }
        
        if (str[i] == '+' || str[i] == '-')
        {
            i++;
        }
        
        for (; i < len; i++)
        {
            value = str[i] - '0' + value * 10;
        }
        
        return sign * value;
    }
};
