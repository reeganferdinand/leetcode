class Solution {
public:
    
    void func(int i,vector<vector<int>> &ans,vector<int> &arr,vector<int> nums,int n)
    {
        if(i==n)
        {
            ans.push_back(arr);
            return;
        }

        arr.push_back(nums[i]);
        func(i+1,ans,arr,nums,n);
        arr.pop_back();
        func(i+1,ans,arr,nums,n);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
       
       vector<vector<int>> ans;
        int n=nums.size();
       vector<int> arr;
       func(0,ans,arr,nums,n);

       return ans;
    }
};