//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int Solve(int W, int n, int wt[], int val[], vector<vector<int>>&dp){
        if(n==0 || W==0) return 0;
        
        if(dp[W][n]!=-1) return dp[W][n];
        int ntake=Solve(W,n-1,wt,val,dp);
        int take=INT_MIN;
        if(W>=wt[n-1]) take=val[n-1]+Solve(W-wt[n-1],n-1,wt,val,dp);
        return dp[W][n]=max(take,ntake);
    }
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>>dp(W+1,vector<int>(n+1,-1));
       return Solve(W,n,wt,val,dp);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends