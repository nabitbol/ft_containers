#include "ft_containers_tester.hpp"
#include <sys/wait.h>
#include <unistd.h>
# include <fcntl.h>

void	displayCrash(const std::string &str, int fd, int status) {
	dup2(fd, STDERR_FILENO);

	std::cout << " \033[0;31m[CRASH]\033[0m " << std::flush;
	std::cerr << str << std::endl;
	if (WIFSIGNALED(status)) {
		std::cerr << "killed by signal " << "\033[0;31m" << WTERMSIG(status) << "\033[0m" << std::endl;
	} else if (WIFSTOPPED(status)) {
		std::cerr << "stopped by signal " << "\033[0;31m" << WSTOPSIG(status) << "\033[0m" << std::endl;
	} else {
		std::cerr << "stopped by signal " << "\033[0;31m" << status << "\033[0m" << std::endl;
	}
}

void	child(const std::string &str, functionPtr function) {
	int	fd = 0;
	int	status = 0;
	fd = open("fails.log", O_CREAT | O_APPEND | O_WRONLY, 0777);

	if (fd == -1)
		std::cerr << "error: fail to load .log file" << std::endl;
	pid_t c_pid = fork();
    if (c_pid == -1) {
		std::cerr << "error: fail create sub-process" << std::endl;
        exit(EXIT_FAILURE);
    } else if (c_pid == 0) {
		dup2(fd, STDERR_FILENO);
		function();
		exit(EXIT_SUCCESS);
    } else {
		waitpid(c_pid, &status, 0);
		if (status != 0)
			displayCrash(str, fd, status);
		if (fd != -1) {
			close(fd);
		}
    }
}

Register::Register() {};

Register::~Register() {};

void	Register::pushTestFunction(const std::string &str, const functionPtr &function) {
		_testErrorMsg.push_back(str);
		_testFunctions.push_back(function);
};

void	Register::runAllTests() {
	int index = 0;
	for (std::vector<functionPtr>::iterator i = _testFunctions.begin(); i != _testFunctions.end(); ++i) {
		child(_testErrorMsg[index], _testFunctions[index]);
		index++;
	}
	std::cout <<"\n" << std::endl;
}
