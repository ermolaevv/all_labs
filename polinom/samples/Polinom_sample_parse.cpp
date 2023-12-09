#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <regex>
#include "Polinom.h"

std::vector<std::string> find_str(std::string s, std::string del) {
	std::vector<std::string> res;
	int end = s.find(del);
	while (end != -1) {
		res.push_back(s.substr(0, end));
		s.erase(s.begin(), s.begin() + end + del.size());
		end = s.find(del);
	}
	res.push_back(s.substr(0, end));

	return res;
}

void parsePol(TPolinom& pol1, TPolinom& pol2) {
	std::vector<std::string> s_inp;

	s_inp.push_back("5*x0^7*x1^3*x2^4 + 3*x0^5*x1*x2 + 1*x0*x1");
	//s_inp.push_back("9*x0^7*x1^3*x2^4 + 3*x0^3*x1^5");
	s_inp.push_back("-5*x0^7*x1^3*x2^4 - 3*x0^5*x1*x2 - 1*x0*x1");

	for (auto it = s_inp.begin(); it < s_inp.end(); it++) {
		std::set<std::string> params;
		std::vector<std::pair<double, std::map<std::string, int>>> monoms;
		std::string str = std::regex_replace(*it, std::regex("\\ *"), "");
		str = std::regex_replace(str, std::regex("\\-"), "+-");
		auto v_monoms = find_str(str, "+");


		for (auto monom : v_monoms) {
            if (monom != "") {
			    auto comp = find_str(monom, "*");
			    std::pair<double, std::map<std::string, int>> p_monom;

			    p_monom.first = std::stod(comp.at(0));
			    for (auto it = ++comp.begin(); it < comp.end(); it++) {
				    std::string str = *it;
				    int deg;
				    auto tmp = find_str(str, "^");
				    if (tmp.size() == 1)
					    deg = 1;
				    else
					    deg = std::stoi(tmp.at(1));
				    params.insert(tmp.at(0));
				    p_monom.second[tmp.at(0)] = deg;
			    }

			    monoms.push_back(p_monom);
            }
		}

		TPolinom tmp(params.size());
		for (auto pr : monoms) {
			for (auto param : params) {
				if (pr.second.find(param) == pr.second.end()) {
					pr.second[param] = 0;
				}
			}
			std::vector<int> deg;
			for (auto it = pr.second.begin(); it != pr.second.end(); ++it) {
				deg.push_back(it->second);
			}
			tmp.AddMonom(TMonom(pr.first, params.size(), &deg[0]));
		}

		if (it == s_inp.begin())
			pol1 = tmp;
		else
			pol2 = tmp;
	}
}

int main() {
	TPolinom pol1, pol2;

	parsePol(pol1, pol2);
	std::cout << pol1 << std::endl << pol2 << std::endl;
	std::cout << (pol1 + pol2).ToString();
}
