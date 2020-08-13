#include <iostream>
using namespace std;

//https://codeforces.com/contest/1391/problem/B

void test(){
	int n,m;
	cin>>n>>m;
	int cnt=0;
	for(int i=1;i<=n;++i){
		string s; cin>>s;
		if(i==n){
			for(int j=0;j<s.size();++j){
				if(s[j]=='D') ++cnt;
			}
		}
		if(s[s.size()-1]=='R') ++cnt;
	}
	cout<<cnt<<endl;

}

int main() {
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	for(;t>0;--t){
		test();
	}
}
