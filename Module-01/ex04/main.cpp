/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonteli <amonteli@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 17:35:58 by amonteli          #+#    #+#             */
/*   Updated: 2021/12/27 14:57:59 by amonteli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int		main(int args_count, char **args)
{
	if (args_count != 4)
	{
		std::cerr <<  "please use ./replace <FILENAME> <from> <to>" << std::endl;
		return (1);
	}

	std::string fileName = args[1];
	std::string from = args[2];
	std::string to = args[3];


	if (fileName.empty() || from.empty() || to.empty())
	{
		std::cerr <<  "please use ./replace <FILENAME> <from> <to>" << std::endl;
		return (1);
	}

	std::ifstream file;
	std::string line;

	std::string fileContent;

	file.open(fileName);
	if (file.is_open())
	{
		while (std::getline(file, line))
		{
			fileContent.append(line);
			fileContent.append("\n");
			line.clear();
		}
		file.close();
	}
	else
	{
		std::cerr <<  "Invalid file! please use ./replace <FILENAME> <from> <to>" << std::endl;
		return (1);
	}

	std::size_t findPosition = 0;
	std::size_t stringPos = 0;

	std::string newFileContent;
	while ((findPosition = fileContent.find(from, stringPos)) != std::string::npos)
	{
		newFileContent.append(fileContent, stringPos, (findPosition - stringPos));
		newFileContent.append(to);
		stringPos = findPosition + from.size();
	}
	newFileContent.append(fileContent, stringPos);

	file.close();
	std::ofstream newFile;

	newFile.open(fileName.append(".replace"));
	if (newFile.is_open())
	{
		newFile << newFileContent;
		newFile.close();
	}
	return (0);
}
