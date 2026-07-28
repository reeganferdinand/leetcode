class Solution {
public:
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> adj;
    unordered_map<string, int> level;

    void dfs(string word, string &beginWord, vector<string> &path) {
        if (word == beginWord) {
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            return;
        }

        for (auto &parent : adj[word]) {
            path.push_back(parent);
            dfs(parent, beginWord, path);
            path.pop_back();
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord,
                                       vector<string>& wordList) {

        unordered_set<string> st(wordList.begin(), wordList.end());

        if (st.find(endWord) == st.end())
            return {};

        queue<string> q;
        q.push(beginWord);
        level[beginWord] = 0;

        st.erase(beginWord);

        while (!q.empty()) {

            string word = q.front();
            q.pop();

            int currLevel = level[word];
            string temp = word;

            for (int i = 0; i < temp.size(); i++) {

                char original = temp[i];

                for (char ch = 'a'; ch <= 'z'; ch++) {

                    temp[i] = ch;

                    if (level.count(temp) && level[temp] == currLevel + 1) {
                        adj[temp].push_back(word);
                    }

                    if (st.find(temp) != st.end()) {

                        q.push(temp);
                        st.erase(temp);

                        level[temp] = currLevel + 1;
                        adj[temp].push_back(word);
                    }
                }

                temp[i] = original;
            }
        }

        if (!level.count(endWord))
            return {};

        vector<string> path;
        path.push_back(endWord);

        dfs(endWord, beginWord, path);

        return ans;
    }
};