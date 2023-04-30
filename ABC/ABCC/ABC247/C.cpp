#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(int i = 1; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
void a(int o){
    if(o==1){
        cout << 1;
    }else{
    a(o-1);
    cout << " ";
    cout << o;
    cout << " ";
    a(o-1);

    }
}
int main(){
    int N;
    cin >> N;
    a(N);
    cout << endl;
}