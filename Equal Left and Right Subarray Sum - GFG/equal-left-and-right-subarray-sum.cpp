//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }
 
    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    int equalSum(int N, vector<int> &A) {
        // code here
        int n=A.size();
        if(n==1){
            return 1;
        }
        int a=A[0],b=A[n-1];
        // if(n==3 && a==b) return 2;
        int i = 1,j = n-2;
        // int cnt=0;
        while(i<n && j>=0 && i!=j){
            // if(cnt==n) return -1;
            // cnt++;
            if(a<b){
                a+=A[i++];
            }
            else if(a>b){
                b+=A[j--];
            }
            else{
                a+=A[i++];
                b+=A[j--];
            }
        }
        if(i>=n || j<0 ) return -1;
        if(a==b)
        return i+1;
        return -1;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N; 
        scanf("%d",&N);
        
        
        vector<int> A(N);
        Array::input(A,N);
        
        Solution obj;
        int res = obj.equalSum(N, A);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends