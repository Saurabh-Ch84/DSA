#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

class LRUCache1
{
    class Node
    {
    public:
        int val, key;
        Node *next, *prev;
        Node(int val = -1, int key = -1)
        {
            this->val = val;
            this->key = key;
            next = nullptr;
            prev = nullptr;
        }
    };

    int capacity;
    Node *tail, *head;
    unordered_map<int, Node *> cache;

    void insertNode(Node *node)
    {
        Node *temp = head->next;
        node->next = head->next;
        node->prev = head;
        head->next = node;
        temp->prev = node;
    }

    void moveNode(Node *node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->next = nullptr;
        node->prev = nullptr;
        insertNode(node);
    }

    void deleteNode()
    {
        Node *LRUnode = tail->prev;
        int key = LRUnode->key;
        LRUnode->next->prev = LRUnode->prev;
        LRUnode->prev->next = LRUnode->next;
        LRUnode->next = nullptr;
        LRUnode->prev = nullptr;
        cache.erase(key);
        delete LRUnode;
    }

public:
    LRUCache1(int capacity)
    {
        this->capacity = capacity;
        tail = new Node();
        head = new Node();
        tail->prev = head;
        head->next = tail;
    }

    int get(int key)
    {
        if (cache.find(key) != cache.end())
        {
            Node *node = cache[key];
            int value = node->val;
            moveNode(node);
            return value;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (cache.find(key) != cache.end())
        {
            Node *node = cache[key];
            node->val = value;
            moveNode(node);
            return;
        }
        else if (cache.find(key) == cache.end() && cache.size() == capacity)
            deleteNode();
        Node *node = new Node(value, key);
        insertNode(node);
        cache[key] = node;
    }

    ~LRUCache1()
    {
        Node *curr = head;
        while (curr != nullptr)
        {
            Node *nxt = curr->next;
            delete curr;
            curr = nxt;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

class LRUCache2
{
    int capacity;
    list<int> listOfLRU;
    unordered_map<int, pair<int, list<int>::iterator>> Cache;

public:
    LRUCache2(int capacity)
    {
        this->capacity = capacity;
    }
    int get(int key)
    {
        if (Cache.find(key) != Cache.end())
        {
            listOfLRU.erase(Cache[key].second);
            listOfLRU.push_front(key);
            int value = Cache[key].first;
            Cache[key].second = listOfLRU.begin();
            return value;
        }
        return -1;
    }
    void put(int key, int value)
    {
        if (Cache.find(key) != Cache.end())
            listOfLRU.erase(Cache[key].second);

        else if (Cache.size() == capacity && Cache.find(key) == Cache.end())
        {
            int LRUkey = listOfLRU.back();
            listOfLRU.pop_back();
            Cache.erase(LRUkey);
        }
        listOfLRU.push_front(key);
        Cache[key] = {value, listOfLRU.begin()};
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main()
{

    return 0;
}