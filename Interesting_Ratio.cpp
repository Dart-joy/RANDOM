    #include <bits/stdc++.h>
    #define ll long long
    using namespace std;
    int main() {
        int t;
        cin >> t;
      //pre compute the primes and their index
        int num = 1e7+1;
        vector<int>prime(num , 0);
        prime[1]=-1;
        for(int i = 2; i <= 3166 ; i ++){
            for(int j = 2*i ; j < num ; j+=i){
                prime[j]=-1;
            }
        }
        vector<int>p;
        for(int i = 2 ; i < num ; i++){
            if(prime[i]==0){
                p.push_back(i);
            }
        }
        map<int ,ll int>prime_num;
        for(int i = 0 ; i <p.size();i++){
            prime_num[p[i]] = i+1;
        }
        while(t--){
           int n ;
           cin >> n ;
           ll int ans=0;
           //only can be the prime multiple of the smaller
           for(int i = 1 ; i <= n ; i++){
                auto it = prime_num.upper_bound(n/i);
                if(it==prime_num.begin())continue;
                it--;
                ans+=it->second;
           }
           cout<<ans<<endl;
        }
 
        return 0;
    }
