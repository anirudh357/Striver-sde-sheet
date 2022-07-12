// Link:- https://leetcode.com/problems/trapping-rain-water/
class Solution {
public:
    int trap(vector<int>& height) {
        // Brute Force Approach
        // int n=height.size();
        // int watertrapped=0;
        // for(int i=0;i<n;i++)
        // {
        //     int leftmax = 0, rightmax = 0;
        //     int j=i;
        //     while(j>=0)
        //     {
        //         leftmax=max(leftmax, height[j]);
        //          j--;   
        //     }    
        //     j=i;
        //     while(j<n)
        //     {
        //         rightmax=max(rightmax, height[j]);
        //         j++;
        //     }    
        //     watertrapped+=min(leftmax, rightmax) - height[i];
        // }    
        // return watertrapped;
        // Time Complexity - O(N*N) and Space Complexity - O(1)
        
        
        // Optimized Approach - taking prefix and suffix
//         int n=height.size();
//         int prefix[n], suffix[n];
//         prefix[0]=height[0];
//         for(int i=1;i<n;i++)
//         {
//             prefix[i]=max(prefix[i-1], height[i]);   // why i-1 for starting from i
            
//         }    
//         suffix[n-1]=height[n-1];
//         for(int i=n-2; i>=0; i--)
//         {
//             suffix[i]=max(suffix[i+1], height[i]);  // why i+1 for starting at end and going previous:- doubt 
//         }   
//         int watertrapped=0;
//         for(int i=0;i<n;i++)
//         {
//             watertrapped+=min(prefix[i], suffix[i]) - height[i];
//         } 
//         return watertrapped;
// T.C - O(3*N) as we are traversing through the array only once +  O(2*N) for computing prefix and suffix array.
// S.C - O(N)+O(N) for prefix and suffix arrays.        
        
        // Optimized Solution - Two Pointer Approach
        int n = height.size();
        int left=0, right=n-1;
        int res=0;
        int leftmax=0, rightmax=0;
        
        while(left<=right)
        {
            if(height[left]<=height[right])
            {
                if(height[left]>=leftmax) {
                    leftmax=height[left];
                }
                else
                {
                    res+=leftmax-height[left];
                }  
                
                left++;
            }    
            
            else
            {
                if(height[right]>=rightmax)
                {
                    rightmax=height[right];
                }    
                else
                {
                    res+=rightmax-height[right];
                }  
                right--;
            }    
        }    
        return res;
        
        // Time Complexity - O(N), because we are using 2 pointer approach and Space Complexity - O(1), because we are not using anything extra.
        
    }};