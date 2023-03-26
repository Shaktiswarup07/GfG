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
    vector<int> getDistinctDifference(int N, vector<int> &A) {
        // code here
        vector<int>v1(N),v2(N);
        map<int,int>mp;
        // cout<<mp.size()<<endl;
        for(int i = 0 ; i < N ; i++){
            v1[i]=mp.size();
            mp[A[i]]++;
        }
        mp.clear();
        for(int i=N-1;i>=0;i--){
            v2[i]=mp.size();
            mp[A[i]]++;
        }
        for(int i = 0 ; i < v1.size() ; i++){
            v1[i]=v1[i]-v2[i];
        }
        return v1;
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
        vector<int> res = obj.getDistinctDifference(N, A);
        
        Array::print(res);
        
    }
}

// } Driver Code Ends