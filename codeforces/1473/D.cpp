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

const int MAX =202020;
int seg[MAX*4][3];
int tot[MAX],start = 1;
char S[MAX];
void upd(int* a,int* b,int* c){
	int lm = min(b[1],b[0]+c[1]);
	int rm = max(b[2],b[0]+c[2]);
	a[0] = b[0] + c[0];
	a[1] = lm;
	a[2] = rm;
}
void add(int x,int v1,int v2){
	x += start;
	seg[x][0] = v1 + v2;
	seg[x][1] = v1;
	seg[x][2] = v2;
	for(int e=(x/2);e>=1;e/=2) upd(seg[e],seg[e*2],seg[e*2+1]);
}
pi getn(int l,int r){
	l += start;
	r += start;
	int ll[3],rr[3];
	memset(ll,0,sizeof(ll));
	memset(rr,0,sizeof(rr));
	while(l<=r){
		if(l&1){
			int nll[3];
			upd(nll,ll,seg[l++]);
			for(int e=0;e<3;e++) ll[e] = nll[e];
		}
		if(!(r&1)){
			int nrr[3];
			upd(nrr,seg[r--],rr);
			for(int e=0;e<3;e++) rr[e] = nrr[e];
		}
		l >>= 1;
		r >>= 1;
	}
	int ans[3];
	upd(ans,ll,rr);
	return mk(ans[1],ans[2]);
}
void solve(int tc){
	int n,m;
	start = 1;
	scanf("%d%d%s",&n,&m,S+1);
	while(start<=n+1) start *= 2;
	for(int e=0;e<2*start;e++) seg[e][0] = seg[e][1] = seg[e][2] = 0;
	for(int e=1;e<=n;e++){
		tot[e] = tot[e-1];
		if(S[e]=='+'){
			tot[e]++;
			add(e,0,1);
		}else{
			tot[e]--;
			add(e,-1,0);
		}
	}
	while(m--){
		int l,r;
		scanf("%d%d",&l,&r);
		pi f1 = getn(0,l-1);
		pi f2 = getn(r+1,n+1);
		f2.x += tot[l-1];
		f2.y += tot[l-1];
		int lx = min(f1.x,f2.x),rx = max(f1.y,f2.y);
		printf("%d\n",rx-lx+1);
	}
}


int main(void){
	/*
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	*/
	int tc = 1;
	
		scanf("%d",&tc);
	
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}