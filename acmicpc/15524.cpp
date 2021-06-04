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
bool eq(double a,double b){
	if(abs(a-b)<0.0000001) return true;
	return false;
}
// #include <bits/stdc++.h>

// using namespace std;

struct G2DLine;
struct G2DAxByC;
struct G2DPoint;
struct G2DVector;

struct G2DLine{
	double sx,sy,ex,ey;
	G2DLine(double sx,double sy,double ex,double ey) : sx(sx),sy(sy),ex(ex),ey(ey){

	}
};

struct G2DPoint{
	double x,y;
	G2DPoint(double x,double y) : x(x),y(y){

	}
	double DPoint(G2DPoint PT){
		return sqrt((x-PT.x)*(x-PT.x) + (y-PT.y)*(y-PT.y));
	}
};

struct G2DVector{
	double x,y;
	G2DVector(double x,double y) : x(x),y(y){

	}
	double operator+(G2DVector& k){
		return (this->x)*k.x + (this->y)*k.y;
	}
};

struct G2DAxByC{
	double A,B,C;
		// given A, B, C directly
	G2DAxByC(double A,double B,double C) : A(A),B(B),C(C){
	}
		// given sx,sy,ey,ex
	G2DAxByC(G2DLine X){
			// Line
		if(X.sx==X.ex){
			this->A = -1.0;
			this->B = 0.0;
			this->C = X.sx;
		}else{
			this->A = (X.ey-X.sy)/(X.ex-X.sx);
			this->B = -1.0;
			this->C = (X.ex*X.sy-X.sx*X.ey)/(X.ex-X.sx); 
		}
	}
	double value(double x,double y){
		return A*x + B*y + C;
	}
	double DPoint(G2DPoint Pt){
		return abs(value(Pt.x,Pt.y)/sqrt(A*A+B*B));
	}
};


double DLineToPoint(G2DLine LN,G2DPoint PT){
	G2DVector f1(PT.x-LN.sx,PT.y-LN.sy);	
	G2DVector f2(LN.ex-LN.sx,LN.ey-LN.sy);
	G2DVector s1(PT.x-LN.ex,PT.y-LN.ey);
	G2DVector s2(LN.sx-LN.ex,LN.sy-LN.ey);
	double v1 = f1 + f2;
	double v2 = s1 + s2;
	if(v1>0&&v2>0){
		G2DAxByC g = G2DAxByC(LN);
		return g.DPoint(PT);
	}else{
		double x1 = PT.DPoint(G2DPoint(LN.sx,LN.sy));
		double x2 = PT.DPoint(G2DPoint(LN.ex,LN.ey));
		return min(x1,x2);
	}
}


// int main(void){
// 	return 0;
// }

struct Node{
	G2DLine	Line;
	double r;
	Node(G2DLine a,double b) : Line(a), r(b){

	}
	Node() : Line(G2DLine(0,0,0,0)), r(0){

	}
};

Node arr[MAX];
void solve(int tc){
	int n;
	cin >> n;
	for(int e=0;e<n;e++){
		double a,b,c,x,y;
		cin >> a >> b >> c >> x >> y;
		arr[e] = {G2DLine(b,c,x,y),a};
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
						double dist1 = DLineToPoint(arr[p].Line,G2DPoint(arr[r].Line.ex,arr[r].Line.ey));
						double dist2 = arr[r].r + arr[p].r;
						if(dist1<dist2) tmr = false;
					}else{
						double dist1 = DLineToPoint(arr[p].Line,G2DPoint(arr[r].Line.sx,arr[r].Line.sy));
						double dist2 = arr[r].r + arr[p].r;
						if(dist1<dist2) tmr = false;
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