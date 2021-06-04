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

const int MAX = 1010101;
int seg[MAX*4],start = 1;
pi arr[MAX];
void add(int x,int v){
	x += start;
	seg[x] = min(seg[x],v);
	for(int e=(x/2);e>=1;e/=2) seg[e] = min(seg[e*2],seg[e*2+1]);
}
int getn(int l,int r){
	l += start;
	r += start;
	int ans = 1e9;
	while(l<=r){
		if(l&1) ans = min(ans,seg[l++]);
		if(!(r&1)) ans = min(ans,seg[r--]);
		l >>= 1;
		r >>= 1;
	}
	return ans;
}
void solve(int tc){
	while(start<MAX) start *= 2;
	for(int e=0;e<start*2;e++) seg[e] = 1e9;
	int n,m;
	scanf("%d%d",&n,&m);
	for(int e=1;e<=n;e++){
		scanf("%d",&arr[e].x);
	}
	for(int e=1;e<=n;e++){
		scanf("%d",&arr[e].y);
	}
	add(min(m,arr[1].y+arr[1].x),0);
	sort(arr+2,arr+1+n);
	for(int e=2;e<=n;e++){
		if(arr[e].x<=arr[1].x) continue;
		int xx = getn(arr[e].x,m);
		if(xx==1e9) continue;
		add(min(arr[e].y+arr[e].x,m),xx+1);
	}
	int xx = getn(m,m);
	if(xx==1e9) xx = -1;
	printf("%d\n",xx);
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