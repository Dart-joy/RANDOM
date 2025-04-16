    #include <bits/stdc++.h>
    #define ll long long
    const ll int mod = 998244353;
    using namespace std;
    int main(){
        int t ;
        cin >> t;
        while(t--){
           int n ;
           cin >> n;
           ll int A[n];
           for(int i = 0 ; i <n ; i++)cin >> A[i];
           vector<ll int>AA(n ,0);
           vector<ll int>BB(n ,0);
           vector<ll int>CC(n ,0);
           if(A[0]==1)AA[0]=1;
           for(int i = 1; i< n ;i++){
            if(A[i]==1){
                AA[i]=AA[i-1]+1;
            }
            else AA[i] = AA[i-1] ;
           }
           for(int i= 1 ; i< n ;i++){
                if(A[i]==2){
                    BB[i] = ((BB[i-1]+ BB[i-1])%mod + AA[i])%mod;
                }
                else{
                    BB[i] = BB[i-1];
                }
           }
           for(int i = 2 ; i< n ;i++){
             if(A[i]!=3){
                CC[i] = CC[i-1] ;
             }
             else{
                CC[i] = (BB[i-1] + CC[i-1])%mod;
             }
           }
           cout<<CC[n-1]<<endl;

    }
    }
