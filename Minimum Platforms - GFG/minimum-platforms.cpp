//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	map<int,int>mp;
    	for(int i = 0 ; i < n ; i++){
    	    mp[(dep[i])]--;
    	    mp[(arr[i])-1]++;
    	}
    	int ans=0;
    	int maxi=INT_MIN;
    	for(auto i:mp){
    	   // cout<<i.first<<endl;
    	    ans+=i.second;
    	    maxi=max(maxi,ans);
    	}
    	return maxi;
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
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends