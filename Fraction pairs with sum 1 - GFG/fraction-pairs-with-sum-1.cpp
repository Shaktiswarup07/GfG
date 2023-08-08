//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    int countFractions(int n, int num[], int den[])
    {
        map<pair<int,int>,int>mp;
        for(int i = 0 ; i < n ; i++){
            int x= __gcd(num[i],den[i]);
            num[i]/=x;
            den[i]/=x;
            mp[{num[i],den[i]}]++;
        }
        int cnt=0;
        for(int i = 0 ; i < n ; i++){
            mp[{num[i],den[i]}]--;
            int x=den[i]-num[i];
            cnt+=mp[{x,den[i]}];
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
        int n;
        cin>>n;
        int numerator[n],denominator[n];
        for(int i=0;i<n;i++)
            cin>>numerator[i];
        for(int i=0;i<n;i++)
            cin>>denominator[i];
        Solution ob;
        int ans=ob.countFractions(n,numerator,denominator);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends