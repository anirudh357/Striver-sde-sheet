//Link:- https://leetcode.com/problems/two-sum/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Brute Force Approach
        // T.C - O(N^2) and S.C - O(1)
        // vector<int> res;
        // for(int i=0;i<nums.size();i++)
        // {
        //     for(int j=i+1;j<nums.size();j++)
        //     {
        //         if(nums[i]+nums[j]==target)
        //         {
        //             res.emplace_back(i);
        //             res.emplace_back(j);
        //             break;
        //         }    
        //     }    
        // }    
        // return res;
        
        // Two pinters Approach
        // T.C - O(NlogN) and S.C - O(N)
//            vector<int> res, store;
//            store=nums; //              sort(store.begin(), store.end());
//            int left=0, right=nums.size()-1;
//            int num1,num2;        
//            while(left<right)
//            {
//                    if(nums[left]+nums[right]==target)
//                    {
//                        num1=nums[left];
//                        num2=nums[right];
//                    }    
//                    else if(nums[left]+nums[right]>target)
//                    {
//                        right--;
//                    }    
//                    else
//                    {
//                        left++;
//                    }    
//            }    
        
//            for(int i; i<nums.size(); i++)
//            {
//                if(nums[left]==num1)
//                   res.emplace_back(i);
//                else if(nums[right]==num2)
//                   res.emplace_back(i);
//                break;
//            }    
        
          
//          return res;
        
        // Hashmap Approach - Most Optimized
        // T.C - O(N) and S.C - O(N)
        vector<int> res;
        unordered_map<int, int> mpp;
        
        for(int i=0;i<nums.size();i++)
        {
            if(mpp.find(target-nums[i]) != mpp.end())
            {
                res.push_back(mpp[target-nums[i]]);
                res.push_back(i);
                break;
            }    
            mpp[nums[i]]=i;
        }    
        return res;
    }
};