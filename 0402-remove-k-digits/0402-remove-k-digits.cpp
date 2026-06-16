class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;

        for(int i=0;i<num.size();)
        {
            if(st.empty())
            {
                st.push(num[i]);
                i++;
            }
            else
            {
                char tp=st.top();
                if(k>0 && tp>num[i]) 
                {
                    st.pop();
                    k--;
                }
                else
                {
                    st.push(num[i]);
                    i++;
                }
            }
        }

        while(k>0 && !st.empty())
        {
            st.pop();
            k--;
        }

        string rev;

        while(!st.empty())
        {
            rev+=st.top();
            st.pop();
        }
        
        

        reverse(rev.begin(),rev.end());
        int j=0;

        while(j<rev.size() && (rev[j]=='0'))
        {
            j++;
        }

        
        string ans=rev.substr(j);
        return ans.empty()?"0":ans;
    }
};