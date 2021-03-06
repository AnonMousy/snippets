#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef vector<int> vi;
typedef set<vi> svi;

svi gen_cycl_grps(vi v1) {
    // gen_cycl_grps(v1) is the cyclic subgroup 
    // generated by permutation v1
    vi v1a = v1, v1b = v1;
    svi s2;
    s2.insert(v1a);
    
    while (1 == 1) {
        for (int i = 0; i < v1.size(); i++) v1a[i] = v1b[v1[i] - 1];
        v1 = v1a;
        if (v1a == *s2.begin())
            break;
        else s2.insert(v1a);
        }
        
    return s2;
    }

void print_svi(svi s1) {
    // print elements of s1
    int j = 1;
    for (auto t = s1.begin(); t != s1.end(); t++) {

        for (int i = 0; i < (*t).size(); i++)
            cout << (*t)[i] << ' ';
        cout << "   ";
        j++;
        }
    }

int main() {
    vi v1 {2, 7, 4, 6, 1, 5, 3};
    
    print_svi(gen_cycl_grps(v1));
    }
