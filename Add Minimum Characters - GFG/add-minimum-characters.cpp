//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int addMinChar(string str){
        int i=0,j=str.size()-1;
        while(i<j){
                if(str[i]==str[j]){
                    i++;
                    j--;
            }
            else {
                    if(str[0]==str[j] && str[i]!=str[j]){
                        i=0;
                    }
                    else{
                        i=0;j--;
                    }
            }
        }
        if(i==j) return str.size()-i*2-1;
        else return str.size()-i*2;
    }
};

//{ Driver Code Starts.


int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin >> str;
        
        Solution ob;
        cout << ob.addMinChar(str) << endl;
    }
    return 0; 
} 
// } Driver Code Ends