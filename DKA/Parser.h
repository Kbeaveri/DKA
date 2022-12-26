#include <vector>
#include <deque>
#include "Analizator.h"

using namespace std;
class Parser
{
public:
	string all_txt;
	Analizator A;
	pair <string, string> now;
	Parser(string all_txt) {
		this->all_txt = all_txt;
		A.Add(all_txt);
	}
	void start()
	{
		now = Next_Lic();
		if (now.first == "PROGRAM") {
			now = Next_Lic();
			if (now.second == "ID") {
				now = Next_Lic();
			}
			else {
				cout << "Oøèáêà";
			}
		}

		INTEGER();
		if (now.second == "ID") {
			now = Next_Lic();
			Operators();
		}
		FOR_OP();
	}
	void INTEGER() {
		if (now.first == "INTEGER") {
			now = Next_Lic();
			ID();
		}
	}
	void ID() {
		if (now.second == "ID") {
			now = Next_Lic();
			if (now.first == ",") {
				now = Next_Lic();
				ID();
			}
			else if (now.first == "\n") {
				now = Next_Lic();
				return;
			}
			else {
				Operators();
			}
		}
		else {
			error();
		}
	}
	void Operators() {
		if (now.first == "=") {
			now = Next_Lic();
			Expr();
		}
		else {
			error();
		}
	}
	void Expr() {
		SimpleExp();
		if (now.first == "+") {
			now = Next_Lic();
			Expr();
		}
		if (now.first == "-") {
			now = Next_Lic();
			Expr();
		}
		if (now.second == "ID" || now.second == "IntNum") {
			Expr();
		}
	}
	void SimpleExp() {
		if (now.second == "ID") {
			now = Next_Lic();
			Expr();
		}
		if (now.first == "(") {
			now = Next_Lic();
			Expr();
		}
		if (now.second == "IntNum") {
			now = Next_Lic();
			Expr();
		}
	}
	void FOR_OP() {
		if (now.first == "FOR") {
			now = Next_Lic();
			ID();
		}
		else {
			return;
		}
		if (now.first == "TO") {
			now = Next_Lic();
			Expr();
		}
		else {
			error();
		}
		if (now.first == "DO") {
			now = Next_Lic();
			Operators();
		}
		else {
			error();
		}
	}
	void error() {
		cout << "Îøèáêà";
	}

	void OOO_Kurva() {
		
	}


	pair <string, string> Next_Lic() 
	{
		if (A.is_empty()) {
			return A.Licsema();
		}
	}
};

