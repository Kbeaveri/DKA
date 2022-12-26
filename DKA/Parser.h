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
		if (now.second == "PROGRAM") {
			now = Next_Lic();
			if (now.second == "ID") {
				now = Next_Lic();
			}
			else {
				cout << "Oøèáêà";
			}
		}
	}
	void INTEGER() {
		if (now.second == "INTEGER") {
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
			else {
				now = Next_Lic();
				Operators();
			}
		}
		else {
			error();
		}
	}
	void Operators() {
		if (now = "ID") {
			now = Next_Lic();
			if (now.first == "=") {
				Expr();
			}
			else {
				error();
			}
		}
	}
	void Expr() {

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

