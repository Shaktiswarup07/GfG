//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minThrow(int N, int arr[]){
        // code here
        vector<int>adj[31];
        for(int i = 1 ; i <= 30 ; i++){
            for(int j = i+1 ; j<=i+6 ; j++){
                if(j<=30)
                adj[i].push_back(j);
            }
        }
        for(int i = 0 ; i < 2*N ; i+=2){
            if(arr[i+1]>arr[i]){
                // adj[arr[i]].push_back(arr[i+1]);
                int x=arr[i];
                int y=arr[i+1];
                for(int j = x-6 ; j<=x-1 ; j++){
                    if(j>=1){
                        adj[j].push_back(y);
                        // cout<<j<<" "<<y<<endl;
                    }
                    
                }
            }
            else{
                adj[arr[i]].push_back(arr[i+1]);
            }
        }
        // for(auto i:adj[1]){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        vector<int>vis(31,0);
        queue<int>q;
        q.push(1);
        vis[1]=1;
        int count=0;
        while(!q.empty()){
            int sz=q.size();
            
            for(int i = 0 ; i < sz ; i++){
                int node=q.front();
                q.pop();
                if(node==30) return count;
                for(int j = 0 ; j < adj[node].size() ; j++){
                    if(!vis[adj[node][j]]){
                        vis[adj[node][j]]=1;
                        q.push(adj[node][j]);
                        // cout<<adj[node][j]<<" ";
                        // if(adj[node][j]==30) return count;
                    }
                }
            }
            // cout<<endl;
            count++;
        }
        return 0;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[2*N];
        for(int i = 0;i < 2*N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.minThrow(N, arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends