// Link:- https://leetcode.com/problems/unique-paths/

class Solution {
public:
    int uniquePaths(int m, int n) {
        //Brute Force Approach
        // int countPaths(int i, int j, int m, int n)
        // int i,j;
        // if(i==(n-1) || j==(m-1)) return 1;
        // else if(i>=n && j>=m) return 0;
        // else return countPaths(i+1,j) + countPaths(i,j+1); 
        
        //DP Solution
//         int countPaths(int i, int j, int m, int n, vector<vector<int>> &dp)
//         {
//             if(i==(n-1) && j==(m-1)) return 1;
//             else if(i>=n || j>=m) return 0;
            
//             else if(dp[i][j]!=-1) return dp[i][j];
//             else return dp[i][j]= countPaths(i+1,j,m,n,dp) + countPaths(i,j+1,m,n,dp);
//         }
        
        // Combinatorics Solution
        int N=n+m-2;
        int r=m-1;
        double res=1;
        for(int i=1;i<=r;i++)
        {
            res=res*(N-r+i)/i;
            
            
        }
        return (int)res;
    }
};