    #include <bits/stdc++.h>
    #define ll long long
    using namespace std;
    int main(){
        int t ;
        cin >> t;
        while(t--){
            int n ; double x ;
            cin >> n >> x;
            ll int sum = 0 ;ll int maxx=0;
            for(int i = 0 ; i < n ; i++){
                ll int y;
                cin>> y;
                maxx= max(maxx, y);
                sum+=y;
            }
            ll int per = ceil(sum/x);
            cout<<max(per , maxx)<<endl;

    }
    }
