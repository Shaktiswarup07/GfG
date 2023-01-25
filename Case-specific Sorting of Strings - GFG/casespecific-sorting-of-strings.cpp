//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string s, int n)
    {
        // your code here
        string a,b;
        for(int i=0;i<n;i++){
            if(isupper(s[i])) a+=s[i];
            else b+=s[i];
        }
        
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        string ans;
        int i=0,j=0;
        int k=0;
        while(ans.size()!=n){
            if(isupper(s[k])){
                ans.push_back(a[i]);i++;
            }
            else{
                ans.push_back(b[j]);
                j++;
                // cout<<ans<<endl;
            }
            // cout<<ans<<endl;
            k++;
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
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends