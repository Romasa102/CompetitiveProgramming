#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,P;
  int a [150000];
  int ans = 0;
  cin >> N >> P;
  for(int i = 0; i < N; i++){
    cin >> a[i];
  }
  for(int i = 0; i < N; i++){
    if(a[i] < P){
      ans++;
    }
  }
  cout << ans << endl;
}