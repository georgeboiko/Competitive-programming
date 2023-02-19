#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <numeric>
#include <set>
#include <map>
#include <stack>
#include <queue>

using namespace std;

#define el '\n'
#define fastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;

const ll INF = 1e14;

bool comp(string bigger, string less) {
	if ((less == "*" && bigger != "*") || less == "(" || less == ")" || bigger == "(" || bigger == ")") return false;
	if (less == "+" || less == "-" || (less == "*" && bigger == "*")) return true;
}

bool isNum(string& s) {
	for (char i : s) {
		if (i < '0' || i > '9') return false;
	}
	return true;
}

vector<string> split(string s) {
	vector<string>ans;
	string temp = "";
	for (ll i = 0; i < s.size(); ++i) {
		if (s[i] >= '0' && s[i] <= '9') {
			temp += s[i];
			if (i == s.size() - 1) {
				ans.push_back(temp);
			}
		}
		else if (s[i] == '*') {
			if (temp != "") ans.push_back(temp);
			temp = "";
			ans.push_back("*");
		}
		else if (s[i] == '+') {
			if (temp != "") ans.push_back(temp);
			temp = "";
			ans.push_back("+");
		}
		else if (s[i] == '-') {
			if (temp != "") ans.push_back(temp);
			temp = "";
			ans.push_back("-");
		}
		else if (s[i] == '(') {
			if (temp != "") ans.push_back(temp);
			temp = "";
			ans.push_back("(");
		}
		else if (s[i] == ')') {
			if (temp != "") ans.push_back(temp);
			temp = "";
			ans.push_back(")");
		}
		else if (s[i] == ' ') {
			if (temp != "") ans.push_back(temp);
			temp = "";
		}
		else {
			return {};
		}
	}
	for (ll i = 1; i < ans.size(); ++i) {
		if (isNum(ans[i]) && isNum(ans[i - 1])) return {};
	}
	return ans;
}

int main() {
	stack<char>st;
	vector<string> s;
	string str;
	getline(cin, str);
	vector<string>v = split(str);
	if (v.size() == 0) {
		cout << "WRONG" << el;
		return 0;
	}
	ll bal = 0;
	for (ll i = 0; i < v.size(); ++i) {
		if (v[i] == "(") ++bal;
		if (v[i] == ")") --bal;
	}
	if (bal != 0) {
		cout << "WRONG" << el;
		return 0;
	}
	for (auto c : v) {
		if (isNum(c)) {
			s.push_back(c);
		}
		else if (c == "+" || c == "-" || c == "*") {
			string tmp = "";
			if (!st.empty()) tmp += st.top();
			while (!st.empty() && comp(tmp, c)) {
				string tm = "";
				tm += st.top();
				s.push_back(tm);
				st.pop();
				if (!st.empty()) {
					tmp = "";
					tmp += st.top();
				}
			}
			st.push(c[0]);
		}
		else if (c == "(") {
			st.push(c[0]);
		}
		else if (c == ")") {
			while (!st.empty() && st.top() != '(') {
				string tm = ""; 
				tm += st.top();
				s.push_back(tm);
				st.pop();
			}
			if (!st.empty()) st.pop();
		}
		else {
			cout << "WRONG" << el;
			return 0;
		}
	}
	while (!st.empty()) {
		string tm = "";
		tm += st.top();
		s.push_back(tm);
		st.pop();
	}
	stack<ll>cl;
	for (ll i = 0; i < s.size(); ++i) {
		if (s[i][0] >= '0' && s[i][0] <= '9') cl.push(stoll(s[i]));
		else if (cl.size() >= 2) {
			ll x = cl.top(); cl.pop();
			ll y = cl.top(); cl.pop();
			if (s[i] == "+") {
				cl.push(x + y);
			}
			if (s[i] == "-") {
				cl.push(y - x);
			}
			if (s[i] == "*") {
				cl.push(x * y);
			}
		}
		else {
			cout << "WRONG" << el;
			return 0;
		}
	}
	cout << cl.top() << el;
}
