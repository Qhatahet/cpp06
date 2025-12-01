/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhatahet <qhatahet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 13:18:16 by qhatahet          #+#    #+#             */
/*   Updated: 2025/11/25 21:44:24 by qhatahet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>

class ScalarConverter
{
	private:
		static bool	isChar(const std::string& literal);
		static bool	isInt(const std::string& literal);
		static bool	isFloat(const std::string& literal);
		static bool	isDouble(const std::string& literal);
		static void	printChar(char c);
		static void	printInt(int i);
		static void	printFloat(float f);
		static void	printDouble(double d);
	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& obj);
		ScalarConverter& operator=(const ScalarConverter& obj);
		~ScalarConverter();
		static void    convert(const std::string& literal);
};

#endif