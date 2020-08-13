#include <iostream>
using namespace std;

//https://codeforces.com/contest/1391/problem/A

int main() {
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	for(;t>0;--t){
		int n;
		cin>>n;
		for(int i=n;i>=1;--i) cout<<i<<" ";
		cout<<endl;
	}
}
