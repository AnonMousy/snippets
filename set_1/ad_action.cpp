#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vvi ad_action(vi v1c) {
    // elements of vvi ad_action(v1c) belong to orbit under
    // adjoint action of permutation group on map v1c:
    // ad_action (v1c) = { v1 * v1c * (inverse of permutation v1)|v1 in P(n)}
    int n = v1c.size();
    vi v1(n, 0);
    for (int i = 0; i < n; i++) v1[i] = i + 1;
    
    vvi v2a, v2c;
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
        
    vi v1d;
    
    for (int i = 0; i < v2a.size(); i++) {
        vi v1i = v2a[i];
        for (int k = 0; k < v2a[i].size(); k++)
            v1i[k] = v2a[i][v1c[k] - 1];
            
        v1d = v1i;
        vi v1j = v1d;
        for (int k = 0; k < v1d.size(); k++)
            v1j[k] = v1d[v2b[i][k] - 1];
            
        v1d = v1j;
        sort(v2c.begin(), v2c.end());
        
        if (binary_search(v2c.begin(), v2c.end(), v1d) != true)
            v2c.push_back(v1d);
        }
        
    return v2c;
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
    vi v1c {3, 1, 1};
    print_vvi(ad_action(v1c));
    
    cout << endl << ad_action(v1c).size();
    
    }
