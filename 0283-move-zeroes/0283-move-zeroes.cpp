class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int l=0;
        while(l<nums.size() && nums[l]!=0)
        {
            l++;
        }

        int r=l;
        while(r<nums.size() && nums[r]==0)
        {
            r++;
        }

        while(r<nums.size())
        {
            if(nums[r]!=0)
            {
                swap(nums[l],nums[r]);
                l++;
            }

            r++;
        }







    }
};