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
bool tmr(pi a,pi b){
	return a.x - a.y < b.x - b.y;
}
vector<int> v[MAX];
pair<int,pi>  dfs(int x,int lx){
	int f1 = 1,f2 = 0;
	int ty = 1;
	int k1 = 0,k2 = 0;
	int s1 = 0,s2 = 0;
	vector<pi> v2;
	for(int e=0;e<sz(v[x]);e++){
		int nx = v[x][e];
		if(nx!=lx){
			pair<int,pi> xx = dfs(nx,x);
			if(xx.x) v2.push_back(xx.y);
			else{
				if(xx.y.x>xx.y.y){
					k1 += xx.y.x;
					k2 += xx.y.y;
				}else{
					s1 += xx.y.x;
					s2 += xx.y.y;
				}
			}
		}
	}
	f1 += s1;
	f2 += s2;
	sort(all(v2),tmr);
	for(int e=0;e<sz(v2);e++){
		if(ty){
			f1 += v2[e].x;
			f2 += v2[e].y;
			ty ^= 1;
		}else{
			f2 += v2[e].x;
			f1 += v2[e].y;
			ty ^= 1;
		}
	}
	if(ty){
		f1 += k1;
		f2 += k2;
	}else{
		f2 += k1;
		f1 += k2;
	}
	return mk(ty,mk(f1,f2));
}
void solve(int tc){
	int n;
	scanf("%d",&n);
	for(int e=2;e<=n;e++){
		int r;
		scanf("%d",&r);
		v[r].push_back(e);
	}
	printf("%d\n",dfs(1,-1).y.x);
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