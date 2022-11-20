//#pragma once
//#include "BTree.h"
//#include <vector>
//#include <deque>
//using namespace std;
//class Parser
//{
//	void Convert(vector<pair<string, string>> Tokens) {
//		deque <string>Oper;
//		deque <pair<string,string>> Exp;
//		for (int i = 0; i < Tokens.size(); i++) {
//			if (Tokens[i].second == "OPERATOR") {
//				Oper.push_back(Tokens[i].first);
//			}
//			if (Tokens[i].second == "IntNum" || Tokens[i].second == "ID") {
//				Exp.push_back(Tokens[i]);
//			}
//		}
//		binary_tree* Tree = 0;
//		while (!Exp.empty()) {
//			if (!Oper.empty()) {
//				Tree->insert(Oper.front(), "OPERATOR", Tree);
//				Tree->insert(Exp.front().first, Exp.front().second, Tree);
//				Oper.pop_front();
//				Exp.pop_front();
//			}
//			else {
//				while (!Exp.empty()) {
//				Tree->Add(Exp.front().first, Exp.front().second, Tree);
//				}
//			}
//		}
//	}
//};
//
