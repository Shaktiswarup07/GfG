//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int minSubset(vector<int> &Arr,int N){
        sort(Arr.begin(),Arr.end(),greater<int>());
        long long int s=0;
        for(int i = 0 ; i < Arr.size() ; i++) s+=Arr[i];
        long long int p=0;
         int c=0;
        for(int i = 0 ; i < Arr.size() ; i++){
            p+=Arr[i];
            s-=Arr[i];
            c++;
            if(p>s){
                break;
            }
        }
        return c;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> Arr(N);
        for(int i=0;i<N;i++){
            cin>>Arr[i];
        }
        Solution ob;
        cout<<ob.minSubset(Arr,N)<<endl;
    }
    return 0;
}
// } Driver Code Ends