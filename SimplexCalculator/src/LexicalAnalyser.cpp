#include "LexicalAnalyser.h"

LexicalAnalyser::LexicalAnalyser() : m_Position(0)
{
}

bool LexicalAnalyser::isDigit(char c)
{
	if (int(c) > 47 && int(c) < 58)
	{
		return true;
	}
	else
	{
		return false;
	}
}

std::string LexicalAnalyser::getNextNumber(std::string input)
{
	int start = m_Position;
	bool hasDecimal = false;

	while (m_Position < input.length() && (isDigit(input[m_Position]) || input[m_Position] == '.'))
	{
		if (input[m_Position] == '.')
		{
			if (hasDecimal)
			{
				break;
			}
			hasDecimal = true;
		}
			
		m_Position++;
	}

	m_Position--;
	return input.substr(start, m_Position - start + 1);;
}

void LexicalAnalyser::m_Reset()
{
	m_Position = 0;
}

std::vector<Token> LexicalAnalyser::tokenise(std::string input)
{
	std::vector<Token> tokens;

	while (m_Position < input.length())
	{
		char currentChar = input[m_Position];

		if (currentChar == ' ' || currentChar == '=')
		{
			m_Position++;
			continue;
		}

		if (std::isalpha(currentChar))
		{
			tokens.emplace_back(TokenType::VARIABLE, std::string(1, currentChar));
		}
		else if (isDigit(currentChar))
		{
			std::string number = getNextNumber(input);
			if (number.find('.') != std::string::npos)
			{
				tokens.emplace_back(TokenType::FLOAT_LITERAL, number);
			}
			else
			{
				tokens.emplace_back(TokenType::INTEGER_LITERAL, number);
			}
		}
		else if (currentChar == '+' || currentChar == '-')
		{
			tokens.emplace_back(TokenType::OPERATOR, std::string(1, currentChar));
		}
		else if (currentChar == '<' || currentChar == '>')
		{
			tokens.emplace_back(TokenType::INEQUALITY, std::string(1, currentChar));
		}
		else
		{
			std::cerr << "Unrecognised character " << currentChar << " at position " << m_Position << std::endl;
			break;
		}

		m_Position++;
	}

	m_Reset();
	return tokens;
}

void LexicalAnalyser::outputTokens(std::string input)
{
	std::vector<Token> tokens = tokenise(input);

	for (auto token : tokens)
	{
		switch (token.type)
		{
		case TokenType::INTEGER_LITERAL:
			std::cout << "INTEGER " << token.value << std::endl;
			break;
		case TokenType::FLOAT_LITERAL:
			std::cout << "FLOAT " << token.value << std::endl;
			break;
		case TokenType::VARIABLE:
			std::cout << "VARIABLE " << token.value << std::endl;
			break;
		case TokenType::OPERATOR:
			std::cout << "OPERATOR " << token.value << std::endl;
			break;
		case TokenType::INEQUALITY:
			std::cout << "INEQUALITY " << token.value << std::endl;
			break;
		}
	}
}


