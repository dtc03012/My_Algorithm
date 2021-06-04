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

const int MAX =101010;
int cnt[MAX],arr[MAX];
const lld mod = 1e9 + 7;
int start = 1;
lld seg[MAX*4];
void upd(int x,lld v){
	x += start;
	seg[x] += v;
	for(int e=(x/2);e>=1;e/=2) seg[e] = (seg[e*2]+seg[e*2+1])%mod;
}
lld getn(int l,int r){
	l += start;
	r += start;
	lld ans = 0;
	while(l<=r){
		if(l&1) ans = (ans+seg[l++])%mod;
		if(!(r&1)) ans = (ans+seg[r--])%mod;
		l >>= 1;
		r >>= 1;
	}
	return ans;
}
int wh[MAX];
void solve(int tc){
	int n;
	scanf("%d",&n);
	while(start<=n) start *= 2;
	for(int e=0;e<=n;e++){
		cnt[e] = 0;
		wh[e] = -1;
	}
	for(int e=0;e<start*2;e++) seg[e] = 0;
	for(int e=1;e<=n;e++){
		 scanf("%d",&arr[e]);
		 cnt[arr[e]]++;
	}
	set<pi> s;
	int mx = 0;
	for(int e=0;e<=n;e++){
		if(cnt[e]==0){
			mx = e;
			break;
		}
	}
	upd(0,1);
	for(int e=1;e<=n;e++){
		if(arr[e]<mx){
			if(wh[arr[e]]==-1){
				wh[arr[e]] = e;
				s.insert(mk(e,arr[e]));
			}else{
				s.erase(mk(wh[arr[e]],arr[e]));
				wh[arr[e]] = e;
				s.insert(mk(e,arr[e]));
			}
		}
		if(sz(s)==mx){
			if(sz(s)==0){
				lld now = getn(0,e-1);
				upd(e,now);
			}else{
				set<pi>::iterator it = s.begin();
				int pos = it->x;
				lld now = getn(0,pos-1);
				upd(e,now);
			}
		}
	}
	printf("%lld\n",getn(n,n));
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