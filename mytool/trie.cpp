#include <bits/stdc++.h>
using namespace std;

struct Trie {
    struct Node {
        using MP = map<char,int>;
        MP to;
        int num;  // # of words that go through this node
        int words; // # of words that end at this node
        Node(MP to=MP(), int num=0, int words=0): to(to),num(num),words(words) {}
    };
    int n;  // # of nodes
    vector<Node> node;
    Trie(): n(1),node(1) {}  // only root node
    void add(string &s) {
        int v = 0;
        node[0].num++;
        for(auto c: s) {
            if(!node[v].to.count(c)) {
                node.push_back(Node());
                node[v].to[c] = n;
                ++n;
            }
            v = node[v].to[c];
            node[v].num++;
        }
        node[v].words++;
    }
    int search_num(string &s) { // # of s added to the trie
        int v = 0;
        for(auto c: s) {
            if(!node[v].to.count(c)) return 0;
            v = node[v].to[c];
        }
        return node[v].words;
    }
    int search_prefix_num(string &s) { // # of words that have s as prefix
        int v = 0;
        int ret = node[v].num;
        for(auto c: s) {
            if(!node[v].to.count(c)) return 0;
            v = node[v].to[c];
            ret = node[v].num;
        }
        return ret;
    }
    int get_lcp(string &s) { // Use this function after s is added.
        int v = 0;
        int ret = 0;
        for(auto c: s) {
            if(!node[v].to.count(c)) return 0;
            int nv = node[v].to[c];
            if(node[nv].num<=1) break;
            ++ret;
            v = nv;
        }
        return ret;
    }
};

//! Binary Trie (template only)
template<class T=long long, int k=62> class BinaryTrie {
    struct Node {
        int to[2];
        int cnt, p;
        Node(int p=-1): cnt(0), p(p) { to[0] = to[1] = -1; }
    };
    vector<Node> nodes;
public:
    BinaryTrie(): nodes(1,Node()) {}
    void add(T x, int c) {
        int v = 0;
        nodes[v].cnt += c;
        for(int i=k; i>=0; --i) {
            int b = x>>i&1;
            if(nodes[v].to[b]==-1) {
                nodes[v].to[b] = nodes.size();
                nodes.push_back(Node(v));
            }
            v = nodes[v].to[b];
            nodes[v].cnt += c;
        }
    }
};
