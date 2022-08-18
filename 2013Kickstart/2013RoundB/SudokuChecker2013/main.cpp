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

bool solve();

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    read(t);

    FOR(t) {
        write("Case #", i+1, ": ");
        solve();
    }
    return 0;
}

bool solve() {
    int n;
    read(n);
    vt<vt<vt<int>>> sudoku(n*n, vt<vt<int>>(n, vt<int>(n)));
    read(sudoku);
    set<int> refSet;
    FOR(n*n) {
        refSet.insert(i + 1);
    }
    set<int> test;
    EACH(row, sudoku) {
        EACH(section, row) {
            EACH(value, section) {
                test.insert(value);
            }
        }
        if (test != refSet) {
            write("No");
            print();
            return 0;
        }
        test.clear();
    }
    test.clear();
    FOR(n*n) {
        int section = i / n;
        int pos = i % n;
        EACH(row, sudoku) {
            test.insert(row.at(section).at(pos));
        }
        if (test != refSet) {
            write("No");
            print();
            return 0;
        }
    }
    test.clear();
    FOR(n) {
        FOR(j, n) {
            vt<vt<int>> block;
            FOR(k, n) {
                block.pb(sudoku.at(j + k).at(i));
            }
            EACH(row, block) {
                EACH(pos, row) {
                    test.insert(pos);
                }
            }
            if (test != refSet) {
                write("No");
                print();
                return 0;
            }
        }
    }
    write("Yes");
    print();
    return 1;
}
