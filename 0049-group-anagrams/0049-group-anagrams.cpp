class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mpp;

        for(int i=0;i<strs.size();i++)
        {
            string str1 = strs[i];
            sort(str1.begin(), str1.end());

            mpp[str1].push_back(strs[i]);
        }

        vector<vector<string>> ans;

        for(auto it:mpp)
        {
            ans.push_back(it.second);
        }

        return ans;
    }
};