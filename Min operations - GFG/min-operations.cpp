//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int solve(int a, int b) {
        // code here
        if(a==b) return 0;
        int x=0,y=0;
        
        for(int i=0;i<32;i++){
            int f=(a&1);
            int e=(b&1);
            if(f==0 && e==1) x=1;
            else if(f==1 && e==0) y=1;
            a>>=1;
            b>>=1;
        }
        if(x&&y) return 2;
        return 1;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int a;
        scanf("%d",&a);
        
        
        int b;
        scanf("%d",&b);
        
        Solution obj;
        int res = obj.solve(a, b);
        
        printf("%d\n", res);
        
    }
}

// } Driver Code Ends