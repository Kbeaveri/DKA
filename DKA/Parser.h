#pragma once
#include <vector>
#include <deque>
#include "Analizator.h"

using namespace std;
class Parser
{
public:
	string all_txt;
	Analizator A();
	Parser(string all_txt) {
		this->all_txt = all_txt;
		//A.Add(all_txt);
	}
	void start() {

	}
	pair <string, string> Next_Lic() {
	}
};

