//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// Function returns the second
	// largest elements
int findMax(int arr[],int s,int e){
        if(s==e){
            return arr[s];
        }
        else{
            int mid=s+(e-s)/2;
            int x=findMax(arr,s,mid);
            int y=findMax(arr,mid+1,e);
            return max(x,y);
            
        }
    }
	int print2largest(int arr[], int n) {
	    int s=0,e=n-1;
	    // code here
	    int x= findMax(arr,s,e);
	    for(int i=0;i<n;i++) if(arr[i]==x) arr[i]=-1;
	    int y= findMax(arr,s,e);
	    if(y==-1) return -1;
	    return y;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.print2largest(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends