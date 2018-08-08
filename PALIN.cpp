#include<iostream>
// #include<vector>
using namespace std;

int main(){
  int t,j;
  cin>>t;
  for(j=0; j<t; j++){
    string c;
    cin>>c;
    // cout<<c.size()<<endl;
    int n = c.size();
    int left,right;
    left = 0;
    right = n-1;
    int flag=0;

    while(left<right){
      // cout<<c<<endl;
      if(c[left] != c[right]){
        flag=1;
      }
      if(c[left] > c[right]){
        c[right] = c[left];
      }
      left++;
      right--;
    }

    //if already a palindrome, increase the middle digits
    if(flag == 0){
      c[left]++;
      c[right] = c[left];
    }

    left--;
    right++;

    while(left >= 0){
      // cout<<c<<endl;
      if(c[left] < c[right]){
        c[left]++;
        c[right] = c[left];
        break;
      }
      left--;
      right++;
    }
    while(left >= 0){
      // cout<<c<<endl;
      c[right] = c[left];
      left--;
      right++;
    }

    cout<<c<<endl;
  }
  // 21212123
  // 21222212
  // 21222212
  //

  return 0;
}
