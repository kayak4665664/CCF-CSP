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
using namespace std;

struct zhuangtai{
	int zt;
	string zhanyong;
	int guoqishike;
	zhuangtai(){
	}
};

long long n,N,tdef,tmin,tmax;
long long t,ip,guoqit;
string fasong,jieshou,leixing,H;
map<int,zhuangtai> pool;
 
int main(){
	cin>>N>>tdef>>tmax>>tmin>>H>>n;
	for(int i=1;i<=N;++i){
		zhuangtai tmp;
		tmp.zt=0;
		tmp.zhanyong="";
		tmp.guoqishike=0;
		pool[i]=tmp;
	}
	for(int i=0;i<n;++i){
		cin>>t>>fasong>>jieshou>>leixing>>ip>>guoqit;
		if((jieshou==H||jieshou=="*")||leixing=="REQ"){
			if(leixing!="DIS"&&leixing!="REQ") continue;
			if((jieshou=="*"&&leixing!="DIS")||(jieshou==H&&leixing=="DIS")) continue;
			if(leixing=="DIS"){
				int choose=0,minwfp,mingq;
				bool ok=false,okwfp=false,okgq=false;
				for(int j=1;j<=N;++j){
					if(pool[j].zt==1&&pool[j].guoqishike<=t){
						pool[j].zt=0;
						pool[j].zhanyong="";
						pool[j].guoqishike=0;
					}else if(pool[j].zt==2&&pool[j].guoqishike<=t){
						pool[j].zt=3;
						pool[j].guoqishike=0;
					}
					if(pool[j].zhanyong==fasong){
						ok=true;
						choose=j;
						break;
					}
					if(okwfp==false&&pool[j].zt==0){
						okwfp=true;
						minwfp=j;
					}
					if(okgq==false&&pool[j].zt==3){
						okgq=true;
						mingq=j;
					}
				}
				if(ok==false){
					if(okwfp==true) choose=minwfp;
					else if(okgq==true) choose=mingq;
					else continue;
				}
				pool[choose].zt=1;
				pool[choose].zhanyong=fasong;
				if(guoqit==0){
					pool[choose].guoqishike=t+tdef;
				}else{
					if(guoqit-t<tmin) pool[choose].guoqishike=t+tmin;
					else if(guoqit-t>tmax) pool[choose].guoqishike=t+tmax;
					else pool[choose].guoqishike=guoqit;
				}
				//
				cout<<H<<' '<<fasong<<' '<<"OFR"<<' '<<choose<<' '<<pool[choose].guoqishike<<endl;
				continue;
			}else if(leixing=="REQ"){
				if(jieshou!=H){
					for(int j=1;j<=N;++j){
						if(pool[j].zt==1&&pool[j].zhanyong==fasong){
							pool[j].zt=0;
							pool[j].zhanyong="";
							pool[j].guoqishike=0;
						}
					}
					continue;
				}else{
					if(ip<1||ip>N||pool[ip].zhanyong!=fasong){
						//
						cout<<H<<' '<<fasong<<' '<<"NAK"<<' '<<ip<<' '<<0<<endl;
						continue; 
					}
					pool[ip].zt=2;
					if(guoqit==0){
						pool[ip].guoqishike=t+tdef;
					}else{
						if(guoqit-t<tmin) pool[ip].guoqishike=t+tmin;
						else if(guoqit-t>tmax) pool[ip].guoqishike=t+tmax;
						else pool[ip].guoqishike=guoqit;
					}
					//
					cout<<H<<' '<<fasong<<' '<<"ACK"<<' '<<ip<<' '<<pool[ip].guoqishike<<endl;
					continue;
				}
			}
		}
	}
	return 0;
}