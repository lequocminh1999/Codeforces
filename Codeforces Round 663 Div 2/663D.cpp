#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int n,m;
vector<vector<int> > v;

//https://codeforces.com/contest/1391/problem/D

int f2[505000][3][3];
int f3[405000][3][3][3];

void test2(){
	int res=n*m;
	for(int j=0;j<m;++j){
		for(int c1=0;c1<=1;++c1){
			for(int c2=0;c2<=1;++c2){
				int cnt=(c1!=v[0][j])+(c2!=v[1][j]);
				if(j==0){
					f2[j][c1][c2]=cnt;
				}
				else{
					f2[j][c1][c2]=n*m+1;
					for(int d1=0;d1<=1;++d1){
						for(int d2=0;d2<=1;++d2){
							if((c1+c2+d1+d2)%2==0) continue;
							f2[j][c1][c2]=min(f2[j][c1][c2],f2[j-1][d1][d2]+cnt);
						}
					}
				}
				if(j==(m-1)) res=min(res,f2[j][c1][c2]);
			}
		}
	}
	cout<<res;
	return;
}

void test3(){
	int res=n*m;
	for(int j=0;j<m;++j){
		for(int c1=0;c1<=1;++c1){
			for(int c2=0;c2<=1;++c2){
				for(int c3=0;c3<=1;++c3){
					int cnt=(c1!=v[0][j])+(c2!=v[1][j])+(c3!=v[2][j]);
					if(j==0){
						f3[j][c1][c2][c3]=cnt;
					}
					else{
						f3[j][c1][c2][c3]=n*m+1;
						for(int d1=0;d1<=1;++d1){
							for(int d2=0;d2<=1;++d2){
								for(int d3=0;d3<=1;++d3){
									if((c1+c2+d2+d1)%2==0) continue;
									if((c3+c2+d2+d3)%2==0) continue;
									f3[j][c1][c2][c3]=min(f3[j][c1][c2][c3],f3[j-1][d1][d2][d3]+cnt);
								}
							}
						}
					}
					if(j==(m-1)) res=min(res,f3[j][c1][c2][c3]);
				}
			}
		}
	}
	cout<<res<<endl;
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=min(n,m);++i){
		vector<int> s;
		for(int j=1;j<=max(n,m);++j){
			s.push_back(0);
		}
		v.push_back(s);
	}
	if(n<=m){
		for(int i=0;i<n;++i){
			string s; cin>>s;
			for(int j=0;j<s.size();++j) if(s[j]=='1') v[i][j]=1;
		}
	}
	else{
		for(int i=0;i<n;++i){
			string s; cin>>s;
			for(int j=0;j<s.size();++j) if(s[j]=='1') v[j][i]=1;
		}
		swap(n,m);
	}
	if(min(n,m)>=4){
		cout<<-1;
		return 0;
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	if(n==2) test2();
	if(n==3) test3();

}
