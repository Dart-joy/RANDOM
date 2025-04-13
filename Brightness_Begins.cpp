    #include <bits/stdc++.h>
    #define ll long long
    using namespace std;
    const long long int num = 1e18 + 1e13 ;
    ll int dev(ll int k , ll int low , ll int high){
        if(low==high)return low;
        if(high==low+1){
            ll int z = low - floor(sqrt(low));
            if(z==k)return low;
            return high;
        }
        ll int mid = (low+high)/2;
        ll int y = mid - floor(sqrt(mid));
        if(y>=k)return dev(k , low , mid);
        return dev(k ,mid+1 , high);
    }
    int main(){
        int t ;
        cin >> t;
        while(t--){
            ll int k ;
            cin >> k ;
            cout<<dev(k , 1, num)<<endl;
    }
    }
