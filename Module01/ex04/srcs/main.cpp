/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul.com.tr>   +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 22:11:06 by azorlutu          #+#    #+#             */
/*   Updated: 2026/01/22 22:11:07 by azorlutu         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Replace.hpp"

#include <string>
#include <fstream>
#include <iostream>

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cerr << "Usage: ./replace <filename> <s1> <s2>" << std::endl;
        return (1);
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    std::ifstream infile(filename.c_str());
    if(!infile.is_open())
    {
        std::cerr << "Error: Could not open file " << std::endl;
        return (1);
    }

    std::ofstream outfile((filename + ".replace").c_str());
    if (!outfile.is_open())
    {
        std::cerr << "Error: Could not create output file." << std::endl;
        infile.close(); // Giriş dosyasını kapatmayı unutma!
        return (1);
    }

    std::string content;
    std::string line;

    while (std::getline(infile, line))
    {
        content += line;
        if(!infile.eof())
        {
            content += "\n";
        }
    }

    myReplace(content, s1, s2);

    outfile << content;

    infile.close();
    outfile.close();
    
    return (0);
}