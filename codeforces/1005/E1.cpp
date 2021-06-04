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

const int MAX = 202020;
int arr[MAX];
map<int,int> mm;
void solve(int tc){
	int n,m;
	scanf("%d%d",&n,&m);
	int wh = -1;
	for(int e=1;e<=n;e++){
		scanf("%d",&arr[e]);
		if(arr[e]==m) wh = e;
	}
	mm[0]++;
	int vv = 0;
	for(int e=wh+1;e<=n;e++){
		if(arr[e]>m) vv++;
		else vv--;
		mm[vv]++;
	}
	lld ans = mm[1]+mm[0];
	vv = 0;
	for(int e=wh-1;e>=1;e--){
		if(arr[e]>m) vv++;
		else vv--;
		ans += mm[1-vv] + mm[-vv];
	}
	printf("%lld\n",ans);
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