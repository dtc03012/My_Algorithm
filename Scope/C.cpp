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

const int MAX = 55;
string arr[MAX];
int sz[MAX];
void solve(int tc){
	int n;
	scanf("%d",&n);
	for(int e=0;e<n;e++) cin >> arr[e];
	int ans = 0;
	for(int e=1;e<=n;e++){
		for(int p=0;p<n;p++){
			for(int q=0;q<n;q++){
				if(p+e<=n&&q+e<=n){
					int tot = 0;
					for(int r=p;r<p+e;r++){
						for(int t=q;t<q+e;t++){
							if(arr[r][t]=='0') tot++;
						}
					}
					if(tot==0){
						ans++;
						sz[e]++;
					}
				}
			}
		}
	}
	printf("total: %d\n",ans);
	for(int e=1;e<=n;e++){
		if(sz[e]==0) break;
		printf("size[%d]: %d\n",e,sz[e]);
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