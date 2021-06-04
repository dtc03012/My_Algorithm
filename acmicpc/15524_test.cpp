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
const int MAX = 16;
int dp[(1<<MAX)];
struct inf{
	double r,x1,y1,x2,y2;
};
inf arr[MAX];
bool eq(double a,double b){
	if(abs(a-b)<0.0000001) return true;
	return false;
}
bool can(int x,int y,double rx,double ry,double r){
	double k1 = (rx-arr[x].x1)*(arr[x].x2-arr[x].x1) + (arr[x].y2-arr[x].y1)*(ry-arr[x].y1);
	swap(arr[x].x1,arr[x].x2);
	swap(arr[x].y1,arr[x].y2);
	double k2 = (rx-arr[x].x1)*(arr[x].x2-arr[x].x1) + (arr[x].y2-arr[x].y1)*(ry-arr[x].y1);
	swap(arr[x].x1,arr[x].x2);
	swap(arr[x].y1,arr[x].y2);
	if(k1>0&&k2>0){
		double n1;
		if(arr[x].x2==arr[x].x1){
			n1 = abs(rx-arr[x].x1);
		}else{
			double a = (arr[x].y2-arr[x].y1)/(arr[x].x2-arr[x].x1);
			double b = -1.0;
			double c = (arr[x].x2*arr[x].y1 - arr[x].x1*arr[x].y2)/(arr[x].x2-arr[x].x1);
			double f1 = (a*rx+b*ry+c)/(sqrt(a*a+b*b));
			n1 = abs(f1);
			cout <<fixed;
			cout.precision(6);
		}
		cout <<"X " <<  x << " " << y << " : " << n1 << endl;
		if(n1>arr[x].r+r||eq(n1,arr[x].r+r)) return true;
		return false;
	}else{
		double n1 = (arr[x].x1-rx)*(arr[x].x1-rx) + (arr[x].y1-ry)*(arr[x].y1-ry);
		double n2 = (arr[x].x2-rx)*(arr[x].x2-rx) + (arr[x].y2-ry)*(arr[x].y2-ry);
		n1 = min(n1,n2);
		n1 = sqrt(n1);
		cout <<"Y "<< x << " " << y << " : " << n1 << endl;
		if(n1>arr[x].r+r||eq(n1,arr[x].r+r)) return true;
		return false;
	}
}
void solve(int tc){
	int n;
	cin >> n;
	for(int e=0;e<n;e++){
		double a,b,c,x,y;
		cin >> a >> b >> c >> x >> y;
		arr[e] = {a,b,c,x,y};
	}
	memset(dp,-1,sizeof(dp));
	dp[0] = 0;
	int ans = 0;
	for(int e=0;e<(1<<n);e++){
		if(dp[e]==-1) continue;
		ans = max(ans,dp[e]);
		for(int p=0;p<n;p++){
			if((e&(1<<p))==0){
				bool tmr = true;
				for(int r=0;r<n;r++){
					if(r==p) continue;
					if(e&(1<<r)){
						if(!can(p,r,arr[r].x2,arr[r].y2,arr[r].r)) tmr = false;
					}else{
						if(!can(p,r,arr[r].x1,arr[r].y1,arr[r].r)) tmr = false;
					}
				}
				if(tmr){
					dp[e^(1<<p)] = max(dp[e^(1<<p)],dp[e]+1);
				}
			}
		}
	}
	printf("%d\n",ans);
}


int main(void){
	
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int tc = 1;
	/*
		scanf("%d",&tc);
	*/
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}