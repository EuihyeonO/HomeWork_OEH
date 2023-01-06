#include <iostream>
#include <string>
#include <filesystem>

std::string MoveToParentPath(std::string& _path)
{
	for (int i = _path.size() - 1; i >= 0; i--)
	{
		if (_path[i] == 92)
		{
			std::string ReturnString(_path);

			for (int j = i+1; j < _path.size(); j++)
			{
				ReturnString.pop_back();
			}

			return ReturnString;
		}
	}
	return _path;
}

int main()
{
	std::filesystem::path mypath = std::filesystem::current_path();

	std::string cur_path = mypath.string();
	std::string parrent_path = MoveToParentPath(cur_path);

	int a = 0;
}