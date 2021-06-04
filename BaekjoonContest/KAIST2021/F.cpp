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

	const int MAX = 20;
	int arr[(1<<MAX)];
	vector<int> v,g[(1<<MAX)];
	void solve(int tc){
		int n;
		cin >> n;
		for(int e=0;e<(1<<n);e++){
			cin >> arr[e];
			v.push_back(arr[e]);
		}
		sort(all(v));
		v.erase(unique(all(v)),v.end());
		for(int e=0;e<(1<<n);e++){
			int k = lower_bound(all(v),arr[e]) - v.begin();
			if(e-arr[e]<10000) g[k].push_back(e);
		}
		vector<int> k;
		for(int e=0;e<sz(v);e++){
			if(sz(k)>20000) break;
			if(sz(g[e])<100){
				for(int p=0;p<sz(g[e]);p++) k.push_back(g[e][p]);
				for(int p=0;p<sz(g[e]);p++){
					for(int q=0;q<sz(k);q++){
						int f1 = (g[e][p]|k[q]);
						int f2 = (g[e][p]&k[q]);
						int x1 = arr[g[e][p]] + arr[k[q]];
						int x2 = arr[f1] + arr[f2];
						if(x1<x2){
							cout << g[e][p] << " " << k[q] << endl;
							exit(0);
						}
					}
				}
			}
		}
		k.clear();
		for(int e=sz(v)-1;e>=0;e--){
			if(sz(k)>20000) break;
			if(sz(g[e])<100){
				for(int p=0;p<sz(g[e]);p++) k.push_back(g[e][p]);
				for(int p=0;p<sz(g[e]);p++){
					for(int q=0;q<sz(k);q++){
						int f1 = (g[e][p]|k[q]);
						int f2 = (g[e][p]&k[q]);
						int x1 = arr[g[e][p]] + arr[k[q]];
						int x2 = arr[f1] + arr[f2];
						if(x1<x2){
							cout << g[e][p] << " " << k[q] << endl;
							exit(0);
						}
					}
				}
			}
		}
		k.clear();
		int mid = (sz(v))/2;
		for(int e=mid;e<sz(v);e++){
			if(sz(k)>20000) break;
			if(sz(g[e])<100){
				for(int p=0;p<sz(g[e]);p++) k.push_back(g[e][p]);
				for(int p=0;p<sz(g[e]);p++){
					for(int q=0;q<sz(k);q++){
						int f1 = (g[e][p]|k[q]);
						int f2 = (g[e][p]&k[q]);
						int x1 = arr[g[e][p]] + arr[k[q]];
						int x2 = arr[f1] + arr[f2];
						if(x1<x2){
							cout << g[e][p] << " " << k[q] << endl;
							exit(0);
						}
					}
				}
			}
		}
		k.clear();
		mid = (sz(v))/4;
		for(int e=mid;e<sz(v);e++){
			if(sz(k)>20000) break;
			if(sz(g[e])<100){
				for(int p=0;p<sz(g[e]);p++) k.push_back(g[e][p]);
				for(int p=0;p<sz(g[e]);p++){
					for(int q=0;q<sz(k);q++){
						int f1 = (g[e][p]|k[q]);
						int f2 = (g[e][p]&k[q]);
						int x1 = arr[g[e][p]] + arr[k[q]];
						int x2 = arr[f1] + arr[f2];
						if(x1<x2){
							cout << g[e][p] << " " << k[q] << endl;
							exit(0);
						}
					}
				}
			}
		}
		cout << "-1";
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