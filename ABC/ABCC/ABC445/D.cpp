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
    ll H,W,N;
    cin >> H >> W >> N;
    ll curH = H;
    ll curW = W;
    P origin = {0,0};
    vector<P> hw(N);
    rep(i,N){
        cin >> hw[i].first >> hw[i].second;
    }
    vector<P> hSort(N);
    vector<P> wSort(N);
    rep(i,N){
        hSort[i].first=hw[i].first;
        hSort[i].second = i;
    }
    rep(i,N){
        wSort[i].first = hw[i].second;
        wSort[i].second = i;
    }
    sort(hSort.begin(),hSort.end());
    sort(wSort.begin(),wSort.end());
    vector<P> ans(N,{-1,-1});
    while(true){
        auto curTallest = hSort[hSort.size()-1];
        auto curWidest = wSort[wSort.size()-1];
        if(curTallest.first == curH){
            if(ans[curTallest.second].first != -1){
                hSort.pop_back();
                continue;
            }
            ans[curTallest.second] = origin;
            origin.second+=hw[curTallest.second].second;
            curW-=hw[curTallest.second].second;
            hSort.pop_back();
        }else if(curWidest.first == curW){
            if(ans[curWidest.second].first != -1){
                wSort.pop_back();
                continue;
            }
            ans[curWidest.second] = origin;
            origin.first+=hw[curWidest.second].first;
            curH-=hw[curWidest.second].first;
            wSort.pop_back();
        }else{
            break;
        }
    }
    rep(i,N){
        cout << ans[i].first + 1<< " " << ans[i].second + 1 << endl;
    }
}