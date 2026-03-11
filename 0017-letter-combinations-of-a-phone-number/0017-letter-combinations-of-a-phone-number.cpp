class Solution {
public:
    void solve(int index, string digits, vector<string>& ans, string temp, vector<string>& map)
    {
        if(index == digits.size())
        {
            ans.push_back(temp);
            return;
        }

        string letters = map[digits[index] - '0'];

        for(char c : letters)
        {
            solve(index + 1, digits, ans, temp + c, map);
        }
    }

    vector<string> letterCombinations(string digits) {

        vector<string> ans;
        if(digits.size() == 0) return ans;

        vector<string> map = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        solve(0, digits, ans, "", map);

        return ans;
    }
};