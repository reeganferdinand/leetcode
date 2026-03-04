class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int k=1;

        int l=0;
        int h=1;

        while(h<n)
        {
            if(nums[l]!=nums[h]) 
            {
                nums[++l]=nums[h];
                k++;
                h++;
            }
            else
            {
                h++;
            }
        }

        return k;
    }
};