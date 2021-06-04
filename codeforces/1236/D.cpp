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
set<int> row[101010],col[101010];
	int n,m,k;
bool suc(int xx){
lld cnt = k + 1;
	int dir = xx,y = 1,x = 1,ck = 0;
	int ly = 1,ry = n,lx = 1,rx = m;
	while(cnt<=1ll*n*m){
		if(ly>ry||lx>rx) break;
		dir %= 4;
		if(dir==0){
			auto wh = row[y].lower_bound(x+1);
			int pos = min((*wh) - 1,rx);
			if(pos==x){
				break;
			}else{
				ck = 0;
				cnt += (pos-x);
				ly = y + 1;
				x = pos;
			}
			dir++;
		}
		else if(dir==1){
			auto wh = col[x].lower_bound(y+1);
			int pos = min((*wh) - 1,ry);
			if(pos==y){
				break;
			}else{
				ck = 0;
				cnt += (pos-y);
				rx = x - 1;
				y = pos;
			}
			dir++;
		}
		else if(dir==2){
			auto wh = row[y].lower_bound(x);
			wh--;
			int pos = max((*wh) + 1,lx);
			if(pos==x){
				break;
			}else{
				ck = 0;
				cnt += (x-pos);
				ry = y - 1;
				x = pos;
			}
			dir++;
		}
		else if(dir==3){
			auto wh = col[x].lower_bound(y);
			wh--;
			int pos = max((*wh) + 1,ly);
			if(pos==y){
				break;
			}else{
				ck = 0;
				cnt += (y-pos);
				lx = x + 1;
				y = pos;
			}
			dir++;
		}
	}
	if(cnt==1ll*n*m){
		return true;
	}else{
		return false;
	}
}
void solve(int tc){
	scanf("%d%d%d",&n,&m,&k);
	for(int e=0;e<k;e++){
		int y,x;
		scanf("%d%d",&y,&x);
		col[x].insert(y);
		row[y].insert(x);
	}
	for(int e=1;e<=n;e++){
		row[e].insert(0);
		row[e].insert(m+1);
	}
	for(int e=1;e<=m;e++){
		col[e].insert(0);
		col[e].insert(n+1);
	}
	if(suc(0)||suc(1)){
		printf("Yes\n");
	}else{
		printf("No\n");
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
