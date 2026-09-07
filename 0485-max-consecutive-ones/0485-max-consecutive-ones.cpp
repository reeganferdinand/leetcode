class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi=0;

        int l=0,r=0;

        while(r<nums.size())
        {
            if(nums[r]==1)
            {
                maxi=max(maxi,r-l+1);
            }
            else l=r+1;

            r++;
        }

        return maxi;
    }
};