//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    string stringMirror(string str){
        // Code here
        string x;
            x+=str[0];
            x+=str[0];
        if(str.size()==1){
            return x;
        }
        int len=0;
        int i=1;
        if(str[0]==str[1]){
            
            return x;
        }
        while((int)str[i]<=(int)str[i-1]){
            i++;
        }
        string ans;
        for(int p = 0 ; p < i ; p++) ans+=str[p];
        for(int p=i-1 ; p>=0 ; p--) ans+=str[p];
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        Solution ob;
        string res=ob.stringMirror(str);
        cout<<res<<endl;
    }
}
// } Driver Code Ends