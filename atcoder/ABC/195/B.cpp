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
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	c *= 1000;
	int mi=1e9,ma=-1e9;
	for(int e=1;e<=c;e++){
		if(1ll*e*a>1ll*c) break;
		int now = c - e*a;
		if(now%e){
			int f1 = (now/e);
			int f2 = f1 + 1;
			if(f1<=b-a&&f2<=b-a){
				mi = min(mi,e);
				ma = max(ma,e);
			}
		}else{
			int f1 = (now/e);
			if(f1<=b-a){
				mi = min(mi,e);
				ma = max(ma,e);
			}
		}
	}
	if(mi==1e9) printf("UNSATISFIABLE");
	else printf("%d %d\n",mi,ma);
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