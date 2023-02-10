//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    bool check(char x){
        if(x=='b' || x=='a' || x=='l' || x=='o' || x=='n') return true;
        return false;
    }
    int maxInstance(string s){
        map<char,int>mp;
        for(int i=0;i<s.size();i++) {
            if(check(s[i])) mp[s[i]]++;
        }
        if(mp.size()<5) return 0;
        else{
            int mini=INT_MAX;
            for(auto i:mp){
                if(i.first=='l' || i.first=='o') {mini=min(mini,i.second/2);}
               else mini=min(mini,i.second);
            }
            return mini;
        }
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.maxInstance(s)<<endl;
    }
    return 0;
}
// } Driver Code Ends