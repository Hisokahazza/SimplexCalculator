#include "TableauGenerator.h"


std::unordered_map<std::string, std::string> TableauGenerator::m_MapVariables(std::vector<Token> tokenisedExpression)
{
	std::unordered_map<std::string, std::string> variableMap;
	std::vector<std::string> variableNames;
	std::vector<std::string> variableValues;

	for (int i = 0; i < tokenisedExpression.size(); i++)
	{
		if (tokenisedExpression[i].type == TokenType::FLOAT_LITERAL || tokenisedExpression[i].type == TokenType::INTEGER_LITERAL)
		{
			variableValues.emplace_back(tokenisedExpression[i].value);
		}
		else if (tokenisedExpression[i].type == TokenType::VARIABLE)
		{
			variableNames.emplace_back(tokenisedExpression[i].value);
		}
	}

	for (int i = 0; i < variableNames.size(); i++)
	{
		variableMap.emplace(variableNames[i], variableValues[i]);
	}

	return variableMap;
}

TableauGenerator::TableauGenerator(const std::vector<std::string>& constraints, const std::string& objectiveFunction, bool isMaximising) : m_Constraints(constraints), m_ObjectiveFunction(objectiveFunction), m_IsMaximising(isMaximising)
{
}

Tableau TableauGenerator::generateTableau()
{
	std::vector<std::vector<Token>> tokenisedConstraints;
	std::vector<Token> tokenisedObjectiveFunction;
	std::unordered_map<std::string, std::string> variablesMap;

	// Tokenise constraints
	for (auto& constraint : m_Constraints)
	{
		tokenisedConstraints.emplace_back(m_LexicalAnalyser.tokenise(constraint));
	}

	// Tokenise profit function
	tokenisedObjectiveFunction = m_LexicalAnalyser.tokenise(m_ObjectiveFunction);

	variablesMap = m_MapVariables(tokenisedObjectiveFunction);

	std::cout << variablesMap["x"] << std::endl;

	return Tableau();
}
