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
    unordered_map<ll,ll> num;
    vector<ll> Ans;
    repp(i,1,2237){
        repp(j,i+1,3301){
            if(i*i+j*j > N)break;
            num[i*i+j*j]++;
        }
    }
    for(auto it = num.begin();it!=num.end();it++){
        if(it->second == 1){
            Ans.push_back(it->first);
        }
    }
    sort(Ans.begin(),Ans.end());
    cout << Ans.size() << endl;
    rep(i, Ans.size()){
        cout << Ans[i] << " ";
    }cout << endl;
}