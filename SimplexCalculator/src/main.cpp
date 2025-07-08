#include "Tableau.h"
#include "LexicalAnalyser.h"

int main()
{
	bool isUniform = false;

	std::vector<std::vector<float>> vecTest = {{ 1, 1, 1 }, { 2, 1, 3}};

	Tableau tableau(vecTest);

	tableau.addRowMultiple(0, 1, 2);
	tableau.outputTableau();

	/*LexicalAnalyser lexicalAnalyser("2.3x + 3.8 - 9.9 >= 19999.9");

	lexicalAnalyser.outputTokens();*/
}