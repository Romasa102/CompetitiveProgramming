#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    string T;
    cin >> T;
    P Ans;
    ll R = 0;
    rep(i,N){
        if(T[i] == 'S'){
            if(R == 0){
                Ans.first++;
            }else if(R == 1){
                Ans.second--;
            }else if(R == 2){
                Ans.first--;
            }else if(R == 3){
                Ans.second++;
            }
        }else if(T[i] == 'R'){
            R++;
            if(R >= 4){
                R = 0;
            }
        }
    }cout << Ans.first << " " << Ans.second;
}