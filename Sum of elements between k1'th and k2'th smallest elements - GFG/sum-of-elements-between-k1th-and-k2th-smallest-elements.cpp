//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long sumBetweenTwoKth( long long A[], long long N, long long K1, long long K2)
    {
        // Your code goes here
        //find K2th smallest element
        priority_queue<long long>maxH;
        for(long long i=0;i<N;i++){
            maxH.push(A[i]);
            if(maxH.size()>K2) maxH.pop();
        }
        maxH.pop();
        long long ans=0;
        while(maxH.size()>K1){
            ans+=maxH.top();
            maxH.pop();
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        cin>>n;
        long long a[n+5];
        for(int i =0;i<n;i++)
            cin >> a[i];
        
        long long k1, k2;
        cin >> k1 >> k2;
        Solution ob;
        cout << ob.sumBetweenTwoKth(a, n, k1, k2) << endl;
        
    }
	return 0;
}

// } Driver Code Ends