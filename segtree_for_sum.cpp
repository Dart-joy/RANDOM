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
    void set(int i , int v , int x , int lx , int rx){
        if(rx-lx ==1){
            sum[x] = v ;
            return ;
        }
        int m = (lx+rx)/2 ;
        if(i<m){
            set(i , v , 2*x+1 , lx , m) ;
        }
        else {
            set(i , v , 2*x+2 , m , rx);
        }
        sum[x] = sum[2*x+1] + sum[2*x+2];
    }
    void set(int i , int v){
        set(i , v , 0 , 0 , sz);
    }
    ll ert(int l , int r , int x , int lx , int rx){
        if(lx >= r || l>= rx) return 0 ;
        if(lx>= l && rx<=r) return sum[x] ;
        int m = (lx+rx)/2 ;
        ll s1 = ert(l , r , 2*x+1 , lx , m);
        ll s2 = ert(l , r , 2*x+2 , m , rx);
        return s1+s2 ;
    }
    //sum from l to r-1
    ll retsum(int l , int r){
        return ert(l , r , 0 , 0 , sz);
    }
};
int main() {
    int n , m ;
    cin >> n >> m ;
    segtree gtree ;
    gtree.init(n);
    for(int i = 0 ; i < n ; i++){
        int x ; cin >> x ;
        gtree.set(i , x);
    }
    for(int i = 0 ; i < m ; i++){
        int op ; cin >> op ;
        if(op==1){
            int j , v ; cin >> j >> v;
            gtree.set(j , v);
        }
        else{
            int l , r ; cin >> l >> r ; //sum from l to r-1
            cout<<gtree.retsum(l , r)<<endl;
        }
    }
}
