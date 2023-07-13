//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    int Solve(int temp, int target, vector<int>&dp){
        if(temp==target) return 0;
        if(dp[temp]!=-1) return dp[temp];
        int ans=INT_MAX;
        if(temp+1<=target) ans=min(ans,1+Solve(temp+1,target,dp));
        if(temp*2<=target) ans=min(ans,1+Solve(temp*2,target,dp));
        return dp[temp]=ans;
    }
    int minOperation(int n)
    {
        //code here.
        vector<int>dp(n+1,-1);
        return Solve(1,n,dp)+1;
        // int ops=0;
        // while(n){
        //     if(n%2==0){
        //         n/=2;
        //     }
        //     else{
        //         n-=1;
        //     }
        //     ops++;
        // }
        // return ops;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	    {
	        int n;
	        cin>>n;
	        Solution ob;
	        cout<<ob.minOperation(n)<<endl;
	    }
}
// } Driver Code Ends