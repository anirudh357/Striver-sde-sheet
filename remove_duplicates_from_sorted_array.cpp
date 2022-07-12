// Link:- https://leetcode.com/problems/remove-duplicates-from-sorted-array/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // Brute Force Approach
        // Hashset Used as hashSet only stores unique elements.
        /* Approach
           1) Declare a HashSet.
           2) Run a for loop from starting to the end.
           3) Put every element of the array in the set.
           4) Store size of the set in a variable K.
           5) Now put all elements of the set in the array from the starting of the array.
           6) Return K.
        */
//         set <int> set;
//         int n=nums.size();
//         for(int i=0;i<n;i++)
//         {
//             set.insert(nums[i]);
//         }    
//         int k=set.size();
//         int j=0;
//         for(int x:set)
//         {
//             nums[j++]=x;
//         }
        
//         return k;
        // Time Complexity - O(NlogN) + O(N) and Space Complexity - O(N)
        
        // Optimized Approach - Two pointers approach
        
        //Intuition: We can think of using two pointers ‘i’ and ‘j’, we move ‘j’ till we don’t get a number arr[j] which is different from arr[i]. As we got a unique number we will increase the i pointer and update its value by arr[j]. 
        /*
          Approach
          1) Take a variable i as 0;
          2) Use a for loop by using a variable ‘j’ from 1 to length of the array.
          3) If arr[j] != arr[i], increase ‘i’ and update arr[i] == arr[j].
          4) After completion of the loop return i+1, i.e size of the array of unique elements.
        */  
        
        if(nums.size()==0){
            return 0;
        }        
        int i=0;
        for(int j=1; j<nums.size();j++)
        {
            if(nums[j]!=nums[i])
            {
                i++;                // Update i and then nums[i]=nums[j], as they are different
                nums[i]=nums[j];
            }    
        }    
        return i+1;                 // Returns length
        // Time Complexity - O(N) and Space Complexity - O(1)
    }
};