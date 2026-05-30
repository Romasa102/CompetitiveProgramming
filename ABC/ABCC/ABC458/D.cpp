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
    ll X;
    cin >> X;
    ll curMid = X;
    multiset<ll> smaller_set;
    multiset<ll> larger_set;
    ll Q;
    cin >> Q;
    ll A[Q],B[Q];
    
    rep(i,Q){
        cin >> A[i] >> B[i];
        if(curMid < A[i] && curMid < B[i]){
            larger_set.insert(A[i]);
            larger_set.insert(B[i]);
            smaller_set.insert(curMid);
            curMid = *larger_set.begin();
            larger_set.erase(larger_set.begin());
        }else if(curMid > A[i]  && curMid > B[i]){    
            smaller_set.insert(A[i]);
            smaller_set.insert(B[i]);
            larger_set.insert(curMid);
            curMid = *smaller_set.rbegin();
            smaller_set.erase(prev(smaller_set.end()));
        }else{
            if(A[i] > curMid){
                larger_set.insert(A[i]);
                smaller_set.insert(B[i]);
            }else{
                larger_set.insert(B[i]);
                smaller_set.insert(A[i]);
            }
        }
        cout << curMid << endl;
    }
}