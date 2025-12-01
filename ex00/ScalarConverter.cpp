/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhatahet <qhatahet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 13:18:09 by qhatahet          #+#    #+#             */
/*   Updated: 2025/11/25 21:49:28 by qhatahet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

# include <cstdlib>
# include <cerrno>
# include <climits>
# include <cfloat>
# include <cmath>
# include <cctype>
# include <iomanip>
# include <limits>
# include <cstring>

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& obj) { (void)obj; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& obj) { (void)obj; return (*this); }
ScalarConverter::~ScalarConverter() {}

bool ScalarConverter::isChar(const std::string& literal)
{
	return (literal.length() == 1 && !std::isdigit(static_cast<unsigned char>(literal[0])));
}

bool ScalarConverter::isInt(const std::string& literal)
{
	size_t i = 0;
	if (literal.empty())
		return (false);
	if (literal[i] == '-' || literal[i] == '+') i++;
	if (i == literal.length())
		return (false);
	for (; i < literal.length(); ++i)
		if (!std::isdigit(static_cast<unsigned char>(literal[i])))
			return (false);
	return (true);
}

bool ScalarConverter::isFloat(const std::string& literal)
{
	size_t i = 0;
	bool dot_found = false;
	if (literal.empty())
		return (false);
	if (literal[i] == '-' || literal[i] == '+')
		i++;
	if (i == literal.length())
		return (false);
	for (; i < literal.length(); ++i)
	{
		if (literal[i] == '.')
		{
			if (dot_found)
				return (false);
			dot_found = true;
		}
		else if (literal[i] == 'f' && i == literal.length() - 1)
			return (dot_found);
		else if (!std::isdigit(static_cast<unsigned char>(literal[i])))
			return (false);
	}
	return (false);
}

bool ScalarConverter::isDouble(const std::string& literal)
{
	size_t i = 0;
	bool dot_found = false;
	if (literal.empty())
		return (false);
	if (literal[i] == '-' || literal[i] == '+')
		i++;
	if (i == literal.length())
		return (false);
	for (; i < literal.length(); ++i)
	{
		if (literal[i] == '.')
		{
			if (dot_found)
				return (false);
			dot_found = true;
		}
		else if (!std::isdigit(static_cast<unsigned char>(literal[i])))
			return (false);
	}
	return (dot_found);
}

void ScalarConverter::printChar(char c)
{
	if (!std::isprint(static_cast<unsigned char>(c)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;
}

void ScalarConverter::printInt(int i)
{
	std::cout << "int: " << i << std::endl;
}

void ScalarConverter::printFloat(float f)
{
	if (std::isnan(f))
	{
		std::cout << "float: nanf" << std::endl;
		return ;
	}
	if (std::isinf(f))
	{
		std::cout << "float: " << (f < 0 ? "-inff" : "inff") << std::endl;
		return ;
	}
	std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
}

void ScalarConverter::printDouble(double d)
{
	if (std::isnan(d))
	{
		std::cout << "double: nan" << std::endl;
		return ;
	}
	if (std::isinf(d))
	{
		std::cout << "double: " << (d < 0 ? "-inf" : "inf") << std::endl;
		return ;
	}
	std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

static bool isPseudoLiteral(const std::string& s)
{
	return (s == "nan" || s == "nanf" ||
			s == "+inf" || s == "-inf" || s == "inf" ||
			s == "+inff" || s == "-inff" || s == "inff");
}

void ScalarConverter::convert(const std::string& literal)
{
	if (isChar(literal))
	{
		char c = literal[0];
		printChar(c);
		printInt(static_cast<int>(c));
		printFloat(static_cast<float>(c));
		printDouble(static_cast<double>(c));
		return;
	}
	if (isPseudoLiteral(literal))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;

		if (literal == "nan" || literal == "nanf")
			std::cout << "float: nanf" << std::endl;
		else if (literal == "-inf" || literal == "-inff")
			std::cout << "float: -inff" << std::endl;
		else
			std::cout << "float: inff" << std::endl;

		if (literal == "nan" || literal == "nanf")
			std::cout << "double: nan" << std::endl;
		else if (literal == "-inf" || literal == "-inff")
			std::cout << "double: -inf" << std::endl;
		else
			std::cout << "double: inf" << std::endl;
		return ;
	}
	errno = 0;
	const char* str = literal.c_str();
	char* endptr = NULL;
	double d = 0.0;
	bool float_literal = (literal.length() > 0 && literal[literal.length() - 1] == 'f');

	if (float_literal)
	{
		std::string trimmed = literal.substr(0, literal.length() - 1);
		d = std::strtod(trimmed.c_str(), &endptr);
		if (endptr == NULL || *endptr != '\0' || errno == ERANGE)
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
			return ;
		}
	}
	else
	{
		d = std::strtod(str, &endptr);
		if (endptr == NULL || *endptr != '\0' || errno == ERANGE)
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
			return ;
		}
	}

	// char
	if (std::isnan(d) || std::isinf(d) ||
		d < static_cast<double>(std::numeric_limits<char>::min()) ||
		d > static_cast<double>(std::numeric_limits<char>::max()))
	{
		std::cout << "char: impossible" << std::endl;
	}
	else
	{
		char c = static_cast<char>(d);
		printChar(c);
	}

	// int
	if (std::isnan(d) || std::isinf(d) ||
		d < static_cast<double>(std::numeric_limits<int>::min()) ||
		d > static_cast<double>(std::numeric_limits<int>::max()))
	{
		std::cout << "int: impossible" << std::endl;
	}
	else
	{
		int i = static_cast<int>(d);
		printInt(i);
	}

	// float
	if (std::isnan(d))
	{
		std::cout << "float: nanf" << std::endl;
	}
	else if (std::isinf(d))
	{
		std::cout << "float: " << (d < 0 ? "-inff" : "inff") << std::endl;
	}
	else if (d < -static_cast<double>(std::numeric_limits<float>::max()) ||
			 d > static_cast<double>(std::numeric_limits<float>::max()))
	{
		std::cout << "float: impossible" << std::endl;
	}
	else
	{
		float f = static_cast<float>(d);
		printFloat(f);
	}

	// double
	printDouble(d);
}
