#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int len = 4e5+10;
struct segtree{
    int sz;
    vector<ll>sum;
    void init(int n ){
        sz = 1 ;
        while(sz<n)sz*=2 ;
        sum.assign(2*sz , 0LL);
    }
    void set(int i , ll v , int x , int lx , int rx){
        if(rx-lx ==1){
            sum[x] = max(v , sum[x]) ;
            return ;
        }
        int m = (lx+rx)/2 ;
        if(i<m){
            set(i , v , 2*x+1 , lx , m) ;
        }
        else {
            set(i , v , 2*x+2 , m , rx);
        }
        sum[x] = max(sum[2*x+1] , sum[2*x+2]);
    }
    void set(int i , ll v){
        set(i , v , 0 , 0 , sz);
    }
    ll ert(int l , int r , int x , int lx , int rx){
        if(lx >= r || l>= rx) return 0 ;
        if(lx>= l && rx<=r) return sum[x] ;
        int m = (lx+rx)/2 ;
        ll s1 = ert(l , r , 2*x+1 , lx , m);
        ll s2 = ert(l , r , 2*x+2 , m , rx);
        return max(s1 ,s2) ;
    }
    //sum from l to r-1
    ll retsum(int l , int r){
        return ert(l , r , 0 , 0 , sz);
    }
};
int main() {
     int n ;
    cin >> n ;
    vector<ll>A(n) ;
    vector<pair<ll , int >>within(n);
    segtree gtree;
    gtree.init(n);
    for(int i = 0 ; i < n ; i++)cin >> A[i] ;
    for(int i = 0 ; i < n ; i++){
        within[i] = {A[i] , i};
    }
    stack<int>nextt;
    stack<int>prevv;
    vector<int>next(n , n);
    vector<int>prev(n , -1);
    for(int i = 0 ; i < n ; i++){
        while(!nextt.empty()){
            if(A[nextt.top()] <= A[i]){
                next[nextt.top()] = i ;
                nextt.pop() ;
            }
            else{
                break ;
            }
        }
        nextt.push(i);
    }
    for(int i = n-1; i >= 0 ; i--){
        while(!prevv.empty()){
            if(A[prevv.top()] <= A[i]){
                prev[prevv.top()]= i ;
                prevv.pop() ;
            }
            else{
                break ;
            }
        }
        prevv.push(i);
    }
    sort(within.begin() , within.end());
    for(int i = 0 ; i < n ; i++){
        int ind = within[i].second ;
        int a = prev[ind]+1;
        int b = next[ind];
        ll ans = 1 + gtree.retsum(a , b);
        gtree.set(ind , ans);
    }
    cout<<gtree.retsum(0 , n)<<endl;
}
