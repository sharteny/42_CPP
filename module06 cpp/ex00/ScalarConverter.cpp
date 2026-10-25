#include "ScalarConverter.hpp"


ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter& other){
	(void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter(){}

bool isCharLiteral(const std::string& s)
{
	return s.length() == 3
		&& s[0] == '\''
		&& s[2] == '\'';
}

bool isSpecial(const std::string& s)
{
	return s == "nan" || s == "nanf"
		|| s == "+inf" || s == "-inf"
		|| s == "+inff" || s == "-inff";
}

bool isIntLiteral(const std::string& s)
{
	if (s.empty())
		return false;

	std::string::size_type i = 0;

	if (s[i] == '+' || s[i] == '-')
		++i;

	if (i == s.length())
		return false;

	for (; i < s.length(); ++i)
	{
		if (s[i] < '0' || s[i] > '9')
			return false;
	}
	return true;

}

bool isFloatLiteral(const std::string& s)
{
	if (s.length() < 4 || s[s.length() - 1] != 'f')
		return false;

	std::string number = s.substr(0, s.length() - 1);

	if (number.find('.') == std::string::npos)
		return false;

	char* end;
	std::strtod(number.c_str(), &end);

	return end != number.c_str() && *end == '\0';
}

bool isDoubleLiteral(const std::string& s)
{
	if (s.find('.') == std::string::npos)
		return false;

	if (s.empty() || s[s.length() - 1] == 'f')
		return false;

	char* end;
	std::strtod(s.c_str(), &end);

	return end != s.c_str() && *end == '\0';
}

void printChar(double value)
{
	if (std::isnan(value) || std::isinf(value)
		|| value < 0 || value > 127)
	{
		std::cout << "char: impossible" << std::endl;
	}
	else if (value < 32 || value == 127)
	{
		std::cout << "char: Non displayable" << std::endl;
	}
	else
	{
		std::cout << "char: '" 
			  << static_cast<char>(value) << "'" << std::endl;
	}
}

void printInt(double value)
{
	if (std::isnan(value) || std::isinf(value)
		|| value < INT_MIN || value > INT_MAX)
	{
		std::cout << "int: impossible" << std::endl;
	}
	else
	{
		std::cout << "int: "	
			  << static_cast<int>(value) << std::endl;
	}
}

void printFloat(double value)
{
	float f = static_cast<float>(value);

	if (std::isnan(value))
		std::cout << "float: nanf" << std::endl;
	else if (std::isinf(value))
		std::cout << (value < 0 ? "float: -inff" : "float: +inff")
				  << std::endl;
	else if (std::fabs(value) > FLT_MAX)
		std::cout << "float: impossible" << std::endl;
	else
	{
		std::cout << "float: " << std::fixed << std::setprecision(1)
				  << f << "f" << std::endl;
	}
}

void printDouble(double value)
{
	if (std::isnan(value))
		std::cout << "double: nan" << std::endl;
	else if (std::isinf(value))
		std::cout << (value < 0 ? "double: -inf" : "double: +inf")
				  << std::endl;
	else
	{
		std::cout << "double: " << std::fixed << std::setprecision(1)
				  << value << std::endl;
	}
}


void ScalarConverter::convert(const std::string& literal)
{
	if (isSpecial(literal))
	{
		double value;

		if (literal == "nan" || literal == "nanf")
			value = std::numeric_limits<double>::quiet_NaN();
		else if (literal == "-inf" || literal == "-inff")
			value = -std::numeric_limits<double>::infinity();
		else
			value = std::numeric_limits<double>::infinity();

		printChar(value);
		printInt(value);
		printFloat(value);
		printDouble(value);
		return;
	}

	double value;
	char* end;

	if (isCharLiteral(literal))
	{
		value = static_cast<double>(literal[1]);
	}
	else if (isIntLiteral(literal))
	{
		value = std::strtod(literal.c_str(), &end);
	}
	else if (isFloatLiteral(literal))
	{
		std::string number = literal.substr(0, literal.length() - 1);
		value = std::strtod(number.c_str(), &end);
	}
	else if (isDoubleLiteral(literal))
	{
		value = std::strtod(literal.c_str(), &end);
	}
	else
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return;
	}

	printChar(value);
	printInt(value);
	printFloat(value);
	printDouble(value);
}