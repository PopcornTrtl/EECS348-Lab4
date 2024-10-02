#include <stdio.h>
#include <stdbool.h>

void scoreBreakdown(int gameScore)
{
    int safety;
    int touchdown;
    int touchdownExtra;
    int touchdownConversion;
    int fieldGoal;
    
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
        scanf("%d", &gameScore);
        if (gameScore > 1)
        {
            scoreBreakdown(gameScore);
        }
        else
        {
            isRunning = false;
        }
    }
    return 0;
}

