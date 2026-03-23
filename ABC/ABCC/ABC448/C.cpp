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
    ll N,Q;
    cin >> N >> Q;
    vector<ll>  A(N);
    rep(i,N)cin >> A[i];
    vector<ll> CopyA = A;
    sort(CopyA.begin(),CopyA.end());
    vector<ll> M(6);
    rep(i,6){
        M[i] = CopyA[i];
    }
    while(Q--){
        ll K;
        cin >> K;
        ll B[K];
        rep(i,K){
            cin >> B[i];
            B[i]--;
        }
        vector<ll> have = M;
        rep(i,K){
            rep(j,have.size()){
                if(have[j] == A[B[i]]){
                    have.erase(have.begin()+j);
                    break;
                }
            }
        }
        //rep(i,have.size())cout << have[i] << " ";
        //cout << endl;
        cout << have[0] << endl;
    }
}