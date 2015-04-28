#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vvi all_maps(int n) {
    // all_maps is vvi vector of all all maps of set {1, 2, ... ,n};
    // a map is defined by vi vector in a natural way
    vi v1;
    int i;
    
    for (i = 0; i < n; i++) v1.push_back(i + 1);
    vi v1a, v1b(n, 0);
    vvi v2;
    
    do {
        for (i = n - 1; i >= 0; --i) v1a.push_back(v1[v1b[i]]);
        
        v2.push_back(v1a);
        v1a.clear();
        
        for (i = 0; i < n; ++i)
            if (++v1b[i] < n) break;
            else v1b[i] = 0;
        }
    while (i < n);
    
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
    print_vvi(all_maps(3));
    cout << endl << all_maps(3).size() << endl;
    
    }
