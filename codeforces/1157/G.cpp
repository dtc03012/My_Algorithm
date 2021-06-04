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

const int MAX = 202;
int arr[MAX][MAX],col[MAX],row[MAX],n,m;
bool suc(){
	int wh = -1;
	for(int e=0;e<n;e++){
		for(int p=0;p<m;p++){
			if(wh==-1){
				if(arr[e][p]==1) wh = 0;
			}else{
				if(arr[e][p]==0) return false;
			}
		}
	}
	printf("YES\n");
	for(int e=0;e<n;e++) printf("%d",row[e]);
	printf("\n");
	for(int e=0;e<m;e++) printf("%d",col[e]);
	exit(0);
}
void solve(int tc){
	scanf("%d%d",&n,&m);
	for(int e=0;e<n;e++){
		for(int p=0;p<m;p++){
			scanf("%d",&arr[e][p]);
		}
	}
	for(int p=0;p<m;p++){
		if(arr[0][p]==0){
			for(int e=0;e<n;e++){
				arr[e][p] ^= 1;
			}
			col[p] = 1;
		}
	}
	for(int e=0;e<n;e++){
		if(arr[e][0]==0){
			for(int p=0;p<m;p++){
				arr[e][p] ^= 1;
			}
			row[e] = 1;
		}
	}
	suc();
	row[0] ^= 1;
	for(int p=0;p<m;p++){
		arr[0][p] ^= 1;
	}
	for(int p=1;p<m;p++){
		for(int e=0;e<n;e++){
			arr[e][p] ^= 1;
		}
		col[p] ^= 1;
	}
	suc();
	for(int p=1;p<m;p++){
		for(int e=0;e<n;e++){
			arr[e][p] ^= 1;
		}
		col[p] ^= 1;
		suc();
	}
	for(int e=1;e<n;e++){
		for(int p=0;p<m;p++){
			arr[e][p] ^= 1;
		}
		row[e] ^= 1;
		suc();
	}
	printf("NO");
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