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
    ll t;
    cin >> t;
    rep(_,t){
        ll Px,Py,Qx,Qy,Rx,Ry,Sx,Sy;
        cin >> Px >> Py >> Qx >> Qy >> Rx >> Ry >> Sx >> Sy;
        if((Qx-Px) * (Sy-Ry) != (Sx-Rx) * (Qy-Py)){
            cout << "Yes" << endl;
            continue;
        }else{
            ll mid1X = (Px + Qx);
            ll mid2X = (Rx + Sx);
            ll mid1Y = (Py + Qy);
            ll mid2Y = (Ry + Sy);
            if((mid2X - mid1X) * (Qx-Px) == -1 * (mid2Y - mid1Y) * (Qy-Py)){
                cout << "Yes" << endl;
                continue;
            }else{
                cout << "No" << endl;
                continue;
            }
        }
    }
}