#include <iostream>
#include <fstream>
#include <string>

 /*     Задание 1:
	 Используя библиотеку fstream реализуйте следующие функции:
   + Полная замена содержимого файла
   + Добавление нового содержимого в конец файла
   + Вывод содержимого файла
   + Удаление файла
   + Вывод размера файла
   + После каждой операции нужно сообщать пользователю все ли прошло успешно
   + Перед тем как выполнить какую либо операцию, запросите название файла
	 над которым эти операции будут выполнены
 */


bool complete_replacement(const std::string& path, const std::string& txt)
{
	std::ios::openmode outputMode = std::ios::trunc | std::ios::out;
	std::fstream output(path, outputMode);

	if (output) {
		output << txt;
		output.close();
		return true;
	}
	return false;
}

bool Append(const std::string& path, const std::string& txt)
{
	std::fstream output(path, std::ios::app | std::ios::out);

	if (output) {
		output << txt;
		output.close();
		return true;
	}
	return false;
}

bool input(const std::string& path)
{
	std::fstream input(path);
	if (input)
	{
		std::string line;
		while (std::getline(input, line))
		{
			std::cout << line << '\n';
		}
		input.close();
		return true;
	}
	return false;
}

bool removve(const char* path)
{
	if (std::remove(path) != 0)
		return false;
	else
		return true;
}

bool out_put_size(const std::string& path)
{
	std::fstream file(path);

	if (file) {
		int size = 0;
		file.seekg(0, std::ios::end);
		size = file.tellg();
		std::cout << size;
		file.close();
		return true;
	}
	return false;
}


enum { EXIT, REPLACEMENT, APPEND, INPUT, REMOVE, OUT_PUT_SIZE, };

int main()
{
	int action; std::string path, text;
	char location[50];

	do
	{
		std::cout << R"(
0 - Exit
1 - Replacement
2 - Append
3 - In put
4 - Remove
5 - Out put size
)";
		std::cin >> action;
		system("cls");
		std::cin.ignore();
		if (action == EXIT)
		{
			break;
		}
		else if (action == REPLACEMENT)
		{
			std::cout << "Enter file location\n";
			std::cin >> path;
			std::cin.ignore();

			std::cout << "Enter text\n";
			std::getline(std::cin, text);

			if (complete_replacement(path, text)) std::cout << "The action was successful\n";
			else std::cout << "Action failed\n";

		}
		else if (action == APPEND)
		{
			std::cout << "Enter file location\n";
			std::cin >> location;
			std::cin.ignore();
			std::cout << "Enter text\n";
			std::getline(std::cin, text);

			if (Append(location, text)) std::cout << "The action was successful\n";
			else std::cout << "Action failed\n";

		}
		else if (action == INPUT)
		{
			std::cout << "Enter file location\n";
			std::cin >> path;

			if (!input(path)) std::cout << "Action failed\n";
		}
		else if (action == REMOVE)
		{
			std::cout << "Enter file location\n";
			std::cin >> location;

			if (removve(location)) std::cout << "File successfully delete\n";
			else std::cout << "File not found error deleting\n";
		}
		else if (action == OUT_PUT_SIZE)
		{
			std::cout << "Enter file path for size\n";
			std::cin >> path;

			if (out_put_size(path)) std::cout << " bite\n";
			else std::cout << "Action failed\n";
		}
		else
		{
			std::cout << "\nIncorrect choice\n";
		}
	} while (true);


}
