//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        // code here
        unordered_set<string>st(wordList.begin(),wordList.end());
        queue<vector<string>>q;
        q.push({beginWord});
        vector<vector<string>>ans;
        while(!q.empty()){
            int sz=q.size();
            vector<string>del;
            for(int i = 0 ; i < sz ; i++){
                vector<string>vec=q.front();
                q.pop();
                string word=vec.back();
                if(word==endWord) {
                    ans.push_back(vec);
                    continue;
                }
                string po=word;
                
                for(int j = 0 ; j < word.size() ; j++){
                    for(char x='a' ; x<='z' ; x++){
                        word[j]=x;
                        if(st.find(word)!=st.end()){
                            del.push_back(word);
                            vec.push_back(word);
                            q.push(vec);
                            vec.pop_back();
                        }
                    }
                    word=po;
                }
            }
            for(auto it:del){
                st.erase(it);
            }
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

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
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}
// } Driver Code Ends