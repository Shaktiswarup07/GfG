//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    vector<int>kthSmallestNum(int n, vector<vector<int>>&range, int q, vector<int>queries){
        //Write your code here
        //MERGE INTERVALS.
        sort(range.begin(), range.end());
        vector<pair<int,int>>merg;
        
        int a=range[0][0],b=range[0][1];
        for(int i = 1 ; i < n ; i++){
            if(b<range[i][0]){
                merg.push_back({a,b});
                a=range[i][0];
                b=range[i][1];
            }
            else{
                b=max(b,range[i][1]);
            }
        }
        merg.push_back({a,b});
        vector<int>ans;
        for(int i = 0 ; i < queries.size() ; i++){
            int k=queries[i],p=queries[i];
            int cnt=0;
            // cout<<"starting"<<endl;
            for(int j = 0 ; j < merg.size() ; j++){
                // cout<<merg[j].first<<" "<<merg[j].second<<endl;
                int del=merg[j].second-merg[j].first+1;
                // cout<<"del="<<del<<endl;
                cnt+=(merg[j].second-merg[j].first+1);
                // cout<<"p="<<p<<endl;
                if(cnt>=k){
                    ans.push_back(merg[j].first+p-1);
                    break;
                }
                 p=p-del;
            }
            if(cnt<k) ans.push_back(-1);
        }
        return ans;
        
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
	    cin >> n;
	    vector<vector<int>>range(n, vector<int>(2, 0));
	    for(int i = 0 ; i < n; i++){
	        cin >> range[i][0] >> range[i][1];
	    }
	    int q;
	    cin >> q;
	    vector<int>queries;
	    for(int i = 0 ; i < q; i++){
	        int x;
            cin >> x;
	        queries.push_back(x);
	    }
	    Solution ob;
	    vector<int>ans = ob.kthSmallestNum(n, range, q, queries);
	    for(auto it : ans){
	        cout << it << " ";
	    }
	    cout << endl;
	}
	return 0;
}

// } Driver Code Ends