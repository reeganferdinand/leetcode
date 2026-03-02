class Solution {
public:

    void func(vector<vector<int>> &ans, int ind, vector<int>& nums, 
              vector<int>& arr, int n)
    {
        if(ind >= n)
        {
            ans.push_back(arr);
            return;
        }

        // Take element
        arr.push_back(nums[ind]);
        func(ans, ind+1, nums, arr, n);

        // Not take element
        arr.pop_back();
        func(ans, ind+1, nums, arr, n);
    }    
    
    vector<vector<int>> subsets(vector<int>& nums) {
       
       int n = nums.size();   
       vector<vector<int>> ans;
       vector<int> arr;

       func(ans, 0, nums, arr, n);

       return ans;
    }
};