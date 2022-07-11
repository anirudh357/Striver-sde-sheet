// Link:- https://leetcode.com/problems/3sum/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //Brute force approach - Three Pointers Approach
        // vector<vector<int>> ans;
        // vector<int> temp;
        // int i,j,k;
        // for(i=0;i<nums.size()-2;i++)
        // {
        //     for(j=i+1;j<nums.size()-1;j++)
        //     {
        //         for(k=j+1;k<nums.size();k++)
        //         {
        //             temp.clear();
        //             if(nums[i]+nums[j]+nums[k]==0)
        //             {
        //                 temp.push_back(nums[i]);
        //                 temp.push_back(nums[j]);
        //                 temp.push_back(nums[k]);
        //             }    
        //             if(temp.size()!=0)
        //             {
        //                 ans.push_back(temp);
        //             }    
        //         }    
        //     }    
        // }    
        
        // return ans;
        // Time Complexity - O(N^3) and space complexity - O(3*K)
        
        
        
        // Optimized Approach - Two Pointers Approach
        // a+b+c=0 => b+c=-a  => so requires two pointers 
        // First sort the array and then keep the one pointer considered for a, then another one pointer lo(low) on extreme left , and third pointer hi(high) on extreme right and then iterate.
        // If one pointer on first then suppose b+c=2 and then if lo=-2 and hi=2 then low+hi=0, which is less than 2, so increase the -2 value, so move pointer move the lo pointer to one step ahead or towards right.
        // After finding out the set, then move both low and high by one step each, then lo iterate till gives better lo than previous and high till previous value skipped for no duplications and both get stopped when hi crosses lo or each other.
        // Then move pointer a to next number 1, we require set as b+c=1, repeat same process as above.
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size()-2;i++)        //here iterate upto third last because second last and last numbers are occupied with b and c. 
        {
            //For moving a
            if(i==0|| (i>0 && nums[i]!=nums[i-1]))
            {
                int lo=i+1, hi=nums.size()-1, sum=0-nums[i];
                while(lo<hi)
                {
                    if(nums[lo]+nums[hi]==sum)
                    {
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[lo]);
                        temp.push_back(nums[hi]);
                        ans.push_back(temp);
                      
                    while(lo<hi && nums[lo]==nums[lo+1]) lo++;
                    while(lo<hi && nums[hi]==nums[hi-1]) hi--;
                    
                    lo++; hi--;
                }    
                else if(nums[lo]+nums[hi]<sum) lo++;
                else hi--;
            }  
        }
    }      
        
        return ans;
        
        
        
        
    }
};