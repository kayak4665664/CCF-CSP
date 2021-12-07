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

int  m,n,x,y;
struct dian{
	int num;
	int x,y;
}dians[2000];

bool cmp(dian a,dian b){
	int j1=(x-a.x)*(x-a.x)+(y-a.y)*(y-a.y);
	int j2=(x-b.x)*(x-b.x)+(y-b.y)*(y-b.y);
	if(j1!=j2) return j1<j2;
	else return a.num<b.num;
}

int main(){
	cin>>n>>x>>y;
	for(int i=0;i<n;++i){
		cin>>dians[i].x>>dians[i].y;
		dians[i].num=i+1;
	}
	sort(dians,dians+n,cmp);
	for(int i=0;i<3;++i) cout<<dians[i].num<<endl;
	return 0;
}