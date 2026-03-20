class Solution {
public:
    bool isSubsequence(string s, string t) {
        int left=0;
        int right=0;


        int n=s.size();
        int m=t.size();

        while(left<n && right<m)
        {
            if(s[left]==t[right])
            {
                left++;
                right++;
            }
            else right++;
        }

        return left==n;
    }
};