class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int sum=0;

        unordered_map<int,int>mpp;

        mpp[nums[0]]=0;
        for(int i=1;i<nums.size();i++)
        {
            int diff=target-nums[i];
            if(mpp.find(diff)!=mpp.end())
            {
                return {mpp[diff],i};
            }
            mpp[nums[i]]=i;
        }

        return {-1,-1};
    }
};