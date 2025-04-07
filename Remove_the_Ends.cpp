    #include <bits/stdc++.h>
    #define ll long long
    using namespace std;
    int main(){
        int t ;
        cin >> t;
        while(t--){
            int n ;
            cin >> n ;
            ll int A[n];
            for(int i = 0 ; i < n ; i ++)cin >> A[i];
            vector<ll int>poccum(n , 0);
            vector<ll int>nig(n, 0);
            if(A[0]>0)poccum[0]=A[0];
            else nig[0]=abs(A[0]);
            for(int i = 1 ; i < n ; i++){
                if(A[i]>0){poccum[i]=abs(A[i])+poccum[i-1];
                nig[i]=nig[i-1];
                }
                else {
                    poccum[i]=poccum[i-1];
                    nig[i]=abs(A[i])+ nig[i-1];
                }
            }
            vector<ll int> dp(n , 0);
            dp[0] = abs(A[0]);
            for(int i = 1 ; i < n ; i++){
                if(A[i]<0){
                    dp[i] = dp[i-1]+abs(A[i]);
                }
                else{
                    dp[i] = max(dp[i-1] , poccum[i-1]+A[i]);
                }
            }
            cout<<dp[n-1]<<endl;
        }
    }
