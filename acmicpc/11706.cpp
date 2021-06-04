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
vector<int> v[MAX],nv[MAX];
char S[MAX];
int sz[MAX],ck[MAX],n,ck2[MAX];
map<int,int> mm[MAX];
map<int,int> f1,s1;
int zero;
int getsz(int x,int lx){
	sz[x] = 1;
	for(int e=0;e<sz(v[x]);e++){
		int nx = v[x][e];
		if(nx!=lx&&ck[nx]==0) sz[x] += getsz(nx,x);
	}
	return sz[x];
}
int getct(int x,int lx,int cap){
	for(int e=0;e<sz(v[x]);e++){
		int nx = v[x][e];
		if(nx!=lx&&ck[nx]==0&&sz[nx]*2>cap) return getct(nx,x,cap);
	}
	return x;
}
int make_centroid_tree(){
	getsz(1,-1);
	int rt = getct(1,-1,n);
	queue<int> q;
	q.push(rt);
	ck[rt] = 1;
	while(!q.empty()){
		int x = q.front();q.pop();
		for(int e=0;e<sz(v[x]);e++){
			int nx = v[x][e];
			if(ck[nx]==0){
				getsz(nx,-1);
				int k = getct(nx,-1,sz[nx]);
				nv[k].push_back(rt);
				nv[rt].push_back(k);
				q.push(k);
				ck[k] = 1;
			}
		}
	}
	return rt;
}
void dfs(int x,int lx,int tot1,int k1,int tot2,int k2){
	if(S[x]=='('){
		tot1++;
		tot2--;
		k1++;
		k2--;
	}else{
		tot1--;
		tot2++;
		k1--;
		k2++;
	}
	if(tot1>=0&&k1>=0) f1[tot1]++;
	if(tot2>=0&&k2>=0) s1[tot2]++;
	for(int e=0;e<sz(v[x]);e++){
		int nx = v[x][e];
		if(nx!=lx&&ck2[nx]==0) dfs(nx,x,tot1,min(0,k1),tot2,min(0,k2));
	}
}
lld dfs(int x,int lx){
	lld tot = 0;
	ck2[x] = 1;
	map<int,int> f2,s2;
	f2[0] = 1;
	s2[0] = 1;
	for(int e=0;e<sz(v[x]);e++){
		int nx = v[x][e];
		if(nx!=lx&&ck2[nx]==0){
			dfs(nx,-1,0,0,0,0);
			for(auto k : f1){
				int vf = k.x;
				if(S[x]=='(') vf++;
				else vf--;
				tot += 1ll*s2[vf]*k.y;
			}
			for(auto k: s1){
				int vf = k.x;
				if(S[x]==')') vf++;
				else vf--;
				tot += 1ll*f2[vf]*k.y;
			}
			for(auto k : f1) f2[k.x] += k.y;
			for(auto k : s1) s2[k.x] += k.y;
			f1.clear();
			s1.clear();
		}
	}
	for(int e=0;e<sz(nv[x]);e++){
		int nx = nv[x][e];
		if(nx!=lx) tot += dfs(nx,x);
	}
	return tot;
}
int main(void){
	/*
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	*/
	scanf("%d%s",&n,S+1);
	for(int e=0;e<n-1;e++){
		int a,b;
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	int crt = make_centroid_tree();
	lld ans = dfs(crt,-1);
	printf("%lld",ans);
	return 0;
}
