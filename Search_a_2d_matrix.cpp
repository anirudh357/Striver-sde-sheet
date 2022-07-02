//Link:- https://leetcode.com/problems/search-a-2d-matrix/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        /*if(!matrix.size())
            return false;
        int m=matrix.size();
        int n=matrix[0].size();
        int lo=0;
        int hi=(n*m)-1;
        
        while(lo<=hi)
        {
            int mid=(lo + (hi-lo))/2;
            if(matrix[mid/m][mid%m]==target)
            {
                return mid;
            }    
            else if(matrix[mid/m][mid%m]<target)
            {
                lo=mid+1;
            }    
            else
            {
                hi=mid-1;
            }    
        } 
        
        return false;
    }*/
    int rows=matrix.size();
    int cols=matrix[0].size();
    int row=0;
    int col=cols-1;
     
    while(row < rows && col >-1)
    {
        int curr=matrix[row][col];
        if(curr==target)
        {
            return true;
        }    
        else if(curr<target)
        {
            row++;
        } 
        else
        {
            col--;
        }    
    }    
    return false;   } 
};