#include <bits/stdc++.h>
using namespace std;

class BST
{
public:
    BST()
    {
        root = NULL;
    }

    struct node
    {
        int data;
        node *l;
        node *r;
        node(int a)
        {
            data = a;
            l = r = NULL;
        }
    };

    node *root;

    void insert(int a)
    {
        node *temp = new node(a);
        node *prev = root;
        if (root == NULL)
            root = temp;
        else
        {
            while (1)
            {
                if (prev->data > a)
                {
                    if (prev->l == NULL)
                    {
                        prev->l = temp;
                        break;
                    }
                    else
                        prev = prev->l;
                }
                else
                {
                    if (prev->r == NULL)
                    {
                        prev->r = temp;
                        break;
                    }
                    else
                        prev = prev->r;
                }
            }
        }
    }

    void del(int a)
    {
        node *temp = root;
        node **prev = &root;
        while (temp->data != a)
        {
            if (temp->data < a)
                prev = &(temp->r), temp = temp->r;
            else
                prev = &(temp->l), temp = temp->l;
        }
        node *rep = NULL;

        if (temp->r == NULL)
        {
            if (temp->l == NULL)
                *prev = NULL;
            else
            {
                rep = temp->l;
                while (rep->r != NULL)
                    rep = rep->r;
                int rd = rep->data;
                del(rep->data);
                (*prev)->data = rd;
            }
        }
        else
        {
            rep = temp->r;
            while (rep->l != NULL)
                rep = rep->l;
            int rd = rep->data;
            del(rep->data);
            (*prev)->data = rd;
        }
    }

    void inorder(node *root)
    {
        if (root == NULL)
            return;
        inorder(root->l);
        cout << root->data << " ";
            inorder(root->r);
    }
};


int main(){
    BST bst;
    bst.insert(29);
    bst.insert(30);
    bst.insert(1);
    bst.insert(-15);
    bst.insert(99);
    bst.insert(1025);
    bst.inorder(bst.root);
    bst.del(1);
}