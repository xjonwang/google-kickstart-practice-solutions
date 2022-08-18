#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ar array

#define vt vector
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()

#define F_OR(i, a, b, s) for (int i=(a); (s)>0?i<(b):i>(b); i+=(s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define EACH(x, a) for (auto& x: a)

template<class T> void read(T& x) {
	cin >> x;
}
void read(double& d) {
	string t;
	read(t);
	d=stod(t);
}
void read(long double& d) {
	string t;
	read(t);
	d=stold(t);
}
template<class H, class... T> void read(H& h, T&... t) {
	read(h);
	read(t...);
}
template<class A> void read(vt<A>& x) {
	EACH(a, x)
		read(a);
}
template<class A, size_t S> void read(array<A, S>& x) {
	EACH(a, x)
		read(a);
}

string to_string(char c) {
	return string(1, c);
}
string to_string(bool b) {
	return b?"true":"false";
}
string to_string(const char* s) {
	return string(s);
}
string to_string(string s) {
	return s;
}
string to_string(vt<bool> v) {
	string res;
	FOR(sz(v))
		res+=char('0'+v[i]);
	return res;
}

template<size_t S> string to_string(bitset<S> b) {
	string res;
	FOR(S)
		res+=char('0'+b[i]);
	return res;
}
template<class T> string to_string(T v) {
    bool f=1;
    string res;
    EACH(x, v) {
		if(!f)
			res+=' ';
		f=0;
		res+=to_string(x);
	}
    return res;
}

template<class A> void write(A x) {
	cout << to_string(x);
}
template<class H, class... T> void write(const H& h, const T&... t) { 
	write(h);
	write(t...);
}
void print() {
	write("\n");
}
template<class H, class... T> void print(const H& h, const T&... t) { 
	write(h);
	if(sizeof...(t))
		write(' ');
	print(t...);
}

void solve();

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    write("Case #", "1", ": ");
    solve();
    return 0;
}

void updateChecking(string& checking, int index) {
    checking = checking.substr(index + 2);
}

void solve() {
    vt<string> program;
    string str;
    while (getline(cin, str)) {
        program.pb(str);
    }
    int index = 0;
    string checking;
    int openCounter = 0;
    vt<pair<int, int>> startIndex;
    vt<pair<int, int>> endIndex;
    while (index < sz(program)) {
        checking = program.at(index);
        const int indexCheck = index;
        const int checkingLength = checking.length();
        while (index == indexCheck) {
            int openIndex = checking.find("/*");
            int closeIndex = checking.find("*/");
            //cout << index << " " << openCounter << endl;
            if (openCounter == 0) {
                if (openIndex == -1) {
                    index++;
                }
                else {
                    openCounter++;
                    startIndex.pb(make_pair(index, checkingLength - checking.length() + openIndex));
                    updateChecking(checking, openIndex);
                }
            }
            else if (openCounter == 1) {
                if ((closeIndex < openIndex && closeIndex != -1) || (openIndex == -1 && closeIndex != -1)) {
                    openCounter--;
                    endIndex.pb(make_pair(index, checkingLength - checking.length() + closeIndex + 2));
                    updateChecking(checking, closeIndex);
                }
                else if ((closeIndex > openIndex && openIndex != -1) || (closeIndex == -1 && openIndex != -1)) {
                    openCounter++;
                    updateChecking(checking, openIndex);
                }
                else {
                    index++;
                }
            }
            else {
                if ((closeIndex < openIndex && closeIndex != -1) || (openIndex == -1 && closeIndex != -1)) {
                    openCounter--;
                    updateChecking(checking, closeIndex);
                }
                else if ((closeIndex > openIndex && openIndex != -1) || (closeIndex == -1 && openIndex != -1)) {
                    openCounter++;
                    updateChecking(checking, openIndex);
                }
                else {
                    index++;
                }
            }
        }
    }
    if (sz(startIndex) > sz(endIndex)) {
        startIndex.pop_back();
    }
    /*
    EACH(item, startIndex) {
        cout << "row: " << item.first << " pos: " << item.second << endl;
    }
    EACH(item, endIndex) {
        cout << "row: " << item.first << " pos: " << item.second << endl;
    }
    */
    FOR(j, sz(startIndex) - 1, -1, -1) {
        int startRow = startIndex.at(j).first;
        int startPos = startIndex.at(j).second;
        int endRow = endIndex.at(j).first;
        int endPos = endIndex.at(j).second;
        program.at(startRow) = program.at(startRow).substr(0, startPos) + program.at(endRow).substr(endPos);
        FOR(k, endRow, startRow, -1) {
            program.erase(program.begin() + k);
        }
    }
    EACH(line, program) {
        print();
        write(line);
    }
}
