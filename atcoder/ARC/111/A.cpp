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

lld n,m;
pl dfs(lld N){
	if(N==0) return mk(0,1%m);
	if(N==1){
		lld xx = (10/m);
		return mk((xx%m),10%m);
	}
	pl xx = dfs(N/2);
	lld f1 = (xx.y*xx.x*2)%m;
	lld f2 = (xx.y*xx.y);
	f1 = (f1+(f2/m))%m;
	f2 %= m;
	if(N%2==0){
		return mk(f1,f2);
	}else{
		f1 = (f1*10)%m;
		f2 = (f2*10);
		f1 = (f1+(f2/m))%m;
		f2 %=m;
		return mk(f1,f2);
	}
}
void solve(int tc){
	scanf("%lld%lld",&n,&m);
	printf("%lld\n",dfs(n).x);
}


int main(void){
	/*
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	*/
	int tc = 1;
	/*
		scanf("%d",&tc);
	*/
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}