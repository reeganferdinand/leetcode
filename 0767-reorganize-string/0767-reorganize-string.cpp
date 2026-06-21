class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> freq;
        string ans;
        for(auto it:s)
        {
            freq[it]++;
        }

        for(auto &it:freq)
        {
            if(it.second> ((s.size()+1)/2))
            {
                return "";
            }
        }

        priority_queue<pair<int,char>> pq;
        for(auto it:freq)
        {
            pq.push({it.second,it.first});
        }

        

        pair<int,char> prev={0,'#'};

        while(!pq.empty())
        {
            auto temp=pq.top();
            pq.pop();

            ans+=temp.second;

            temp.first--;

            if(prev.first>0)
            {
                pq.push(prev);
            }

            prev=temp;

        } 

        return ans;
    }
};