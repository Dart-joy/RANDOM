    #include <bits/stdc++.h>
    #define ll long long
    using namespace std;
    const int num = 2e5+5;
    int main(){
        int t ;
        cin >> t;
        while(t--){
            ll int n ; ll int x ;
            cin >> n >> x ;
            vector<ll int>A(n+5,0);
            for(int i = 0 ; i < n ; i++){
                int y ;
                cin >> y;
                if(y<n+5)A[y]+=1;
            }
            int mex = 0 ;
            for(int i = 0 ; i < n+5;i++){
                if(A[i]>0){
                    mex++;
                    if(i+x<n+5){A[i+x]+=A[i]-1;A[i]=1;}
                }
                else break;
            }
            cout<<mex<<endl;
    }
    }
