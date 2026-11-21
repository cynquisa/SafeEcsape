#pragma once
#include <iostream>
#include <string>
#include "ConsoleColor.h"

class Input

{
public:

	static int GetNumber(const std::string& prompt, int min, int maxNumber)
	{
		std::string input;
		while (true)
		{
			if (!std::cin)
			{
				std::cin.clear();
			}
			std::cout << prompt;

			if (!std::getline(std::cin, input) || input.empty())
			{
				continue;
			}
			try
			{
				std::size_t processedCharaters = 0;
				int number = std::stoi(input, &processedCharaters);
				if (processedCharaters != input.length())
				{
					std::cout << "[ERROR] Please enter numbers only.\n\n";
					continue;
				}
				if (number >= min && number <= maxNumber)
				{
					return number;
				}
				std::cout << "[ERROR] That number is not an available choice.\n\n";
			}
			catch (...)
			{
				std::cout << "[ERROR] Invalid input. Please enter a valid number.\n\n";
			}
		}
	}


	static std::string GetString(const std::string& prompt, bool allowEmpty = false)
	{
		std::string input;
		while (true)
		{
			if (!std::cin)
			{
				std::cin.clear();
			}
			std::cout << prompt;

			if (std::getline(std::cin, input))
			{

				if (allowEmpty || !input.empty())
				{
					return input;
				}
				std::cout << " [ERROR] You must enter a valid response.\n\n";
			}
			else
			{
				std::cin.clear();
				return "";
			}
		}
	}

		static void Pause(const std::string & prompt = "\nPress Enter to continue...", ConsoleColor::Ink color = ConsoleColor::Ink::Yellow)
		{
			ConsoleColor::Print(prompt, color);
			std::string dummy;
			std::getline(std::cin, dummy);
		}	
};