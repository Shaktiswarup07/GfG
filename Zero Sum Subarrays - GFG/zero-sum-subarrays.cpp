//{ Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
public:
    //Function to count subarrays with sum equal to 0.
    long long int findSubarray(vector<long long int> &arr, int n ) {
        //code here
        int i=0;
        int cntInitialZeros=0;
        // while(arr[i]==0){
        //     cntInitialZeros++;
        //     i++;
        // }
        int initialAns=(cntInitialZeros*(cntInitialZeros+1))/2;
        map<int,int>mp;
        mp[0]=1;
        int sum=0;
        int finAns=0;
        for(int j = i ; j < n ; j++){
            sum+=arr[j];
            if(mp.find(sum)!=mp.end()){
                finAns+=mp[sum];
            }
            mp[sum]++;
        }
        return finAns+initialAns;
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
        cin>>n; //input size of array
       
        vector<long long int> arr(n,0);
        
        for(int i=0;i<n;i++)
            cin>>arr[i]; //input array elements
        Solution ob;
        cout << ob.findSubarray(arr,n) << "\n";
    }
	return 0;
}
// } Driver Code Ends