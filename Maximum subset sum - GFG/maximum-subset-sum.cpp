//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class IntArray
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {

  public:
    long long Recur(int idx, int n, vector<int>&arr, vector<long long>&dp){
        if(idx>=n){
            return 0;
        }
        if(dp[idx]!=-1) return dp[idx];
        long long x=arr[idx]+Recur(idx+1,n,arr,dp);
        long long y=0;
        if(idx+1<n) y=arr[idx+1] + Recur(idx+2,n,arr,dp);
        return dp[idx]=max(x,y);
    }
    long long findMaxSubsetSum(int N, vector<int> &A) {
        // code here
        int idx=0;
        vector<long long>dp(N+1,-1);
        return Recur(idx,N,A,dp);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        IntArray::input(A,N);
        
        Solution obj;
        long long res = obj.findMaxSubsetSum(N, A);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends