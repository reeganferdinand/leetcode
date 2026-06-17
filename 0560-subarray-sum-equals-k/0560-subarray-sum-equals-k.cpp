class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
      int count=0;

      unordered_map<int,int> hash;

      int sum=0;
    
      for(int i=0;i<nums.size();i++)
      {
        sum+=nums[i];
        if(sum==k) count+=1;
        int remove=sum-k;
        if(hash.find(remove)!=hash.end())
        {
            count+=hash[remove];
        }

        hash[sum]++;
      }

      return count;
   }
};