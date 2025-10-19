#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};


class Solution {
private:
    struct Comp {
        int target;
        Comp(int target_val) : target(target_val) {}
        bool operator()(const int a, const int b) const {
            long long A = std::abs((long long)a - target);
            long long B= std::abs((long long)b - target);

            if (A < B) return true;
            if (A > B) return false;
            return a < b;
        }
    };
    
    // Alias for the complex priority_queue type
    using MaxHeap = std::priority_queue<int, std::vector<int>, Comp>;

    void inorder(Node* root, int target, int k, MaxHeap &pq) { 
        if (!root) return;
        inorder(root->left, target, k, pq);
        
        int data = root->data;
        if (pq.size() < k) {
            pq.push(data);
        } else {
            long long diffTop = std::abs((long long)pq.top() - target);
            long long diffNew = std::abs((long long)data - target);
            if (diffNew < diffTop || (diffNew == diffTop && data < pq.top())) {
                pq.pop();
                pq.push(data);
            }
        }
        
        inorder(root->right, target, k, pq);
    }
    
public:
    std::vector<int> getKClosest(Node* root, int target, int k) {
        MaxHeap pq{Comp(target)};
        inorder(root, target, k, pq);

        std::vector<int> ans;
        while (!pq.empty()){
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};

int main(){

return 0;
}