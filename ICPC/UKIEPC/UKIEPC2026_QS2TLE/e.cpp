#include <bits/stdc++.h>
using namespace std;

int main(){
    double a,b,c;
    cin>>a>>b>>c;
    double x=max(max(a/12,b/12),c/40);
    fixed(cout);
    cout<<setprecision(10)<<x*12-a<<' '<<x*12-b<<' '<<x*40-c<<endl;
}