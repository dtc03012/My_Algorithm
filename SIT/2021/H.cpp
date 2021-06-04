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
vector<pli> v1,v2;
vector<pair<lld,pi> > v;
lld ans[MAX];
int vis[MAX];
void solve(int tc){
	memset(ans,-1,sizeof(ans));
	int n;
	scanf("%d",&n);
	for(int e=0;e<n;e++){
		int a,b;
		scanf("%d%d",&a,&b);
		if(b==1) v1.push_back(mk(a,e));
		else v2.push_back(mk(a,e));
		v.push_back(mk(a,mk(b,e)));
	}
	sort(all(v1));
	sort(all(v2));
	sort(all(v));
	int fcn = 0,scn = 0,rt = 0;
	lld f1 = 0,f2 = 0;
	lld tot = 0;
	for(int e=0;e<sz(v);e++){
		if(vis[v[e].y.y]) continue;
		if((fcn+1)*2==scn){
			while(fcn<sz(v1)&&vis[v1[fcn].y]) fcn++;
			if(fcn==sz(v1)){
				break;
			}else{
				tot += v1[fcn].x;
				vis[v1[fcn].y] = 1;
				fcn++;
				f1++;
				e--;
				ans[rt++] = tot;
			}
		}else if((scn+1)*2==fcn){
			while(scn<sz(v2)&&vis[v2[scn].y]) scn++;
			if(scn==sz(v2)){
				break;
			}else{
				tot += v2[scn].x;
				vis[v2[scn].y] = 1;
				scn++;
				f2++;
				e--;
				ans[rt++] = tot;
			}
		}else{
			if(v[e].y.x==1){
				tot += v[e].x;
				ans[rt++] = tot;
				vis[v[e].y.y] = 1;
				f1++;
				fcn++;
			}else{
				tot += v[e].x;
				ans[rt++] = tot;
				vis[v[e].y.y] = 1;
				f2++;
				scn++;
			}
		}
	}
	for(int e=0;e<n;e++) printf("%d\n",ans[e]);
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