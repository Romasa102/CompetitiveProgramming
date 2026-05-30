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
    ll t;cin>>t;
    rep(_,t){
        ll X1,Y1,R1,X2,Y2,R2;
        cin >> X1 >> Y1 >> R1 >> X2 >> Y2 >> R2;

        if(abs(X2-X1)*abs(X2-X1) + abs(Y2-Y1)*abs(Y2-Y1) > abs(R1+R2) * abs(R1+R2) || abs(X2-X1)*abs(X2-X1) + abs(Y2-Y1)*abs(Y2-Y1) < (max(R1,R2)-min(R1,R2)) * (max(R1,R2)-min(R1,R2))){
            cout << "No" << endl;
        }else{
            cout << "Yes" << endl;
        }
    }
}