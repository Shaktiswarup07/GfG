//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int isPossible(int n, int m, string s){
        // code here
        int l=INT_MAX,r=INT_MIN,u=INT_MIN,d=INT_MAX;
        int p=0,q=0;
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i]=='L'){
                p--;
                l=min(l,p);
            }
            else if(s[i]=='R'){
                p++;
                r=max(r,p);
            }
            else if(s[i]=='U'){
                q++;
                u=max(u,q);
            }
            else if(s[i]=='D'){
                q--;
                d=min(d,q);
            }
            
        }
        if(d==INT_MAX || d>0) d=0;
        if(u==INT_MIN || u<0) u=0;
        if(r==INT_MIN || r<0) r=0;
        if(l==INT_MAX || l>0) l=0;
        // cout<<l<<" "<<r<<" "<<d<<" "<<u<<endl;
        if(r-l<=m-1 && u-d<=n-1) return 1;
        return 0;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.isPossible(n, m, s)<<endl;
    }
    return 0;
}
// } Driver Code Ends