//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++


class Solution
{

public:
    int xmod11(string x)
    {
       // code here
       long long int a=0,b=0;
       for(int i = 0 ; i < x.size() ; i++){
           if(i%2==0){
               a+=(x[i]-'0');
           }
           else b+=(x[i]-'0');
       }
       if(a==b) return 0;
       if(x.size()%2==0)
        return (11111111-a+b)%11;
        else 
        return (11111111+a-b)%11;
    
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string x;
        cin>>x;
        Solution ob;
        int ans = ob.xmod11(x);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends