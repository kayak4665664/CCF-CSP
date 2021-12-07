#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<string>
#include<algorithm>
#include<queue>
#include<iomanip>
#include<vector>
#include<cstring>
#include<sstream>
#include<map>
using namespace std;

int  n,k,t,xl,yd,xr,yu;
int dl,jg;
vector<pair<int,int>> jm[2000];

int main(){
	cin>>n>>k>>t>>xl>>yd>>xr>>yu;
	for(int i=0;i<n;++i){
		for(int j=0;j<t;++j){
			int x,y;
			cin>>x>>y;
			jm[i].push_back(make_pair(x,y));
		}
	}
	for(int i=0;i<n;++i){
		int cnt=0;
		int max=-1;
		int ddl=0;
		for(int j=0;j<t;++j){
			if(jm[i][j].first>=xl&&jm[i][j].first<=xr&&jm[i][j].second>=yd&&jm[i][j].second<=yu){
				++cnt;
				++ddl;
				if(ddl>max) max=ddl;
			}else ddl=0;
		}
		if(cnt) ++jg;
		if(max>=k) ++dl;
	}
	cout<<jg<<endl;
	cout<<dl<<endl;
	return 0;
}