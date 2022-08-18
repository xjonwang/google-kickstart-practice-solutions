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

ld highestPowerOf2(ld n) {
    ld res = 1;

    // Try all powers starting from 2^1
    for (ld i = 0; i < 8 * (int) sizeof(ld); i++)
    {
        ld curr = pow(2, i);

        // If current power is more than n, break
        if (curr > n)
            break;

        res = curr;
    }
    return res;
}

void solve();

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;
    cout << setprecision(0);

    int t = 1;
    read(t);

    FOR(t) {
        write("Case #", i+1, ": ");
        solve();
    }
    return 0;
}

void solveOne() {
    ld element;
    read(element);
    ld row = highestPowerOf2(element);
    ld numerator = 1;
    ld denominator = 1;
    while (row > 1) {
        if (fmod((element - row + 1), row) == 0 || fmod((element - row + 1), row) > (row / 2)) {
            numerator += denominator;
            element -= row;
            row /= 2;
        }
        else {
            denominator += numerator;
            element -= row/2;
            row /= 2;
        }
    }
    cout << numerator << " " << denominator;
}

void solveTwo() {
    ld numerator, denominator;
    read(numerator, denominator);
    queue<bool> binaries;
    while (!(numerator == 1 && denominator == 1)) {
        if (numerator < denominator) {
            denominator -= numerator;
            binaries.push(0);
        }
        else {
            numerator -= denominator;
            binaries.push(1);
        }
    }
    ld element = 0;
    ld basis = 1;
    binaries.push(1);
    while (!binaries.empty()) {
        element += basis * binaries.front();
        binaries.pop();
        basis *= 2;
    }
    cout << element;
}

void solve() {
    int id = 0; 
    read(id);
    if (id == 1) {
        solveOne();
    }
    else {
        solveTwo();
    }
    print();
}
