//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
  int ternarySearch(int arr[], int n, int k, int s, int e){
      if(e>=s){
          int mid1=s+(e-s)/3;
          int mid2=e-(e-s)/3;
          if(arr[mid1]==k) return mid1;
          if(arr[mid2]==k) return mid2;
          if(arr[mid1]>k){
              return ternarySearch(arr,n,k,s,mid1-1);
          }
          else if(arr[mid2]<k){
               return ternarySearch(arr,n,k,mid2+1,e);
          }
          else return ternarySearch(arr,n,k,mid1+1,mid2-1);
      }
      else return -1;
  }
    int binarysearch(int arr[], int n, int k) {
        // code here
        int s=0,e=n-1;
        return ternarySearch(arr,n,k,s,e);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];
        int key;
        cin >> key;
        Solution ob;
        int found = ob.binarysearch(arr, N, key);
        cout << found << endl;
    }
}

// } Driver Code Ends