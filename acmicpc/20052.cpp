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
char S[MAX];
int seg[MAX*4],start = 1;
void add(int x,int v){
	x += start;
	seg[x] = v;
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
	scanf("%s",S+1);
	add(0,0);
	int xx = 0,len = strlen(S+1);
	for(int e=1;e<=len;e++){
		if(S[e]=='(') xx++;
		else xx--;
		add(e,xx);
	}
	int q;
	scanf("%d",&q);
	int ans = 0;
	while(q--){
		int l,r;
		scanf("%d%d",&l,&r);
		int lv = seg[l+start-1],rv = seg[r+start];
		if(lv==rv){
			int xx= getn(l,r-1);
			if(xx>=lv) ans++;
		}
	}
	printf("%d",ans);
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