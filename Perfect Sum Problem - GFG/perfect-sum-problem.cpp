//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{

	public:
	const int M=1e9+7;
	int Solve(int idx, int sum , int nums[], int n,int tar,vector<vector<int>>&dp){
        if(sum>tar) return 0;
        if(idx==n){
            if(sum==tar) return 1;
            else return 0;
        }
        if(dp[idx][sum]!=-1) return (dp[idx][sum])%M;
        return dp[idx][sum]=(Solve(idx+1,sum+nums[idx],nums,n,tar,dp)%M + Solve(idx+1,sum,nums,n,tar,dp)%M)%M;
    }
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        // int n=num.size();
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return Solve(0,0,arr,n,sum,dp);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends