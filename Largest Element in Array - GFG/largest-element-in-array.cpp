//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    int Solve(vector<int>arr,int l,int r){
        if(l==r){
            return l;
        }
        int mid=l+(r-l)/2;
        int idx1=Solve(arr,l,mid);
        int idx2=Solve(arr,mid+1,r);
        return arr[idx1]>arr[idx2]?idx1:idx2;
    }
    int largest(vector<int> &arr, int n)
    {
        int idx=Solve(arr,0,n-1);
        return arr[idx];
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int>arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        cout << ob.largest(arr, n) << "\n";
    }
    return 0;
}

// } Driver Code Ends