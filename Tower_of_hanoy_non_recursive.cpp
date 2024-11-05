#include <bits/stdc++.h>


using namespace std;

void towerOfHanoi(int N, char BEG, char AUX, char END) {
    stack<tuple<int, char, char, char, int>> st;
    int step = 1;

    // Initial push of parameters to the stack
    st.push(make_tuple(N, BEG, AUX, END, step));

    while (!st.empty()) { 
        tie(N, BEG, AUX, END, step) = st.top();
        st.pop();

        if (N == 1) {
            cout << "Move disk 1 from " << BEG << " to " << END << endl;
            continue;
        }

        // Depending on the step, push corresponding operations onto the stack
        if (step == 1) {
            // Move N-1 disks from BEG to AUX using END as auxiliary
            st.push(make_tuple(N, BEG, AUX, END, 2));
            st.push(make_tuple(N-1, BEG, END, AUX, 1));
        } else if (step == 2) {
            // Move the N-th disk from BEG to END
            cout << "Move disk " << N << " from " << BEG << " to " << END << endl;
            st.push(make_tuple(N-1, AUX, BEG, END, 1));
        }
    }
}

int main() {
    int N;
    cin >> N;

    towerOfHanoi(N, 'A', 'B', 'C');

    return 0;
}
