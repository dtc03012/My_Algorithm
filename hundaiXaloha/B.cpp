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
pi arr[MAX];
int dp[MAX];
bool comp(pi a,pi b){
	if(a.y!=b.y) return a.y < b.y;
	return a.x < b.x;
}
int seg[MAX*4],start = 1;
void upd(int x,int v){
	x += start;
	seg[x] = v;
	for(int e=(x/2);e>=1;e/=2) seg[e] = max(seg[e*2],seg[e*2+1]);
}
int getn(int l,int r){
	l += start;
	r += start;
	int ans = 0;
	while(l<=r){
		if(l&1) ans = max(ans,seg[l++]);
		if(!(r&1)) ans = max(ans,seg[r--]);
		l >>= 1;
		r >>= 1;
	}
	return ans;
}
void solve(int tc){
	while(start<MAX) start *= 2;
	int n;
	scanf("%d",&n);
	for(int e=0;e<n;e++){
		scanf("%d%d",&arr[e].x,&arr[e].y);
	}
	sort(arr,arr+n,comp);
	for(int e=0;e<n;e++){
		int wh = lower_bound(arr,arr+e,mk(-1,arr[e].x+1),comp) - arr;
		if(wh==0) upd(e,1);
		else{
			wh--;
			int xx = getn(0,wh);
			upd(e,xx+1);
		}
	}
	printf("%d\n",getn(0,n-1));
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