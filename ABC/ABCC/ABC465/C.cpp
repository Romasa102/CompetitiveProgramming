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
    ll N;
    string S;
    cin >> N >> S;
    vector<ll> ans(N,-1);
    bool isT = false;
    ll top = 0;
    ll end = N-1;
    for(ll i = N-1; i >= 0; i--){
        if(S[i] == 'o'){
            isT = !isT;
            if(isT){
                ans[top] = i+1;
                top++;
            }else{
                ans[end] = i+1;
                end--;
            }
        }else{ 
            if(isT){
                ans[top] = i+1;
                top++;
            }else{
                ans[end] = i+1;
                end--;
            }
        }
    }
    rep(i,N){
        cout << ans[i] << " ";
    }cout << endl;
}