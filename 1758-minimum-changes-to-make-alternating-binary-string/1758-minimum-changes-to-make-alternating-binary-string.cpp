class Solution {
public:
    int minOperations(string s) {
        

        int n=s.size();
        if(n==1) return 0;
        int count1=0,count2=0;

        char prev='0';

        for(int i=0;i<n;i++)
        {
            if(prev!=s[i]) 
            {
                count1++;
            }

            if(prev=='0') prev='1';
                else prev='0';
        }

        prev='1';

        for(int i=0;i<n;i++)
        {
            if(prev!=s[i]) 
            {
                count2++;
            }

            if(prev=='0') prev='1';
                else prev='0';
        }

        return min(count1,count2);

       
    }
};