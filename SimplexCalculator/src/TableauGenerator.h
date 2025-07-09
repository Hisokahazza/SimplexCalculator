#pragma once

#include <unordered_map>

#include "Tableau.h"
#include "LexicalAnalyser.h"

class TableauGenerator
{
private:
	LexicalAnalyser m_LexicalAnalyser;
	std::vector<std::string> m_Constraints;
	std::string m_ObjectiveFunction;
	bool m_IsMaximising = true;

	std::unordered_map<std::string, std::string> m_MapVariables(std::vector<Token> tokenisedExpression);

public:
	TableauGenerator(const std::vector<std::string>& constraints, const std::string& objectiveFunction, bool isMaximising);
	Tableau generateTableau();
};