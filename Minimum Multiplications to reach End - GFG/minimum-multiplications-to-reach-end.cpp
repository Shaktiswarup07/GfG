//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
#define mod 100000
class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        vector<int>dist(100000,INT_MAX);
        dist[start]=0;
        queue<pair<int,int>>q;
        //{node,dist}
        q.push({start,0});
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            int node=p.first;
            int dis=p.second;
            if(node==end){
                return dis;
            }
            for(auto i:arr){
                int el=(i*node)%mod;
                if(dis+1<dist[el]){
                    dist[el]=dis+1;
                    q.push({el,dis+1});
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends