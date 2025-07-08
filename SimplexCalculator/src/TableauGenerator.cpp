#include "TableauGenerator.h"

TableauGenerator::TableauGenerator(const std::vector<std::string>& constraints, const std::string& profitFunction, bool isMaximising) : m_Constraints(constraints), m_ProfitFunction(profitFunction), m_IsMaximising(isMaximising)
{
}

Tableau TableauGenerator::generateTableau()
{
	return Tableau();
}
