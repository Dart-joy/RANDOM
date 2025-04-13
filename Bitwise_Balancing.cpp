    #include <bits/stdc++.h>
    #define ll long long
    using namespace std;
    const int num = 2e5+5;
    int main(){
        int t ;
        cin >> t;
        while(t--){
            ll  int b , c ,d ;
            cin >> b >> c >> d;
            ll int c1 = c ; ll int b1 = b ;ll int d1 = d;
            ll int a = pow(2 , 61);
            ll int yu = (a|b) - (a&c);
            if(yu==d){cout<<a<<endl;continue;}
            vector<int> barr(62 , 0);
            vector<int> carr(62 , 0);
            vector<int> darr(62 , 0);
            vector<int> aarr(62 , 0);
            for(int i = 0 ; i < 62 ; i ++){
                barr[i] = b%2;
                carr[i] = c%2;
                darr[i] = d%2;
                b = b/2;
                c = c/2;
                d = d/2;
            }
            bool imp = 1 ;
            for(int i = 0 ;i < 62 ; i++){
                    if(barr[i] ==0 && carr[i]==0 && darr[i]==0){
                        aarr[i]=0;
                    }
                    else if(barr[i] ==1 && carr[i]==0 && darr[i]==0){
                        imp = 0 ;break;
                    }
                    else if (barr[i] ==1 && carr[i]==0 && darr[i]==1){
                        aarr[i]=0;
                    }else if (barr[i] ==1 && carr[i]==1 && darr[i]==1){
                        aarr[i]=0;
                    }else if (barr[i] ==0 && carr[i]==0 && darr[i]==1){
                        aarr[i]=1;
                    }else if (barr[i] ==0 && carr[i]==1 && darr[i]==1){
                        imp = 1;
                    }else if (barr[i] ==0 && carr[i]==1 && darr[i]==0){
                        aarr[i]=0;
                    }else if (barr[i] ==1 && carr[i]==1 && darr[i]==0){
                        aarr[i]=1;
                    }
            }
            if(imp==0)cout<<-1<<endl;
            else{
                ll int y = 0 ;
                for(int i = 61 ; i>=0; i--){
                    y =2*y+aarr[i];
                }
                ll int yh = (y|b1) - (y&c1);
                if(yh==d1)cout<<y<<endl;
                else cout<<-1<<endl;
            }
    }
    }
