#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int x;

bool isCompletion(int z) {
	int bitval = 0;
	z += 1; while (z % 2 == 0) {z /= 2; bitval++;}
	return (z == 1);
}

int MSB(int z) {
	for (int i=20; i>=0; i--) {
		if ((z >> i) & 1) return i;
	}
	return -1;
}

void Input() {
	cin >> x;
}

void Solve() {
	int i = 0; vector<int> xorCmd;
	while (!isCompletion(x)) {
		i = i + 1;
		if (i % 2 == 0) {x++; continue;}
		int r = MSB(x);
		if ((1 << r) != x) r++;
		x = (x ^ ((1 << r) - 1)); xorCmd.push_back(r);
	}
	cout << i << endl;
	for (auto z: xorCmd) cout << z << " "; cout << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); Input(); Solve();
	return 0;
}