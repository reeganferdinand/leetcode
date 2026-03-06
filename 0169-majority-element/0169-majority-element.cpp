class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        if(n == 1) return nums[0];

        int maxlen = 0;
        int maxele = nums[0];

        int l = 0;
        int h = 0;

        while(h < n)
        {
            if(nums[l] == nums[h])
            {
                h++;
            }
            else
            {
                int len = h - l;
                if(len > maxlen)
                {
                    maxlen = len;
                    maxele = nums[l];
                }
                l = h;
            }
        }

        // check last segment
        int len = h - l;
        if(len > maxlen)
        {
            maxlen = len;
            maxele = nums[l];
        }

        return maxele;
    }
};