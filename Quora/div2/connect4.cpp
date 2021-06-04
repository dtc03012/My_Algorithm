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

int cnt[8];
int arr[8][8];
int ck(){
	for(int e=1;e<=7;e++){
		for(int p=1;p<=7;p++){
			if(arr[e][p]){
				{
					int tot = 0;
					for(int q=0;q<4;q++){
						if(p+q>=1&&p+q<=7){
							if(arr[e][p+q]==arr[e][p]) tot++;
							else break;
						}else{
							break;
						}
					}
					if(tot>=4) return arr[e][p];
				}
				{
					int tot = 0;
					for(int q=0;q<4;q++){
						if(p-q>=1&&p-q<=7){
							if(arr[e][p-q]==arr[e][p]) tot++;
							else break;
						}else{
							break;
						}
					}
					if(tot>=4) return arr[e][p];
				}
				{
					int tot = 0;
					for(int q=0;q<4;q++){
						if(e+q>=1&&e+q<=7){
							if(arr[e+q][p]==arr[e][p]) tot++;
							else break;
						}else{
							break;
						}
					}
					if(tot>=4) return arr[e][p];
				}
				{
					int tot = 0;
					for(int q=0;q<4;q++){
						if(e-q>=1&&e-q<=7){
							if(arr[e-q][p]==arr[e][p]) tot++;
							else break;
						}else{
							break;
						}
					}
					if(tot>=4) return arr[e][p];
				}
				{
					int tot = 0;
					for(int q=0;q<4;q++){
						if(p+q>=1&&p+q<=7&&e+q>=1&&e+q<=7){
							if(arr[e+q][p+q]==arr[e][p]) tot++;
							else break;
						}else{
							break;
						}
					}
					if(tot>=4) return arr[e][p];
				}
				{
					int tot = 0;
					for(int q=0;q<4;q++){
						if(p-q>=1&&p-q<=7&&e-q>=1&&e-q<=7){
							if(arr[e-q][p-q]==arr[e][p]) tot++;
							else break;
						}else{
							break;
						}
					}
					if(tot>=4) return arr[e][p];
				}
				{
					int tot = 0;
					for(int q=0;q<4;q++){
						if(p+q>=1&&p+q<=7&&e-q>=1&&e-q<=7){
							if(arr[e-q][p+q]==arr[e][p]) tot++;
							else break;
						}else{
							break;
						}
					}
					if(tot>=4) return arr[e][p];
				}
				int tot = 0;
					for(int q=0;q<4;q++){
						if(p-q>=1&&p-q<=7&&e+q>=1&&e+q<=7){
							if(arr[e+q][p-q]==arr[e][p]) tot++;
							else break;
						}else{
							break;
						}
					}
					if(tot>=4) return arr[e][p];
			}
		}
	}
	return -1;
}
void solve(int tc){
	for(int e=1;e<=42;e++){
		int r;
		scanf("%d",&r);
		if(e%2) arr[r][++cnt[r]] = 1;
		else arr[r][++cnt[r]] = 2;
		int xx = ck();
		if(xx==1){
			printf("RED %d",e);
			return;
		}else if(xx==2){
			printf("YELLOW %d",e);
			return;
		}
	}
	printf("DRAW");
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