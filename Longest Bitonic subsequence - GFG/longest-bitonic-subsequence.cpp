//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int LongestBitonicSequence(vector<int>nums)
	{
	    // code here
	    int n=nums.size();
	    vector<int>dp1(n,1),dp2(n,1);
	    for(int i = 0 ; i < n ; i++){
	        for(int j = 0 ; j < i ; j++){
	            if(nums[j]<nums[i] && dp1[j]+1>dp1[i]){
	                dp1[i]=dp1[j]+1;
	            }
	        }
	    }
	    reverse(nums.begin(),nums.end());
	    for(int i = 0 ; i < n ; i++){
	        for(int j = 0 ; j < i ; j++){
	            if(nums[j]<nums[i] && dp2[j]+1>dp2[i]){
	                dp2[i]=dp2[j]+1;
	            }
	        }
	    }
	    reverse(dp2.begin(),dp2.end());
	    int maxi=INT_MIN;
	    for(int i = 0 ; i < n ; i++){
	        maxi=max(maxi,dp1[i]+dp2[i]-1);
	    }
	    return maxi;
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends