//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int getAngle(int H , int M) {
        // code here
        //angle betn 0 and M
        double a0M=M*6;
        double a0H=H*30;
        double extra0H=0.5*M;
        double angle=abs(a0H+extra0H-a0M);
        double ans=min(angle,360-angle);
        return floor(ans);
        // cout<<angle<<endl;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int H,M;
        
        cin>>H>>M;

        Solution ob;
        cout << ob.getAngle(H,M) << endl;
    }
    return 0;
}
// } Driver Code Ends