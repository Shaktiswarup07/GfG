//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int Solve(int idx, int sum, int nums[],int n, vector<vector<int>>&dp){
    if(sum<0) return 1e8;
    if(sum==0) return 0;
    if(idx==n) return 1e8;
    
    if(dp[idx][sum]!=-1) return dp[idx][sum];

    int mini=INT_MAX;
    //pick
    mini=min({mini,1+Solve(idx,sum-nums[idx],nums,n,dp), 1+Solve(idx+1,sum-nums[idx],nums,n,dp)});
    mini=min(mini,Solve(idx+1,sum,nums,n,dp));

    return dp[idx][sum]=mini;
}
	int minCoins(int coins[], int M, int V) 
	{ 
	    // Your code goes here
	    vector<vector<int>>dp(M+1, vector<int>(V+1,-1));
	    int x= Solve(0,V,coins,M,dp);
	    return x==1e8?-1:x;
	} 
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends