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

stack<char> makeStack(string A){
    ll numB = 0;
    ll numX = 0;
    stack<char> Astack;
    rep(i,A.size()){
        if(A[i] == 'x'){
            numX++;
        }
        if(A[i] == '('){
            rep(j,numX){
                Astack.push('x');
            }
            Astack.push('(');
            numX=0;
        }
        if(A[i] == ')'){
            if(numX==2){
                if(!Astack.empty() &&Astack.top() == '('){
                    Astack.pop();
                }else{
                    Astack.push('x');
                    Astack.push('x');
                    Astack.push(')');
                    numX=0;
                }
            }else{
                rep(j,numX){
                    Astack.push('x');
                }
                Astack.push(')');
                numX=0;
            }
        }
    }
    rep(j,numX){
        Astack.push('x');
    }
    return Astack;
}
int main(){
    ll T;
    cin >> T;
    rep(_,T){
        string A,B;
        cin >> A >> B;
        stack<char> Astack = makeStack(A);
        stack<char> Bstack = makeStack(B);
        bool work = true;
        while(!Astack.empty() && !Bstack.empty()){
            if(Astack.top()!=Bstack.top()){
                work = false; break;
            }
            Astack.pop();
            Bstack.pop();
        }
        if(Astack.size()!=0 || Bstack.size()!=0){
            work = false;
        }
        if(work){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
}