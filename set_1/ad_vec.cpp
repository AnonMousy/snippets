#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

vvvi ad_vec(int n) {
    // v3 = vvvi ad_vec(n) has two elements: v3[0] that holds all
    // permutations and, v3[1] that holds corresponding inverses;
    // thus v[0][i] * v[1][i] = Id = v[0][0] = v[1][0] = 1 2 … n
    // for all i = 0, 1, ... , n! - 1
    vi v1;
    for (int i = 1; i <= n; i++) v1.push_back(i);
    
    vvi v2a;
    do v2a.push_back(v1);
    while (next_permutation(v1.begin(), v1.end()) != 0);
    
    vi v1b;
    vvi v2b;
    v2b.push_back(v1);
    
    while (next_permutation(v1.begin(), v1.end()) != 0) {
        v1b = v1;
        for (int i = 0; i < v1.size(); i++) v1b[v1[i] - 1] = i + 1;
        v2b.push_back(v1b);
        }
    
    vvvi v3;
    v3.push_back(v2a);
    v3.push_back(v2b);
    return v3;
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
    int j = 3;
    vvi v2;
    
    v2 = ad_vec(j)[0];
    cout << "vvi vector of permutation group: " << endl;
    print_vvi(v2);
    
    cout << endl << "--------------------------------------" << endl;
    cout << "vvi vector of inverse permutation group: " << endl;
    v2 = ad_vec(j)[1];
    print_vvi(v2);
    
    }
