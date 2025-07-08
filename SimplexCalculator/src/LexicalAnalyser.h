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
	const std::string m_Input;
	size_t m_Position;

	bool isDigit(char c);
	std::string getNextNumber();
public:
	LexicalAnalyser();

	std::vector<Token> tokenize(std::string input);
	void outputTokens(std::string input);
};

