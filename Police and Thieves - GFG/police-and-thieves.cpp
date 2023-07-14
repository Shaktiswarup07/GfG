//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int catchThieves(char arr[], int n, int k) 
    {
        // Code here 
        int cnt=0;
        for(int i = 0 ; i < n ; i++){
            if(arr[i]=='P'){
                int j;
                if(i-k>=0) j=i-k;
                else j=0;
                for(  ; j<=i+k&&j<n ; j++){
                    if(arr[j]=='T'){
                        cnt++;
                        arr[j]='X';
                        break;
                    }
                }
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n, k;
		cin>>n >> k;
		char arr[n];
		for (int i = 0; i < n; ++i)
			cin>>arr[i];
		Solution obj;
		cout<<obj.catchThieves(arr, n, k) << endl;
	}
	return 0; 
} 


// } Driver Code Ends