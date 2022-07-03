//Link:- https://leetcode.com/problems/majority-element/submissions/ 
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        /* Moore's Voting Algorithm
        int count=0;
        int candidate=0;
        
        for(int num:nums)
        {
            if(count==0)
            {
                candidate=num;
                count++;
            }    
            else if(num==candidate)
            {
                count +=1;
            }    
            else
            {
                count -=1;
            }    
        }    
        
        return candidate;*/
        // Hash Map Approach
        
        unordered_map<int,int> counter;
        
        for(int num:nums)
        {
            if(++counter[num]>nums.size()/2)
            {
                return num;
            }    
        }    
        
        return 0;
        
    }
};
