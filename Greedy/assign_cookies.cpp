class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int child=0;
        int cookie=0;
        int cnt=0;
        while(cookie<s.size() && child<g.size()){
            if(s[cookie]>=g[child]){
                child++;
                cnt++;
            }
            cookie++;
        }
        return cnt;
    }
};