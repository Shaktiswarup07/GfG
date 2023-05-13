//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumSum(string s) {
        // code here
        int i = 0 , j = s.size() -1;
        while(i<j){
            if(s[i]==s[j]){
                i++;j--;
            }
            else if(s[i]!='?' && s[j]!='?'){
                return -1;
            }
            else{
                if(s[i]=='?')
                swap(s[i],s[j]);
                i++;j--;
            }
        }
        string p;
        int k=(s.size()+1)/2;
        for(int i = 0 ; i < k ; i++){
            if(s[i]!='?') p+=s[i];
        }
        if(p.size()<=1) return 0;
        int cnt=0;
        for(int i = 0 ; i < p.size()-1 ; i++){
            cnt+=abs((int)p[i]-(int)p[i+1]);
        }
        return 2*cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        int ans = ob.minimumSum(s);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends