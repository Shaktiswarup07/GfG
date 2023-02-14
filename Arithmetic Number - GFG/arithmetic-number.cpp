//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int inSequence(int A, int B, int C){
        // code here
        if(C==0) return A==B;
        long long int d=C;
        long long int a=A;
        //is B part of AP?
        long long int x=B-a;
        if((B-a)%d==0){
            int n=1+(B-a)/d;
            if(n>0) return 1;
            else return 0;
        }
        return 0;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int A, B, C;
        cin>>A>>B>>C;
        
        Solution ob;
        cout<<ob.inSequence(A, B, C)<<endl;
    }
    return 0;
}
// } Driver Code Ends