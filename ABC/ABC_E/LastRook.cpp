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
    A = 1;
    B = N+1;
    ll M;
    ll num;
    ll S = (N)/2 - 1;
    while(A+1 != B){
        M = (A+B)/2;
        cout << "? "<< A << " " << M-1 << " " << 1 << " " << N << endl;
        cin >> num;
        
        S = M - A;
        if(S - num == 0){
            A = M;
        }else{
            B = M;
        }
    }
    ll C,D;
    C = 1;
    D = N+1;
    S = (N)/2 - 1;
    while(C +1 != D){
        M = (C+D)/2;
        S = M - C;
        cout << "? "<< 1 << " " << N << " " << C << " " << M-1 << endl;

        cin >> num;
        
        if(S - num == 0){
            C = M;
        }else{
            D = M;
        }
    }
    cout << "! " << A << " " << C << endl;
}