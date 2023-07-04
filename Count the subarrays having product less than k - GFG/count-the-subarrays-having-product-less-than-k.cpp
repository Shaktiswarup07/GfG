//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

#define ll long long int
class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        int cnt=0;
        int i=0,j=0;
        ll tot=(1ll*n*(n+1))/2;
        ll prod=1;
        if(k==1){
            return 0;
        }
        while(j<n+1 && i<n){
            if(j==n && prod<k){
                break;
            }
            if(j<n && prod<k){
                prod*=a[j];
                j++;
            }
            else if(prod>=k){
                cnt+=(n-j+1);
                prod/=a[i];
                i++;
            }
            else if(i==n-1 && j==n) break;
        }
        // cout<<<<endl;
        return (tot-cnt);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends