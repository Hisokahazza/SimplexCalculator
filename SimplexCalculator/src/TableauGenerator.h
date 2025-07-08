#pragma once

#include "Tableau.h"
#include "LexicalAnalyser.h"

class TableauGenerator
{
private:
	LexicalAnalyser m_LexicalAnalyser;
	std::vector<std::string> m_Constraints;
	std::string m_ProfitFunction;
	bool m_IsMaximising = true;

public:
	TableauGenerator(const std::vector<std::string>& constraints, const std::string& profitFunction, bool isMaximising);
	Tableau generateTableau();
};