#include <iostream>
#include <string>
#include <vector>
#include "HashTable.h"

using namespace std;

class Analizator {
public:
    HashTable<string> A;
    vector <string> KW = { "PROGRAM","END","INTEGER" };
    vector <string> SEP = { "\n","\t" };
    vector <string> Raz = { "=" , "+","FOR","TO","DO" };
    string all_txt;
    string buf;
    int num = 0;
    Analizator() {
        this->all_txt = "";
    }
    Analizator(string all_txt) {
        this->all_txt = all_txt;
    }
    void Add(string a) {
        this->all_txt = a;
    }
    string Go_next() {
        int i = num;
        string buf;
        while (all_txt[i] != '\n' && all_txt[i] != ' ') {
            buf += all_txt[i];
            i++;
        }
        num = i + 1;
        return buf;
    };
    int DKA() {
        int state = 1;
        buf = Go_next();
        bool isnum = false;
        pair <string, string> answer;
        if (isdigit(buf[0])) {
            state = 2;
        }
        else if (isalpha(buf[0])) {
            state = 3;
        }
        else {
            return 4;
        }
        switch (state)
        {
        case 2:
            for (int i = 0; i < buf.size(); i++) {
                if (!isdigit(buf[i])) {
                    return 4;
                }
            }
            return 2;
        case 3:
            for (int i = 0; i < buf.size(); i++) {
                if (!isalpha(buf[i])) {
                    return 4;
                }
            }
            return 3;
        }
    }
    pair <string, string> Licsema() {
        pair <string, string> answer;
        int a = DKA();
        if (a == 2) {
            answer.first = buf;
            answer.second = "IntNum";
            A.Add(answer.first, answer.second);
            return answer;
        }
        if (a == 3) {
            if (find(KW.begin(), KW.end(), buf) != KW.end()) {
                answer.first = buf;
                answer.second = "KEY WORLD";
                A.Add(answer.first, answer.second);
                return answer;
            }
            else {
                answer.first = buf;
                answer.second = "ID";
                A.Add(answer.first, answer.second);
                return answer;
            }
        }
        if (a == 4) {
            if (find(Raz.begin(), Raz.end(), buf) != Raz.end()) {
                answer.first = buf;
                answer.second = "OPERATOR";
                A.Add(answer.first, answer.second);
                return answer;
            }
            else {
                answer.first = buf;
                answer.second = "ERROR";
                A.Add(answer.first, answer.second);
                return answer;
            }
        }

    }
    bool is_empty() {
        if (num < all_txt.size()) {
            return true;
        }
        else {
            return false;
        }
    }
};