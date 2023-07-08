//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    int lcs(string &x, string &y){
        int n=x.size(),m=y.size();
        // vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        vector<int>prev(m+1,0),cur(m+1,0);
        for(int i = 0 ; i <=n ; i++){
            for(int j = 0 ; j <=m ; j++){
                if(i==0 || j==0) cur[j]=0;
                else{
                    if(x[i-1]==y[j-1]){
                        cur[j]=1+prev[j-1];
                    }
                    else
                    cur[j]=max(prev[j],cur[j-1]);
                }
            }
            prev=cur;
        }
        return cur[m];
    }
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        //code here
        int lonestCommonSubseq=lcs(X,Y);
        return m+n-lonestCommonSubseq;
    }
};

//{ Driver Code Starts.

int main()
{   
    
    int t;
    
    //taking total testcases
    cin >> t;
    while(t--){
    string X, Y;
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	Solution obj;
	cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size())<< endl;
    }
	return 0;
}


// } Driver Code Ends