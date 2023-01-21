//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    void Solve(int idx,string s, vector<string>&ans,string &ds){
        if(idx==s.size()){
            ans.push_back(ds);
            return;
        }
        ds.push_back(' ');
        ds.push_back(s[idx]);
        Solve(idx+1,s,ans,ds);
        ds.pop_back();
        ds.pop_back();
        ds.push_back(s[idx]);
        Solve(idx+1,s,ans,ds);
        ds.pop_back();
        
    }

    vector<string> permutation(string S){
        // Code Here
        string op="";
        op.push_back(S[0]);
        // S.erase(S.begin()+0);
        vector<string> ans;
        // string ds;
        Solve(1,S,ans,op);
        return ans;
        
    }
};

//{ Driver Code Starts.

int  main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        vector<string> ans;
        Solution obj;
        ans = obj.permutation(S);
        for(int i=0;i<ans.size();i++){
            cout<<"("<<ans[i]<<")";
        }
        cout << endl;
    }
}

// } Driver Code Ends