#include "header.h"

#define DEFAULT_ATTEMPTS 9  // constant variable including round 0

_Bool isCorect(char ans[])
{
    int i = 0;
    while (i < 4)
    {
        if (ans[i] > 8 || ans[i] < 0)
        {
            printf("Wrong input!\n");
            return 0;
        }
        i++;
    }
    return 0;
}

int main(int argc, char* argv[])
{
    int tries = DEFAULT_ATTEMPTS;
    char win[4];

    srand(time(0));

    for (int i = 0; i < 4; i++)
    {
        win[i] = (char)rand() % 8 + '0';
    }
    // printf("code: %s\n", win);
    if (argc > 1)
    {
        for (int i = 1; i < argc; i += 2)
        {
            if (argv[i][1] == 'c')
            {
                for (int ac = 0; ac < 4; ac++)
                {
                    win[ac] = argv[i + 1][ac];
                }
            }
            else if (argv[i][1] == 't')
            {
                tries = atoi(argv[i + 1]);
            }
        }
    }
    printf("Welcome to MASTERMIND\n");
    printf("Will you find the secret code?\n");
    printf("Please enter a valid guess\n");
    for (int i = 0; i < tries; i++)
    {
        printf("---\nRound %d\n", i);
        printf(">\n");

        char* ans = (char*)malloc(5 * sizeof(char));

        int r = read(0, ans, 5);
        if (r == 0)
        return 0;

        int inPlace = 0;
        int missPlace = 0;

        for (int ac = 0; ac < 4; ac++)
        {
            if (win[ac] == ans[ac])
            {
                inPlace++;
                missPlace--;
            }

            for (int x = 0; x < 4; x++)
            {
                if (win[x] == ans[ac])
                {
                    missPlace++;
                }
            }
        }

        if (inPlace == 4)
        {
            printf("Congratz! You did it!");
            return 0;
        }

        printf("Well placed pieces: %d\n", inPlace);
        printf("Misplaced pieces: %d\n", missPlace);
        // printf("---\n");
    }
    return 0;
}
