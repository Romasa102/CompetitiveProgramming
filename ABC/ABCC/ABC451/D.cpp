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

    vector<set<string>> nums(10);

    ll cur = 1;
    while (cur < 1000000000) {
        string s = to_string(cur);
        nums[s.size()].insert(s);
        cur *= 2;
    }

    repp(i,2,10){
        for(auto nm : nums[i]){
            cout << nm << " ";
        }cout << endl;
        rep(j,i){
            //add j th row + i-j th row;
            for(auto str : nums[j]){
                for(auto str2 : nums[i-j]){
                    nums[i].insert(str + str2);
                }
            }
        }
    }
    vector<ll> accnums;
    repp(i,1,10){
        for(auto j : nums[i]){
            accnums.push_back(stoi(j));
        }
    }
    sort(accnums.begin(),accnums.end());
    cout << accnums[N-1] << endl;
}