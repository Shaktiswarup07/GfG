//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends


class Solution{
  public:
    long int lenOfLongIncSubArr(long int arr[], long int n) {
        // int n=arr.size();
        vector<long int>dp1(n,1);
        long int maxi=1;
        for(int i = 1 ; i < n ; i++){
            if(arr[i]>arr[i-1]){
                dp1[i]=1+dp1[i-1];
            }
            maxi=max(maxi,dp1[i]);
        }
       
    //   for(int i =)
    return maxi;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long int n;
        cin >> n;
        long int arr[n], i;
        for (i = 0; i < n; i++) 
            cin >> arr[i];
        Solution obj;
        cout << obj.lenOfLongIncSubArr(arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends