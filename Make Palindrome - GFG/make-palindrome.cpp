//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    bool isPal(string s){
        int lo=0,hi=s.size()-1;
        while(lo<=hi){
            if(s[lo]!=s[hi]) return 0;
            lo++;hi--;
        }
        return 1;
    }
    bool makePalindrome(int n,vector<string> &arr){
        // Code here
        map<string,int>mp;
        for(int i = 0 ; i< arr.size(); i++){
            string p=arr[i];
            reverse(p.begin(),p.end());
            if(mp[p]){
                mp[p]++;
            }
            else
            mp[arr[i]]++;
            
        }
        int cnt=0;
        for(auto i :mp){
            if(i.second%2==1) cnt++;
        }
        if(cnt==0) return 1;
        if(cnt==1){
            for(auto i:mp){
                if(i.second==1){
                    if(isPal(i.first)) return 1;
                    else return 0;
                }
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        if(ob.makePalindrome(n,arr)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
// } Driver Code Ends