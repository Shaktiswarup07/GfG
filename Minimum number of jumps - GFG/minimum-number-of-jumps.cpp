//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
  
    long long int Solve(int arr[],int idx,int n){
        if(idx>=n-1){
            return 0;
        }
        // if(idx+arr[idx]>=n-1) return 1;
        long long int ans=INT_MAX;
        for(int i=1;i<=arr[idx];i++){
             ans=min(1+Solve(arr,idx+i,n),ans);
        }
        return ans;
    }
    int minJumps(int arr[], int n){
        
        if(n==1) return 0;
        if(arr[0]==0) return -1;
        int jumps=0,maxreach=0,currEnd=0;
        for(int i=0;i<n;i++){
            maxreach=max(maxreach,arr[i]+i);
            if(maxreach>=n-1){
                jumps++;
                return jumps;
            }
            if(i==maxreach){
                return -1;
            }
            if(i==currEnd){
                currEnd=maxreach;
                jumps++;
            }
        }
        return jumps;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends