class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        long long sum=0;
        long long pro=1;
        int ans=-1;
        int n=nums.size();

        for(int i=0;i<n;i++)
            {
                sum+=nums[i];
            }

        for(int i=n-1;i>=0;i--)
            {
                sum-=nums[i];
                if(sum==pro) ans=i;
                if(pro > sum) break;
                if (pro > LLONG_MAX / nums[i]) 
                {
                    pro=LLONG_MAX;
                }
                else pro*=nums[i];
            }

        return ans;


        
    }
};