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
        unordered_map<int,int>mp;
        long long cnt=0;
        
        int maxi=arr[0];
        mp[arr[0]]++;
        
        for(int i=1;i<arr.size();i++){
            if(mp[arr[i]]>0){
               cnt+=(maxi+1-arr[i]);
                arr[i]=maxi+1;
                mp[arr[i]]++;
            }
            else  mp[arr[i]]++;

            maxi=max(maxi,arr[i]);
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