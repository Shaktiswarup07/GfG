//{ Driver Code Starts
//Initial Template for CPP

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    long long maxTripletProduct(long long arr[], int n)
    {
    	// Complete the function
    if(n==3){
        return arr[0]*arr[1]*arr[2];
    }
    else{
        bool f=0;
        for(int i = 0 ; i < n ; i++){
            if(arr[i]==0){
                f=1;
            }
            if(i<n-1 && f==1){
                arr[i]=arr[i+1];
            }
        }
        if(f){
            arr[n-1]=0;
            sort(arr,arr+n-1);
        }else{
            sort(arr,arr+n);
        }
        // sort();
        if(f){
          long long p=arr[0]*arr[1]*arr[n-2];
          long long q=arr[n-2]*arr[n-3]*arr[n-4];
          long long h=max(p,q);
          if(h<0) return 0;
          else return h;
        }
        else{
            long long p=arr[0]*arr[1]*arr[n-1];
          long long q=arr[n-1]*arr[n-2]*arr[n-3];
          long long h=max(p,q);
          return h;
        }
        
    }
    	
    	
    	
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,i;
	    cin>>n; long long arr[n];
	    for(i=0;i<n;i++)
	    cin>>arr[i];
	    Solution ob;
	    cout <<ob.maxTripletProduct(arr, n);
	    cout<<"\n";
	}
    return 0;
}
// } Driver Code Ends