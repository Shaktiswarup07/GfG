//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int totalCuts(int N,int K,vector<int> &A){
        // Code here
        vector<int>pre(N),post(N);
        int maxi=INT_MIN,mini=INT_MAX;
        for(int i = 0 ; i < N ; i++){
            pre[i]=max(maxi,A[i]);
            maxi=max(maxi,A[i]);
        }
        for(int i = N-1 ; i>=0 ; i--){
            post[i]=min(mini,A[i]);
            mini=min(mini,A[i]);
        }
        // for(auto i:pre) cout<<i<<" ";
        // cout<<endl;
        // for(auto i:post) cout<<i<<" ";
        // cout<<endl;
        int ans=0;
        for(int i = 0 ; i < N-1; i++){
            if(pre[i]+post[i+1]>=K){
                ans=N-i-1;
                break;
            }
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N,K;
        cin>>N>>K;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution ob;
        cout<<ob.totalCuts(N,K,A)<<endl;
    }
    return 0;
}
// } Driver Code Ends