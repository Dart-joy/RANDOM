    #include <bits/stdc++.h>
    #define ll long long
    using namespace std;
    int main(){
        int t ;
        cin >> t;
        while(t--){
            int n ;
            cin >> n ;
            string pzpz;
            cin >> pzpz;
            if(pzpz[0]=='s')pzpz[0] = '.';
            if(pzpz[n-1]=='p')pzpz[n-1] = '.';
            int undetected = -1;
            for(int i = 0 ; i <n ; i++){
                if(pzpz[i]=='.')continue;
                else if(undetected == -1 ){
                    if(pzpz[i]=='s')undetected = 1 ;
                    else undetected = 2;
                }
                else {
                    if(undetected == 1 && pzpz[i]=='p')undetected = 100;
                    if(undetected == 2 && pzpz[i]=='s')undetected = 100;
                }
            }
            if(undetected <= 6)cout<<"yes"<<endl;
            else cout<<"NO"<<endl;
        }
    }
