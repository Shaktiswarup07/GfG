//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isStraightHand(int N, int groupSize, vector<int> &hand) {
        // code here
        if(N%groupSize) return 0;
        else{
            // int gs=groupSize;
            vector<int>v;
            sort(hand.begin(), hand.end());
            map<int,int>mp;
            for(int i = 0 ; i < hand.size() ; i++) mp[hand[i]]++;
            while(mp.size()!=0){
                vector<int>vec;
                int cnt=groupSize;
                for(auto i:mp){
                    cnt--;
                    v.push_back(i.first);
                    vec.push_back(i.first);
                    if(cnt==0) break;
                    // mp[i.first]--;
                }
                for(auto j:vec){
                    mp[j]--;
                    if(mp[j]==0) mp.erase(j);
                }
                // cout<<mp.size()<<endl;
                // break;
                
            }
            // for(auto i:v) cout<<i<<" ";
            // cout<<endl;
            for(int i = 0 ; i < v.size() ; i+=groupSize){
                // cout<<i<<endl;
                for(int j=i; j<i+groupSize-1; j++){
                    // cout<<v[j+1]<<" "<<v[j]<<endl;
                    if(v[j+1]==v[j]+1) continue;
                    else return false;
                }
            }
            return true;
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, groupSize;
        cin >> N >> groupSize;

        vector<int> hand(N);
        for (int i = 0; i < N; i++) cin >> hand[i];

        Solution obj;
        int ans = obj.isStraightHand(N, groupSize, hand);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends