//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
		
	int isDivisible(string s){
	    //complete the function here
	    int odd=0,even=0;
	    reverse(s.begin(),s.end());
	    for(int i = 0; i<s.size() ; i++){
	        if(i%2==0 && s[i]=='1') even++;
	        else if(i%2==1 && s[i]=='1') odd++;
	    }
	    return abs(odd-even)%3==0?1:0;
	}

};

//{ Driver Code Starts.
int main(){
    
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isDivisible(s) << endl;
    }
return 0;
}


// } Driver Code Ends