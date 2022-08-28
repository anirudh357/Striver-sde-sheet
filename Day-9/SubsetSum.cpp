// Link:- https://practice.geeksforgeeks.org/problems/subset-sums2234/1
#include<bits/stdc++.h> 
using namespace std; 


class Solution
{
    public:
        void func(int ind, int sum, vector<int> &arr, int N, vector<int> &sumSubset){
            if(ind==N){
                sumSubset.push_back(sum);
                return;
            }
            
            // pick the element
            func(ind+1, sum+arr[ind], arr, N, sumSubset);
            
            // don not pick the element
            func(ind+1, sum, arr, N, sumSubset);
        }
    
    
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> sumSubset;                       // data structure to store the ans.
        func(0,0,arr,N,sumSubset);
        sort(sumSubset.begin(), sumSubset.end());
        return sumSubset;
        
    }
};


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}