//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int Memsolve(int H[],int N,int curr,int prev,vector<vector<int>>&dp){
        if(curr==N) return 0;
        
        //include
        if(dp[curr][prev+1]!=-1) return dp[curr][prev+1];
        
        int take=0;
        if(prev==-1|| H[curr]>H[prev]){
            take=1+Memsolve(H,N,curr+1,curr,dp);
        }
        //exclude
        int nottake=0+Memsolve(H,N,curr+1,prev,dp);
        
        return dp[curr][prev+1]= max(take,nottake);
    } 
    int longestSubsequence(int N, int H[])
    {
       // your code here
       vector<vector<int>>dp(N,vector<int>(N+1,-1));
        // int x= solve(H,N,0,-1);
        int x=Memsolve(H,N,0,-1,dp);
        return x;
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends