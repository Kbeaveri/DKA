#pragma once
#include <iostream>
#include <string>


using namespace std;

class tree_elem
{
public:
    pair<string,string> m_data;
    tree_elem* m_left;
    tree_elem* m_right;
    tree_elem(pair<string,string> val)
    {
        m_left = NULL; 
        m_right = NULL;
        m_data = val;
    }
};
class binary_tree
{
private:
    tree_elem* m_root;
    int m_size;

public:
    binary_tree(pair<string, string> key)
    {
        m_root = new tree_elem(key);
        m_size = 1;
    }

    ~binary_tree()
    {
        delete_tree(m_root);
    }

    void delete_tree(tree_elem* curr)
    {
        if (curr)
        {
            delete_tree(curr->m_left);
            delete_tree(curr->m_right);
            delete curr;
        }
    }

    void insert(pair<string, string> key, tree_elem* curr)
    {
        while (curr && curr->m_data != key)
        {
            if (curr->m_right == NULL)
            {
                curr->m_left = new tree_elem(key);
                ++m_size;
                return;
            }
            if (curr->m_left == NULL)
            {
                curr->m_left = new tree_elem(key);
                ++m_size;
                return;
            }
            curr = curr->m_left;
        }
    }

    void print()
    {
        print_tree(m_root);
        cout << endl;
    }

    void print_tree(tree_elem* curr)
    {
        if (curr) // Проверка на ненулевой указатель
        {
            print_tree(curr->m_left);
            cout << curr->m_data.first << " ";
            print_tree(curr->m_right);
        }
    }
  /*  bool Check(pair<string, string> key, tree_elem* curr) {
        bool flag;
        if ()
    }*/
};

