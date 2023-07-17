//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    queue<char>q;
		    map<char,int>mp;
		    string s;
		    for(int i = 0 ; i < A.size() ; i++){
		        mp[A[i]]++;
		        if(q.size() && mp[q.front()]!=1){
		            while( q.size() && mp[q.front()]!=1){
		                q.pop();
		            }
		        }
		      //  else{
		            if(mp[A[i]]==1)
		            q.push(A[i]);
		            if(q.size())
		            s+=q.front();
		            else
		            s+='#';
		      //  }
		        
		    }
		    return s;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends