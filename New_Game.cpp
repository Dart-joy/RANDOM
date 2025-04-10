    #include <bits/stdc++.h>
    #define ll long long
    using namespace std;
    int main(){
        int t ;
        cin >> t;
        while(t--){
            int n , k ;
            cin >> n >> k ;
            map<int , int > cnt ;
            for(int i = 0 ; i < n ; i++){
                int y ;
                cin >> y;
                cnt[y]++;
            }
            int prev = -10;
            vector<vector<int>>cont(n+3);
            int p = 0;
            for(auto it = cnt.begin() ; it!=cnt.end();it++){
                if(it->first == prev+1){
                    if(cont[p].size()==0){
                        cont[p].push_back(it->second);
                    }
                    else{
                       cont[p].push_back(cont[p][cont[p].size()-1] +it->second);
                    }
                    prev+=1;
                }
                else{
                    p++;
                    prev = it->first;
                    cont[p].push_back(it->second);
                }
            }
            set<int>uo;
            for(int i = 0 ; i < n+3 ; i++){
                if(cont[i].size()!=0){
                    if(cont[i].size()<=k){
                        uo.insert(cont[i][cont[i].size()-1]);
                    }
                    else{
                        uo.insert(cont[i][k-1]);
                        for(int j = k ; j<cont[i].size();j++){
                            uo.insert(cont[i][j]-cont[i][j-k]);
                        }
                    }
                }
            }
            auto it = uo.end();
            it--;
            cout<<*it<<endl;
        }
    }
