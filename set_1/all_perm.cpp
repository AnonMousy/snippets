#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vvi all_perm(int n) {
    // vvi vector of all permutations of set {1, 2, ... ,n}
    vi v1;
    for (int i = 0; i < n; i++) v1.push_back(i + 1);
    
    vvi v2;
    do v2.push_back(v1);
    while (next_permutation(v1.begin(), v1.end()) != 0);
    
    return v2;
    }

void print_vvi(vvi v2) {
    // prints vi vectors elements of v2
    for (int i = 0; i < v2.size(); i++) {
        for (int j = 0; j < v2[i].size(); j++) {
            cout << v2[i][j];
            if (j + 1 < v2[i].size()) cout << " ";
            }
        if (i != v2.size() - 1) cout << "   ";
        }
    }

int main() {
    print_vvi(all_perm(3));
    
    }
