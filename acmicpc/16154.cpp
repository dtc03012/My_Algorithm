#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
const int MAX = 201010;
const int NMAX = 1000001;
int n,q;
int arr[MAX],dp[NMAX],num[8],pm[NMAX][8],ck[NMAX],len[NMAX];
vector<int> go[NMAX];
lld getn(int x){
	if(x==1) return 0;
	lld ans = 0;
	for(int e=0;e<(1<<len[x]);e++){
		int tot = 0,kk = 1;
		for(int p=0;p<len[x];p++) if(e&(1<<p)){
			tot++;
			kk *= pm[x][p];
		}
		if(tot%2) ans += dp[kk];
		else ans -= dp[kk];
	}
	return ans;
}
void upd(int x,int k){
	if(x==1) return;
	if(sz(go[x])==0){
		int lim = sqrt(x);
		go[x].push_back(x);
		for(int p=2;p<=lim;p++){
			if(x%p==0){
				int f1 = p;
				int f2 = x/p;
				go[x].push_back(f1);
				if(f1!=f2) go[x].push_back(f2);
			}
		}
	}
	for(int e=0;e<sz(go[x]);e++) dp[go[x][e]] += k;
}
void solve(int tc){
	for(int e=2;e<NMAX;e++){
		for(int p=e;p<NMAX;p+=e){
			if(ck[e]==0&&p!=e) ck[p] = 1;
			if(ck[e]==0){
				pm[p][len[p]++] = e;
			}
		}
	}
	
	int n,q;
	scanf("%d%d",&n,&q);
	lld tot = 0;
	for(int e=0;e<n;e++){
		scanf("%d",&arr[e]);
		tot += getn(arr[e]);
		upd(arr[e],1);
	}
	while(q--){
		int x,v;
		scanf("%d%d",&x,&v);
		upd(arr[x],-1);
		tot -= getn(arr[x]);
		tot += getn(v);
		upd(v,1);
		arr[x] = v;
		printf("%lld\n",tot);
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