#pragma once

#include <vector>
#include <iostream>

#include "Vec.h"

class Tableau
{
private:
	std::vector<std::vector<float>> m_Tableau;
	const size_t m_Rows;
	const size_t m_Columns;
public:
	Tableau(size_t rows = 0, size_t columns = 0, const std::vector<std::vector<float>>& tableau = {}) : m_Rows(rows), m_Columns(columns), m_Tableau(tableau)
	{
	}

	void outputTableau();

	void multiplyRow(unsigned int row, int multiplier);
	void multiplyRow(unsigned int row, float multiplier);

	void addRow(unsigned int rowToAdd, unsigned int rowToAddTo);

	void addRowMultiple(unsigned int rowToMultiply, unsigned int rowToAddMultiple, int multiplier);
	void addRowMultiple(unsigned int rowToMultiply, unsigned int rowToAddMultiple, float multiplier);
};


