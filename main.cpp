 #include <time.h>
#include <iostream>
#include <unistd.h>
#define BGRN "\e[1;32m"
#define COLOR_RESET "\e[0m"
#define BRED "\e[1;31m"
int main(int __ac, char *__av[]) {
	clock_t __start, __end;
	if (__ac != 2)
		return (std::cout << BRED << "Bad argument" << COLOR_RESET << std::endl, 1);
	std::string __commit_message(__av[1]);
	if (__commit_message.length() < 6)
		return (std::cout << BRED << "Bad commit message" << COLOR_RESET << std::endl, 1);
	if (system("git add .") != 0 )
		return (std::cout << BRED << "< git add > command failed>" << COLOR_RESET << std::endl, 1);
	std::cout << BGRN << "Successfully added" << COLOR_RESET << std::endl;
	std::string __commit_command = "git commit -m \"(chore) : " + __commit_message + " \"";
	if (system (__commit_command.c_str()) != 0 )
		return (std::cout << BRED << "<git commit> command failed" << COLOR_RESET << std::endl, 1);
	std::cout << BGRN << "Successfully commited" << COLOR_RESET << std::endl;
	if (system("git push origin master") != 0 )
		return (std::cout << BRED << "<git push> command failed" << COLOR_RESET << std::endl, 1);
	std::cout << BGRN << "Push complited successfully" << COLOR_RESET << std::endl;
	return (0);
}

