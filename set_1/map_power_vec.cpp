#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vvi map_power_vec(vi v1, int m) {
    // vvi vector of first m powers of map v1
    int j = 1;
    vi v1a = v1, v1b = v1;
    vvi v2;
    v2.push_back(v1a);
    
    while (j < m) {
        for (int i = 0; i < v1.size(); i++) v1a[i] = v1b[v1[i] - 1];
        
        v1 = v1a;
        v2.push_back(v1a);
        j++;
        }
        
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
    int a[] = {2, 4, 1, 1};
    vi v1(a, a + sizeof(a) / sizeof(*a));
    
    print_vvi(map_power_vec(v1, 10));
    
    }
