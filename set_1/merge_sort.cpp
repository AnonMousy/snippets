#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

vi merge_sort(vi v1) {
    if (v1.size() == 1) {
        return v1;
        }
    
    auto t = v1.begin() + (v1.size() / 2);
    vi v1a(v1.begin(), t);
    vi v1b(t, v1.end());
    v1a = merge_sort(v1a);
    v1b = merge_sort(v1b);
    
    vi v1c;
    int i = 0, j = 0;
    while (i < v1a.size() && j < v1b.size()) {
        if (v1a[i] < v1b[j]) {
            v1c.push_back(v1a[i]);
            i++;
            }
        else {
            v1c.push_back(v1b[j]);
            j++;
            }
        }
    while (i < v1a.size()) {
        v1c.push_back(v1a[i]);
        i++;
        }
    while (j < v1b.size()) {
        v1c.push_back(v1b[j]);
        j++;
        }
    
    return v1c;
    }

void print_vi(vi v1) {
    // prints elements of v1
    for (int i = 0; i < v1.size(); i++) cout << v1[i] << ' ';
    cout << "\t";
    }

int main() {
    int a[] = {4, 1, 4, 2, 1};
    vi v1(a, a + sizeof(a) / sizeof(*a));
    print_vi(merge_sort(v1));
    }
