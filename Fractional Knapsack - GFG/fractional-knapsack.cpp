//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        double ans=0;
        vector<pair<double,double>>v;
        for(int i=0;i<n;i++){
            v.push_back({((arr[i].value*1.0)/arr[i].weight),(arr[i].weight)});
        }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        int sum=W;
        for(int i=0;i<n;i++){
            if(sum>=v[i].second){
                ans+=(v[i].second*v[i].first);
                sum-=v[i].second;
            }
            else{
                ans+=sum*(v[i].first);
                break;
            }
        }
        return ans;
        
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends