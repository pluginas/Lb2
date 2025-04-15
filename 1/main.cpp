#include <iostream>
#include <algorithm>

using namespace std;

void forward_step(unsigned arr[], unsigned const begin_idx, unsigned const end_idx){
    for(int i=begin_idx; i<end_idx; i++){
        if(arr[i]>arr[i+1]){
            swap(arr[i], arr[i+1]);
        }
    }
}



void backward_step(unsigned arr[], unsigned const begin_idx , unsigned const end_idx){
    for(int i=end_idx; i>begin_idx; i--){
        if(arr[i]<arr[i-1]){
            swap(arr[i], arr[i-1]);
        }
    }
}



void shaker_sort(unsigned arr[], unsigned const begin_idx, unsigned const end_idx){
    int l = begin_idx;
    int r = end_idx;
    while(l<r){
        forward_step(arr, l, r);
        --r;
        backward_step(arr, l, r);
        ++l;
    } 
}



void test_forward_step() {
    unsigned arr[] = {1, 6, 5, 95, 11};
    unsigned size = sizeof(arr) / sizeof(arr[0]);
  
    forward_step(arr, 0, size - 1);
    
    for (unsigned i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

void test_backward_step() {
    unsigned arr[] = {1, 6, 5, 95, 11};
    unsigned size = sizeof(arr) / sizeof(arr[0]);
    
    backward_step(arr, 0, size - 1);
    
    for (unsigned i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}


void test_shaker_sort() {
    unsigned arr[] = {1, 6, 5, 95, 11};
    unsigned size = sizeof(arr) / sizeof(arr[0]);
    
    shaker_sort(arr, 0, size - 1);
    
    for (unsigned i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}



int main() {
    test_forward_step();
    test_backward_step();
    test_shaker_sort();
    return 0;
}
