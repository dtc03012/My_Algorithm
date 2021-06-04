#include <bits/stdc++.h>
using namespace std;
typedef long long int lld;
typedef pair<int,int> pi;
typedef pair<lld,lld> pl;
typedef pair<int,lld> pil;
typedef pair<lld,int> pli;
typedef vector<int> vit;
typedef vector<vit> vitt;
typedef vector<lld> vlt;
typedef vector<vlt> vltt;
typedef vector<pi> vpit;
typedef vector<vpit> vpitt;
typedef long double ld;
#define x first
#define y second
#define pb push_back
#define all(v) v.begin(), v.end()
#define sz(x) (int)x.size()
#define mk(a,b) make_pair(a,b)
bool isrange(int y,int x,int n,int m){
	 if(0<=y&&y<n&&0<=x&&x<m) return true;
	 return false;
}
int dy[4] = {1,0,-1,0},dx[4]={0,1,0,-1},ddy[8] = {1,0,-1,0,1,1,-1,-1},ddx[8] = {0,1,0,-1,1,-1,1,-1};

int calc(lld now,lld num,lld mod){
	if(num==0) return 1;
	if(num==1) return now;
	int now2 = calc(now,num/2,mod);
	if(num%2==0) return (now2*now2)%mod;
	return (((now2*now2)%mod)*now)%mod;
}
void solve(int tc){
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	a %= 10;
	if(a==1||a==5||a==6) printf("%d",a);
	else{
		if(a==4||a==9){
			if(b%2==0) printf("%d",(a*a)%10);
			else printf("%d\n",a);
		}else{
			int x = (b%4);
			int y = calc(x,c,4);
			int f1 = a , f2 = (f1*a)%10, f3 = (f2*a)%10,f4 = (f3*a)%10;
			if(y==1) printf("%d\n",f1);
			if(y==2) printf("%d\n",f2);
			if(y==3) printf("%d\n",f3);
			if(y==0) printf("%d\n",f4);
		}
	}
}


int main(void){
	/*
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	*/
	int tc = 1;
	/*
		cin >> tc;
	*/
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}