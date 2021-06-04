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

const int MAX = 111;
pi arr[MAX],que[MAX];
int cnt[MAX];
void solve(int tc){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int e=0;e<m;e++) scanf("%d%d",&arr[e].x,&arr[e].y);
	int k;
	scanf("%d",&k);
	for(int e=0;e<k;e++){
		int a,b;
		scanf("%d%d",&a,&b);
		que[e] = mk(a,b);
	}
	int ans = 0;
	for(int e=0;e<(1<<k);e++){
		memset(cnt,0,sizeof(cnt));
		for(int p=0;p<k;p++){
			if(e&(1<<p)) cnt[que[p].y]++;
			else cnt[que[p].x]++;
		}
		int tot = 0;
		for(int p=0;p<m;p++){
			if(cnt[arr[p].x]&&cnt[arr[p].y]) tot++;
		}
		ans = max(ans,tot);
	}
	printf("%d\n",ans);
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