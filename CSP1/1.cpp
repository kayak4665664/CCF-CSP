#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdlib>
#include<cctype>
#include<vector>
#include<set>
#include<map>
#include<stack>
#include<unordered_map>
#include<sstream>
#include<algorithm>
using namespace std;

int n,m,L,t;
int A[600][600],h[400];


int main(){
	cin>>n>>m>>L;
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			cin>>t;
			++h[t];
		}
	}
	for(int i=0;i<L;++i) cout<<h[i]<<' ';
	cout<<endl;
	return 0;
}