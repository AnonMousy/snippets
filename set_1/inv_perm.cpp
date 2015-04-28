#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

vi inv_perm(vi v1) {
    // inv_perm (v1) is the inverse permutation of v1
    vi v1b = v1;
    for (int i = 0; i < v1.size(); i++)
        v1b[v1[i] - 1] = i + 1;
        
    return v1b;
    }

void print_vi(vi v1) {
    // prints elements of v1
    for (int i = 0; i < v1.size(); i++) cout << v1[i] << ' ';
    cout << "\t";
    }

int main() {
    int a[] = {3, 8, 5, 10, 9, 4, 6, 1, 7, 2};
    vi v1(a, a + sizeof(a) / sizeof(*a));
    
    print_vi(inv_perm(v1));
    
    }
