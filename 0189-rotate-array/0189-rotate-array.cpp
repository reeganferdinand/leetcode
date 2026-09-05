class Solution {
public:
    
    
    void rev_array(vector<int>& arr,int st,int end)
    {
        while(st<end)
        {
            swap(arr[st++],arr[end--]);
        }
    }
    
    
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        
        rev_array(nums,0,n-1);
        rev_array(nums,0,k-1);
        rev_array(nums,k,n-1);

    }
};