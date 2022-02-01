#include <bits/stdc++.h>
using namespace std;

class Pizza {
public:
	int C;
	vector<vector<int>> L;
	vector<vector<int>> D;

	unordered_map<string, int> label;
	unordered_map<int, string> label__;
	int sz;

	vector<unordered_set<int>> like_set;
	vector<unordered_set<int>> dislike_set;
	vector<unordered_set<int>> deg_set;
	Pizza(){
		int n;
		string ingredient;

		cin >> C;
		L.resize(C);
		D.resize(C);
		like_set.resize(C);
		dislike_set.resize(C);

		for (int i = 0; i < C; i++){
			cin >> n;
			L[i].resize(n);
			for(int j = 0 ; j < n; j++){
				cin >> ingredient;
				if (label.find(ingredient) == label.end()){
					label[ingredient] = sz++;
					label__[label[ingredient]] = ingredient;
					unordered_set<int> tmp;
					deg_set.push_back(tmp);
				}
				L[i][j] = label[ingredient];
				like_set[i].insert(label[ingredient]);
			}
		
			cin >> n;
			D[i].resize(n);
			for(int j = 0 ; j < n; j++){
				cin >> ingredient;
				if (label.find(ingredient) == label.end()){
					label[ingredient] = sz++;
					label__[label[ingredient]] = ingredient;
					unordered_set<int> tmp;
					deg_set.push_back(tmp);
				}
				D[i][j] = label[ingredient];
				dislike_set[i].insert(label[ingredient]);
				deg_set[label[ingredient]].insert(i);
			}
		}
		// cout << "C = " << C << endl;
		// cout << "Number of different ingredients = " << sz << endl;
	}

	// Check if s2 is a subset of s1.
	bool is_subset(unordered_set<int>& s1, unordered_set<int>& s2){
		if (s1.size() < s2.size()) return false;
		for (auto& x: s2){
			if (s1.find(x) == s1.end()){
				return false;
			}
		}
		return true;
	}

	bool is_disjoint(unordered_set<int>& s1, unordered_set<int>& s2){
		for (auto& x: s2){
			if (s1.find(x) != s1.end()){
				return false;
			}
		}
		return true;
	}

	// s1 = Union(s1, s2)
	void merge(unordered_set<int>& s1, unordered_set<int>& s2){
		for (auto& x: s2){
			s1.insert(x);
		}
	}

	void greedy(){
		vector<pair<int, int>> deg(C);
		for (int i = 0 ; i < C; i++){
			unordered_set<int> ss;
			for (auto& j: L[i]){
				merge(ss, deg_set[j]);
			}
			deg[i].first = ss.size();
			deg[i].second = i;
		}

		sort(deg.begin(), deg.end());

		// for (auto& p: deg){
		// 	cout << p.first << " " << p.second << endl;
		// }

		unordered_set<int> sol_include;
		unordered_set<int> sol_exclude;
		int score = 0;
		for (auto& p: deg) {
			int id = p.second;
			if (is_disjoint(sol_include, dislike_set[id]) and is_disjoint(sol_exclude, like_set[id])){
				merge(sol_include, like_set[id]);
				merge(sol_exclude, dislike_set[id]);
				score++;
			}
		}


		// cout << "Score = " << score << endl;
		cout << sol_include.size();
		for (auto& x: sol_include){
			cout << " " << label__[x];
		}
		cout << endl;
	}
};


int main(){
	Pizza* pizza = new Pizza();
	pizza->greedy();
	return 0;
}
