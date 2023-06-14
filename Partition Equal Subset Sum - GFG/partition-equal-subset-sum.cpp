//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool Solve(int idx, int sum , int nums[], int n,int tar,vector<vector<int>>&dp){
        if(sum>tar) return false;
        if(idx==n){
            if(sum==tar) return true;
            else return false;
        }
        if(dp[idx][sum]!=-1) return dp[idx][sum];
        return dp[idx][sum]=Solve(idx+1,sum+nums[idx],nums,n,tar,dp) || Solve(idx+1,sum,nums,n,tar,dp);
    }
    int equalPartition(int n, int arr[])
    {
        // code here
        int sum=0;
        int tar=0;
        for(int i = 0 ; i< n ; i++){
            tar+=arr[i];
        }
        if(tar%2!=0) return 0;
        tar/=2;
        vector<vector<int>>dp(n+1,vector<int>(tar+1,-1));
        return Solve(0,sum,arr,n,tar,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends