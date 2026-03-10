class Solution {
public:
    
    void func(vector<string>& ans,int open,int close,int n,string s)
    {
        if(s.size()==2*n)
        {
            ans.push_back(s);
            return;
        }

        if(open<n)
        {
            func(ans,open+1,close,n,s+"(");
        }

        if(close<open)
        {
            func(ans,open,close+1,n,s+")");
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;

        func(ans,0,0,n,"");

        return ans;
    }
};