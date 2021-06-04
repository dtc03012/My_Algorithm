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
int cnt[MAX];
void solve(int tc){
	int n;
	scanf("%d",&n);
	int mx = 0;
	for(int e=0;e<n;e++){
		int r;
		scanf("%d",&r);
		cnt[r]++;
		mx = max(mx,r);
	}
	int ll = -1,rr = -1,tot = 0,ans = 0,lx = -1,rx = -1;
	for(int e=1;e<=mx;e++){
		if(cnt[e]==0){
			ll = -1;
			rr = -1;
			tot = 0;
		}else{
			if(ll==-1) ll = e;
			rr = e;
			tot += cnt[e];
			if(tot>ans){
				lx = ll;
				rx = rr;
				ans = tot;
			}
			if(cnt[e]==1){
				ll = e;
				rr = e;
				tot = cnt[e];
			}
		}
	}
	printf("%d\n",ans);
	for(int p=0;p<cnt[lx];p++) printf("%d ",lx);
	for(int p=lx+1;p<rx;p++){
		for(int q=0;q<cnt[p]-1;q++) printf("%d ",p);
	}
	if(lx!=rx){
		for(int p=0;p<cnt[rx];p++) printf("%d ",rx);
		for(int p=rx-1;p>lx;p--) printf("%d ",p);
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