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

const int MAX = 1010;
int arr[MAX][MAX],n,vis[MAX][MAX];
pi dfs(int y,int x){
	vis[y][x] = 1;
	pi xx = mk(0,0);
	for(int e=0;e<8;e++){
		int nx = x + ddx[e];
		int ny = y + ddy[e];
		if(isrange(ny,nx,n,n)){
			if(arr[ny][nx]==arr[y][x]&&vis[ny][nx]==0){
				pi yy = dfs(ny,nx);
				xx.x += yy.x;
				xx.y += yy.y;
			}else{
				if(arr[ny][nx]>arr[y][x]){
					xx.x++;
				}else if(arr[ny][nx]<arr[y][x]){
					xx.y++;
				}
			}
		}
	}
	return xx;
}
void solve(int tc){
	scanf("%d",&n);
	for(int e=0;e<n;e++){
		for(int p=0;p<n;p++){
			scanf("%d",&arr[e][p]);
		}
	}
	int f1 = 0,f2 = 0;
	for(int e=0;e<n;e++){
		for(int p=0;p<n;p++){
			if(vis[e][p]==0){
				pi xx = dfs(e,p);
				if(xx.x&&!xx.y) f2++;
				else if(!xx.x&&xx.y) f1++;
				else if(!xx.x&&!xx.y){
					f1++;
					f2++;
				}
			}
		}
	}
	printf("%d %d\n",f1,f2);
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