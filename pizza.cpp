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
				}
				D[i][j] = label[ingredient];
				dislike_set[i].insert(label[ingredient]);
			}
		}
		cout << "C = " << C << endl;
		cout << "Number of different ingredients = " << sz << endl;
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

	void brute_force(){
		int n = 1 << sz;
		int m = min(10, sz);
		int ans = 0;
		int max_score = 0;
		for (int i = 0; i < n; i++){
			unordered_set<int> ss;
			for (int j = 0; j < m; j++)
				if (i & (1 << j))
					ss.insert(j);

			int score = 0;

			for (int j = 0; j < C; j++){
				if (is_subset(ss, like_set[j]) and is_disjoint(ss, dislike_set[j]))
					score++;
			}


			if (score > max_score){
				max_score = score; 
				ans = i;
			}
		}


		cout << "max_score =  " << max_score << endl;
		cout << "Ingredient: " << endl;

		int sum = 0;
		for (int j = 0; j < m; j++){
			if (ans & (1 << j)){
				sum ++;
			}
		}
		cout << sum;

		for (int j = 0; j < m; j++){
			if (ans & (1 << j)){
				cout << " " << label__[j];
			}
		}
		cout << endl;
	}
};


int main(){
	Pizza* pizza = new Pizza();
	pizza->brute_force();
	return 0;
}
