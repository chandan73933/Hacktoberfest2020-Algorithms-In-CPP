#include<bits/stdc++.h>
using namespace std;

class Trie
{
public:
    struct node
    {
        node *child[26];
        int count;
        node()
        {
            for (int i = 0; i < 26; i++)
                child[i] = NULL;
            count = 0;
        }
    };

    node *head;
    Trie()
    {
        node *temp = new node();
        head = temp;
    }

    void insert(string str)
    {
        int len = str.length();
        node *temp = head;
        for (int i = 0; i < len; i++)
        {
            int p = str[i] - 'a';
            if (temp->child[p] == NULL)
            {
                node *n = new node();
                temp->child[p] = n;
            }
            temp = temp->child[p];
        }
        temp->count++;
    }

    int count(node *hd)
    {
        int ans = 0;
        if (hd->count != 0)
            ans++; // to count distinct strings
        //ans += hd->count;       // uncomment this line to count total strings (and comment just above line)
        for (int i = 0; i < 26; i++)
        {
            if (hd->child[i] != NULL)
            {
                ans += count(hd->child[i]);
            }
        }
        return ans;
    }
};

int main(){
    Trie trie;
    trie.insert("arpit");
    trie.insert("arpitgupta");
    trie.insert("arpit");
    trie.insert("arpitgupta");
    trie.insert("arpitcodingtrie");
    trie.insert("arpitgpta");
    trie.insert("arpitgpta");
    trie.insert("arpitgupta");
    trie.insert("arpitgpta");
    trie.insert("arpitcodingtrie");
    trie.insert("arpitgpta");
    trie.insert("arpitcodingtrie");
    trie.count(trie.head);
}