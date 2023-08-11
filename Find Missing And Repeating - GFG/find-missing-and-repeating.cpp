//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int N) {
        // code here
        for(int i = 0 ; i < N ; i++){
            if(arr[i]==i+1) continue;
            else{
                if(arr[i]==arr[arr[i]-1]) continue;
                else{
                   swap(arr[i],arr[arr[i]-1]);
                   i--;
                }
                
            }
        }
        for(int i = 0 ; i < N ; i++){
            if(arr[i]!=i+1){
                return {arr[i],i+1};
            }
        }
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends