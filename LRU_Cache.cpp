#include <unordered_map>
using namespace std;

class LRUCache {
public:
    class Node {
    public:
        int key;
        int val;
        Node *prev;
        Node *next;
        Node(int _key, int _val) : key(_key), val(_val), prev(nullptr), next(nullptr) {}
    };

private:
    int cap;
    unordered_map<int, Node*> m;
    Node *head, *tail;

    void addNode(Node* newNode) {
        newNode->next = head->next;
        newNode->prev = head;
        head->next->prev = newNode;
        head->next = newNode;
    }

    void deleteNode(Node* delNode) {
        Node* prevNode = delNode->prev;
        Node* nextNode = delNode->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

public:
    LRUCache(int capacity) : cap(capacity) {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key_) {
        if (m.find(key_) != m.end()) {
            Node* node = m[key_];
            deleteNode(node);
            addNode(node);
            return node->val;
        }
        return -1;
    }

    void put(int key_, int value) {
        if (m.find(key_) != m.end()) {
            Node* existingNode = m[key_];
            deleteNode(existingNode);
            delete existingNode;  // Clean up memory
            m.erase(key_);
        }

        if (m.size() == cap) {
            Node* lruNode = tail->prev;
            m.erase(lruNode->key);
            deleteNode(lruNode);
            delete lruNode;  // Clean up memory
        }

        Node* newNode = new Node(key_, value);
        addNode(newNode);
        m[key_] = newNode;
    }

    ~LRUCache() {
        // Clean up all nodes
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
};
