#include <iostream>
using namespace std;

void TOWER(int N, char BEG, char AUX, char END) {
    if (N == 1) {
        cout << "Move disk " << N << " from " << BEG << " to " << END << endl;
        return;
    }

    // Move N-1 disks from BEG to AUX using END as auxiliary
    TOWER(N - 1, BEG, END, AUX);

    // Move the Nth disk from BEG to END
    cout << "Move disk " << N << " from " << BEG << " to " << END << endl;

    // Move N-1 disks from AUX to END using BEG as auxiliary
    TOWER(N - 1, AUX, BEG, END);
}

int main() {
    int N;
    
    cin >> N;

    TOWER(N, 'A', 'B', 'C'); 

    return 0;
}
