//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
   public:
   int maxi=INT_MIN,mini=INT_MAX;
   void MaxMin(int a[], int n,int l,int r){
       if(r==l){
           maxi=max(maxi,a[r]);
           mini=min(mini,a[r]);
           return;
       }
       int mid=l+(r-l)/2;
       MaxMin(a,n,l,mid);
       MaxMin(a,n,mid+1,r);
   }
    int findSum(int A[], int N)
    {
    	//code here.
    	MaxMin(A,N,0,N-1);
    	return maxi+mini;
    }

};

//{ Driver Code Starts.
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
	    Solution ob;  
	    int ans=ob.findSum(arr, n);
	    cout<<ans;
	    cout<<"\n";
	}
	return 0;
}

// } Driver Code Ends