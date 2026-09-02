class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int l=0,r=0;
        int maxsum;
        int sum;
        while(l<=r  && r<nums.size())
        {
            sum+=nums[r++];
            maxsum=max(sum,maxsum);
            while(sum<0)
            {
                sum=0;
            }
            
            
        }

        return maxsum;
    }
};