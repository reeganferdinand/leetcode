class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count=1;

        int l=0,r=1;

        while(l<=r && r<nums.size())
        {
            if(nums[l]!=nums[r])
            {
                count++;
                nums[++l]=nums[r];
            }

            r++;
        }


        return count;
    }
};
