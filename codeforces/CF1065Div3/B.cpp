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
        ll N;
        cin >> N;
        ll A[N];
        rep(i,N){
            cin >> A[i];
        }
        if(A[0] == -1 || A[N-1] == -1){
            cout << 0 << endl;
        }else{
            cout << abs(A[N-1] - A[0]) << endl;
        }
        if(A[0] == -1 && A[N-1] == -1){
            A[0] = 0;
            A[N-1] = 0;
        }
        if(A[0] == -1){
            A[0] = A[N-1];
        }
        if(A[N-1] == -1){
            A[N-1] = A[0];
        }
        rep(i,N){
            if(A[i] == -1)A[i] = 0;
            cout << A[i] << " ";
        }cout << endl;
    }
}