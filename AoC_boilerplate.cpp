#include <cstdint>
#include <iostream>
#include <fstream>
#include <string>

#define     WRITE_P1_FILE           1
#define     WRITE_P2_FILE           2

#define     WRITE_OUTPUT_FILES      0

int main()
{
    std::cout << "DIVE!" << std::endl;
    std::string file_prefix = "Dive";

    std::string input_file_name = file_prefix + "_input.txt";
    std::ifstream input_file = std::ifstream(input_file_name.c_str());
#if (WRITE_OUTPUT_FILES & WRITE_P1_FILE) == WRITE_P1_FILE
    std::ofstream p1_output_file = std::ofstream((file_prefix + "P1_output.txt").c_str());
    std::string p1_output_info_str;
#endif
#if (WRITE_OUTPUT_FILES & WRITE_P2_FILE) == WRITE_P2_FILE
    std::ofstream p2_output_file = std::ofstream((file_prefix + "P2_output.txt").c_str());
    std::string p2_output_info_str;
#endif

    std::string input_line;
    int16_t line_number = 1;
    while (std::getline(input_file, input_line))
    {

    }

#if (WRITE_OUTPUT_FILES & WRITE_P1_FILE) == WRITE_P1_FILE
    p1_output_file << std::endl << "You would have a " << 
        "horizontal position of " << "placeholder" << "and a " <<
        "depth of " << "placeholder" << ". (" <<
        "Multiplying these together produces " << "placeholder" << ".)" << std::endl;
#endif
#if (WRITE_OUTPUT_FILES & WRITE_P2_FILE) == WRITE_P2_FILE
    p2_output_file << std::endl << "placeholder" <<
        " placeholder" << std::endl;
#endif

    std::cout << "--- Part One ---" << std::endl <<
        "Answer: " << "placeholder" << std::endl;
    std::cout << "--- Part Two ---" << std::endl <<
        "Answer: " << "placeholder" << std::endl;

    return 0;
}