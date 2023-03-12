//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> solveQueries(int N, int num, vector<int> &A, vector<vector<int>> &Q) {
        // code here
        unordered_map<int,int>mp;
        unordered_map<int,int>m;
        for(int i=0 ; i< N ; i++){
            mp[A[i]]++;
            m[A[i]]++;
        }
        int ans=0;
        vector<int>an;
        for(int i=0 ; i< Q.size(); i++){
             int cnt=0;
            for(int j= 0 ;j <= Q[i][1]; j++){
                if(j>=Q[i][0]){
                  if(mp[A[j]]==Q[i][2]){
                    cnt++;
                }  
                }
                
                mp[A[j]]--;
            }
            an.push_back(cnt);
            mp=m;
            
        }
        return an;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int num;
        cin>>num;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        vector<vector<int>> Q(num, vector<int>(3));
        for(int i=0;i<num;i++){
            for(int j=0;j<3;j++){
                cin>>Q[i][j];
            }
        }
        Solution obj;
        vector<int> res = obj.solveQueries(N, num, A, Q);
        
        for(auto ele:res){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
}

// } Driver Code Ends