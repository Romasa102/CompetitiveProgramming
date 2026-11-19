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
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll T;
    cin >> T;
    rep(i,T){
        ll N;
        cin >> N;
        ll Q[N];
        vector<P> possibility;
        rep(i,N){
            cin >> Q[i];
            if(Q[i]-i-1<=0){
                possibility.push_back(make_pair(i+1,Q[i]));
            }
        }
        ll Ans = possibility.size();
        rep(i,possibility.size()){
            rep(j,possibility.size()){
                if(possibility[i].first > possibility[j].first && possibility[i].second <= possibility[j].second){
                    Ans--;
                    break;
                }else if(possibility[i].first >= possibility[j].first && possibility[i].second < possibility[j].second){
                    Ans--;
                    break;
                }
            }
        }
    }
}