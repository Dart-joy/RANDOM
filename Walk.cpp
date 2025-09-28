#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1e9 + 7 ;
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
vector<vector<ll>> matmul(vector<vector<ll>>&A , ll k ){
    int n = A.size();
    vector<vector<ll>>r(n , vector<ll>(n , 0));
    if(k==0LL){
        for(int  i= 0 ; i < n ; i++)r[i][i]=1;
        return r;
    }
    else if(k==1){
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++)r[i][j] = A[i][j] ;
        }
        return r ;
    }
    if(k%2==0){
    auto vec1 = matmul(A , k/2);
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j< n ; j++){
            for(int k = 0 ; k<n ; k++){
                r[i][j]=((vec1[i][k] * vec1[k][j])%MOD + r[i][j])%MOD ;
            }
        }
    }
    return r ;
    }
    else{
        auto vec1 = matmul(A , k/2);
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j< n ; j++){
            for(int k = 0 ; k<n ; k++){
                r[i][j]=((vec1[i][k] * vec1[k][j])%MOD + r[i][j])%MOD ;
            }
        }
    }
    vector<vector<ll>>r1(n , vector<ll>(n , 0));
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j< n ; j++){
            for(int k = 0 ; k<n ; k++){
                r1[i][j]=((r[i][k] * A[k][j])%MOD + r1[i][j])%MOD ;
            }
        }
    }
    return r1 ;
    }
}
int main() {
    int n ; ll k ;
    cin >> n >> k ;
    vector<vector<ll>>A(n , vector<ll>(n , 0));
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++)cin >> A[i][j];
    }
    auto vec = matmul(A , k);
    ll sum = 0 ;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            sum = (sum + vec[i][j])%MOD ;
        }
    }
    cout<<sum<<endl;
}
