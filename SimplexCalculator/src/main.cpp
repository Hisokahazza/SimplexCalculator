#include "TableauGenerator.h"

int main()
{
	std::vector<std::vector<float>> vecTest = {{ 1, 1, 1 }, { 2, 1, 3}};

	Tableau tableau(vecTest);

	std::vector<std::string> constraints = { "3x + 5y + 6z <= 20", "4z + 3y + 5x + 6x >= 10" };
	std::string objectiveFunction = "5x + 3y + 4z = 50";

	LexicalAnalyser lexicalAnalyser;

	TableauGenerator tableauGenerator(constraints, objectiveFunction, true);
	tableauGenerator.generateTableau();
}