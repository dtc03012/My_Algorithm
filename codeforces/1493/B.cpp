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
int tran[10];
bool can(int rh,int rm,int h,int m){
	int xh = 0,xm = 0;
	if(tran[rm%10]==-1||tran[rm/10]==-1||tran[rh%10]==-1||tran[rh/10]==-1) return false;
	xh = tran[rm%10]*10 + tran[rm/10];
	xm = tran[rh%10]*10 + tran[rh/10];
	if(xh<h&&xm<m) return true;
	return false;
}
void solve(int tc){
	memset(tran,-1,sizeof(tran));
	tran[0] = 0;
	tran[1] = 1;
	tran[8] = 8;
	tran[2] = 5;
	tran[5] = 2;
	int h,m;
	scanf("%d%d",&h,&m);
	int rh,rm;
	scanf("%2d:%2d",&rh,&rm);
	while(!can(rh,rm,h,m)){
		rm++;
		if(rm==m){
			rm = 0;
			rh++;
			if(rh==h){
				rh = 0;
			}
		}
	}
	printf("%02d:%02d\n",rh,rm);
}


int main(void){
	
	// ios_base :: sync_with_stdio(false);
	// // cin.tie(NULL);
	// cout.tie(NULL);
	
	int tc = 1;
	
		cin >> tc;
	
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}