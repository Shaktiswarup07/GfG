//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int minOperation(string s) {
        // code here
        //longest repeating substring n-len(substr)+1
        string p;
        bool g=0;
        int maxi=INT_MIN;
        for(int i=0;i<s.size();i++){
            p+=s[i];
            string x;
            for(int j=i+1;j<s.size();j++){
                x+=s[j];
                if(x==p){
                    g=1;
                    int sz=p.size();
                    maxi=max(maxi,sz);
                }
            }
        }
        if(g==0) return s.size();
        
        return  s.size()-maxi+1;
        
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
        cout << ob.minOperation(s) << "\n";
    }
    return 0;
}

// } Driver Code Ends