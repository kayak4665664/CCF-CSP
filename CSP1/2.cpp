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

int n,r,L,t,a;
int A[700][700],ans;
int xa,xb,ya,yb,cnt;


int main(){
	scanf("%d%d%d%d",&n,&L,&r,&t);
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			scanf("%d",&a);
			if(j==0) A[i][j]=a;
			else A[i][j]=A[i][j-1]+a;
		}
	}
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			xa=i-r;
			if(xa<0) xa=0;
			xb=i+r;
			if(xb>=n) xb=n-1;
			ya=j-r;
			if(ya<0) ya=0;
			yb=j+r;
			if(yb>=n) yb=n-1;
			int cnt=0,sum=0;
			for(int k=xa;k<=xb;++k){
				cnt+=1+yb-ya;
				if(ya==0) sum+=A[k][yb];
				else sum+=A[k][yb]-A[k][ya-1];
			}
			if(1.0*sum/cnt<=t) ++ans;
		}
	}
	cout<<ans<<endl;
	return 0;
}