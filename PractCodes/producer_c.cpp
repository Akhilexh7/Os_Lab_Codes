#include <bits/stdc++.h>
using namespace std;

// Global variables
int n;                 // number of items (or buffer size)
int buffer[20];
int in = 0, out = 0;
int item, item1;

// Semaphores
int mutex_ = 1;  // mutual exclusion (binary semaphore)
int empty_;      // counts empty slots
int full_;       // counts filled slots

// wait() operation
void wait(int &s) {
    while (s <= 0) {
        // In real OS, process would block. Here we just simulate.
        cout << "Process waiting..." << endl;
        return;
    }
    s--;
}

// signal() operation
void signal(int &s) {
    s++;
}

// Producer function
void producer() {
    do {
        wait(empty_);
        wait(mutex_);

        cout << "Enter item to produce: ";
        cin >> item;
        buffer[in] = item;
        in = in + 1;

        signal(mutex_);
        signal(full_);
    } while (in < n);
}

// Consumer function
void consumer() {
    do {
        wait(full_);
        wait(mutex_);

        item1 = buffer[out];
        cout << "Consumed: " << item1 << endl;
        out = out + 1;

        signal(mutex_);
        signal(empty_);
    } while (out < n);
}

// Main function
int main() {
    cout << "Enter the value of n (<=20): ";
    cin >> n;

    empty_ = n;   // initially all slots empty
    full_ = 0;    // initially no items

    // Simulate producer first, then consumer
    producer();
    consumer();

    return 0;
}
