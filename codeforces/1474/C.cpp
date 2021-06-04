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

const int MAX = 2010;
int arr[MAX],vis[MAX],num[1000100],ck[1000100];
vector<int> v[1000100];
void solve(int tc){
	int n;
	scanf("%d",&n);
	for(int e=0;e<2*n;e++){
		scanf("%d",&arr[e]);
		v[arr[e]].clear();
		ck[arr[e]] = tc;
	}
	sort(arr,arr+2*n);
	for(int e=0;e<2*n;e++) v[arr[e]].push_back(e);
	for(int e=0;e<2*n-1;e++){
		for(int p=0;p<2*n;p++){
			vis[p] = 0;
			num[arr[p]] = 0;
		}
		vis[2*n-1] = 1;
		vis[e] = 1;
		vector<pi> v2;
		v2.push_back(mk(arr[e],arr[2*n-1]));
		int x = arr[2*n-1];
		bool suc = true;
		for(int p=2*n-2;p>=0;p--){
			if(vis[p]) continue;
			int df = x - arr[p];
			if(ck[df]!=tc){
				suc = false;
				break;
			}
			if(sz(v[df])==num[df]){
				suc = false;
				break;
			}else{
				int wh = v[df][num[df]];
				if(wh<p){
					vis[wh] = 1;
					vis[p] = 1;
					v2.push_back(mk(df,arr[p]));
					x = arr[p];
					num[df]++;
				}else{
					suc = false;
					break;
				}
			}
		}
		if(suc){
			printf("YES\n%d\n",arr[e]+arr[2*n-1]);
			for(int e=0;e<sz(v2);e++) printf("%d %d\n",v2[e].x,v2[e].y);
			return;
		}
	}
	printf("NO\n");
}


int main(void){
	/*
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	*/
	int tc = 1;
	
		scanf("%d",&tc);
	
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}