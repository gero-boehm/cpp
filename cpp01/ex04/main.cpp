#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int get_content(const std::string &filename, std::string &content)
{
	std::ifstream infile(filename.c_str());

	if(!infile.is_open())
	{
		std::cerr << "Error opening file " << filename << std::endl;
		return 1;
	}

	std::ostringstream stream;
	stream << infile.rdbuf();

	content = stream.str();

	infile.close();

	return 0;
}

void replace(std::string &str, const std::string &s1, const std::string &s2)
{
	size_t pos = 0;
	size_t s1_len = s1.length();
	size_t s2_len = s2.length();

	while((pos = str.find(s1, pos)) != std::string::npos)
	{
		str.erase(pos, s1_len);
		str.insert(pos, s2);

		pos += s2_len;

		if(s1_len == 0)
			pos++;
	}
}

int write_str(const std::string &filename, const std::string &str)
{
	std::ofstream outfile((filename + ".replace").c_str());

	if(!outfile.is_open())
	{
		std::cerr << "Error opening file " << filename << ".replace" << std::endl;
		return 1;
	}

	outfile << str;

	outfile.close();

	return 0;
}

int	run(const std::string &filename, const std::string &s1, const std::string &s2)
{
	std::string str;

	if(get_content(filename, str))
		return 1;
	replace(str, s1, s2);
	if (write_str(filename, str))
		return 1;
	return 0;
}

int main(int argc, char **argv)
{
	if(argc != 4)
	{
		std::cerr << "Invalid argument count" << std::endl;
		return 1;
	}

	return run(argv[1], argv[2], argv[3]);
}
