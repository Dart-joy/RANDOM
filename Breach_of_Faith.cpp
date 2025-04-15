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
           int n ;
           cin >> n ;
           vector<ll int >A(2*n , 0);
           for(int i = 0 ; i < 2*n ; i++){
            cin >> A[i];
           }
           sort(A.rbegin() , A.rend());
           ll int ne = A[0] ;
           for(int i = 1 ; i <2*n ;i++){
                if(i==1)ne+=A[i];
                else if(i%2==0)ne+=A[i];
                else ne-=A[i];
           }
           cout<<A[0]<<" "<<ne<<" "<<A[1]<<" ";
           for(int i = 1 ; i <n ;i++){
                cout<<A[2*i+1]<<" "<<A[2*i]<<" ";
           }
           cout<<endl;
    }
    }
