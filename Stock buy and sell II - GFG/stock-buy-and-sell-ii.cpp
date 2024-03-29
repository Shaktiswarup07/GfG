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
  int Solve(int idx, int buy,vector<int>& prices,vector<vector<int>>&d){
    if(idx==prices.size()) return 0;
    if(d[idx][buy]!=-1) return d[idx][buy];
    int maxi=INT_MIN;
    if(buy)
    maxi=max(maxi,max(-prices[idx]+Solve(idx+1,0,prices,d),0+Solve(idx+1,1,prices,d)));
    else{
        maxi=max(maxi,max(prices[idx]+Solve(idx+1,1,prices,d),0+Solve(idx+1,0,prices,d)));
    }
    return d[idx][buy]=maxi;
}
    int stockBuyAndSell(int n, vector<int> &prices) {
        // code here
        // vector<vector<int>>dp(prices.size()+1,vector<int>(2,0));
        vector<int>prev(2,0),cur(2,0);
        for(int idx = n ; idx>=0 ; idx--){
            for(int buy=0;buy<2 ; buy++){
                if(idx==n) cur[buy]=0;
                else{
                    int maxi=INT_MIN;
                    if(buy)
                    maxi=max(maxi,max(-prices[idx]+prev[0],prev[1]));
                    else{
                        maxi=max(maxi,max(prices[idx]+prev[1],prev[0]));
                    }
                    cur[buy]=maxi;
                }
            }
            prev=cur;
        }
        
        return cur[1];
        // return Solve(0,1,prices,dp);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        vector<int> prices(n);
        Array::input(prices,n);
        
        Solution obj;
        int res = obj.stockBuyAndSell(n, prices);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends