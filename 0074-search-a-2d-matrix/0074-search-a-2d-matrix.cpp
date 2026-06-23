class Solution {
public:
    
    bool find(vector<int> nums,int target)
    {
        int low=0;
        int high=nums.size()-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;

            if(nums[mid]==target) return true;

            else if(target < nums[mid]) high=mid-1;
            else low=mid+1;
        }

        return false;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int low=0;
        int high=n-1;
        bool ans=false;
        while(low<=high)
        {
            int mid=low+(high-low)/2;

            int n1=matrix[mid].size();

            if(find(matrix[mid],target)==true)
            {
                return true;
            }
            else if(target<matrix[mid][0])
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }

        return ans;
    }
};