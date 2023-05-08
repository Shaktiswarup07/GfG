//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    int findMidSum(int ar1[], int ar2[], int n) {
            // code here 
        //     if(nums1.size()>nums2.size()){
        //     return findMedianSortedArrays(nums2,nums1);
        // }
        int n1=n,n2=n;
        int low=0,high=n;
        while(low<=high){
            int cut1=(low+high)/2;
            int cut2=((n1+n2+1)/2)-cut1;

            int l1=cut1==0?INT_MIN:ar1[cut1-1];
            int l2=cut2==0?INT_MIN:ar2[cut2-1];
            int r1=cut1==n1?INT_MAX:ar1[cut1];
            int r2=cut2==n2?INT_MAX:ar2[cut2];
            if(l1<=r2 && l2<=r1){
                if((n1+n2)%2==0) return (max(l1,l2)+min(r1,r2));
                else return max(l1,l2);
            }
            else if(l1>r2){
                high=cut1-1;
            }
            else if(l2>r1){
                low=cut1+1;
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int ar1[n], ar2[n];
        for (i = 0; i < n; i++) {
            cin >> ar1[i];
        }
        for (i = 0; i < n; i++) {
            cin >> ar2[i];
        }
        Solution ob;
        auto ans = ob.findMidSum(ar1, ar2, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends