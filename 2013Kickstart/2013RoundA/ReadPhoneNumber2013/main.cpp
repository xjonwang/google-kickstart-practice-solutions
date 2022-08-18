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

void solve(const map<int, string>& m, const map<int, string>& n);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    map<int, string> prefixes;
    prefixes.insert(make_pair(1, ""));
    prefixes.insert(make_pair(2, " double"));
    prefixes.insert(make_pair(3, " triple"));
    prefixes.insert(make_pair(4, " quadruple"));
    prefixes.insert(make_pair(5, " quintuple"));
    prefixes.insert(make_pair(6, " sextuple"));
    prefixes.insert(make_pair(7, " septuple"));
    prefixes.insert(make_pair(8, " octuple"));
    prefixes.insert(make_pair(9, " nonuple"));
    prefixes.insert(make_pair(10, " decuple"));
    map<int, string> numbers;
    numbers.insert(make_pair(0, " zero"));
    numbers.insert(make_pair(1, " one"));
    numbers.insert(make_pair(2, " two"));
    numbers.insert(make_pair(3, " three"));
    numbers.insert(make_pair(4, " four"));
    numbers.insert(make_pair(5, " five"));
    numbers.insert(make_pair(6, " six"));
    numbers.insert(make_pair(7, " seven"));
    numbers.insert(make_pair(8, " eight"));
    numbers.insert(make_pair(9, " nine"));

    int t = 1;
    read(t);

    FOR(t) {
        write("Case #", i+1, ":");
        solve(prefixes, numbers);
    }
    return 0;
}

void solve(const map<int, string>& prefixes, const map<int, string>& numbers) {
    string phone, format;
    read(phone);
    read(format);
    vt<int> formatVT;
    int startIndex = 0;
    while (format.find("-") != format.npos) {
        formatVT.pb(stoi(format.substr(0, format.find("-"))));
        startIndex = format.find("-") + 1;
        format = format.substr(startIndex);
    }
    formatVT.pb(stoi(format));
    int counter = 0;
    vt<int> repeats;
    EACH(j, formatVT) {
        string group = phone.substr(counter, j);
        EACH(item, group) {
            int value = item - '0';
            if (sz(repeats) == 0 || repeats.at(0) == value) {
                repeats.pb(value);
            }
            else {
                try {
                    write(prefixes.at(sz(repeats)), numbers.at(repeats.at(0)));
                }
                catch (out_of_range& ex) {
                    EACH(num, repeats) {
                        write(numbers.at(num));
                    }
                }
                repeats.clear();
                repeats.pb(value);
            }
        }
        try {
            write(prefixes.at(sz(repeats)), numbers.at(repeats.at(0)));
        }
        catch (out_of_range& ex) {
            EACH(num, repeats) {
                write(numbers.at(num));
            }
        }
        repeats.clear();
        counter += j;
    }
    print();    
}
