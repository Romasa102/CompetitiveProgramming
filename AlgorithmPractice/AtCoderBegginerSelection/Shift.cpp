#include <bits/stdc++.h>
using namespace std;

int main(){
  int count;
  int A[210];
  cin >> count;
  for(int i = 0; i < count; i++){
    cin >> A[i];
  }
  bool CanDevide = true;
  int DevideTime = 0;
  while(true){
    for (int i = 0; i < count; i++)
    {
      if(A[i]%2 != 1){
        A[i] = A[i]/2;
      }
      else{
        CanDevide = false;
        break;
      }
    }
    if(CanDevide == false){
      break;
    }else{      
      DevideTime += 1;
    }
  }
  cout << DevideTime << endl;
}