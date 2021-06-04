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

const int MAX = 111;
int arr[MAX][MAX];
void solve(int tc){
	int n,k;
	cin >> n >> k;
	if(n%2){
		if(k>n*n-n) cout << "NO\n";
		else{
			cout << "YES\n";
			for(int e=0;e<n;e++){
				for(int p=0;p<n;p++){
					if(e==p) cout << ".";
					else{
						if(k){
							cout << "#";
							k--;
						}
						else cout << ".";
					}
				}
				cout << "\n";
			}
		}
	}else{
		if(n==2){
			if(k>1) cout << "NO\n";
			else{
				cout << "YES\n";
				if(k==1){
					cout << "#.\n..";
				}else{
					cout << "..\n..";
				}
			}
		}else{
			if(k>n*n-n) cout << "NO\n";
			else{
				cout << "YES\n";
				for(int e=0;e<n;e++){
					for(int p=0;p<n;p++){
						if(e==p){
							if(e>=(n/2)-1&&e<=n/2){
								if(k){
									cout << "#";
									k--;
								}else{
									cout << ".";
								}
							}else{
								cout << ".";
							}
						}else{
							if(e==(n/2)-1&&p==(n/2)) cout << ".";
							else if(e==(n/2)&&p==(n/2)-1) cout << ".";
							else{
								if(k){
									cout << "#";
									k--;
								}else{
									cout << ".";
								}
							}
						}
					}
					cout << "\n";
				}
			}
		}
	}
}


int main(void){
	
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int tc = 1;
	/*
		cin >> tc;
	*/
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}