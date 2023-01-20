//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int carpetBox(int A, int B, int C, int D){
        //code here
        int len=A,wid=B;
        int steps1=0;
        while((len>C) || (wid>D)){
            if(len>C){
                len/=2;steps1++;
            }
            if(wid>D){
                wid/=2;steps1++;
            }
        }
        len=B,wid=A;
        int steps2=0;
        while((len>C) || (wid>D)){
            if(len>C){
                len/=2;steps2++;
            }
            if(wid>D){
                wid/=2;steps2++;
            }
        }
        return min(steps1,steps2);
        
        
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        int A,B,C,D;
        cin>>A>>B>>C>>D;
        
        Solution ob;

        int ans = ob.carpetBox(A,B,C,D);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends