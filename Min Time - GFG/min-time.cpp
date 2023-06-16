//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  unordered_map<int,int>mp1,mp2;
    long long Solve(int idx, int prev, vector<int>&sTypes,vector<vector<long long>>&dp,int dir){
        if(idx==sTypes.size()) return 0;
        if(dp[idx][dir]!=-1) return dp[idx][dir];
        int lmost=mp1[sTypes[idx]];
        int rmost=mp2[sTypes[idx]];
        
        long long a=(abs(prev-rmost)) + abs(rmost-lmost) +Solve(idx+1,lmost,sTypes,dp,0);
        if(idx==sTypes.size()-1) a+=abs(lmost);
        long long b=(abs(prev-lmost)) + abs(lmost-rmost) + Solve(idx+1,rmost,sTypes,dp,1);
        if(idx==sTypes.size()-1) b+=abs(rmost);
        return dp[idx][dir]=min(a,b);
    }
    long long minTime(int n, vector<int> &locations, vector<int> &types) {
        // code here
        mp1.clear();
        mp2.clear();
        int maxi=*max_element(types.begin(),types.end());
        vector<int>temp(maxi+1,0);
        for(int i = 0 ; i < types.size() ; i++){
            temp[types[i]]=1;
            if(mp1.find(types[i])==mp1.end()){
                mp1[types[i]]=locations[i];
                mp2[types[i]]=locations[i];
            }
            else{
                mp1[types[i]]=min(mp1[types[i]],locations[i]);
                mp2[types[i]]=max(mp2[types[i]],locations[i]);
            }
        }
        vector<int>sortedTypes;
        for(int i = 0 ; i<=maxi ; i++){
            if(temp[i]) sortedTypes.push_back(i);
        }
        int k=sortedTypes.size();
        // vector<int>dp(sortedTypes.size()+1,-1);
        vector<vector<long long>>dp(k+1,vector<long long>(2,-1));
        
        return Solve(0,0,sortedTypes,dp,0);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        
        
        vector<int> locations(n);
        for(int i=0;i<n;i++){
            cin>>locations[i];
        }
        
        
        vector<int> types(n);
        for(int i=0;i<n;i++){
            cin>>types[i];
        }
        
        Solution obj;
        long long res = obj.minTime(n, locations, types);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends