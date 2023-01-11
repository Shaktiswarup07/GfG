//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long int minIncrements(vector<int> arr, int N) {
        // Code here
        sort(arr.begin(),arr.end());
        map<int,int>mp;
        long long cnt=0;
        for(int i=0;i<arr.size();i++){
            while(mp.find(arr[i])!=mp.end()){
                arr[i]++;
                // mp[arr[i]]++;
                cnt++;
            }
            mp[arr[i]]++;
            // else{
            //     mp[arr[i]]++;
            // }
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minIncrements(arr, N) << endl;
    }
}
// } Driver Code Ends