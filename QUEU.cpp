#include <bits/stdc++.h>
using namespace std;

const int N = 5; // Max size of the queue

void QINSERT(int QUEUE[], int& FRONT, int& REAR, int ITEM) {
    // Step 1: Check if the queue is already filled
    if ((FRONT == 1 && REAR == N) || (FRONT == REAR + 1)) {
        cout << "OVERFLOW" << endl;
        return;
    }

    // Step 2: Find the new value of REAR
    if (FRONT == -1) {  // Queue initially empty
        FRONT = 1;
        REAR = 1;
    } else if (REAR == N) {
        REAR = 1;
    } else {
        REAR = REAR + 1;
    }

    // Step 3: Insert the new element
    QUEUE[REAR - 1] = ITEM;

    // Step 4: Return
    cout << "Inserted " << ITEM << " into the queue at position " << REAR << endl;
}

int main() {
    int QUEUE[N];
    int FRONT = -1, REAR = -1;

    QINSERT(QUEUE, FRONT, REAR, 10);
    QINSERT(QUEUE, FRONT, REAR, 20);
    QINSERT(QUEUE, FRONT, REAR, 30);
    QINSERT(QUEUE, FRONT, REAR, 40);
   // QINSERT(QUEUE, FRONT, REAR, 50);

  

    return 0;
}
