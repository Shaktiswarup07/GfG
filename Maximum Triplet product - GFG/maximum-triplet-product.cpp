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
            long long int min1=LLONG_MAX,min2=LLONG_MAX;
            long long int max1=LLONG_MIN,max2=LLONG_MIN,max3=LLONG_MIN;
            for(int i=0;i<n;i++){
                if(arr[i]<min1){
                    min2=min1;
                    min1=arr[i];
                }
                else if(arr[i]<min2){
                    min2=arr[i];
                }
                if(arr[i]>max1){
                    max3=max2;
                    max2=max1;
                    max1=arr[i];
                }
                else if(arr[i]>max2){
                    max3=max2;
                    max2=arr[i];
                }
                else if(arr[i]>max3){
                    max3=arr[i];
                }
            }
            return max(min1*min2*max1,max1*max2*max3);
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