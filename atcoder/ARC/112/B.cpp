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


void solve(int tc){
	lld B,C;
	scanf("%lld%lld",&B,&C);
	if(B==0){
		lld ans = 1;
		if(C>=2) ans += (C-2)/2 + 1;
		if(C>=3) ans += (C-3)/2 + 1;
		printf("%lld\n",ans);
	}else{
		if(B>0){
			lld ans = 1;
			if(C>=4) ans += (C-4)/2 + 1;
			ans += (C+1)/2;xcxcdd
			if(C>=2){
				ans += min(C-1,B*2-1);
			}
			printf("%lld\n",ans);
		}else{
			lld ans = 1;
			if(C>=1) ans += (C-1)/2 + 1;
			if(C>=2) ans += (C-2)/2 + 1;
			if(C>=3){
				ans += min(C-2,abs(B)*2-1);
			}
			printf("%lld\n",ans);
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
		scanf("%d",&tc);
	*/
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}