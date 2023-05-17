//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        // Code here
        queue<pair<string,int>>q;
        q.push({startWord,1});
        unordered_set<string>st(wordList.begin(),wordList.end());
        st.erase(startWord);
        while(!q.empty()){
            pair<string,int>p=q.front();
            q.pop();
            string x=p.first;
            string z=x;
            int k=p.second;
            if(x==targetWord) return k;
            for(int i = 0 ; i < x.size() ; i++){
                for(char j = 'a' ; j <= 'z' ; j++){
                    x[i]=j;
                    if(st.find(x)!=st.end()){
                        q.push({x,k+1});
                        st.erase(x);
                    }
                }
                x=z;
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends