#pragma once

#include <iostream>
#include <string>
#include <vector>

enum class TokenType
{
	INTEGER_LITERAL,
	FLOAT_LITERAL,
	VARIABLE,
	OPERATOR,
	INEQUALITY
};

struct Token
{
	TokenType type;
	std::string value;

	Token(TokenType t, const std::string& v) : type(t), value(v)
	{
	}
};

class LexicalAnalyser
{
private:
	size_t m_Position;

	bool isDigit(char c);
	std::string getNextNumber(std::string input);
	void m_Reset();
public:
	LexicalAnalyser();

	std::vector<Token> tokenise(std::string input);
	void outputTokens(std::string input);
};

