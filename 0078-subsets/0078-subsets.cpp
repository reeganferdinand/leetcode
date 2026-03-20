class Solution {
public:
    
    void func(vector<vector<int>> &ans,vector<int> &arr,int i,int n,vector<int> &nums)
    {
        if(i==n)
        {
            ans.push_back(arr);
            return;
        }
        arr.push_back(nums[i]);
        func(ans,arr,i+1,n,nums);
        arr.pop_back();
        func(ans,arr,i+1,n,nums);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
       
       vector<vector<int>> ans;
        int n=nums.size();
       vector<int> arr;
       func(ans,arr,0,n,nums);

       return ans;
    }
};