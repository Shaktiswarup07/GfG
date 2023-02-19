//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
   public:
//   int maxi=INT_MIN,mini=INT_MAX;
   pair<int,int> MaxMin(int a[], int n,int l,int r){
       if(r==l){
        //   cout<<a[r]<<" ";
           return {a[r],a[l]};
       }
       int mid=l+(r-l)/2;
       pair<int,int>mami1;
       pair<int,int>mami2;
       mami1 = MaxMin(a,n,l,mid);
       mami2 = MaxMin(a,n,mid+1,r);
       int maxi,mini;
       if(mami1.first<mami2.first) maxi=mami2.first;
       else maxi=mami1.first;
       if(mami1.second<mami2.second) mini=mami1.second;
       else mini=mami2.second;
       return {maxi,mini};
       
       
   }
    int findSum(int A[], int N)
    {
    	//code here.
    	pair<int,int>mp=	MaxMin(A,N,0,N-1);
    
    	return mp.first+mp.second;
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