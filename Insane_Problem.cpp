    #include <bits/stdc++.h>
    #define ll long long
    using namespace std;
    int main(){
        int t ;
        cin >> t;
        while(t--){
            ll int k , l1 , r1, l2 , r2 ;
            cin >> k >> l1 >> r1 >> l2 >> r2;
            vector<ll int >Kz(1 ,1);
            ll int u = 1 ;
            while(u<=LLONG_MAX/k){
                u = u*k;
                Kz.push_back(u);
            }
            ll int ans = 0 ;
            ll int zero = 0 ;
            for(int i = 0 ; i < Kz.size();i++){
                ll int y ;
                if(l2%Kz[i]==0)y = l2/Kz[i];
                else y = l2/Kz[i]+1;
                ans += max(zero , min(r2/Kz[i] ,r1) - max(l1 , y) +1) ;
            }
            cout<<ans<<endl;
        }
    }
