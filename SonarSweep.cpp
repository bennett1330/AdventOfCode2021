#include <cstdint>
#include <iostream>
#include <fstream>
#include <string>

#define     WRITE_P1_FILE           1
#define     WRITE_P2_FILE           2

#define     WRITE_OUTPUT_FILES      0

#define     WINDOW_SIZE             3

int main()
{
    std::cout << "SONAR SWEEP" << std::endl;

    const char input_file_name[] = "SonarSweep_input.txt";
    std::ifstream input_file = std::ifstream(input_file_name);

#if (WRITE_OUTPUT_FILES & WRITE_P1_FILE) == WRITE_P1_FILE
    std::ofstream p1_output_file = std::ofstream("SonarSweepP1_output.txt");
    char *p1_output_info_str[35];
#endif
#if (WRITE_OUTPUT_FILES & WRITE_P2_FILE) == WRITE_P2_FILE
    std::ofstream p2_output_file = std::ofstream("SonarSweepP2_output.txt");
    char *p2_output_info_str[35];
#endif

    uint16_t total_positive_deltas = 0;
    int16_t prev_input_value = 0, curr_input_value = 0, delta_value = 0;

    uint16_t window_positive_deltas = 0;
    int16_t prev_window_value = 0, curr_window_value = 0, delta_window_value = 0;

    int16_t sums[WINDOW_SIZE];
    for (uint8_t i = 0; i < WINDOW_SIZE; i++) sums[i] = 0;
    uint8_t ready_clear_sum_index = 0;

    std::string input_line;
    int16_t line_number = 1;
    while (std::getline(input_file, input_line))
    {
        prev_input_value = curr_input_value;
        curr_input_value = atoi(input_line.c_str());
        delta_value = curr_input_value - prev_input_value;

        if ((line_number != 1) && (delta_value > 0))
        {
            total_positive_deltas++;
        }

#if (WRITE_OUTPUT_FILES & WRITE_P1_FILE) == WRITE_P1_FILE
        if (line_number == 1)
        {
            *p1_output_info_str = "(N/A - no previous measurement)\0";
        }
        else if (delta_value > 0)
        {
            *p1_output_info_str = "(increased)\0";   
        }
        else
        {
            *p1_output_info_str = "(decreased)\0";
        }
        p1_output_file << curr_input_value << "\t" << *p1_output_info_str << std::endl;
#endif

        for (uint8_t i = 0; i < WINDOW_SIZE; i++)
        {
            sums[i] += curr_input_value;
        }

        ready_clear_sum_index = line_number % WINDOW_SIZE;
        if (line_number >= WINDOW_SIZE)
        {
            prev_window_value = curr_window_value;
            curr_window_value = sums[ready_clear_sum_index];
            delta_window_value = curr_window_value - prev_window_value;

            if ((line_number != WINDOW_SIZE) && (delta_window_value > 0))
            {
                window_positive_deltas++;
            }

#if (WRITE_OUTPUT_FILES & WRITE_P2_FILE) == WRITE_P2_FILE
            if (line_number == WINDOW_SIZE)
            {
                *p2_output_info_str = "(N/A - no previous sums)\0";
            }
            else if (delta_window_value > 0)
            {
                *p2_output_info_str = "(increased)\0";   
            }
            else
            {
                *p2_output_info_str = "(decreased)\0";
            }
            p2_output_file << curr_window_value << "\t" << *p2_output_info_str << std::endl;
#endif
        }
        sums[ready_clear_sum_index] = 0;

        line_number++;
    }

#if (WRITE_OUTPUT_FILES & WRITE_P1_FILE) == WRITE_P1_FILE
    p1_output_file << std::endl << "There are " << total_positive_deltas << 
        " measurements that are larger than the previous measurement." << std::endl;
#endif
#if (WRITE_OUTPUT_FILES & WRITE_P2_FILE) == WRITE_P2_FILE
    p2_output_file << std::endl << "There are " << window_positive_deltas <<
        " sums that are larger than the previous sum." << std::endl;
#endif

    std::cout << "--- Part One ---" << std::endl <<
        "Answer: " << total_positive_deltas << std::endl;
    std::cout << "--- Part Two ---" << std::endl <<
        "Answer: " << window_positive_deltas << std::endl;

    return 0;
}