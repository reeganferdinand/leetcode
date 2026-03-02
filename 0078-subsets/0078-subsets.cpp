class Solution {
public:


    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        
        int n=nums.size();
        int subset=(1<<n);

        for(int i=0;i<subset;i++)
        {
            vector<int> nums1;

            for(int j=0;j<n;j++)
            {
                if(i&(1<<j))
                {
                    nums1.push_back(nums[n-j-1]);
                }
                
            }

            ans.push_back(nums1);
        }


        return ans;
    }
};