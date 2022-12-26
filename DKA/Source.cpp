#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include "Parser.h"

using namespace std;

int main() {
    //ifstream fin("input.txt");
    //ofstream fout("output.txt");
    //string all_txt;
    //string buffer;
    //while (!fin.eof()) {
    //    getline(fin, buffer);
    //    all_txt += buffer +" |n ";
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
    Parser A("PROGRAM a INTEGER c \n b = 36 FOR i = 1 TO 3 + 7 DO i + 1");
    A.start();
}