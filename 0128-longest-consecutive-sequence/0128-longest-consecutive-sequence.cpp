class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if(nums.empty()) return 0;

        map<int,int> mpp;

        for(int num : nums)
        {
            mpp[num]++;
        }

        int count = 1;
        int ans = 1;

        auto it = mpp.begin();
        int prev = it->first;
        ++it;

        for(; it != mpp.end(); ++it)
        {
            if(it->first == prev + 1)
            {
                count++;
            }
            else
            {
                count = 1;
            }

            ans = max(ans, count);
            prev = it->first;
        }

        return ans;
    }
};