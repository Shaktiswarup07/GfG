//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  const int M=1e9+7;
    int Solve(int idx, int sum , vector<int>&nums, int n,int tar,vector<vector<int>>&dp){
        if(sum>tar) return 0;
        if(idx==n){
            if(sum==tar) return 1;
            else return 0;
        }
        if(dp[idx][sum]!=-1) return dp[idx][sum];
        return dp[idx][sum]=(Solve(idx+1,sum+nums[idx],nums,n,tar,dp)%M + Solve(idx+1,sum,nums,n,tar,dp)%M)%M;
    }
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        int sum=0;
        for(auto i:arr) sum+=i;
        if((sum+d)%2==1) return 0;
        int tar=(sum+d)/2;
        vector<vector<int>>dp(n+1,vector<int>(tar+1,-1));
        return Solve(0,0,arr,n,tar,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends