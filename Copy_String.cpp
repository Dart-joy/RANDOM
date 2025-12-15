// good question had fun 
#include<bits/stdc++.h>
#define ll long long int 
using namespace std ; 
const ll mod = 998244353 ;
ll pow4(ll a, ll b) {
    a %= mod;
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}
ll mod_inverse(ll a){
    return pow4(a, mod-2);
}
class min_queue_by_stack{
    stack<pair<int , int>> s1 , s2 ; 
    public:
    void push(int x){
        int mn = s1.empty() ? x : max(x , s1.top().second) ; 
        s1.push({x , mn}) ;
    }
    void pop(){
        if(s2.empty()){
            while(!s1.empty()){
                int val = s1.top().first ; 
                s1.pop() ; 
                int mn = s2.empty() ? val : max(val , s2.top().second) ; 
                s2.push({val , mn}) ; 
            }
        }
        if(s2.empty()){
            cout<<"Khali hai bc\n" ;
            return ; 
        }
        s2.pop() ; 
    }
    int returnmin(){
        if(s1.empty() && s2.empty()){
            cout<<"Khali hai bc\n" ;
            return -1 ; 
        }
        else if(s1.empty()){
            return s2.top().second ; 
        }
        else if(s2.empty()){
            return s1.top().second ; 
        }
        else{
            return max(s1.top().second , s2.top().second) ; 
        }
    }
} ;
class sparsetable{
    vector<vector<ll>> Table; 
public:
    sparsetable(vector<ll> &array){
        int n = array.size();
        int sz = 1;
        int y = 1;  
        while (y <= n) {
            y *= 2;
            sz++;
        }
        vector<ll> Arr(n, 0);
        for (int i = 0; i < sz; i++) {
            Table.push_back(Arr);
        }
        for (int i = 0; i < n; i++)
            Table[0][i] = array[i];
        for (int i = 1; (1 << i) <= n && i < sz; i++) {
            for (int j = 0; j + (1 << i) <= n; j++) {
                Table[i][j] = min(Table[i - 1][j] , Table[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    ll retsum(int i, int j){
        int len = j - i + 1;
        if (len <= 0) return 0;
        int sz = (int)log2(len);
        ll ans = 0;
        int sxx = len;

        // FIX 3: decompose length in binary correctly
        while (sxx > 0 && sz >= 0) {
            ll a = 1LL << sz;
            if (sxx >= a) {                  // use this block size if it fits
                ans += Table[sz][i];
                i   += a;
                sxx -= a;
            }
            sz--;
        }
        return ans;
    }
    ll retmin(int i , int j){
        int len = j - i + 1 ; 
        int k = log2(len) ; 
        return min(Table[k][i] , Table[k][j - (1<<k) + 1]) ; 
    }
};
int BFS(int start , vector<vector<int>>& edge , vector<int>&level){
    queue<int> q ; 
    q.push(start) ; 
    level[start] = 0 ;
    int mxlevel = 0 ; 
    while(!q.empty()){
        int node = q.front() ; q.pop() ; 
        for(auto nbr : edge[node]){
            if(level[nbr] == -1){
                level[nbr] = level[node] + 1 ; 
                mxlevel = max(mxlevel , level[nbr]) ;
                q.push(nbr) ; 
            }
        }
    }
    return mxlevel;
}
ll  rundp(int currlevel , vector<vector<int>>& edges , vector<vector<int>>& nodes_at_level , vector<int>& level , int n , vector<int>& ansarr){
    if(currlevel == nodes_at_level.size() -1){
        ll ret = 0 ; 
        for(int node: nodes_at_level[currlevel]){
            ansarr[node] = 1 ;
            ret = (ret + ansarr[node])%mod ;
        }
        return ret ;
    }
    ll kk = rundp(currlevel +1 , edges , nodes_at_level , level , n , ansarr) ;
    ll ret = 0 ; 
    for(int node: nodes_at_level[currlevel]){
        ansarr[node]= kk ; 
        if(currlevel!=0){
        for(int nbr : edges[node]){
            if(level[nbr]==currlevel+1){
                ansarr[node] = (ansarr[node]+ (mod - ansarr[nbr]))%mod ;
            }
        }
        }
        ansarr[node] = (ansarr[node]  + 1)%mod ;
        ret = (ret + ansarr[node])%mod ;
    }
    //cout<<"Level "<<currlevel<<" "<<ret<<endl;
    return ret;
}
void dfs(int start , vector<vector<int>>&edge , vector<int>&par){
    par[start] = 0 ;
    int cnt = 0 ; 
    for(int node : edge[start]){
        if(par[node]==-1){
            dfs(node , edge , par);
            if(par[node]==1){
                par[start] = 2 ;
            }
            cnt++;
        }
    } 
    if(cnt==0)par[start]=1;
}
void meximise(int n , vector<ll>&cnt){
    int sum = 0 ;
    for(int i = 0 ; i<=n; i++){
        if(cnt[i]==0){cnt[i]==sum ; break ;}
        if(cnt[i]>1){sum+=cnt[i] ; cnt[i]=0;}
    }
    return ;
}
bool isreplicatable(int n , vector<ll>&cnt , ll& limit , ll& rest , ll& ans ){
    limit = 0 ; 
    rest = n ; 
    ans = 0 ; 
    bool ret = true ;
    for(int i = 0 ; i<=n; i++){
        if(cnt[i]==0){ break ;}
        if(cnt[i]>1){ret = false ; limit++; }
        if(cnt[i]==1){
            rest-- ; 
            limit++;
            ans += (ll)(i) ;
        }
    }
    ans += rest*limit ; 
    return ret  ; 
}
const int MAXN = 2e5 + 10 ;
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    int t ;
    cin >> t ; 
    while(t--){
        int n , kmax ; 
        cin >> n >> kmax ; 
        string s ; 
        string t ; 
        cin >> s ; cin>>t ; 
        if(s[0]!=t[0]){
            cout<<-1<<"\n"; continue ; 
        }
        vector<vector<int>>cnt(26);
        for(int i = 0 ; i <n ; i++){
            cnt[(s[i]-'a')].push_back(i);
        }
        vector<int>move(n , 0);
        bool iff = true ; 
        int before = n-1 ; 
        for(int i =n-1 ; i>=1 ; i--){
            int ind = (t[i]-'a');
            if(cnt[ind].size()==0){
                iff = false ; break ; 
            }
            auto it = upper_bound(cnt[ind].begin() , cnt[ind].end() , before) ;
            if(it ==cnt[ind].begin()){
                iff = false ; break ; 
            }
            it-- ; 
            before = *it ; 
            move[i] = i - before ; 
            before = min(before , i-1);
        }
        if(!iff){
            cout<<-1<<"\n";continue; 
        }
        int k = 0 ; 
        for(int i = 0 ; i < n ; i++) k = max(k , move[i]);
        string neu = s;
        if(k>kmax){
            cout<<-1<<endl; continue ; 
        }
        cout<<k<<"\n"; 
        //cout<<s<<"\n";
        for(int i = 0 ; i<k ;i++){
            neu[0] = s[0] ; 
            for(int j = 1 ; j< n ; j++){
                if(move[j]>i)neu[j] = s[j-1];
                else neu[j] = s[j] ;
            }
            cout<<neu<<"\n" ; 
            s = neu ; 
        }
        //for(int i = 0 ; i < n ; i++)cout<<move[i]<<" ";
        //cout<<endl;
    }
}
