//{ Driver Code Starts
// A C++ program to find if there is a zero sum
// subarray
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    //Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int arr[], int n)
    {
        //Your code here
        vector<int>pre(n);
        for(int i = 0 ; i < n ; i++){
            if(i==0) pre[i]=arr[i];
            else pre[i]=arr[i]+pre[i-1];
            if(pre[i]==0) return 1;
        }
        if(pre[n-1]==0) return 1;
        map<int,int>mp;
        for(auto i:pre){
            mp[i]++;
            if(mp[i]==2) return 1;
        }
        return 0;
        
    }
};

//{ Driver Code Starts.
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    Solution obj;
	    	if (obj.subArrayExists(arr, n))
		cout << "Yes\n";
	else
		cout << "No\n";
	}
	return 0;
}
// } Driver Code Ends