class Solution {
public:


    string invert(string s)
    {
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='0') s[i]='1';
            else s[i]='0';
        }

        return s;
    }

    char func(string s,int n,int i,int k)
    {
        if(i==n)
        {
            return s[k-1];
        }
        string s1=invert(s);
        reverse(s1.begin(),s1.end());
        s=s+"1"+s1;
        return func(s,n,i+1,k);

    }
    
    
    char findKthBit(int n, int k) {
        
        string s="0";
        return func(s,n,1,k);

    }
};