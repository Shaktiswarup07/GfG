//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    int solve(int N, vector<int> p){
        // code here
        map<int,int>mp;
        for(int i = 1 ; i < N ; i++){
            mp[p[i]]++;
            mp[i]++;
        }
        int cnt=0;
        for(auto i:mp){
            if(i.second==1) cnt++;
        }
        return N-1-cnt>=0?N-1-cnt:0;
        
        
    }
};


//{ Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        vector<int> p(N);
        for(int i = 0; i < N; i++){
            cin >> p[i];
        }

        Solution obj;
        cout << obj.solve(N, p) << "\n";
    }
}   
// } Driver Code Ends