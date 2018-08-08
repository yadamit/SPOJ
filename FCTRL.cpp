#include <iostream>
#include<cmath>
using namespace std;

int zeros(int n){
	if(n==0) return 0;
	return n/5+zeros(n/5);
}
int main() {

	int i,t,n;
	cin>>t;
	for(i=0; i<t; i++){
		cin>>n;
		cout<<zeros(n)<<endl;
	}


	return 0;
}
