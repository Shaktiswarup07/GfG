//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
/*You are required to complete this method */

class Solution
{
    public:
    int Solve(vector<int>&v, int k, int idx){
        if(v.size()==1) return v[0];
        //(pos+k-1)%n
        idx=(idx+k-1)%v.size();
        v.erase(v.begin()+idx);
        return Solve(v,k,idx);
        
    }
    int josephus(int n, int k)
    {
       //Your code here
       vector<int>v(n,0);
       for(int i = 0 ; i < n ; i++){
           v[i]=i+1;
       }
       return Solve(v,k,0);
    }
};



//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;//testcases
	while(t--)
	{
		int n,k;
		cin>>n>>k;//taking input n and k
		
		//calling josephus() function
		Solution ob;
		cout<<ob.josephus(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends