class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        stack<int> st;
        int size=arr.size();
        vector<int> ans(size);
        
        int i=size-1;
        
        ans[i--]=0;
        st.push(size-1);
        
        for(int j=size-2;j>=0;)
        {
            if(st.empty())
            {
                ans[i--]=0;
                st.push(j--);
            }
            else
            {
                if(arr[st.top()]>arr[j])
                {
                    ans[i--]= st.top()-j;
                    st.push(j--);
                }
                else
                {
                    st.pop();
                }
            }
        }
        
        return ans;
    }
};