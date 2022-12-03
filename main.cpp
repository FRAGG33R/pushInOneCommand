#include <time.h>
#include <iostream>
#include <unistd.h>
int main(int __ac, char *__av[]){
	clock_t __start, __end;
	if (__ac != 2)
		return (std::cout << "Bad argument" << std::endl, 1);
	std::string __commit_message(__av[1]);
	if (__commit_message.length() < 6)
		return (std::cout << "Bad commit message" << std::endl, 1);
	if (system("git add .") != 0 )
		return (std::cout << "< git add > command failed>" << std::endl, 1);
	sleep(200);
	std::string __commit_command = "git commit -m \"(chore) : " + __commit_message + " \"";
	__start = clock();
	if (system (__commit_command.c_str()) != 0 )
		return (std::cout << "<git commit> command failed" << std::endl, 1);
	__end = clock();
	sleep(__end - __start);
	__start = clock();
	if (system("git push origin master") != 0 )
		return (std::cout << "<git push> command failed" << std::endl, 1);

	__end = clock();
	sleep(__end - __start);
	std::cout << "Push complited successfully" << std::endl;
	return (0);
}