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
set<pi> s[MAX];
void solve(int tc){
	int n,m,ans = 0;
	scanf("%d%d",&n,&m);
	for(int e=0;e<m;e++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		{
			set<pi>::iterator it = s[a].lower_bound(mk(c,-1));
			int xx = 0;
			if(it==s[a].begin()) xx = 1;
			else{
				it--;
				xx = it->y + 1;
			}
			ans = max(ans,xx);
			it = s[b].lower_bound(mk(c,-1));
			for(;it!=s[b].end()&&it->y<=xx;) s[b].erase(it++);
			if(it==s[b].begin()) s[b].insert(mk(c,xx));
			else{
				it--;
				if(it->y<xx) s[b].insert(mk(c,xx));
			}
		}
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