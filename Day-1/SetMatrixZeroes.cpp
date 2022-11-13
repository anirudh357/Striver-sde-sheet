// Link:- https://leetcode.com/problems/set-matrix-zeroes/
class Solution {
public:
    // T.C - O(2*(N*M)) and S.C - O(1)
    void setZeroes(vector<vector<int>>& matrix) {
        int col0=1, rows=matrix.size(), cols=matrix[0].size();
        // 1st traverse
        for(int i=0;i<rows;i++){
            if(matrix[i][0]==0){
                 col0=0;   
            }
            // for the rest of the columns
            for(int j=1;j<cols;j++){
                 if(matrix[i][j]==0){
                     matrix[0][j]=0;
                     matrix[i][0]=0;
                 }
            }
        }
        // 2nd traverse - backwards
        for(int i=rows-1;i>=0;i--){
            for(int j=cols-1;j>=1;j--){
                if(matrix[i][0]==0 || matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
            if(col0==0) matrix[i][0]=0;
        }
        
        
    }
};