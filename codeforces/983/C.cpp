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

const int MAX = 2020;
int dp[MAX][10][10][10][10],dp2[MAX][10][10][10][10];
void solve(int tc){
	for(int e=0;e<MAX;e++){
		for(int p=0;p<10;p++){
			for(int q=0;q<10;q++){
				for(int r=0;r<10;r++){
					for(int y=0;y<10;y++){
						dp[e][p][q][r][y] = 1e9;
					}
				}
			}
		}
	}
	dp[0][1][0][0][0] = 0;
	int n;
	scanf("%d",&n);
	for(int e=1;e<=n;e++){
		int a,b;
		scanf("%d%d",&a,&b);
		for(int h=1;h<=9;h++){
			for(int f1=0;f1<=9;f1++){
				for(int f2=0;f2<=9;f2++){
					int tim = dp[e-1][h][f1][f2][0] + abs(h-a) + 1;
					dp[e][a][f1][f2][b] = min(dp[e][a][f1][f2][b],tim);
				}
			}
			for(int f1=0;f1<=9;f1++){
				for(int f2=0;f2<=9;f2++){
					int tim = dp[e-1][h][f1][0][f2] + abs(h-a) + 1;
					dp[e][a][f1][b][f2] = min(dp[e][a][f1][b][f2],tim);
				}
			}
			for(int f1=0;f1<=9;f1++){
				for(int f2=0;f2<=9;f2++){
					int tim = dp[e-1][h][0][f1][f2] + abs(h-a) + 1;
					dp[e][a][b][f1][f2] = min(dp[e][a][b][f1][f2],tim);
				}
			}
			for(int f1=1;f1<=9;f1++){
				for(int f2=1;f2<=9;f2++){
					for(int f3=1;f3<=9;f3++){
						int tim = dp[e-1][h][f1][f2][f3] + abs(h-a) + 1;
						{
							// f1
							int ntim = tim + abs(a-f1) + 1;
							dp[e][f1][b][f2][f3] = min(dp[e][f1][b][f2][f3],ntim);
						}
						{
							// f2
							int ntim = tim + abs(a-f2) + 1;
							dp[e][f2][f1][b][f3] = min(dp[e][f2][f1][b][f3],ntim);
						}
						{
							// f3
							int ntim = tim + abs(a-f3) + 1;
							dp[e][f3][f1][f2][b] = min(dp[e][f3][f1][f2][b],ntim);
						}
						{
							// now
							int ntim = tim + abs(a-b) + 1;
							dp[e][b][f1][f2][f3] = min(dp[e][b][f1][f2][f3],ntim);
						}
					}
				}
			}
		}
		for(int f1=9;f1>=0;f1--){
			for(int f2=9;f2>=0;f2--){
				for(int f3=9;f3>=0;f3--){
					for(int h=1;h<=9;h++){
						int tim = dp[e][h][f1][f2][f3];
						if(f1) dp[e][f1][0][f2][f3] = min(dp[e][f1][0][f2][f3],tim+abs(f1-h)+1);
						if(f2) dp[e][f2][f1][0][f3] = min(dp[e][f2][f1][0][f3],tim+abs(f2-h)+1);
						if(f3) dp[e][f3][f1][f2][0] = min(dp[e][f3][f1][f2][0],tim+abs(f3-h)+1);
					}
				}
			}
		}
	}
	int ans = 1e9;
	for(int e=1;e<=9;e++) ans = min(ans,dp[n][e][0][0][0]);
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