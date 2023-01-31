//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	   // int dp[n];
	    vector<int>dp(n);
	    int sum[n];
	    dp[0]=arr[0];
	    sum[0]=arr[0];
	    for(int i = 1 ; i < n ; i++){
	        int maxi=0;
	        for(int j = 0 ; j < i ; j++){
	            if(arr[i]>arr[j]){
	                maxi=max(maxi,sum[j]);
	            }
	            dp[i]=arr[i]+maxi;
	            sum[i]=arr[i]+maxi;
	        }
	    }
	    return *max_element(dp.begin(),dp.end());
	    
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends