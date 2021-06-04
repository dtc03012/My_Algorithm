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

string v = "RGB";
const int MAX = 555;
char arr[MAX][MAX];
void solve(int tc){
	int n,m;
	pi a[3];
	a[0] = mk(0,0);
	a[1] = mk(0,1);
	a[2] = mk(0,2);
	scanf("%d%d",&n,&m);
	for(int e=0;e<3;e++) scanf("%d",&a[e].x);
	sort(a,a+3);
	if(n>=6){
		for(int e=0;e<n;e++){
			for(int p=0;p<m;p++){
				if(a[0].x){
					arr[e][p] = v[a[0].y];
					a[0].x--;
				}else if(a[2].x){
					arr[e][p] = v[a[2].y];
					a[2].x--;
				}else{
					arr[e][p] = v[a[1].y];
					a[1].x--;
				}
			}
		}
	}else if(m>=6){
		for(int p=0;p<m;p++){
			for(int e=0;e<n;e++){
				if(a[0].x){
					arr[e][p] = v[a[0].y];
					a[0].x--;
				}else if(a[2].x){
					arr[e][p] = v[a[2].y];
					a[2].x--;
				}else{
					arr[e][p] = v[a[1].y];
					a[1].x--;
				}
			}
		}
	}else if(n>=3&&n>m){
		int lim = (n*m)/2;
		if((n*m)%2) lim++;
		if(a[2].x<=lim){
			for(int e=0;e<n;e++){
				for(int p=0;p<m;p++){
					if((e%2)==(p%2)){
						if(a[2].x){
							arr[e][p] = v[a[2].y];
							a[2].x--;
						}
						else if(a[1].x){
							arr[e][p] = v[a[1].y];
							a[1].x--;
						}
						else if(a[0].x){
							arr[e][p] = v[a[0].y];
							a[0].x--;
						}
					}
				}
			}
			for(int e=0;e<n;e++){
				for(int p=0;p<m;p++){
					if((e%2)!=(p%2)){
						if(a[2].x){
							arr[e][p] = v[a[2].y];
							a[2].x--;
						}
						else if(a[1].x){
							arr[e][p] = v[a[1].y];
							a[1].x--;
						}
						else if(a[0].x){
							arr[e][p] = v[a[0].y];
							a[0].x--;
						}
					}
				}
			}
		}else{
			for(int e=0;e<n;e++){
				for(int p=0;p<m;p++){
					if(a[0].x){
						arr[e][p] = v[a[0].y];
						a[0].x--;
					}else if(a[2].x){
						arr[e][p] = v[a[2].y];
						a[2].x--;
					}else{
						arr[e][p] = v[a[1].y];
						a[1].x--;
					}
				}
			}
		}
	}else if(m>=3){
		int lim = (n*m)/2;
		if((n*m)%2) lim++;
		if(a[2].x<=lim){
			for(int p=0;p<m;p++){
				for(int e=0;e<n;e++){
					if((e%2)==(p%2)){
						if(a[2].x){
							arr[e][p] = v[a[2].y];
							a[2].x--;
						}
						else if(a[1].x){
							arr[e][p] = v[a[1].y];
							a[1].x--;
						}
						else if(a[0].x){
							arr[e][p] = v[a[0].y];
							a[0].x--;
						}
					}
				}
			}
			for(int p=0;p<m;p++){
				for(int e=0;e<n;e++){
					if((e%2)!=(p%2)){
						if(a[2].x){
							arr[e][p] = v[a[2].y];
							a[2].x--;
						}
						else if(a[1].x){
							arr[e][p] = v[a[1].y];
							a[1].x--;
						}
						else if(a[0].x){
							arr[e][p] = v[a[0].y];
							a[0].x--;
						}
					}
				}
			}
		}else{
			for(int p=0;p<m;p++){
				for(int e=0;e<n;e++){
					if(a[0].x){
						arr[e][p] = v[a[0].y];
						a[0].x--;
					}else if(a[2].x){
						arr[e][p] = v[a[2].y];
						a[2].x--;
					}else{
						arr[e][p] = v[a[1].y];
						a[1].x--;
					}
				}
			}
		}
	}else{
		for(int e=0;e<n;e++){
			for(int p=0;p<m;p++){
				if(a[0].x){
					arr[e][p] = v[a[0].y];
					a[0].x--;
				}else if(a[2].x){
					arr[e][p] = v[a[2].y];
					a[2].x--;
				}else{
					arr[e][p] = v[a[1].y];
					a[1].x--;
				}
			}
		}
	}
	for(int e=0;e<n;e++){
		for(int p=0;p<m;p++) printf("%c",arr[e][p]);
		printf("\n");
	}
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