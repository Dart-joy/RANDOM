    #include <bits/stdc++.h>
    #define ll long long
    using namespace std;
    int main(){
        int t ;
        cin >> t;
        while(t--){
            int n ;
            cin >> n ;
            vector<pair<int ,int>>pr(n);
            for(int i = 0 ; i < n ; i++){
                cin >> pr[i].first>>pr[i].second;
            }
            set<int>yo;
            for(int i = 0 ; i < n ; i++){yo.insert(pr[i].first);yo.insert(pr[i].second);}
            map<int , int>what;
            int ind = 0 ;
            for(auto it = yo.begin() ; it != yo.end() ; it++){
                what[*it] = ind ;
                ind++;
            }
            map<int ,vector<pair<int ,int>>>fin;
            for(int i = 0 ; i <n ; i++){
                int uu = what[max(pr[i].second , pr[i].first)] + what[min(pr[i].second , pr[i].first)];
                fin[uu].push_back(pr[i]);
            }
            for(auto it = fin.begin();it!=fin.end();it++){
                auto vec = it->second;
                for(int i = 0 ;i<vec.size();i++){
                    cout<<vec[i].first<<" "<<vec[i].second<<" ";
                }
            }
            cout<<endl;
    }
    }
