#include<bits/stdc++.h>
using namespace std ; 
class Solution {
public:
    int longestValidParentheses(string s) {
        int mx = 0;
        stack<int> par;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                par.push(1);
            } else {
                int y = 0;
                int done = 0;
                while (!par.empty()) {
                    if (par.top() % 2 == 0)
                        y += par.top();
                    else if (par.top() == 3) {
                        break;
                    } else if (done == 0 && par.top() == 1) {
                        done = 1;
                        y += 2;
                    } else if (done == 1 && par.top() == 1) {
                        break;
                    }
                    par.pop();
                }
                if (done == 1) {
                    par.push(y);
                    mx = max(mx, y);
                } else {
                    par.push(y);
                    par.push(3);
                }
            }
        }
        return mx;
    }
};
int main(){
  //cout<<"just function"<<endl;
}
