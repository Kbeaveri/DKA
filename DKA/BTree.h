#pragma once
#include <iostream>
#include <string>


using namespace std;

class tree_elem
{
public:
    string m_data;
    tree_elem* m_left;
    tree_elem* m_right;
    tree_elem(string val)
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
    binary_tree(string key)
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

    void insert(string key)
    {
        tree_elem* curr = m_root;
        while (curr && curr->m_data != key)
        {
            if (curr->m_left == NULL)
            {
                curr->m_left = new tree_elem(key);
                ++m_size;
                return;
            }
            if (curr->m_right == NULL)
            {
                curr->m_right = new tree_elem(key);
                ++m_size;
                return;
            }
            if (curr->m_data > key)
                curr = curr->m_left;
            else
                curr = curr->m_right;
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
            cout << curr->m_data << " ";
            print_tree(curr->m_right);
        }
    }
};

