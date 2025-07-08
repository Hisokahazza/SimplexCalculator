#pragma once

#include <vector>
#include <iostream>

#include "Vec.h"

class Tableau
{
private:
	std::vector<std::vector<float>> m_Tableau;
	size_t m_Rows;
	size_t m_Columns;
	bool m_IsUniform();
public:
	Tableau(const std::vector<std::vector<float>>& tableau = {});

	void outputTableau();

	void multiplyRow(unsigned int row, int multiplier);
	void multiplyRow(unsigned int row, float multiplier);

	void addRow(unsigned int rowToAdd, unsigned int rowToAddTo);

	void addRowMultiple(unsigned int rowToMultiply, unsigned int rowToAddMultiple, int multiplier);
	void addRowMultiple(unsigned int rowToMultiply, unsigned int rowToAddMultiple, float multiplier);
};


