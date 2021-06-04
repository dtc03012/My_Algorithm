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

const int MAX = 10;
int ans=1e9,can[MAX],uf[MAX],cnt[MAX],n,m,wh=-1;
vector<int> ck;
vector<pair<pi,int> > v;
int find(int x){
	if(uf[x]!=x) return uf[x] = find(uf[x]);
	return x;
}
void dfs(int x,int k,int bit){
	if(x==sz(v)){
		if(k!=n-1) return;
		for(int p=0;p<n;p++){
			uf[p] = p;
			cnt[p] = 0;
		}
		bool suc = true;
		int tot = 0;
		for(int p=0;p<n-1;p++){
			int r = ck[p];
			int x = v[r].x.x;
			int y = v[r].x.y;
			int c = v[r].y;
			cnt[x]++;
			cnt[y]++;
			tot += c;
			x = find(x);
			y = find(y);
			if(x==y){
				suc = false;
				break;
			}
			uf[y] = x;
		}
		for(int p=0;p<n;p++){
			if(find(p)!=find(0)) suc = false;
			if(cnt[p]>can[p]) suc = false;
		}
		if(suc){
			if(ans>tot){
				ans = tot;
				wh = bit;
			}
		}
		return;
	}
	if(k<n-1){
		ck.push_back(x);
		dfs(x+1,k+1,bit+(1<<x));
		ck.pop_back();
	}
	dfs(x+1,k,bit);
}
void solve(int tc){
	scanf("%d%d",&n,&m);
	for(int e=0;e<n;e++) scanf("%d",&can[e]);
	for(int e=0;e<m;e++){
		int x,y,c;
		scanf("%d%d%d",&x,&y,&c);
		x--;y--;
		v.push_back(mk(mk(x,y),c));
	}
	dfs(0,0,0);
	if(wh==-1) printf("NO");
	else{
		printf("YES\n");
		for(int e=0;e<m;e++){
			if(wh&(1<<e)) printf("%d %d\n",v[e].x.x+1,v[e].x.y+1);
		}
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
		cin >> tc;
	*/
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}