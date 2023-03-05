//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<int> optimalArray(int n,vector<int> &a){
    //     // Code here
        int ans=0;
        // for(int i=0;i<n;i++){
        //     ans+=abs(a[i]-a[(n-1)/2]);
        // }
        vector<int>an(n);
        // an[n-1]=ans;
        an[0]=0;
        for(int i=1;i<n;i++){
            an[i]=ans+abs(a[i]-a[i/2]);
            ans=an[i];
        }
        // for(int i=n-2;i>=0;i--){
        //     an[i]=ans-abs(a[i+1]-a[(i+1)/2]);
        //     ans=an[i];
        // }
        return an;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        Solution obj;
        vector<int> ans=obj.optimalArray(n,a);
        for(auto ele:ans){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends