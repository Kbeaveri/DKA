#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include "HashTable.h"
#include "Analizator.h"
#include "BTree.h"

using namespace std;

int main() {
    //ifstream fin("input.txt");
    //ofstream fout("output.txt");
    //string all_txt;
    //string buffer;
    //while (!fin.eof()) {
    //    getline(fin, buffer);
    //    all_txt += buffer +"\n";
    //}
    //Analizator A(all_txt);
    //HashTable<string> B;
    //while (A.is_empty()) {
    //    pair <string, string> f;
    //    f = A.Licsema();
    //    //cout << f.first << " " << f.second<<endl;
    //    B.Add(f.first, f.second);
    //}
    //B.fout();
    binary_tree a("1");
    a.insert("2");
    a.insert("3");
    a.insert("4");
    a.insert("5");
    a.insert("6");
    a.print();
}