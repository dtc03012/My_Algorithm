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

const int MAX = 101010*4;
int cnt[MAX],res[MAX];
void solve(int tc){
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int e=1;e<=4*n;e++) cnt[e%k]++;
	for(int e=0;e<m;e++){
		int a,b;
		scanf("%d%d",&a,&b);
		cnt[a%k]--;
		cnt[b%k]--;
	}
	int x,y;
	scanf("%d%d",&x,&y);
	x %= k;
	y %= k;
	cnt[x]--;cnt[y]--;
	int df = abs(x-y) + 1;
	int ll = k-1,rr = k-1-df,ans = 0;
	while(rr>=0){
		int rst = rr;
		while(res[ll]>=cnt[rr]&&rst-rr<df){
			cnt[ll] += cnt[rr];
			res[ll] -= cnt[rr];
			cnt[rr] = 0;
			rr--;
		}
		while(ll-rr<df) rr--;
		while(cnt[ll]>=cnt[rr]&&rr>=0){
			ans += cnt[rr];
			res[rr] = cnt[rr];
			cnt[ll] -= cnt[rr];
			cnt[rr] = 0;
			rr--;
		}
		if(rr>=0){
			cnt[rr] -= cnt[ll];
			ans += cnt[ll];
			cnt[ll] = 0;
			ll--;
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
		cin >> tc;
	*/
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}