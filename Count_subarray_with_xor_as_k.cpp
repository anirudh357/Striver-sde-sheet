//Link :- https://www.interviewbit.com/problems/subarray-with-given-xor/
//Brute Force Approach
// int Solution::solve(vector<int> &A, int B) {
//     long long int c=0;
//     for(int i=0;i<A.size();i++)
//     {
//         int curr_xor=0;
//         for(int j=i;j<A.size();j++)
//         {
//             curr_xor^=A[j];
//             if(curr_xor==B) c++;
//         }
//     }
//     return c;
// }

int Solution::solve(vector<int> &A, int B) {
    map<int, int> freq;
    int xorr=0;
    long long int count=0;
    for(auto it:A)
    {
        xorr=xorr^it;
        
        if(xorr==B) count++;
        
    
    
    if(freq.find(xorr^B)!=freq.end())
    {
        count=count+freq[xorr^B];
    }    
        freq[xorr]+=1;
    
    }
    return count;
}    