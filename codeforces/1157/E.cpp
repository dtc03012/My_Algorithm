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
int A[MAX],seg[MAX*2*4],start = 1;
pi len[MAX*2*4];
void upd(int x,int v){
	x += start;
	seg[x] += v;
	for(int e=(x/2);e>=1;e/=2) seg[e] = seg[e*2] + seg[e*2+1];
}
int go(int node,int ns,int ne){
	if(ns+1==ne) return node - start;
	int mid = (ns+ne)/2;
	if(seg[node*2]) return go(node*2,ns,mid);
	return go(node*2+1,mid,ne);
}
int getn(int l,int r){
	l += start;
	r += start;
	int cnt[50];
	memset(cnt,-1,sizeof(cnt));
	int ll = 0,rr = 49;
	while(l<=r){
		if(l&1) cnt[ll++] = l++;
		if(!(r&1)) cnt[rr--] = r--;
		l >>= 1;
		r >>= 1;
	}
	for(int p=0;p<50;p++){
		if(cnt[p]==-1) continue;
		if(seg[cnt[p]]==0) continue;
		return go(cnt[p],len[cnt[p]].x,len[cnt[p]].y);
	}
}
void dfs(int node,int ns,int ne){
	len[node] = mk(ns,ne);
	if(ns+1==ne) return;
	int mid = (ns+ne)/2;
	dfs(node*2,ns,mid);
	dfs(node*2+1,mid,ne);
}
void solve(int tc){
	while(start<MAX*2) start *= 2;
	dfs(1,0,start);
	int n;
	scanf("%d",&n);
	for(int e=0;e<n;e++){
		scanf("%d",&A[e]);
	}
	for(int e=0;e<n;e++){
		int r;
		scanf("%d",&r);
		upd(r,1);
		upd(r+n,1);
	}
	for(int e=0;e<n;e++){
		int xx = (n-A[e])%n;
		int wh = getn(xx,xx+n-1)%n;
		printf("%d ",(wh+A[e])%n);
		upd(wh,-1);
		upd(wh+n,-1);
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