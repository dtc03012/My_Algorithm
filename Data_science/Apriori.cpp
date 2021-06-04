#include <bits/stdc++.h>
#include <assert.h>
#include <time.h>
using namespace std;



struct association_rule{
	vector<int> ls,als;
	double support,confidence;
	association_rule(){

	}
	association_rule(vector<int> _ls,vector<int> _als,double _support,double _confidence) : 
		ls(_ls), als(_als), support(_support), confidence(_confidence){
	};
};


vector<vector<int> > arr;
map<vector<int>,bool> map_vector;
vector<vector<int> > association;
vector<int> test;
vector<association_rule> answer;



vector<int> parsing(string a){
	vector<int> number_arr;
	int string_len = (int)a.size() + 10;
	char *str_buff = (char*)malloc(string_len*sizeof(char*));
	strcpy(str_buff,a.c_str());
	char *tok = strtok(str_buff,"\t");
	while(tok!=nullptr){
		int xx = 0,len = strlen(tok);
		for(int p=0;p<len;p++) xx = xx*10 + tok[p] - '0';
		number_arr.push_back(xx);
		tok = strtok(nullptr,"\t");
	}
	free(str_buff);
	sort(number_arr.begin(),number_arr.end());
	return number_arr;
}

int get_max_value(int total_data){
	int val = 0;
	for(int e=0;e<total_data;e++){
		int data_len = (int)arr[e].size();
		for(int p=0;p<data_len;p++){
			val = max(val,arr[e][p]);
		}
	}
	return val;
}

void init(int total_data,int max_value,int minimum_support){
	map<vector<int>,bool> storage;
	int* count_arr = (int*)malloc((max_value+5)*sizeof(int*));
	memset(count_arr,0,sizeof(int*)*(max_value+5));
	for(int e=0;e<total_data;e++){
		int data_len = (int)arr[e].size();
		for(int p=0;p<data_len;p++){
			count_arr[arr[e][p]]++;
		}
	}
	for(int e=0;e<=max_value;e++){
		if(count_arr[e]*100>=total_data*minimum_support){
			vector<int> first_value;
			first_value.push_back(e);
			storage[first_value] = true;
		}
	}
	free(count_arr);
	map_vector = storage;
}

bool can(const vector<int>& check_vector,int total_data,int minimum_support){
	int count_value = 0;
	int check_len = (int)check_vector.size();
	for(int e=0;e<total_data;e++){
		int pos = 0,data_len = (int)arr[e].size();
		for(int p=0;p<data_len;p++){
			if(pos==check_len) break;
			if(arr[e][p]==check_vector[pos]) pos++;
		}
		if(pos==check_len) count_value++;
	}
	if(count_value*100>=minimum_support*total_data) return true;
	return false;
}
void make_frequent_pattern(int total_data,int max_value,int minimum_support){
	init(total_data,max_value,minimum_support);
	for(int e=1;e<=max_value;e++){
		bool flag = false;
		set<int> total_index;
		map<vector<int>,bool> storage;
		map<vector<int>,int> check_num;
		for(map<vector<int>,bool>::iterator it = map_vector.begin();it!=map_vector.end();it++){
			vector<int> now = it->first;
			int now_len = (int)now.size();
			for(int p=0;p<now_len;p++) total_index.insert(now[p]);
		}
		for(map<vector<int>,bool>::iterator map_it = map_vector.begin();map_it!=map_vector.end();map_it++){
			vector<int> now = map_it->first;
			vector<int> res_index;
			for(set<int>::iterator set_it = total_index.begin();set_it!=total_index.end();set_it++){
				if(!binary_search(now.begin(),now.end(),*set_it)) res_index.push_back(*set_it);
			}
			int res_index_len = (int)res_index.size();
			for(int p=0;p<res_index_len;p++){
				vector<int> new_vector = now;
				new_vector.push_back(res_index[p]);
				sort(new_vector.begin(),new_vector.end());
				if(!check_num.count(new_vector)) check_num[new_vector] = 1;
				else check_num[new_vector]++;
			}
		}
		for(map<vector<int>,int>::iterator check_map_it = check_num.begin();check_map_it!=check_num.end();check_map_it++){
			if(check_map_it->second==e+1&&can(check_map_it->first,total_data,minimum_support)){
				flag = true;
				storage[check_map_it->first] = true;
				vector<int> now_vector = check_map_it->first;
				int now_vector_len = (int)now_vector.size();
				association.push_back(check_map_it->first);
			}
		}
		if(!flag) break;
		else map_vector = storage;
	}
}

double calc_support(vector<int>& check_vector,int total_data){
	int count_value = 0;
	int check_len = (int)check_vector.size();
	for(int e=0;e<total_data;e++){
		int pos = 0,data_len = (int)arr[e].size();
		for(int p=0;p<data_len;p++){
			if(pos==check_len) break;
			if(arr[e][p]==check_vector[pos]) pos++;
		}
		if(pos==check_len) count_value++;
	}
	double support = (double)(count_value*100) / (double) total_data;
	return support;
}

double calc_supports(vector<int>& check_vector,int total_data){
	int count_value = 0;
	int check_len = (int)check_vector.size();
	for(int e=0;e<total_data;e++){
		int pos = 0,data_len = (int)arr[e].size();
		for(int p=0;p<data_len;p++){
			if(pos==check_len) break;
			if(arr[e][p]==check_vector[pos]) pos++;
		}
		if(pos==check_len) count_value++;
	}
	double support = (double)(count_value*100) / (double) total_data;
	return support;
}

double calc_confidence(vector<int>& ls,vector<int>& als,int total_data){
	int count_value = 0;
	int ls_len = (int)ls.size();
	int als_len = (int)als.size();
	int this_total_data = 0;
	for(int e=0;e<total_data;e++){
		int pos = 0;
		int data_len = (int)arr[e].size();
		for(int p=0;p<data_len;p++){
			if(pos==ls_len) break;
			if(arr[e][p]==ls[pos]) pos++;
		}
		if(pos==ls_len){
			this_total_data++;
			pos = 0;
			for(int p=0;p<data_len;p++){
				if(pos==als_len) break;
				if(arr[e][p]==als[pos]) pos++;
			}
			if(pos==als_len) count_value++;
		}
	}
	double support = (double)(count_value*100) / (double) this_total_data;
	return support;
}

void make_association_rule(int total_data,int max_value,int minimum_support){
	int total_frequent_pattern_len = (int)association.size();
	for(int e=0;e<total_frequent_pattern_len;e++){
		int node_len = (int)association[e].size();
		double new_support = calc_support(association[e],total_data);
		for(int bit = 1;bit<(1<<node_len)-1;bit++){
			vector<int> ls,als;
			for(int q=0;q<node_len;q++){
				if(bit&(1<<q)) ls.push_back(association[e][q]);
				else als.push_back(association[e][q]);
			}
			double new_confidence = calc_confidence(ls,als,total_data);
			answer.push_back(association_rule(ls,als,new_support,new_confidence));
		}
	}
}

void apriori(int total_data,int max_value,int minimum_support){
	make_frequent_pattern(total_data,max_value,minimum_support);
	make_association_rule(total_data,max_value,minimum_support);
}
int toint(char* x){
	int num = 0;
	int len = strlen(x);
	for(int e=0;e<len;e++) num = num*10 + x[e] - '0';
	return num;
}
int main(int argc,char **argv){
	clock_t start_time = clock();
	int minimum_support = 1;
	ifstream in;
	ofstream out;
	if(argc<4) return 0;
	minimum_support = toint(argv[1]);
	char* input_file = argv[2];
	char* output_file = argv[3];
	in.open(input_file);
	out.open(output_file);
	out << fixed;
	out.precision(2);
	while(!in.eof()){
		string line;
		getline(in,line);
		vector<int> number_arr = parsing(line);
		arr.push_back(number_arr);
	}
	int total_data = (int)arr.size();
	int max_value = get_max_value(total_data);
	apriori(total_data,max_value,minimum_support);
	for(int e=0;e<(int)answer.size();e++){
		vector<int>& ls = answer[e].ls;
		vector<int>& als = answer[e].als;
		double support = answer[e].support;
		double confidence = answer[e].confidence;
		out << "{";
		int ls_len = (int)ls.size();
		for(int p=0;p<ls_len;p++){
			out << ls[p];
			if(p!=ls_len-1) out << ",";
		}
		out << "}\t{";
		int als_len = (int)als.size();
		for(int p=0;p<als_len;p++){
			out << als[p];
			if(p!=als_len-1) out << ",";
		}
		out << "}\t" << support << "\t" << confidence << "\n"; 
	}
	clock_t end_time = clock();
	printf("%f second\n",(double)(end_time-start_time)/1000.0);
	return 0;
}