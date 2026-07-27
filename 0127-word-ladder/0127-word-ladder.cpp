class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        int n=beginWord.size();
        unordered_set<string> st(wordList.begin(),wordList.end());

        //if(st.find(endWord)==st.end()) return 0;
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        st.erase(beginWord);

        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            string str=it.first;

            int level=it.second;
            if(str==endWord) return level;
            for(int j=0;j<n;j++)
            {
                str=it.first;
                for(char i='a';i<='z';i++)
                {   
                    str[j]=i;

                    if(st.find(str)!=st.end() && str!=it.first)
                    {
                        q.push({str,level+1});
                        st.erase(str);
                    }
                }
            }

        }

        return 0;
    }
};