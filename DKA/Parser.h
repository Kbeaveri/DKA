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
			ID();
		}
	}
	void ID() {
		if (now.second == "ID") {
			now = Next_Lic();
			if (now.first == "|n") {
				now = Next_Lic();

			}
		}
	}
	void WHO_NEXT() {
		if (now.first == "INTEGER") {
			now = Next_Lic();
			ID();
		}
		if (now.first == "ID") {
			now = Next_Lic();
			next_beforID();
		}
	}
	void ID2() {
		if (now.second == "ID") {

		}
	}
	void next_beforID() {
		if (now.first == "=") {
			now = Next_Lic();

		}
	}
	void Next_INTEGER() {
		if (now.first == "ID") {
			now = Next_Lic();
			if (now.first == "|n") {
				now = Next_Lic();
				WHO_NEXT();
			}
		}
	}
	void Exp() {
		while (now.first == "Intnum" || now.first == "ID" || now.first == "(" || now.first == ")" || now.first == "+" || now.first == "-") {
			now = Next_Lic();
		}
		if (now.first != "|n") {

		}
	}
	void Exp_to() {
		while (now.first == "Intnum" || now.first == "ID" || now.first == "(" || now.first == ")" || now.first == "+" || now.first == "-") {
			now = Next_Lic();
		}
		if (now.first != "To") {

		}
	}
	void Exp_do() {
		while (now.first == "Intnum" || now.first == "ID" || now.first == "(" || now.first == ")" || now.first == "+" || now.first == "-") {
			now = Next_Lic();
		}
		if (now.first != "DO") {

		}
	}

	pair <string, string> Next_Lic() 
	{
		if (A.is_empty()) {
			return A.Licsema();
		}
	}
};

