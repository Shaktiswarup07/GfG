//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int catchThieves(char arr[], int n, int k) 
    {
        // Code here 
        vector<int>p,t;
        for(int i = 0 ; i < n ; i++){
            if(arr[i]=='P') p.push_back(i);
            else t.push_back(i);
        }
        int i=0,j=0;
        int cnt=0;
        while(j<t.size() && i<p.size()){
            if(t[j]>=p[i]-k && t[j]<=p[i]+k){
                j++;
                i++;
                cnt++;
            }
            else if(p[i]<t[j]){
                i++;
            }
            else{
                j++;
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n, k;
		cin>>n >> k;
		char arr[n];
		for (int i = 0; i < n; ++i)
			cin>>arr[i];
		Solution obj;
		cout<<obj.catchThieves(arr, n, k) << endl;
	}
	return 0; 
} 


// } Driver Code Ends