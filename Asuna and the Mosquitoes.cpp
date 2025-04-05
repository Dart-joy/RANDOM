    #include <bits/stdc++.h>
    #define ll long long
    using namespace std;
    int main() {
        int t;
        cin >> t;
        while(t--){
            vector<ll int>even ;
            vector<ll int >odd ;
            int n ;
            cin >> n ;
            for(int i = 0 ; i < n ; i++){
                ll int A ;
                cin >> A ;
                if(A%2==0)even.push_back(A);
                else odd.push_back(A);
            }
            ll int dum1 =0 ;
            ll int dum2 =0;
            ll int mx1 = 0 ; ll int mx2 = 0 ;
            for(int i = 0 ; i<even.size();i++){
                dum1+=even[i];mx1 = max(mx1 , even[i]);
            }
            for(int i = 0 ; i<odd.size();i++){
                dum2+=odd[i];mx2 = max(mx2 , odd[i]);
            }
            if(dum1==0 || dum2 == 0 )cout<<max(mx2 ,mx1)<<endl;
            else cout<<dum1 + dum2- (ll int)(odd.size()) +1 <<endl;

        }

        return 0;
    }
