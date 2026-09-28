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
    cin >> N;
    ll A[N];
    rep(i,N)cin >> A[i];
    vector<ll> threeVs; // if the new number is bigger than thirdV then thirdV is updated by secondV
    rep(i,3){
        threeVs.push_back(A[i]);
    }
    sort(threeVs.begin(),threeVs.end(),greater<ll>());

    cout << threeVs[2] << endl;
    repp(i,3,N){
        if(A[i] > threeVs[2]){
            threeVs.erase(--threeVs.end());
            threeVs.push_back(A[i]);

            sort(threeVs.begin(),threeVs.end(),greater<ll>());
        }
        cout << threeVs[2] << endl;
    }
}