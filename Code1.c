#include <stdio.h>
#include <stdbool.h>

void scoreBreakdown(int gameScore)
{
    int safety;
    int touchdown;
    int touchdownExtra;
    int touchdownConversion;
    int fieldGoal;
    
    /*loops through all possible scores with one type of scoring within the given gameScore, checking each one to see if it matches. Prints possiblity if the sum of them matches*/
    for (safety = gameScore / 2; safety >= 0; safety--)
    {
        for (fieldGoal = gameScore / 3; fieldGoal >= 0; fieldGoal--)
        {
            for (touchdown = gameScore / 6; touchdown >= 0; touchdown--)
            {
                for (touchdownExtra = gameScore / 7; touchdownExtra >= 0; touchdownExtra--)
                {
                    for (touchdownConversion = gameScore / 8; touchdownConversion >=0; touchdownConversion--)
                    {
                        if ((gameScore - (safety*2 + fieldGoal*3 + touchdown*6 + touchdownExtra*7 + touchdownConversion*8)) == 0)
                        {
                            printf("%d TD+2pt, %d TD+FG, %d TD. %d 3pt FG, %d Safety \n", touchdownConversion, touchdownExtra, touchdown, fieldGoal, safety);
                        }
                    }
                }
            }
        }
    }
}

int main()
{
    int gameScore;
    bool isRunning = true;

    while (isRunning)
    {
        printf("Enter an NFL score (Enter a score < 1 to stop): \n");
        int err;
        err = scanf("%d", &gameScore);
        /*checks if the program got a good input/did not error.then finds all possible score breakdowns if input score is > 1, stops program if < 1*/
        if(err > 0)
        {
            if (gameScore > 1)
            {
                scoreBreakdown(gameScore);
            }
            else
            {
                isRunning = false;
            }
        }
        else
        {
            printf("The input could not be read.\n");
            /*Clears characters so scan is reset*/
            while(getchar() != '\n');
        }
    }
    return 0;
}

