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

const int MAX = 1001010;
char S[MAX];
int seg[MAX*4][3],start = 1;
void upd(int* xx,int* ll,int* rr){
	xx[0] = ll[0] + rr[0] + min(ll[1],rr[2]);
	xx[1] = ll[1] + rr[1] - min(ll[1],rr[2]);
	xx[2] = ll[2] + rr[2] - min(ll[1],rr[2]);
}
void add(int x,int v1,int v2){
	x += start;
	seg[x][1] = v1;
	seg[x][2] = v2;
	for(int e=(x/2);e>=1;e/=2) upd(seg[e],seg[e*2],seg[e*2+1]);
}
int getn(int l,int r){
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
	return ans[0];
}
set<int> s;
void solve(int tc){
	while(start<MAX) start *= 2;
	int q;
	scanf("%s%d",S+1,&q);
	int xx = 0;
	int len = strlen(S+1);
	for(int e=1;e<=len;e++){
		if(S[e]=='(') add(e,1,0);
		else add(e,0,1);
	}
	while(q--){
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%d\n",getn(l,r)*2);
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