#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv)
{
    if(argc != 4){
        std::cout << "Usage : ./replace file_in string1 string2" << std::endl;
        return 1;
    }

    std::string content;
    std::string filename = argv[1];
    std::string s1 = argv[2];
    if (s1.empty())
    {
        std::cout << "s1 cannot be empty\n";
        return 1;
    }
    std::string s2 = argv[3];
    size_t pos = 0;

    std::ifstream infile(filename);
    if(!infile){
        std::cout << "file not found\n";
        return 1;
    }
    std::getline(infile, content,'\0');
    while((pos = content.find(s1, pos)) != std::string::npos){
        content = content.substr(0, pos) + s2 + content.substr(pos+s1.length());
        pos += s2.length(); 
    }
    std::ofstream outfile(filename + ".replace");
    if (!outfile)
    {
        std::cout << "Error creating output file\n";
        return 1;
    }
    outfile << content;
    infile.close();
    outfile.close();
    return 0;
}