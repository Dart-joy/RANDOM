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
void BFS(int start , vector<vector<int>>& edge , vector<int>&distance){
    queue<int> q ; 
    q.push(start) ; 
    distance[start] = 0 ; 
    while(!q.empty()){
        int node = q.front() ; q.pop() ; 
        for(auto nbr : edge[node]){
            if(distance[nbr] == -1){
                distance[nbr] = distance[node] + 1 ; 
                q.push(nbr) ; 
            }
        }
    }
}
int main(){
// MY FIRST SOS DP PROBLEM 
    int n ; cin >> n ; 
    vector<int> arr(n);
    int bits = 22  ; 
    vector<int> cnt(1<<bits , -1) ;
    int a = (1<<bits) -1 ; 
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i] ; 
        cnt[arr[i]] = arr[i] ;
    }
    for(int i = 0;i < bits; ++i) for(int mask = 0; mask < (1<<bits); ++mask){
        if(mask & (1<<i))
            {
                if(cnt[mask^(1<<i)]!= -1)cnt[mask] = cnt[mask^(1<<i)] ; 
            }
    }
    for(int i = 0 ; i < n ; i++){
        //cout<<a<<endl;
        cout<<cnt[(a^arr[i])]<<" ";
    }
    cout<<endl;
}
