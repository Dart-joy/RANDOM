#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1000000007LL;
vector<int> toposort(vector<vector<int>>&edges , int n ){
    vector<int>d(n+1 , 0);
    queue<int>q ;
    vector<int>vec ;
    for(int i = 1 ; i <=n ; i++){
        for(int nd : edges[i]){
            d[nd]++;
        }
    }
    for(int i = 1 ; i <= n ; i++){
        if(d[i]==0)q.push(i);
    }
    int cnt = 0 ;
    while(!q.empty()){
        int t = q.front();
        for(int i : edges[t] ){
            d[i]--;
            if(d[i]==0)q.push(i);
        }
        vec.push_back(t);
        q.pop();
        cnt++;
    }
    if(cnt==0){
        vec.push_back(-1);
    }
    if(cnt<n){
        vec[0] = -1 ;
    }
    return vec ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n , m ;
    cin >> n >> m ;
    string s ; cin >> s ;
    bool t = false ;
    vector<vector<int>>edges(n+1);
    for(int i = 0 ; i < m ; i++){
        int u , v ; cin >> u >> v ;
        if(u==v){
            t = true ;
        }
        edges[u].push_back(v);
    }
    if(t){
        cout<<-1<<endl;return 0 ;
    }
    auto vec = toposort(edges , n );
    if(vec[0]==-1){
        cout<<-1<<endl;return 0 ;
    }
    reverse(vec.begin() , vec.end());
    vector<vector<int>>dp(n+1 , vector<int>(26 , 0));
    int mm = 1 ;
    for(int i = 0 ; i < n ; i++){
        int node = vec[i];
        int p = s[node-1]-'a' ;
        dp[node][p]=1;
        for(int d: edges[node]){
            for(int j = 0 ; j < 26 ; j++){
                if(s[node-1]-'a' == j){
                    dp[node][j] = max(dp[node][j] , dp[d][j]+1) ;
                }
                else dp[node][j] = max(dp[node][j] , dp[d][j]);
                 mm = max(mm , dp[node][j]);
            }
        }
    }
    cout<<mm<<endl;
