//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    long long countKdivPairs(int A[], int n, int K)
    {
        //code here
        map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[A[i]%K]++;
        }
        long long ans=0;
        for(auto i:mp){
            if(i.first==0){
                ans+=((i.second)*(i.second-1))/2;
                mp.erase(i.first);
            }
            else if(K-i.first==i.first){
                ans+=((i.second)*(i.second-1))/2;
                mp.erase(i.first);
            }
            
            else if(mp.find(K-i.first)!=mp.end()){
                ans+=(i.second*mp[K-i.first]);
                mp.erase(K-i.first);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;

		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

		int k;
		cin >> k;

        Solution ob;
		cout << ob. countKdivPairs(a, n , k) << "\n";



	}


	return 0;
}

// } Driver Code Ends