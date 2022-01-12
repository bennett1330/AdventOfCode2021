#include <iostream>

using namespace std;

#define         MIN_DAY          1
#define         MAX_DAY         25

int main()
{
    char str_input[4];
    bool exit_requested = false;
    unsigned char selected_day = 0;
    printf("Enter 'q' to terminate the program.\r\n");
    while (!exit_requested)
    {
        printf("\r\nEnter the challenge day [%d-%d]...\r\n", MIN_DAY, MAX_DAY);
        scanf("%s", str_input);
        printf("\r\n");
        if (str_input[0] == 'q')
        {
            exit_requested = true;
        }
        else
        {
            selected_day = atoi(str_input);
            if ((selected_day < MIN_DAY) || (selected_day > MAX_DAY))
            {
                printf("Invalid challenge day provided. Please enter a number between %d and %d.\r\n", MIN_DAY, MAX_DAY);
                continue;
            }
            switch(selected_day)
            {
                case 1:
                    system("SonarSweep.exe");
                    break;
                case 2:
                    system("Dive.exe");
                    break;
                default:
                    printf("Not yet implemented.\r\n");
                    break;
            }
        }
    }

    return 0;
}