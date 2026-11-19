#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <bitset>
#include <deque>
#include <functional>
#include <iostream>
#include <iomanip>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;
#define repp(i, c, n) for (ll i = c; i < (n); ++i)
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll X;
    cin >> X;
    vector<pair<P,string>> val; //{value, weight} string
    repp(i,2,50){
        ll A = i/2;
        ll C = i-A;
        ll weight = i*2-1;

        repp(value,1,A*C+1){
            ll q = value/A;
            ll r = value%A;

            string T = "";

            if(r == 0){
                rep(_,C-q){
                    T.append("C");
                }
                rep(_,A){
                    T.append("A");
                }
                rep(_,q){
                    T.append("C");
                }
            }else{
                rep(_,C-q-1){
                    T.append("C");
                }
                rep(_,r){
                    T.append("A");
                }
                T.append("C");
                rep(_,A-r){
                    T.append("A");
                }
                rep(_,q){
                    T.append("C");
                }
            }

            string S = "";
            rep(j,T.size()){
                S += T[j];
                if(j != T.size()-1){
                    S.append("R");
                }
            }

            val.push_back({{value,weight},S});
        }
    }
    //cout << val.size() << endl;
    vector<pair<ll,string>> dp(X+1,{1LL<<40,""});

    //dp[i] how to make i with minimum length

    dp[0] = {0,""};
    rep(i,X){
        string S = dp[i].second;
        ll curV = dp[i].first;
        rep(j,val.size()){
            ll elemV = val[j].first.first;
            ll elemW = val[j].first.second;
            string elemS = val[j].second;
            
            if((i+elemV)<= X && dp[i+elemV].first > curV + elemW){
                dp[i+elemV].first = dp[i].first + elemW;
                dp[i+elemV].second = S+elemS;
            }
        }
    }
    if(dp[X].second == ""){
        cout << "X" << endl;
    }else{
        cout << dp[X].second << endl;
    }
}