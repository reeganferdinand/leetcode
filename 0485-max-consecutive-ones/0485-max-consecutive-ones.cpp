class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi=0;

        int l=0;

        while(l<nums.size() && nums[l]==0) l++;

        int r=l;

        while(l<=r && r<nums.size())
        {
            if(nums[r]==1)
            {
                maxi=max(r-l+1,maxi);
            }
            else l=r+1;
            r++;
        }

        return maxi;
    }
};