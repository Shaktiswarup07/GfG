//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void Solve(int N,vector<int>&arr,vector<bool>&isPrime,map<int,int>mp){
        
        int maxi=*max_element(arr.begin(),arr.end());
        isPrime[0]=1;isPrime[1]=1;
        for(auto i:mp){
            if(i.first>1){
                if(isPrime[i.first]==1){
                for(int j = 2*i.first; j<=maxi ; j+=i.first){
                    isPrime[j]=0;
                }
            }
            }
            
        }
    }
    int countSpecialNumbers(int N, vector<int> arr) {
        map<int,int>mp;
        for(int i = 0 ; i < N ; i++)mp[arr[i]]++;
        int maxi=*max_element(arr.begin(),arr.end());
        // cout<<maxi<<endl;
        vector<bool>isPrime(maxi+1,1);
        Solve(N,arr,isPrime,mp);
        // cout<<isPrime[99997]<<endl;
        int count=0;
        for(int i = 0 ; i < N ; i++){
            if(mp[1]>0 && arr[i]!=1) count++;
            else if(mp[arr[i]]>1) count++;
            else if(isPrime[arr[i]]==0) count++;
        }
        return count;
        // Code here
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.countSpecialNumbers(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends