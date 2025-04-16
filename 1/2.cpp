#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <iomanip>
#include <chrono>
#include <vector>
#include <fstream>
using namespace std;

bool is_sorted_with_gap(const vector<unsigned>& arr, unsigned gap) {
    for (unsigned i = 0; i + gap < arr.size(); ++i) {
        if (arr[i] > arr[i + gap]) {
            return false; 
        }
    }
    return true; 
}

void comb_sort(vector<unsigned>& arr) {
    unsigned n = arr.size();
    double shrink_factor = 1.25;
    unsigned gap = n;
    bool swapped = true;

    while (gap > 1 || swapped) {
        gap = 1; 
        if ((unsigned)(gap / shrink_factor) > 1)
        {
            gap = (unsigned)(gap / shrink_factor);
        }   
        swapped = false;
        for (unsigned i = 0; i + gap < n; ++i) {
            if (arr[i] > arr[i + gap]) {
                swap(arr[i], arr[i + gap]);
                swapped = true;
            }
        }
    }
}



int main() {
    ofstream out;
    out.open("hello.txt");
    for (unsigned cnt = 100; cnt < 100000; cnt += 5000)
    {

        vector<unsigned>a;
        a.resize(cnt);
        for (int i = 0; i < cnt; i++)
        {
            a[i] = cnt-i-1;
        }
        auto begin = chrono::steady_clock::now();
        for (int i = 0; i < 2500; i++)
        {
            comb_sort(a);
        }
        auto end = chrono::steady_clock::now();
        auto time_span = chrono::duration_cast<chrono::milliseconds>(end - begin);
        cout << time_span.count() << " " << cnt << endl;
        out << time_span.count() << " " << cnt << endl;

    }
    out.close();
    std::cout << "File has been written" << std::endl;

    return 0;
}
