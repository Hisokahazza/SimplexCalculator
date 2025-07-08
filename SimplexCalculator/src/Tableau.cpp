#include "Tableau.h"

bool Tableau::m_IsUniform()
{
	for (auto& row : m_Tableau)
	{
		if (row.size() != m_Columns)
		{
			return false;
		}
	}
	return true;
}

Tableau::Tableau(const std::vector<std::vector<float>>& tableau) : m_Tableau(tableau)
{
	if (m_Tableau.empty())
	{
		m_Rows = 0;
		m_Columns = 0;
	}
	else
	{
		m_Rows = m_Tableau.size();
		m_Columns = m_Tableau[0].size();
	}

	if (!m_IsUniform())
	{
		throw std::invalid_argument("Vector is non-uniform");
	}
}

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


