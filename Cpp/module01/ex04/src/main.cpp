/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 13:32:03 by hel-hosr          #+#    #+#             */
/*   Updated: 2023/05/02 15:44:49 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.hpp"

static int check_input(int argc, char **argv)
{
    if (argc < 4)
    {
        std::cout<<"Not enough arguments"<<std::endl;
        return (0);
    }
    else if (argc > 4)
    {
        std::cout<<"Too many arguments"<<std::endl;
        return (0);
    }
    
    if (argv[2][0] == '\0' || argv[3][0] == '\0')
    {
        std::cout<<"You can not have an empty string as argument"<<std::endl;
        return (0);
    }
    return (1);
}

static std::string replacer(std::string buffer, std::string original, std::string replace)
{
    int original_len = original.length();
	int replace_len = replace.length();
	int pos = 0;

	pos = buffer.find(original);
    if (pos == std::string::npos)
        return(buffer);
    else
    {
        while (pos != std::string::npos)
        {
            buffer.erase(pos, original_len);
            buffer.insert(pos, replace);
            pos = buffer.find(original, pos + replace_len);
        }
    }
	return (buffer);
}



int main (int argc, char **argv)
{

    if (!check_input(argc, argv))
        return (0);
    else
    {
        std::string filename = argv[1];
		std::string	original = argv[2];
		std::string	replace = argv[3];
		std::ifstream		input_file;
		std::ofstream		output_file;
        std::string			buffer;

        input_file.open(filename);
        if (!input_file.is_open())
        {
            std::cout<<"Input file doesn't exist"<<std::endl;
            return (0);
        }
        output_file.open(filename + ".replace");
        if (!output_file.is_open())
        {
            std::cout<<"Cant open output file"<<std::endl;
            input_file.close();
            return(0);
        }
        while (std::getline(input_file, buffer))
        {
            buffer = replacer(buffer, original, replace);
            output_file << buffer;
            if (input_file.peek() != EOF)
				output_file << std::endl;
        }
        output_file.close();
        input_file.close();
    }
    return (0);
}