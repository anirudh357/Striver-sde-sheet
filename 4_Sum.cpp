Link:- https://leetcode.com/problems/4sum/
// class Solution {
// public:
//     vector<vector<int>> fourSum(vector<int>& nums, int target) {
// //    Sort + Three pointers and Binary search approach
// //    T.C - O(NlogN + N^3logN) and S.C - O(4*N)    
// //         int n=nums.size();
        
// //         sort(nums.begin(), nums.end());
        
// //         set<vector<int>> sv;
        
// //         for(int i=0;i<n;i++)
// //         {
// //             for(int j=i+1;j<n;j++)
// //             {
// //                 for(int k=j+1;k<n;k++)
// //                 {
// //                     int x = (long long)target - (long long)nums[i] - (long long)nums[j] - (long long)nums[k];
// //                     if(binary_search(nums.begin()+k+1, nums.end(), target))
// //                     {
// //                         vector<int> v;
// //                         v.push_back(nums[i]);
// //                         v.push_back(nums[j]);
// //                         v.push_back(nums[k]);
// //                         v.push_back(x);
// //                         sort(v.begin(), v.end());
// //                         sv.insert(v);
                        
// //                     }    
                    
                    
                    
// //                 }    
// //             }    
// //         }    
// //         vector<vector<int>> res(sv.begin(), sv.end());
                    
// //                     return res;
        
        
//         // Optimized Approach
// //         vector<vector<int>> res;
// //         if(nums.empty())
// //             return res;
// //         sort(nums.begin(), nums.end());
// //         int n=nums.size();
// //         for(int i=0;i<n;i++)
// //         {
// //             int target_3= target-nums[i];
// //             for(int j=i+1;j<n;j++)
// //             {
// //                 int target_2=target_3 - nums[j];
// //                 int front=j+1;
// //                 int back=n-1;
// //                 while(front<back)
// //                 {
// //                     int two_sum= nums[front]+nums[back];
                    
// //                     if(two_sum<target) front++;
// //                     else if(two_sum>target) back--;
// //                     else
// //                     {
// //                         vector<int> quadruplet(4,0);
// //                         quadruplet[0]= nums[i];
// //                         quadruplet[1]= nums[j];
// //                         quadruplet[2]= nums[front];
// //                         quadruplet[3]= nums[back];
// //                         res.push_back(quadruplet);
                        
// //                         while(front < back && nums[front]==quadruplet[2]) ++front;
// //                         while(front < back && nums[back]== quadruplet[3]) ++back;
                        
// //                     }   
                    
                    
// //                 }   
// //                 while(j+1<n && nums[j+1] == nums[j]) ++j;
                
// //             }    
// //             while(i+1<n && nums[i+1]==nums[i]) ++i;
// //         }    
// //         return res;
        
//     }
// };       

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(begin(nums), end(nums));
        return kSum(nums, target, 0, 4);
    }
	
    vector<vector<int>> kSum(vector<int>& nums, long long target, int str, int k) {
        vector<vector<int>> res;
        
        // If we have run out of numbers to add, return res.
        if (str == nums.size()) {
            return res;
        }
        
        // There are k remaining values to add to the sum. The 
        // average of these values is at least target / k.
        long long average_value = target / k;
        
        // We cannot obtain a sum of target if the smallest value
        // in nums is greater than target / k or if the largest 
        // value in nums is smaller than target / k.
        if  (nums[str] > average_value || average_value > nums.back()) {
            return res;
        }
            
        if (k == 2) {
            return twoSum(nums, target, str);
        }
    
        for (int i = str; i < nums.size(); ++i) {
            if (i == str || nums[i - 1] != nums[i]) {
                for (vector<int>& subset : kSum(nums, static_cast<long long>(target) - nums[i], i + 1, k - 1)) {
                    res.push_back({nums[i]});
                    res.back().insert(end(res.back()), begin(subset), end(subset));
                }
            }
        }
                                            
        return res;
    }
	
    vector<vector<int>> twoSum(vector<int>& nums, long long target, int str) {
        vector<vector<int>> res;
        int lo = str, hi = int(nums.size()) - 1;
    
        while (lo < hi) {
            int curr_sum = nums[lo] + nums[hi];
            if (curr_sum < target || (lo > str && nums[lo] == nums[lo - 1])) {
                ++lo;
            } else if (curr_sum > target || (hi < nums.size() - 1 && nums[hi] == nums[hi + 1])) {
                --hi;
            } else {
                res.push_back({ nums[lo++], nums[hi--] });
            }
        }
                                                           
        return res;
    }
};