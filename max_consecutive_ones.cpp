// Link:- https://leetcode.com/problems/max-consecutive-ones/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        // Warmup question in interview
        /* We maintain a variable count that keeps a track of the number of consecutive 1’s while traversing the array. The other variable max_count maintains the maximum number of 1’s, in other words, it maintains the answer.

1) We start traversing from the beginning of the array. Since we can encounter either a 1 or 0 there can be two situations:-

2)If  the value at the current index is equal to 1 we increase the value of count by one. After updating  the count variable if it becomes more than the max_count update the max_count.

3)If the value at the current index is equal to zero we make the variable count as 0 since there are no more consecutive ones. */
        int n=nums.size();
        int cnt=0;
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==1)
            {
                cnt++;
            }    
            else
            {
                cnt=0;
            }    
            maxi=max(maxi,cnt);
        }    
        
        return maxi;
        
        // Time Complexity - O(N), because iterate through an array of size n and Space Complexity - O(1) as we don't use any extra space.
    }
};