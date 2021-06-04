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


void solve(int tc){
	lld n,k;
	scanf("%lld%lld",&n,&k);
	k--;
	if(n%2==0){
		lld f1 = n-1,f2 = 0;
		f2 = (f2+k)%n;
		f1 = ((f1-k)%n+n)%n;
		printf("%d\n",f2+1);
	}else{
		if(n==3){
			if(k%3==1) printf("3\n");
			if(k%3==2) printf("2\n");
			if(k%3==0) printf("1\n");
		}else{
			lld df = (n-1)/2;
			lld xx = df*n;
			k %= xx;
			lld coin = k / n;
			lld len = k % n;
			lld f1 = n-1,f2 = coin*2;
			lld mid = (f1+f2)/2;
			lld go = f1 - mid;
			if(len<go){
				f1 -= len;
				f2 = (f2+len)%n;
				printf("%lld\n",f2+1);
			}else{
				lld last = n - 1 - coin;
				if(len<last){
					f1 -= len;
					f2 = (f2+len+1)%n;
					printf("%lld\n",f2+1);
				}else{
					f1 -= len;
					f2 = (f2+len+2)%n;
					printf("%lld\n",f2+1);
				}
			}
		}
	}
}


int main(void){
	/*
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	*/
	int tc = 1;
	
		cin >> tc;
	
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}