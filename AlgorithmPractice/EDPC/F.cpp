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
    string S,T;
    cin >> S >> T;
    ll dp[S.size()+1][T.size()+1];
    rep(i,S.size()+1)rep(j,T.size()+1)dp[i][j]=0;
    rep(i,S.size()){
        string latest = "";
        rep(j,T.size()){
            if(S[i] == T[j]){
                if(dp[i][j] >= max(dp[i][j+1],dp[i+1][j])){
                    dp[i+1][j+1] = dp[i][j]+1;
                }else{
                    if(dp[i][j+1] > dp[i+1][j]){
                        dp[i+1][j+1] = dp[i][j+1];
                    }else{
                        dp[i+1][j+1] = dp[i+1][j];
                    }
                }
            }else{
                if(dp[i][j+1] > dp[i+1][j]){
                    dp[i+1][j+1] = dp[i][j+1];
                }else{
                    dp[i+1][j+1] = dp[i+1][j];
                }
            }
        }
    }
    ll cur = dp[S.size()][T.size()];
    deque<ll> ans;
    for(ll i = S.size();i > 0;i--){
        for(ll j = T.size(); j > 0;j--){
            if(dp[i][j] == cur &&  dp[i-1][j-1] == (cur-1) && dp[i-1][j] == (cur-1) && dp[i][j-1]==(cur-1)){
                ans.push_front(i);
                cur--;
                break;;
            }
        }
    }
    while(!ans.empty()){
        cout << S[ans.front()-1];
        ans.pop_front();
    }cout << endl;
}