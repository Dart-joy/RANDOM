#include<bits/stdc++.h>
using namespace std ; 
class Solution {
public:
    int longestValidParentheses(string s) {
        int prev = -1 ; 
        int mx = 0 ; 
        int sum = 0 ; 
        int n = s.length();
        for(int i = 0 ; i < n ; i++){
            if(s[i]=='(')sum+=1 ; 
            if(s[i]==')')sum-=1;
            if(sum==0)mx = max(i-prev , mx) ;
            if(sum<0){
                sum=0 ; prev = i ; 
            }
        }
        sum = 0 ; 
        prev = -1 ;
        reverse(s.begin() , s.end());
        for(int i = 0 ; i < n ; i++){
            if(s[i]==')')sum+=1 ; 
            if(s[i]=='(')sum-=1;
            if(sum==0)mx = max(i-prev , mx) ;
            if(sum<0){
                sum=0 ; prev = i ; 
            }
        }
        return mx ; 
    }
};
int main(){
  cout<<"yeeehwaa"<<endl;
}
