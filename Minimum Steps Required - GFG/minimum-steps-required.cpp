//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

int minSteps(string str) {
    // Write your code here.
    int x=0,y=0;
    for(int i = 0 ; i < str.size() ; i++){
        if(str[i]=='a'){
            while(i<str.size()&&str[i]=='a'){
                i++;
            }
            x++;
        }
    }
    for(int i = 0 ; i < str.size() ; i++){
        if(str[i]=='b'){
            while(str[i]=='b'){
                i++;
            }
            y++;
        }
    }
    return min(x+1,y+1);
}

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        cout << minSteps(str) << endl;
    }
}

// } Driver Code Ends