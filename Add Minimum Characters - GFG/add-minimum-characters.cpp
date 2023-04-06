//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    bool isPal(int i,string str){
        int j=0;
        while(j<=i){
            if(str[i]!=str[j]) return false;
            else{
                j++;i--;
            }
        }
        return 1;
    }
    int addMinChar(string str){    
        //code here
        if(isPal(str.size()-1,str)) return 0;
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
        int p=i*2;
        if(isPal(p,str)) return str.size()-p-1;
        
        i+=(i-1);
        return str.size()-i-1;
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