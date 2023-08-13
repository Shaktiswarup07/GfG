//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.'
        int xr=0;
        for(auto i:nums){
            xr^=i;
        }
        
        int cnt=0;
        while((xr&1)!=1){
            cnt++;
            xr>>=1;
        }
        int xor1=0,xor2=0;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] & (1<<cnt)){
                xor1^=nums[i];
            }
            else{
                xor2^=nums[i];
            }
        }
        vector<int>v{xor1,xor2};
        if(xor1>xor2) swap(v[0],v[1]);
        return v;
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends