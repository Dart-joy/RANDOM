    #include <bits/stdc++.h>
    #define ll long long
    using namespace std;
    int main() {
        int t;
        cin >> t;
        while(t--){
           int n ,m;
           cin >> n >>m;
           ll int X[n];ll int Y[n];
           for(int i = 0 ; i <  n ; i++)cin >> X[i];
           for(int i = 0 ; i < n ; i++)cin >> Y[i];
           map<ll int , double >yu;
           for(int i = 0 ; i < n ; i++){
            for(int j = X[i]-Y[i] ; j <=X[i] + Y[i];j++){
                yu[j] = max( yu[j] , floor(sqrt(Y[i]*Y[i] - (X[i]-j)*(X[i]-j))));
            }
           }
           ll int ans = 0 ;
           for(auto it = yu.begin() ; it!=yu.end() ; it++){
            ans+= it->second * 2 +1;
           }
           cout<<ans<<endl;
        }
 
        return 0;
    }
