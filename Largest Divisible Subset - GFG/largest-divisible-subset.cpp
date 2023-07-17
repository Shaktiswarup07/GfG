//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> LargestSubset(int n, vector<int>& nums) {
        // Code here
        sort(nums.begin(),nums.end());
        // int n=nums.size();
        vector<int>dp(n,1);
        for(int i = 0 ; i < n ; i++){
            int maxi=0;
            for(int j = 0 ; j < i ; j++){
                if((nums[i]%nums[j])==0){
                    maxi=max(maxi,dp[j]);
                }
            }
            dp[i]+=maxi;
        }
        int mxel=max_element(dp.begin(),dp.end())-dp.begin();
        vector<int>ans;
        ans.push_back(nums[mxel]);
        while(mxel>=0){
            int k=dp[mxel];
            int el=nums[mxel];
            while(mxel>=0 && (dp[mxel]!=k-1|| el%nums[mxel]!=0)){
                mxel--;
            }
            if(mxel>=0)
            ans.push_back(nums[mxel]);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        vector<int> res = obj.LargestSubset(n, arr);
        int isValidSeq = 1, sz = res.size();
        for (int i = 0; i < sz; i++) {
            for (int j = i + 1; j < sz; j++) {
                if ((res[i] % res[j]) == 0 || (res[j] % res[i]) == 0)
                    continue;
                else {
                    isValidSeq = 0;
                    break;
                }
            }
        }
        cout << isValidSeq << " " << sz << endl;
    }
    return 0;
}
// } Driver Code Ends