//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    int n=nums.size();
	    vector<int>arr=nums;
	    sort(arr.begin(),arr.end());
	    map<int,int>mp;
	    for(int i=0;i<arr.size();i++){
	        mp[arr[i]]=i;
	    }
	    int cnt=0;
	    int j=0;
	    while(true){
	       if(j==n) break;
	        if(mp[nums[j]]==j){j++; continue;}
	        else{
	            swap(nums[j],nums[mp[nums[j]]]);
	            cnt++;
	        }
	    }
	    return cnt;
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
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends