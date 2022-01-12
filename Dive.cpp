#include <cstdint>
#include <iostream>
#include <fstream>
#include <sstream>
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
#endif
#if (WRITE_OUTPUT_FILES & WRITE_P2_FILE) == WRITE_P2_FILE
    std::ofstream p2_output_file = std::ofstream((file_prefix + "P2_output.txt").c_str());
#endif

    uint32_t x = 0, y = 0, aim = 0;

    std::string input_line, input_direction, input_value_str;
    uint16_t input_value;
    int16_t line_number = 1;
    while (std::getline(input_file, input_line))
    {
        uint8_t split_index = input_line.find(" ");
        input_direction = input_line.substr(0, split_index);
        input_value_str = input_line.substr(split_index + 1, input_line.length());
        input_value = atoi(input_value_str.c_str());

        if (input_direction.compare("forward") == 0)
        {
            x += input_value;
            y += input_value*aim;
#if (WRITE_OUTPUT_FILES & WRITE_P1_FILE) == WRITE_P1_FILE
            p1_output_file << "- " << input_line << " adds " << input_value_str << " to your horizontal position, " <<
                "a total of " << std::to_string(x) << "." << std::endl;
#endif
#if (WRITE_OUTPUT_FILES & WRITE_P2_FILE) == WRITE_P2_FILE
            p2_output_file << "- " << input_line << " adds " << input_value_str << " to your horizontal position, " <<
                "a total of " << std::to_string(x) << ". Because your " << 
                "aim is " << std::to_string(aim) << ", ";
            if (aim == 0)
            {
                p2_output_file << "your depth does not change." << std::endl;
            }
            else // (aim > 0)
            {
                p2_output_file << "your depth increases by " << input_value_str << "*" << std::to_string(aim) << 
                    "=" << std::to_string(input_value*aim) << std::endl;
            }
#endif
        }
        else if (input_direction.compare("down") == 0)
        {
            aim += input_value;
#if (WRITE_OUTPUT_FILES & WRITE_P1_FILE) == WRITE_P1_FILE
            p1_output_file << "- " << input_line << " adds " << input_value_str << " to your depth, " <<
                "resulting in a value of " << std::to_string(aim) << "." << std::endl;
#endif
#if (WRITE_OUTPUT_FILES & WRITE_P2_FILE) == WRITE_P2_FILE
            p2_output_file << "- " << input_line << " adds " << input_value_str << " to your depth, " <<
                "resulting in a value of " << std::to_string(aim) << "." << std::endl;
#endif
        }
        else if(input_direction.compare("up") == 0)
        {
            aim -= input_value;
#if (WRITE_OUTPUT_FILES & WRITE_P1_FILE) == WRITE_P1_FILE
            p1_output_file << "- " << input_line << " decreases your depth by " << input_value_str << " " <<
                "resulting in a value of " << std::to_string(aim) << "." << std::endl;
#endif
#if (WRITE_OUTPUT_FILES & WRITE_P2_FILE) == WRITE_P2_FILE
            p2_output_file << "- " << input_line << " decreases your depth by " << input_value_str << " " <<
                "resulting in a value of " << std::to_string(aim) << "." << std::endl;
#endif
        }
        else
        {
            std::cout << "Unrecognized direction specified. [line: " << line_number << "]." << std::endl;
#if (WRITE_OUTPUT_FILES & WRITE_P1_FILE) == WRITE_P1_FILE
            p1_output_file << "*** ERROR : Unable to parse \"" << input_line << "\". ***" << std::endl;
#endif
#if (WRITE_OUTPUT_FILES & WRITE_P1_FILE) == WRITE_P1_FILE
            p2_output_file << "*** ERROR : Unable to parse \"" << input_line << "\". ***" << std::endl;
#endif
        }

        line_number++;
    }

#if (WRITE_OUTPUT_FILES & WRITE_P1_FILE) == WRITE_P1_FILE
    p1_output_file << std::endl << "You would have a " << 
        "horizontal position of " << x << " and a " <<
        "depth of " << aim << ". (" <<
        "Multiplying these together produces " << x*aim << ".)" << std::endl;
#endif
#if (WRITE_OUTPUT_FILES & WRITE_P2_FILE) == WRITE_P2_FILE
    p2_output_file << std::endl << "You would have a " << 
        "horizontal position of " << x << " and a " <<
        "depth of " << y << ". (" <<
        "Multiplying these together produces " << x*y << ".)" << std::endl;
#endif

    std::cout << "--- Part One ---" << std::endl <<
        "Answer: " << x*aim << std::endl;
    std::cout << "--- Part Two ---" << std::endl <<
        "Answer: " << x*y << std::endl;

    return 0;
}