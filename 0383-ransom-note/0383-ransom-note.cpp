class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> hash;

        for(auto it:magazine)
        {
            hash[it]++;
        }

        for(auto it:ransomNote)
        {
            if(hash[it]!=0)
            {
                hash[it]--;
            }
            else return false;
        }

        return true;
    }
};