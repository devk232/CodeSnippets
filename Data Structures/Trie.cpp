#include <iostream>
using namespace std;
/*
     0 
    / \
   0  1
*/

struct trie {
    struct Node {
        
        Node* nxt[2];
        int cnt;
        Node () {
            nxt[0] = nxt[1] = NULL;
            cnt = 0;
        } 
    };
    Node* head;
    trie () {
        head = new Node();
    }
    void insert (int x) {
        Node* cur = head;
        for (int i = 30; i >= 0; i--) {
            int b = 1 & (x >> i);
            if (!cur->nxt[b]) {
                cur->nxt[b] = new Node();
            } 
            cur = cur->nxt[b];
            cur->cnt++;
        }
    }
    void remove (int x) {
        Node* cur = head;
        for (int i = 30; i >= 0; i--) {
            int b = 1 & (x >> i);
            cur = cur->nxt[b];
            cur->cnt--;
        }
    }
    void max_xor_query (int x) {
        int ans = 0;
        Node* cur = head;
        for (int i = 30; i >= 0; i--) {
            int bit = 1 & (x >> i);
            if (cur->nxt[!bit] != NULL && cur->nxt[!bit]->cnt > 0) {
                ans += (1 << i);
                cur = cur->nxt[!bit];
            }
            else cur = cur->nxt[bit];
        }
    }
};