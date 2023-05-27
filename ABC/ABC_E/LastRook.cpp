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
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, c, n) for (ll i = c; i < (n); ++i)
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    ll A,B;
    A = 0;
    B = (N+1)/2;
    ll num;
    ll S = (N+1)/2;
    while(true){
        cout << "? "<< A << " " << B << " " << 1 << " " << N << endl;
        cin >> num;
        if(S - num == 0){
            A = B+1;
            B += S/2;
            S = B - A + 1;
        }else{
            B -= S/2;
            S = B - A + 1;
        }
        if(A == B){
            break;
        }
    }
    ll C,D;
    S = (N+1)/2;
    while(true){
        cout << "? "<< A << " " << B << " " << C << " " << D << endl;
        cin >> num;
        if(num == 0){
            C = D+1;
            D += S/2;
            S = D - C + 1;
        }else{
            D -= S/2;
            S = D - C + 1;
        }
        if(C == D){
            break;
        }
    }
    cout << "! " << A << " " << D << endl;
}