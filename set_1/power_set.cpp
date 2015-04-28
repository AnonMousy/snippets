#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vvi power_set(int n) {
    // power_set(n) is power set of {1, 2, ... ,n}; power_set(n)[0] has
    // only one element, power_set(n)[0][0] = 0, that represents empty set
    vi v1(n + 2), v1a;
    vvi v2;
    int k = 0;
    v1a.push_back(0);
    v2.push_back(v1a);
    v1a.clear();
    
    while (1) {
        if (v1[k] < n) {
            v1[k + 1] = v1[k] + 1;
            k++;
            }
        else {
            v1[k - 1]++;
            k--;
            }
        if (k == 0) break;
        
        for (int i = 1; i <= k; i++) v1a.push_back(v1[i]);
        v2.push_back(v1a);
        v1a.clear();
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
    print_vvi(power_set(4));
    
    }
