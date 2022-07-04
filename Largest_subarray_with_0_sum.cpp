Link:- https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1#
class Solution{
    public:
    int maxLen(vector<int>&a, int n)
    {   
        // Your code here
        unordered_map<int,int>mp;
        int csum=0;
        int fans=0;
        for(int i=0;i<n;i++){
            csum+=a[i];
            if(csum==0)
            {
                fans=max(fans,i+1);
            }
            else{
                if(mp.find(csum)!=mp.end())
                {
                    fans=max(fans,i-mp[csum]);
                }
                else{
                    mp[csum]=i;
                }
            }
        }
        return fans;
    }
};