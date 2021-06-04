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

int arr[6][6],ans = 0;
void dfs(int ty,int now){
	if(ty==3){
		int vvv = 0;
		for(int p=0;p<6;p++){
			int fiv = 0,org;
			for(int e=0;e<6;e++) fiv += arr[e][p];
			org = fiv;
			for(int e=0;e<6;e++){
				int up = 9 - arr[e][p],ntot = org;
				for(int r=0;r<6;r++){
					int nv = (arr[r][p]+up)%10;
					ntot += (nv-arr[r][p]);
				}
				fiv = max(fiv,ntot);
			}
			vvv += fiv;
		}
		ans = max(ans,vvv);
		return;
	}
	if(ty==0){
		for(int e=0;e<6;e++){
			int up = 9 - arr[now][e];
			for(int p=0;p<6;p++){
				int nv = (arr[now][p]+up)%10;
				arr[now][p] = nv;
			}
			if(now+1<6) dfs(0,now+1);
			else dfs(1,0);
			for(int p=0;p<6;p++){
				int nv = (arr[now][p]-up)%10;
				nv = (nv%10+10)%10;
				arr[now][p] = nv;
			}
		}
	}else if(ty==1){
		for(int e=0;e<6;e++){
			int up = 9 - arr[e][e];
			for(int p=0;p<6;p++){
				int nv = (arr[p][p]+up)%10;
				arr[p][p] = nv;
			}
			dfs(2,0);
			for(int p=0;p<6;p++){
				int nv = (arr[p][p]-up)%10;
				nv = (nv%10+10)%10;
				arr[p][p] = nv;
			}
		}
	}else{
		for(int e=0;e<6;e++){
			int up = 9 - arr[e][5-e];
			for(int p=0;p<6;p++){
				int nv = (arr[p][5-p]+up)%10;
				arr[p][5-p] = nv;
			}
			dfs(3,0);
			for(int p=0;p<6;p++){
				int nv = (arr[p][5-p]-up)%10;
				nv = (nv%10+10)%10;
				arr[p][5-p] = nv;
			}
		}
	}
}
void solve(int tc){
	for(int e=0;e<6;e++){
		for(int p=0;p<6;p++){
			scanf("%d",&arr[e][p]);
			ans += arr[e][p];
		}
	}
	dfs(0,0);
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
		cin >> tc;
	*/
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}