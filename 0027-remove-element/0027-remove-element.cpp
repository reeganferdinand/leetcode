class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size()==0 ) return 0;
        
        int l=0;
        int n=nums.size()-1;
        int k=n+1;

        while(n>=0 && nums[n]==val )
        {
            n--;
            k--;
        }

        while(l<=n)
        {
            if(nums[l]==val)
            {
                if(nums[n]!=val)swap(nums[l],nums[n--]);
                k--;
                while(n>=0 && nums[n]==val) 
                {
                    n--;
                    k--;
                }
                
                
            }
            l++;
        }

        return k;
    }
};