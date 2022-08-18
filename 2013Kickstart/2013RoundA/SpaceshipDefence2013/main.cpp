#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ar array

#define vt vector
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
# define INF 0x3f3f3f3f

#define F_OR(i, a, b, s) for (int i=(a); (s)>0?i<(b):i>(b); i+=(s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define EACH(x, a) for (auto& x: a)

typedef pair<int, int> iPair;

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

    int t = 1;
    read(t);

    FOR(t) {
        write("Case #", i+1, ": ");
        solve();
    }
    return 0;
}

void shortestPath(int src, int destination, vector<iPair> adj[], int numRooms) {
    // Create a priority queue to store vertices that
    // are being preprocessed. This is weird syntax in C++.
    // Refer below link for details of this syntax
    // https://www.geeksforgeeks.org/implement-min-heap-using-stl/
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
 
    // Create a vector for distances and initialize all
    // distances as infinite (INF)
    vector<int> dist(numRooms, INF);
 
    // Insert source itself in priority queue and initialize
    // its distance as 0.
    pq.push(make_pair(0, src));
    dist[src] = 0;
 
    /* Looping till priority queue becomes empty (or all
      distances are not finalized) */
    while (!pq.empty())
    {
        // The first vertex in pair is the minimum distance
        // vertex, extract it from priority queue.
        // vertex label is stored in second of pair (it
        // has to be done this way to keep the vertices
        // sorted distance (distance must be first item
        // in pair)
        int u = pq.top().second;
        pq.pop();
 
        // 'i' is used to get all adjacent vertices of a vertex
        EACH(x, adj[u]) {
            // Get vertex label and weight of current adjacent
            // of u.
            int v = x.first;
            int weight = x.second;
 
            //  If there is shorted path to v through u.
            if (dist[v] > dist[u] + weight)
            {
                // Updating distance of v
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    print();
    (dist[destination] != INF) ? write(dist[destination]) : write("-1");
}

void solve() {
    int numRooms, numLifts, numSoldiers;
    read(numRooms);
    vt<string> roomColors(numRooms);
    read(roomColors);
    read(numLifts);
    vt<vt<int>> lifts(numLifts, vt<int>(3));
    read(lifts);
    read(numSoldiers);
    vt<vt<int>> soldiers(numSoldiers, vt<int>(2));
    read(soldiers);
    vector<iPair> adj[numRooms];
    EACH(lift, lifts) {
        adj[lift.at(0) - 1].pb(make_pair(lift.at(1) - 1, lift.at(2))); 
    }
    FOR(i, numRooms) {
        FOR (j, numRooms) {
            if (roomColors.at(i) == roomColors.at(j)) {
                adj[i].pb(make_pair(j, 0)); 
                adj[j].pb(make_pair(i, 0)); 
            }
        }
    }
    EACH(soldier, soldiers) {
        shortestPath(soldier.at(0) - 1, soldier.at(1) - 1, adj, numRooms);
    }
    print();
}