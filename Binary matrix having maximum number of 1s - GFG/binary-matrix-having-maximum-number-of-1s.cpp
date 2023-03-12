//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<int> findMaxRow(vector<vector<int>> mat, int N) {
        // int maxRow=0,maxOnes=0;
        // int maxi=INT_MIN;
        // int n=N;
        // for(int i = 0 ; i < N ; i++){
        //     int ones=0;
        //     int s=0,e=n-1;
        //     int ans=-1;
        //     while(s<=e){
        //         int mid=s+(e-s)/2;
        //         if(mat[i][mid]==1){
        //             ans=mid;
        //             e=mid-1;
        //         }
        //         else{
        //             s=mid+1;
        //         }
        //     }
        //     if(ans>=0)
        //     ones=n-ans;
        //     if(ones>maxOnes){
        //         maxRow=i;
        //         maxOnes=ones;
        //     }
        // }
        // return {maxRow,maxOnes};
        int cnt=0;
        int i=0,j=N-1;
        int row=0;
        while(i>=0 && i<N && j>=0 && j<N){
            if(mat[i][j]==1){
                row=i;
                cnt++;
                j--;
            }
            else if(mat[i][j]==0){
                i++;
                // row++;
            }
        }
        if(cnt>0)
        return {row,cnt};
        else return {0,0};
        
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