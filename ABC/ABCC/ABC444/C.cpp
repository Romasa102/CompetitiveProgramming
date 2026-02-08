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
    ll N;cin >> N;
    ll A[N];rep(i,N)cin >>A[i];
    sort(A,A+N);
    ll k = A[0]+A[N-1];
    bool work = true;
    vector<ll> ans;
    rep(i,N/2){
        if(k!=(A[i]+A[N-i-1])){
            work = false;
        }
    }
    if(N%2==1)work=false;
    if(work)ans.push_back(k);
    k = A[N-1];
    work = true;
    vector<ll> temp;
    rep(i,N){
        if(A[i]!=k){
            temp.push_back(A[i]);
        }
    }
    rep(i,temp.size()/2){
        if((temp[i]+temp[temp.size()-i-1])!=k)work=false;
    }
    if(temp.size()%2==1)work=false;
    if(work)ans.push_back(k);
    sort(ans.begin(),ans.end());
    rep(i,ans.size()){
        cout << ans[i] << " ";
    }cout << endl;
}