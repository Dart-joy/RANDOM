    #include <bits/stdc++.h>
    #define ll long long
    using namespace std;
    int main(){
        int t ;
        cin >> t;
        while(t--){
           ll int n , m ;
           cin >> n >> m ;
           vector<ll int>A(m , 0);
           for(int i = 0 ; i < m ; i++){
            cin >> A[i];
           }
           sort(A.begin() , A.end());
           vector<ll int>Cum(m , 0);
           Cum[m-1]=A[m-1];
           for(int i = m-2 ;i>=0 ; i--){
            Cum[i] = A[i]+Cum[i+1];
           }
           ll int cnt = 0 ;
           for(int i = 0 ; i < m ; i++){
            if(A[i]==n)cnt++;
           }
           ll int deduct = cnt*(cnt-1);
           deduct+=cnt*(m-cnt);
           auto itend = A.end();
           ll int d = 0 ;
           for(int i = 0 ; i< m ; i++){
                ll int rem = n - A[i];
                ll int y = A[i];
                A[i]=-10;
                auto it = lower_bound(A.begin() , A.end() , rem);
                if(it==A.end())continue;
                int ind =(itend - it);
                d+= (Cum[m-ind] + y*ind - ind*n + ind);
           }

           cout<<2*(d-deduct)<<endl;
    }
    }
