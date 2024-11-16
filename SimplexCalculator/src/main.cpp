#include "Tableau.h"

int main()
{
	std::vector<std::vector<float>> vecTest = {{ 1, 1, 1 }, { 1, 1, 1 }};

	Tableau tableau(2, 3, vecTest);

	tableau.addRow(1, 2);
	tableau.outputTableau();
}