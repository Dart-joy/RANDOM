#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int len = 4e5+10;
void merrge(map<int , vector<int>>&du , map<int , int>&noblack , vector<int>&par , int a , int b){
    int par1 = par[a] ; int par2 = par[b];
    if(par1==par2)return ;
    else{
        int a = du[par1].size();
        int b = du[par2].size();
        if(a<=b){
            for(int i = 0 ; i <a ; i++){
                du[par2].push_back(du[par1][i]);
                par[du[par1][i]]=par2;
            }
            du.erase(par1);
            noblack[par2]+=noblack[par1];

            noblack.erase(par1);
        }
        else{
            for(int i = 0 ; i <b ; i++){
                du[par1].push_back(du[par2][i]);
                par[du[par2][i]]=par1;
            }
            du.erase(par2);
            noblack[par1]+=noblack[par2];
            noblack.erase(par2);
        }
    }
}
int main() {
    int n ; cin >> n ;
    string t ; cin >> t ;
    vector<int>A(n+1 , 0);
    for(int i = 1 ; i <=n ; i++){
        if(t[i-1]=='0')A[i]= 1;
        A[i]+=A[i-1];
    }
    vector<ll>even(n+1 , 0);
    vector<ll>odd(n+1 , 0);
    for(int i = 0 ; i <=n ; i++){
        if(A[i]%2==0)even[i]=1;
        else odd[i]=1;
        if(i>0){
            even[i]+=even[i-1];
            odd[i]+=odd[i-1];
        }
    }
    ll an = 0;
    for(int i = 1 ; i<=n ; i++){
        if(A[i]%2==0)an+=even[i-1];
        else an+=odd[i-1];
    }
    cout<<an<<endl;
}
