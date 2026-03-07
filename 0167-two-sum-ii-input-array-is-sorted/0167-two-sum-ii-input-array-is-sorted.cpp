class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        int l=0,r=n-1;
        vector<int> ans(2);
        int sum=0;
        while(l<r)
        {
            sum=numbers[l]+numbers[r];

            if(sum>target)
            {
                r--;
            }
            else if(sum<target)
            {
                l++;
            }
            else
            {
                ans[0]=l+1;
                ans[1]=r+1;
                break;
            }
        }

        return ans;
    }
};