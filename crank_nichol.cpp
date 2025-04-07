    #include <bits/stdc++.h>
    #define ll long long
    using namespace std;
    double func(double x){
        if(x<=0.5) return 2*x ;
        else return 2- 2*x;
    }
    void thomas(vector<vector<double>>&mat ,vector<double>&Y ){ // not exactly but works in this purpose 
        mat[0][1] = mat[0][1]/mat[0][0];
        Y[0] = Y[0]/mat[0][0];
        mat[0][0] = 1;
        for(int i = 1 ; i < mat.size();i++){
            mat[i][i] = mat[i][i]/mat[i][i-1] ; if(i+1<mat.size()){mat[i][i+1] = mat[i][i+1]/mat[i][i-1];}
            Y[i] = Y[i]/mat[i][i-1];
            mat[i][i-1] = 0 ; mat[i][i] -=mat[i-1][i]; if(i+1<mat.size()){mat[i][i+1]-=mat[i-1][i+1];}
            Y[i]-=Y[i-1];
            if(i+1<mat.size()){mat[i][i+1] = mat[i][i+1]/mat[i][i];}
            Y[i] = Y[i]/mat[i][i];mat[i][i]=1;
        }
        for(int i = mat.size()-2;i>=0;i--){
            Y[i]-=Y[i+1]*mat[i][i+1];
        }
    }
    vector<double> crank(vector<double>&prev , double delx , double delt , double k ){
        double lambda = (2*delx * delx)/(k*delt);
        vector<double>Y(prev.size()-2);
        vector<vector<double>>mat(prev.size()-2 , vector<double>(prev.size()-2 , 0));
        for(int i = 1 ; i < prev.size()-1;i++){
            Y[i-1] = -1*prev[i+1] +(2-lambda)*prev[i] - prev[i-1];
            if(i-2>=0)mat[i-1][i-2] = 1;
            mat[i-1][i-1] = -1*(2+lambda);
            if(i<mat.size())mat[i-1][i] = 1;
        }
        thomas(mat , Y);
        return Y ;
    }
    int main() {
        int n = 11;
        int x = 11; // 0 to 1 with 0.1 gap
        double delx = 0.1;
        double delt = 0.1;
        int k = 1 ;
        vector<vector<double>>temp(n , vector<double>(x , 0));
        for(int i = 0 ; i < x ; i++){
            temp[0][i] = func(i*delx);
        }
        for(int i = 0 ; i < n ; i++){
            temp[i][0] = 0 ;
            temp[i][x-1] = 0 ;
        }
        for(int i = 1 ; i <n ; i++){
            auto yo = crank(temp[i-1] , delx , delt , k); // solution dU/dx = 1 . d2U/dt2 assume d to be partial dev
            for(int j = 1 ; j < x-1 ;j++){
                temp[i][j] = yo[j-1];
            }
        }
        for(int i = n-1 ; i >=0 ; i-- ){
            for(int j = 0 ; j < x; j ++)cout<<temp[i][j]<<" ";
            cout<<endl;
        }
    }
