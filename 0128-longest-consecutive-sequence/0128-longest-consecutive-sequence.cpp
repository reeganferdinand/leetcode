class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> st(nums.begin(), nums.end());
        int ans=0;
        for(auto it:st)
        {
            if(st.find(it-1)==st.end())
            {
                int start=it;
                int count=1;

                while(st.find(start)!=st.end())
                {
                    count++;
                    start++;
                }

                ans=max(ans,count-1);
            }
        }

        return ans;
    }
};