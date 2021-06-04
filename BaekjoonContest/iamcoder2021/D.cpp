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

string _min(string a,string b){
	if(sz(a)!=sz(b)){
		if(sz(a)<sz(b)) return a;
		return b;
	}
	return min(a,b);
}
const int MAX = 6;
string a[MAX];
string dp[10][10][10][10][10][10];
void solve(int tc){
	int n;
	scanf("%d",&n);
	for(int e=0;e<n;e++){
		cin >> a[e];
	}
	for(int e=n;e<6;e++) a[e] = "";
	for(int e=0;e<10;e++){
		for(int p=0;p<10;p++){
			for(int q=0;q<10;q++){
				for(int r=0;r<10;r++){
					for(int t=0;t<10;t++){
						for(int y=0;y<10;y++){
							dp[e][p][q][r][t][y] = "?";
						}
					}
				}
			}
		}
	}
	dp[0][0][0][0][0][0] = "";
	for(int e=0;e<=sz(a[0]);e++){
		for(int p=0;p<=sz(a[1]);p++){
			for(int q=0;q<=sz(a[2]);q++){
				for(int t=0;t<=sz(a[3]);t++){
					for(int r=0;r<=sz(a[4]);r++){
						for(int y=0;y<=sz(a[5]);y++){
							string xx = dp[e][p][q][t][r][y];
							if(xx=="?") continue;
							for(char x ='A';x<='D';x++){
								int f0=e,f1=p,f2=q,f3=t,f4=r,f5=y;
								if(f0<sz(a[0])&&a[0][f0]==x) f0++;
								if(f1<sz(a[1])&&a[1][f1]==x) f1++;
								if(f2<sz(a[2])&&a[2][f2]==x) f2++;
								if(f3<sz(a[3])&&a[3][f3]==x) f3++;
								if(f4<sz(a[4])&&a[4][f4]==x) f4++;
								if(f5<sz(a[5])&&a[5][f5]==x) f5++;
								if(dp[f0][f1][f2][f3][f4][f5]=="?") dp[f0][f1][f2][f3][f4][f5] = xx + x;
								else dp[f0][f1][f2][f3][f4][f5] = _min(dp[f0][f1][f2][f3][f4][f5],xx+x);
							}
						}
					}
				}
			}
		}
	}
	cout << dp[sz(a[0])][sz(a[1])][sz(a[2])][sz(a[3])][sz(a[4])][sz(a[5])];
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