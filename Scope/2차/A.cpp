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

const int MAX = 101010;
int tot[MAX];
void solve(int tc){
	int n;
	int h,m,s;
	scanf("%d",&n);
	scanf("%2d:%2d:%2d",&h,&m,&s);
	int total = h * 3600 + m * 60 + s;
	for(int e=1;e<=n;e++){
		int h1,m1;
		scanf("%2d:%2d",&h1,&m1);
		int nt = h1* 60 + m1;
		tot[e] = nt;
	}
	for(int e=1;e<=n;e++) tot[e] += tot[e-1];
	int x = 1e9,ans = 0;
	for(int e=1;e<=n;e++){
		int lv = tot[e-1];
		int wh = lower_bound(tot+e,tot+n+1,total+lv) - tot;
		if(wh==n+1) wh--;
		int diff = wh - e + 1;
		if(diff>ans){
			ans = diff;
			x = e;
		}
	}
	printf("%d %d\n",ans,x);
}


int main(void){
	
	// ios_base :: sync_with_stdio(false);
	// cin.tie(NULL);
	// cout.tie(NULL);
	
	int tc = 1;
	/*
		cin >> tc;
	*/
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}