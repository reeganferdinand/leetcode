class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int size=tasks.size();
        priority_queue<pair<long,long> ,
                vector<pair<long,long>>,
                greater<pair<long,long>>> pq;

        vector<vector<long>> arr;// too store enquetime,pro time and inedx

        for(int i=0;i<size;i++)
        {
            arr.push_back({tasks[i][0],tasks[i][1],i});
        }

        sort(arr.begin(),arr.end());

        long time=0;
        int i=0;
        vector<int> ans;

        while(i<size || !pq.empty())
        {
            if(pq.empty() && arr[i][0]>time)
            {
                time=arr[i][0];
            }

            while(i<size && arr[i][0]<=time)
            {
                pq.push({arr[i][1],arr[i][2]});
                i++;
            }

            auto temp=pq.top();
            pq.pop();

            ans.push_back(temp.second);

            time+=temp.first;
        }

        return ans;


    }
};