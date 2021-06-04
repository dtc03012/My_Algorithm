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
int cnt[MAX];
void solve(int tc){
	int n,m;
	cin >> n >> m;
	for(int e=0;e<=n+1;e++) cnt[e] = 0;
	int mx = 0;
	set<int> s;
	for(int e=0;e<n;e++){
		int r;
		cin >> r;
		mx = max(mx,r);
		s.insert(r);
		if(r<=n) cnt[r]++;
	}
	int mex = -1;
	for(int p=0;p<=n;p++) if(cnt[p]==0){
		mex = p;
		break;
	}
	if(mex==-1) mex = n + 1;
	if(m){
		if(mex==n){
			printf("%d\n",n+m);
			return;
		}
		int xx = (mex+mx)/2;
		if((mex+mx)%2) xx++;
		s.insert(xx);
	}
	printf("%d\n",sz(s));
}


int main(void){
	
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int tc = 1;
	
		cin >> tc;
	
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}