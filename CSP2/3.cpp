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

int Q;
struct qj{
	string lx;
	int k;
	vector<pair<char,int>> srd;
	qj(){
	}
};

int shuru[10100][5000];
int shuchu[10100][5000];
vector<qj> qjs;

bool func(int num,int s){
	string lx=qjs[num].lx;
	int k=qjs[num].k;
	if(lx=="NOT"){
		if(qjs[num].srd[0].first=='I') return !shuru[s][qjs[num].srd[0].second-1];
		else return !func(qjs[num].srd[0].second-1,s);
	}else if(lx=="AND"){
		bool ans=1;
		for(int i=0;i<k;++i){
			if(qjs[num].srd[i].first=='I') ans=ans&&shuru[s][qjs[num].srd[i].second-1];
			else ans=ans&&func(qjs[num].srd[i].second-1,s);
		}
		return ans;
	}else if(lx=="OR"){
		bool ans=0;
		for(int i=0;i<k;++i){
			if(qjs[num].srd[i].first=='I') ans=ans||shuru[s][qjs[num].srd[i].second-1];
			else ans=ans||func(qjs[num].srd[i].second-1,s);
		}
		return ans;
	}else if(lx=="XOR"){
		bool ans;
		if(qjs[num].srd[0].first=='I') ans=shuru[s][qjs[num].srd[0].second-1];
		else ans=func(qjs[num].srd[0].second-1,s);
		for(int i=1;i<k;++i){
			if(qjs[num].srd[i].first=='I'){
				if(ans==shuru[s][qjs[num].srd[i].second-1]) ans=0;
				else ans=1;
			}else{
				bool tmp=func(qjs[num].srd[i].second-1,s);
				if(ans==tmp) ans=0;
				else ans=1;
			}
		}
		return ans;
	}else if(lx=="NAND"){
		bool ans=1;
		for(int i=0;i<k;++i){
			if(qjs[num].srd[i].first=='I') ans=ans&&shuru[s][qjs[num].srd[i].second-1];
			else ans=ans&&func(qjs[num].srd[i].second-1,s);
		}
		return !ans;
	}else if(lx=="NOR"){
		bool ans=0;
		for(int i=0;i<k;++i){
			if(qjs[num].srd[i].first=='I') ans=ans||shuru[s][qjs[num].srd[i].second-1];
			else ans=ans||func(qjs[num].srd[i].second-1,s);
		}
		return !ans;
	}
}

bool flag=false;
int number;
void addr(map<int,int> &rvis,int num){
	for(int i=0;i<qjs[num].k;++i){
		if(qjs[num].srd[i].first=='I') continue;
		else{
			rvis[qjs[num].srd[i].second]=1;
			if(rvis[number]){
				flag=true;
				return;
			}
			addr(rvis,qjs[num].srd[i].second-1);
		}
	}
}

bool check(int N){
	for(int j=0;j<N;++j){
		flag=false;
		map<int,int> rvis;
		number=j+1;
		addr(rvis,j);
		if(flag) return false;
	}
	return true;
}

int main(){
	scanf("%d",&Q);
	while(Q--){
		int M,N,S;
		scanf("%d%d",&M,&N);
		qjs.clear();
		for(int i=0;i<N;++i){
			qj tqj=qj();
			cin>>tqj.lx>>tqj.k;
			string tmp;
			for(int j=0;j<tqj.k;++j){
				cin>>tmp;
				char tc=tmp[0];
				tmp=tmp.substr(1,tmp.length()-1);
				tqj.srd.push_back(make_pair(tc,stoi(tmp)));
			}
			qjs.push_back(tqj);
		}
		scanf("%d",&S);
		for(int i=0;i<S;++i){
			for(int j=0;j<M;++j){
				scanf("%d",&shuru[i][j]);
			}
		}
		for(int i=0;i<S;++i){
			scanf("%d",&shuchu[i][0]);
			for(int j=1;j<=shuchu[i][0];++j){
				scanf("%d",&shuchu[i][j]);
			}
		}
		if(!check(N)) puts("LOOP");
		else{
			for(int i=0;i<S;++i){
				for(int j=1;j<=shuchu[i][0];++j){
					cout<<func(shuchu[i][j]-1,i);
					if(j!=shuchu[i][0]) putchar(' ');
				}
				putchar('\n');
			}
		}
	}
	return 0;
}