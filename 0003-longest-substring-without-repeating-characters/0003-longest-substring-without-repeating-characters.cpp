class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       unordered_map<char,int> mpp;
       int l=0;
       int r=0;
        int ans=0;
       while(l<=r && r<s.size())
       {
            if(mpp.find(s[r])!=mpp.end())
            {
                l=max(l,mpp[s[r]]+1);
            }
            mpp[s[r]]=r;
            ans=max(ans,r-l+1);
            r++;
            
       }

       return ans;
    }
};