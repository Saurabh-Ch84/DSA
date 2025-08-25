#include <iostream>
#include <vector>
using namespace std;

// Max-Heap class (0-based indexing)
class Heap {
    vector<int> heap;
    int sz;
    int maxSize;
public:
    Heap(int size = 100) {
        maxSize = size;
        heap.clear();
        sz = 0;
    }
    void insert(int val) {
        if (sz == maxSize) return;
        heap.push_back(val);
        int idx = sz++;
        // Bubble up
        while (idx > 0 && heap[(idx - 1) / 2] < heap[idx]) {
            swap(heap[(idx - 1) / 2], heap[idx]);
            idx = (idx - 1) / 2;
        }
    }

    void pop() {
        if (sz == 0) return;
        heap[0] = heap[--sz];
        heap.pop_back();
        int idx = 0;
        while (true) {
            int largest = idx;
            int left = 2 * idx + 1,right = 2 * idx + 2;
            if (left < sz && heap[left] > heap[largest]) largest = left;
            if (right < sz && heap[right] > heap[largest]) largest = right;
            if (largest != idx) {
                swap(heap[idx], heap[largest]);
                idx = largest;
            } else {
                break;
            }
        }
    }

    friend void print(const Heap& obj);
};

void print(const Heap& obj) {
    for (int i = 0; i < obj.sz; i++) {
        cout << obj.heap[i] << " ";
    }
    cout << endl;
}

void print(vector<int> &nums) {
    for (int i = 0; i < nums.size(); i++)
        cout << nums[i] << " ";
    cout << endl;
}

// Standalone heapify and buildHeap functions
void heapify(vector<int> &nums, int idx, int n) {
    int largest = idx;
    int left = 2 * idx + 1, right = 2 * idx + 2;
    if (left < n && nums[left] > nums[largest])
        largest = left;
    if (right < n && nums[right] > nums[largest])
        largest = right;
    if (largest != idx) {
        swap(nums[idx], nums[largest]);
        heapify(nums, largest, n);
    }
}

void buildHeap(vector<int> &nums) {
    int n = nums.size();
    for (int i = n / 2 - 1; i >= 0; --i)
        heapify(nums, i, n);
}


void heapSort(vector<int> &nums){
    int n=nums.size();
    buildHeap(nums);

    for(int i = n-1; i > 0; i--) {
        swap(nums[0], nums[i]);
        heapify(nums,0,i);
    }
}

int main() {
    Heap maxHeap;
    maxHeap.insert(50);
    maxHeap.insert(55);
    maxHeap.insert(53);
    maxHeap.insert(52);
    maxHeap.insert(54);
    print(maxHeap);
    maxHeap.pop();
    print(maxHeap);
    //Array heap example
    vector<int> nums = {50, 55, 53, 52, 54};
    vector<int> nums2 = {5,15, -3, 2, 0};
    print(nums2);
    buildHeap(nums);
    print(nums);
    heapSort(nums2);
    print(nums2);
    return 0;
}
