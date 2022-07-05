//Link:- https://leetcode.com/problems/longest-substring-without-repeating-characters/submissions/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    //     Approach 1 - Optimized
    //     int n=s.length();
    //     if(n==0)
    //         return 0;
    //     set<char> st;
    //     int maxsize=0;
    //     int i=0,j=0;
    //     while(j<n)
    //     {
    //         if(st.count(s[j])==0)
    //         {
    //             st.insert(s[j]);
    //             maxsize=max(maxsize,(int)st.size());
    //             j++;
    //         }
    //         else
    //         {
    //             st.erase(s[i]);
    //             i++;
    //         }
    //     }
    //     return maxsize;
    
        
        // Optimized Approach - 2 Hashmap
        vector<int> mpp(256, -1);
        
        int left=0, right=0;
        int n=s.size();
        int length=0;
        while(right<n)
        {
            if(mpp[s[right]]!=-1)
            {
                left=max(mpp[s[right]]+1, left);
            }    
            
            mpp[s[right]]=right;
            
            length=max(length, right-left+1);
            right++;
        } 
        return length;
    }
};