//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int distributeTicket(int N, int k) {
        // code here
        stack<int>st;
        queue<int>q;
        for(int i = 1 ; i <= N ; i++){
            st.push(i);
            q.push(i);
        }
        int cnt=0;
        while(cnt!=N){
            for(int i = 0 ; i<k ; i++){
                int x=q.front();
                q.pop();
                cnt++;
                if(cnt==N) return x;
            }
            for(int i = 0 ; i<k ; i++){
                int x=st.top();
                st.pop();
                cnt++;
                if(cnt==N) return x;
            }
            
        }
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        Solution obj;
        int res = obj.distributeTicket(N, K);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends