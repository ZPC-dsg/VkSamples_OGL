#include <tools.h>

namespace Tools {
	std::string get_solution_dir() {
		char* path = NULL;
		path = _getcwd(NULL, 1);
		std::string str1(path);
		int pos = str1.find_last_of('\\', str1.length());
		std::string solutionDir = str1.substr(0, pos - 5);  // 返回解决方案的路径
		delete path;
		path = nullptr;

		return solutionDir;
	}
}