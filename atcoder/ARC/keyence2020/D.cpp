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

const int MAX = 18;
const int NMAX = 55;
int A[MAX],B[MAX];
set<int> S[NMAX][2];
int len[NMAX][2],k[NMAX];
void solve(int tc){
	int n;
	scanf("%d",&n);
	for(int e=0;e<n;e++) scanf("%d",&A[e]);
	for(int e=0;e<n;e++) scanf("%d",&B[e]);
	int ans = 1e9;
	for(int e=0;e<(1<<n);e++){
		vector<int> g;
		for(int p=0;p<NMAX;p++){
			S[p][0].clear();
			S[p][1].clear();
			len[p][0] = len[p][1] = 0;
		}
		for(int p=0;p<n;p++){
			k[p] = 0;
			if(e&(1<<p)){
				g.push_back(B[p]);
				S[B[p]][(p&1)^1].insert(p);
			}
			else{
				g.push_back(A[p]);
				S[A[p]][(p&1)].insert(p);
			}
		}
		sort(all(g));
		int tot = 0;
		bool suc = true;
		for(int e=0;e<sz(g);e++) len[g[e]][e%2]++;
		for(int e=0;e<NMAX;e++){
			if(len[e][0]!=sz(S[e][0])) suc = false;
			if(len[e][1]!=sz(S[e][1])) suc = false;
		}
		if(suc){
			int tot = 0;
			for(int e=0;e<sz(g);e++){
				int res = 0;
				set<int>::iterator it = S[g[e]][e&1].begin();
				for(int p=(*it)+1;p<n;p++) if(k[p]) res++;
				tot += max(0,(*it)+res-e);
				S[g[e]][e&1].erase(it);
				k[*it] = 1;
			}
			ans = min(ans,tot);
		}
	}
	if(ans==1e9) ans = -1;
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