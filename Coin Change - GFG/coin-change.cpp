//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int Solve(int idx, int sum, int n, int coins[],vector<vector<long long int>>&dp){
        if(idx==n){
            if(sum==0) return 1;
            else return 0;
        }
        if(dp[idx][sum]!=-1) return dp[idx][sum];
        long long int npick=Solve(idx+1,sum,n,coins,dp);
        long long int pick=0;
        if(sum>=coins[idx]){
            pick=Solve(idx,sum-coins[idx],n,coins,dp);
        }
        return dp[idx][sum]=pick+npick;
    }
    long long int count(int coins[], int N, int s) {

        // code here.
        vector<vector<long long int>>dp(N+1,vector<long long int>(s+1,0));
        for(long long int idx = N ;  idx >= 0 ; idx--){
            for(long long int sum = 0 ; sum <= s ; sum++){
                if(idx==N){
                    if(sum==0) dp[idx][sum]= 1;
                    else dp[idx][sum]= 0;
                }
                else{
                    long long int npick=dp[idx+1][sum];
                    long long int pick=0;
                    if(sum>=coins[idx]){
                        pick=dp[idx][sum-coins[idx]];
                    }
                    dp[idx][sum]=pick+npick;
                }
            }
        }
        return dp[0][s];
        // return Solve(0,sum,N,coins,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends