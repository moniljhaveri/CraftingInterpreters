#include <iostream> 
#include <string> 
#include <string_view>


int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        std::cout << "Usage: generate_ast <output directory>" << std::endl;
        return 64;
    }
    auto outputDir = argv[1];
    std::cout << outputDir << std::endl;
    return 0; 
}