class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int size=nums2.size();

        unordered_map<int,int> mpp;

        stack<int> st;
        st.push(nums2[size-1]);
        mpp[nums2[size-1]]=-1;

        for(int i=size-2;i>=0;)
        {
            if(st.empty())
            {
                mpp[nums2[i]]=-1;
                st.push(nums2[i--]);
            }
            else
            {
                if(st.top()>nums2[i])
                {
                    mpp[nums2[i]]=st.top();
                    st.push(nums2[i--]);
                }    
                else
                {
                    st.pop();
                }
            }
        }

        for(int i=0;i<nums1.size();i++)
        {
            ans.push_back(mpp[nums1[i]]);
        }

        return ans;
    }
};