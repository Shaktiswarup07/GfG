//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<int> findMaxRow(vector<vector<int>> mat, int N) {
        int maxRow=0,maxOnes=0;
        int maxi=INT_MIN;
        for(int i = 0 ; i < N ; i++){
            int ones=0;
            for(int j = 0 ; j < N ; j++){
                ones+=mat[i][j];
            }
            if(ones>maxOnes){
                maxRow=i;
                maxOnes=ones;
            }
        }
        return {maxRow,maxOnes};
        //code here
    }
};

//{ Driver Code Starts.

int main() {
	int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<vector<int>> arr(n, vector<int> (n));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> arr[i][j];
        Solution obj;
        vector<int> ans = obj.findMaxRow(arr, n);
        for(int val : ans) {
            cout << val << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends