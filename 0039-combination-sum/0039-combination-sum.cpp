class Solution {
public:
    
    void func(vector<vector<int>> &ans,vector<int> &arr,int i,vector<int> &nums,int t)
    {
        if(i==nums.size()) return;
        
        if(t==0)
        {
            ans.push_back(arr);
            return;
        }

       if(nums[i]<=t) 
       {
        arr.push_back(nums[i]);
        t=t-nums[i];
        func(ans,arr,i,nums,t);
        t+=nums[i];
        arr.pop_back();
       }

       

       func(ans,arr,i+1,nums,t);
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> arr;
        vector<vector<int>> ans;

        func(ans,arr,0,candidates,target);

        return ans;
    }
};