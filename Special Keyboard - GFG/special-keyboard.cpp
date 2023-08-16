//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    long long int optimalKeys(int N){
        // code here
        
        if(N<=6) return N;
        vector<int>dp(N+1,0);
        for(int i = 1 ; i <= 6 ; i++) dp[i]=i;
        
        for(int i = 7 ; i <=N ; i++){
            int maxi=INT_MIN;
            for(int j = 2 ; j<=i-2;j++){
                maxi=max(maxi,dp[i-j-1]*j);
            }
            dp[i]=maxi;
        }
        return dp[N];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.optimalKeys(N)<<"\n";
    }
    return 0;
}
// } Driver Code Ends