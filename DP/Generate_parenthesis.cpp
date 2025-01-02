class Solution {
public:

    void sol(vector<string>&ans,string s,int open,int close,int n){
        if(s.size()==2*n){
            ans.push_back(s);
            return;
        }

        if(open<n){
            s+="(";
            sol(ans,s,open+1,close,n);
            s.pop_back();
        }

        if(close<open){
            s+=")";
            sol(ans,s,open,close+1,n);
            s.pop_back();
        }
    }

    vector<string> soltab(int n) {
        vector<vector<string>> dp(n + 1);  // dp[i] stores valid combinations for i pairs of parentheses
        dp[0] = {""};  // Base case: no pairs, only an empty string

        // Build dp table iteratively
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                for (const string& inside : dp[j]) {           // dp[j] for the inside parentheses
                    for (const string& outside : dp[i - j - 1]) {  // dp[i-j-1] for the outside parentheses
                        dp[i].push_back("(" + inside + ")" + outside);
                    }
                }
            }
        }

        return dp[n];  // Return all valid combinations for n pairs
    }

    
    vector<string> generateParenthesis(int n) {
        vector<string> output;
        string current;
        sol(output, current, 0, 0, n);
        return output;
        //return soltab(n);
    }
};