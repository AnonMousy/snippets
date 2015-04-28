#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

// S1 = {0, 1, 2, ..., n} input alphabet;              type: vi
// S2 is word (string of letters from S1);             type: vi
// function f changes state of automaton

vi f(vi v1, int i) {
    // Automaton in state v1, v1.size() = n, acts on letter i in S2
    // Letter i is changed into v1[i] 
    // Automaton goes into new state f(v1, i) 
    int k = 0;
    int n = v1.size();
    for (int j = 0; j < v1.size(); j++) {
        k = v1[j];
        v1[j] = (j*k + i + k + 2)%n;
        }
    return v1;
    }

void print_vi(vi v1) {
    // print elements of v1
    for (int i = 0; i < v1.size(); i++) {
        cout << v1[i] << ' ';
        }
    cout << "\n";
    }

void deterministic(vi v1, vi S2) {
    // v1 is initial state of automaton, S2 is initial word
    cout << "Initial S2 word: "; print_vi(S2);
    cout << "Initial state of automaton: "; print_vi(v1);
    for (int i = 0; i < S2.size(); i++) {
        int i1 = S2[i];
        // replace letter in word
        S2[i] = v1[S2[i]];
        cout << "word after change of symbol S2[" << i << "]:  ";
        print_vi(S2);
        // New state of automaton: it depends on letter i1 
        // (S2[i] before change) and current state v1 
        v1 = f(v1, i1);
        cout << "state after change of symbol S2[" << i << "]:  ";
        print_vi(v1);
        }
    }

int main() {
    // Choice of alphabet: {0, 1, 2, 3, 4}, n = 5 
    int n = 5; 
    // Choice of initial state v1, v1.size()=n, with elements from alphabet    
    int a[] = {2, 0, 4, 2, 1};
    vi v1(a, a + sizeof(a) / sizeof(*a));
    // Choice of word S2 with letters from alphabet
    vi S2(10, 1);
    for (int i = 0; i < S2.size(); i++)
        S2[i] = ((i + 2)%4 + 1)%4;
   
    deterministic(v1, S2);
    // One can chose some 'accepted states'; then automaton accepts 
    // initial word S2 if final state is one of these states
    }
