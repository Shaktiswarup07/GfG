//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool Solve(vector<int>arr,int sum,int n,vector<vector<int>>&dp){
        //base case
        
        if(sum==0) return 1;
        if(n==0) return 0;
        
        //pick
        // sum-=arr[n-1];
        if(dp[n][sum]!=-1) return dp[n][sum];
        bool x=0,y=0;
        if(sum>=arr[n-1]){
             return dp[n][sum]=Solve(arr,sum-arr[n-1],n-1,dp) || Solve(arr,sum,n-1,dp);
        }
        else{
             return dp[n][sum]=Solve(arr,sum,n-1,dp);
        }
        // return x||y;
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        vector<vector<int>>dp(101,vector<int>(100001,-1));
        int n=arr.size();
        return Solve(arr,sum,n,dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends