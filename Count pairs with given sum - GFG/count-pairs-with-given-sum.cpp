//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        // code here
        map<int,int>mp;
        for(int i = 0 ; i < n ; i++){
            mp[arr[i]]++;
        }
        sort(arr,arr+n);
        int cnt=0;
        for(int i = 0 ; i< n ; i++){
            int x=k-arr[i];
            // cout<<x<<" "<<k<<endl;
            if(mp[x]>0){
                // mp[arr[i]]--;
                if(x==arr[i]){
                    mp[arr[i]]--;
                    // cout<<mp[arr[i]]<<" ";
                    cnt+=mp[arr[i]];
                }
                else{
                    cnt+=mp[x];
                    mp[arr[i]]--;
                }
                
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getPairsCount(arr, n, k);
        cout << ans << "\n";
    }
    
    return 0;
}
// } Driver Code Ends