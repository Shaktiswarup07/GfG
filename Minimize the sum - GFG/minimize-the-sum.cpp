//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int minimizeSum(int N, vector<int> arr) {
        // code here
        priority_queue<int,vector<int>,greater<int>>minH;
        int n=N;
        for(int i=0;i<n;i++){
            minH.push(arr[i]);
        }
        int sum=0;
        while(minH.size()!=1){
            int x=minH.top();
            minH.pop();
            int y=minH.top();
            minH.pop();
            minH.push(x+y);
            sum+=(x+y);
        }
        return sum;
    }
};

//{ Driver Code Starts.

int main() {
	int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++)
            cin>>arr[i];
        Solution obj;
        cout << obj.minimizeSum(n, arr) << "\n";
    }
}
// } Driver Code Ends