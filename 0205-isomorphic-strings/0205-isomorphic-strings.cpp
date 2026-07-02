class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> mpp;
        unordered_map<char,char> mpp1;

        int size=s.size();
        for(int i=0;i<size;i++)
        {
            //ck 1
            if(mpp.find(s[i])!=mpp.end())
            {
                if(mpp[s[i]]!=t[i]) return false;
            }

            //ck 2
            if(mpp1.find(t[i])!=mpp1.end())
            {
                if(mpp1[t[i]]!=s[i]) return false;
            }

            mpp[s[i]]=t[i];
            mpp1[t[i]]=s[i];
        }

        return true;
    }
};