#include <iostream>
using namespace std;

//https://codeforces.com/contest/1391/problem/C

int main() {
	ios_base::sync_with_stdio(false);
	int n; cin>>n;
	long long mod=1000000007;
	long long up=1;
	long long down=1;
	for(int i=1;i<=n;++i){
		if(i!=1) down=(down*2)%mod;
		up=(up*i)%mod;
	}
	cout<<(up-down+mod)%mod;
}
