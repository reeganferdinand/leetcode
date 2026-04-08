class Solution {
public:
    
    void func(int i,vector<vector<int>> &ans,vector<int> &arr,vector<int> nums,int target)
    {
        if(target==0)
        {
            ans.push_back(arr);
            return;
        }
        if(i==nums.size()) return;

       if (nums[i] <= target)
        {
            arr.push_back(nums[i]);
            func(i, ans, arr, nums, target - nums[i]);
            arr.pop_back();
        }

        // Not pick
        func(i + 1, ans, arr, nums, target);

    }
    
    
    
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> arr;
        vector<vector<int>> ans;

        func(0,ans,arr,nums,target);

        return ans;
    }
};