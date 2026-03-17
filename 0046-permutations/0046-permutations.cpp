class Solution {
public:
    
    void func(vector<vector<int>> &ans,vector<int> &arr,int n,vector<int> &nums,map<int,int> &mpp )
    {
        
       
        if(arr.size()==n)
        {
            ans.push_back(arr);
            return;
        }

       


        for(int j=0;j<n;j++)
        {
            if(mpp[nums[j]]==0)
            {
                arr.push_back(nums[j]);
                mpp[nums[j]]=1;
                func(ans,arr,n,nums,mpp);
                mpp[nums[j]]=0;
                arr.pop_back();
            }
        }
    }
    
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> arr;
        map<int,int> mpp;

        for(auto it:nums)
        {
            mpp[it]=0;
        }


        int n=nums.size();

        func(ans,arr,n,nums,mpp);


        return ans;
    }
};