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
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll T;
    cin >> T;
    rep (_,T){
        ll N,W;
        cin >> N >> W;
        ll nums[N];

        rep (j,N){
            cin >> nums[j];
        }
        ll semi_totals[2*W];

        rep (i,(2*W)){
            semi_totals[i] = 0;
        }

        rep (j,N){
            semi_totals[((j+1) % (2*W))] += nums[j];
        }

        ll total;
        total = 0;
        
        ll cumsum_semi[(2*W)+1];
        cumsum_semi[0] = 0;

        rep (j,((2*W) + 1)) {
            cumsum_semi[(j+1)] = semi_totals[(j)] + cumsum_semi[j];
        }
        //rep(i,(2*W)+1){
        //    cout << cumsum_semi[i] << " ";
        //}cout << endl;
        total = (cumsum_semi[(W)]);

        int x = (2*W);
        rep (i, ((2*W)+1)){
            if ((i+W) < ((2*W)+1)){
                if (abs(cumsum_semi[(i+W)] - cumsum_semi[i]) < total) {
                    total = abs(cumsum_semi[(i+W)] - cumsum_semi[i]) ;
                }
            }
            else{
                if (abs(cumsum_semi[x] - cumsum_semi[i] + cumsum_semi[W- x + i]) < total) {
                    total = abs(cumsum_semi[x] - cumsum_semi[i] + cumsum_semi[W- x + i]) ;
                } 
            }
        }

        cout << total << endl;

        

    }

    return 0;
}