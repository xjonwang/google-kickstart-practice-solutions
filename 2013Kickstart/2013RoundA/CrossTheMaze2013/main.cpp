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
template<class A> void read(vt<A>& x) {
	EACH(a, x)
		read(a);
}
template<class A, size_t S> void read(array<A, S>& x) {
	EACH(a, x)
		read(a);
}
template<class H, class... T> void read(H& h, T&... t) {
	read(h);
	read(t...);
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

void solve(const vt<char>& compass);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vt<char> compass{'N', 'E', 'S', 'W'};

    int t = 1;
    read(t);

    FOR(t) {
        write("Case #", i+1, ": ");
        solve(compass);
    }
    return 0;
}

void move(const vt<vt<char>>& maze, int& sx, int& sy, int& steps, vt<char>& directions, char& direction, const vt<char> compass, const int& x1, const int& y1, const int& x2, const int& y2, const int& pos, int& noMoveCounter, auto checkEnd) {
    if (maze.at(sx + x1).at(sy + y1) == '.' && maze.at(sx + x2).at(sy + y2) == '#') {
        sx += x1;
        sy += y1;
        steps++;
        directions.pb(compass.at(pos));
        noMoveCounter = 0;
    }
    else if (maze.at(sx + x1).at(sy + y1) == '.' && maze.at(sx + x2).at(sy + y2) == '.') {
        if (direction == 'E' || direction == 'W'){
            sy += y2;
            steps++;
            directions.pb(compass.at(pos));
            if (!checkEnd(sx, sy)) {
                sx += x2;
                steps++;
                direction = compass.at((pos + 4 - 1) % 4);
                directions.pb(compass.at((pos + 4 - 1) % 4));
                noMoveCounter = 0;
            }
        }
        else {
            sx += x2;
            steps++;
            directions.pb(compass.at(pos));
            if (!checkEnd(sx, sy)) {
                sy += y2;
                steps++;
                direction = compass.at((pos + 4 - 1) % 4);
                directions.pb(compass.at((pos + 4 - 1) % 4));
                noMoveCounter = 0;
            }
        }
    }
    else {
        direction = compass.at((pos + 4 + 1) % 4);
        noMoveCounter++;
    }
}

void solve(const vt<char>& compass) {
    int n;
    read(n);
    vt<vt<char>> maze(n, vt<char>(n));
    read(maze);
    EACH(row, maze) {
        row.insert(row.begin(), '#');
        row.pb('#');
    }
    maze.insert(maze.begin(), vt<char>(n + 2, '#'));
    maze.pb(vt<char>(n + 2, '#'));
    int sx, sy, ex, ey;
    read(sx, sy, ex, ey);
    auto checkEnd = [&ex, &ey] (int& sx, int& sy) {
        return (sx == ex && sy == ey);
    };
    int steps{0};
    int noMoveCounter{0};
    char direction = (maze.at(sx - 1).at(sy) == '#') ? 'E' : ((maze.at(sx).at(sy + 1) == '#') ? 'S' : ((maze.at(sx + 1).at(sy) == '#') ? 'W' : 'N'));
    vt<char> directions;
    while (steps < 10000 && noMoveCounter < 4 && (sx != ex || sy != ey)) {
        switch(direction) {
            case 'E':
                move(maze, sx, sy, steps, directions, direction, compass, 0, 1, -1, 1, 1, noMoveCounter, checkEnd);
                break;
            case 'W':
                move(maze, sx, sy, steps, directions, direction, compass, 0, -1, 1, -1, 3, noMoveCounter, checkEnd);
                break;
            case 'N':
                move(maze, sx, sy, steps, directions, direction, compass, -1, 0, -1, -1, 0, noMoveCounter, checkEnd);
                break;
            case 'S':
                move(maze, sx, sy, steps, directions, direction, compass, 1, 0, 1, 1, 2, noMoveCounter, checkEnd);
                break;
        }
    }
    if (steps < 10000 && noMoveCounter < 4) {
        write(steps, '\n');
        EACH(step, directions) {
            write(step);
        }
    }
    else {
        write("Edison ran out of energy.");
    }
    print();
}
