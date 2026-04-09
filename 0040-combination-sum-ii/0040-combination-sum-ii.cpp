class Solution {
public:
    
    void func(int i,vector<vector<int>> &ans,vector<int> &arr,vector<int> nums,long long  target)
    {
        if(target==0)
        {
            ans.push_back(arr);
            return;
        }
        

       for(int j=i;j<nums.size();j++)
       {
            if(j>i && nums[j]==nums[j-1]) continue;
            if(target<nums[j]) break;
            arr.push_back(nums[j]);
            func(j+1,ans,arr,nums,target-nums[j]);
            arr.pop_back();
       }


    }
    
    
    
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<int> arr;
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        func(0,ans,arr,nums,target);

        return ans;
    }
};