class Solution {
public:
    
    double distance(vector<int>& p)
    {
        return sqrt(1LL * p[0] * p[0] +
                1LL * p[1] * p[1]);
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        priority_queue<pair<double,vector<int>>> pq;
        vector<vector<int>> ans;
        for(int i=0;i<points.size();i++)
        {
            pq.push({distance(points[i]),points[i]});

            if(pq.size()>k) pq.pop();
        }

        for(int i=0;i<k;i++)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};