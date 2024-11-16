#include "Tableau.h"

void Tableau::outputTableau()
{
	for (size_t i = 0; i < m_Columns - 1; i++)
	{
		for (auto element : m_Tableau[i])
		{
			std::cout << element << std::endl;
		}
	}
}

void Tableau::multiplyRow(unsigned int row, int multiplier)
{
	for (size_t i = 0; i < m_Columns; i++)
	{
		m_Tableau[row - 1][i] *= multiplier;
	}
}

void Tableau::multiplyRow(unsigned int row, float multiplier)
{
	for (size_t i = 0; i < m_Columns; i++)
	{
		m_Tableau[row - 1][i] *= multiplier;
	}
}

void Tableau::addRow(unsigned int rowToAdd, unsigned int rowToAddTo)
{
	for (int i = 0; i < m_Columns; i++)
	{
		m_Tableau[rowToAddTo - 1][i] = m_Tableau[rowToAddTo - 1][i] + m_Tableau[rowToAdd][i];
	}
}

void Tableau::addRowMultiple(unsigned int rowToMultiply, unsigned int rowToAddMultiple, int multiplier)
{
	std::vector<int> rowMultiple;
	for (auto element : m_Tableau[rowToMultiply])
	{
		rowMultiple.emplace_back(element * multiplier);
	}

	for (int i = 0; i < m_Columns; i++)
	{
		m_Tableau[rowToAddMultiple - 1][i] = m_Tableau[rowToAddMultiple - 1][i] + rowMultiple[i];
	}
}

void Tableau::addRowMultiple(unsigned int rowToMultiply, unsigned int rowToAddMultiple, float multiplier)
{
	std::vector<float> rowMultiple;
	for (auto element : m_Tableau[rowToMultiply])
	{
		rowMultiple.emplace_back(element * multiplier);
	}

	for (int i = 0; i < m_Columns; i++)
	{
		m_Tableau[rowToAddMultiple - 1][i] = m_Tableau[rowToAddMultiple - 1][i] + rowMultiple[i];
	}
}


