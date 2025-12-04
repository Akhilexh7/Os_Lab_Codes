#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, capacity;
    cout << "Enter number of pages: ";
    cin >> n;
    vector<int> pages(n);
    cout << "Enter page reference sequence:\n";
    for (int i = 0; i < n; i++)
        cin >> pages[i];

    cout << "Enter number of frames: ";
    cin >> capacity;

    vector<int> frames;
    int pageFaults = 0;

    for (int i = 0; i < n; i++) {
        int current = pages[i];

        // If page is already in frame, continue
        if (find(frames.begin(), frames.end(), current) != frames.end())
            continue;

        // Page fault occurs
        pageFaults++;

        if (frames.size() < capacity) {
            // If frame has empty slot, just insert
            frames.push_back(current);
        } else {
            // Find the page to replace (Optimal)
            int idxToReplace = -1;
            int farthest = i;

            for (int j = 0; j < frames.size(); j++) {
                int k;
                for (k = i + 1; k < n; k++) {
                    if (frames[j] == pages[k])
                        break;
                }
                if (k > farthest) {
                    farthest = k;
                    idxToReplace = j;
                }
            }
            // Replace the page
            frames[idxToReplace] = current;
        }

        // Print current frame status
        cout << "Frames after inserting " << current << ": ";
        for (int f : frames)
            cout << f << " ";
        cout << endl;
    }

    cout << "\nTotal Page Faults: " << pageFaults << endl;

    return 0;
}
