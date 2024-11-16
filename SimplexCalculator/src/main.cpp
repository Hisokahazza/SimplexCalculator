#include "Tableau.h"
#include "LexicalAnalyser.h"

int main()
{
	/*std::vector<std::vector<float>> vecTest = {{ 1, 1, 1 }, { 1, 1, 1 }};

	Tableau tableau(2, 3, vecTest);

	tableau.addRow(1, 2);
	tableau.outputTableau();*/

	LexicalAnalyser lexicalAnalyser("2.3x + 3.8 - 9.9 >= 19999.9");

	lexicalAnalyser.outputTokens();
}