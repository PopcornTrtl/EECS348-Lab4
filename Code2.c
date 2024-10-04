#include <stdio.h>
#include <stdbool.h>

/*Functions to convert each of the temperatures to another system*/
float celsius_to_fahrenheit(float celsius)
{
    float fahrenheit = ((9.0/5.0)*celsius) + 32;
    return fahrenheit;
}

float celsius_to_kelvin(float celsius)
{
    float kelvin = celsius + 273.15;
    return kelvin;
}

float fahrenheit_to_celsius(float fahrenheit)
{
    float celsius = (5.0/9.0)*(fahrenheit - 32);
    return celsius;
}

float kelvin_to_celsius(float kelvin)
{
    float celsius = kelvin - 273.15;
    return celsius;
}
/*Convert input to celsius and then celsius to wanted output, using other functions already made*/
float fahrenheit_to_kelvin(float fahrenheit)
{
    float kelvin = celsius_to_kelvin(fahrenheit_to_celsius(fahrenheit));
    return kelvin;
}

float kelvin_to_fahrenheit(float kelvin)
{
    float fahrenheit = celsius_to_fahrenheit(kelvin_to_celsius(kelvin));
    return fahrenheit;
}

/*Prints how hot/cold it is + weather reccomendations based on the celsius conversion of the userTemp*/
void catagorize_temp(float celsius)
{
    if(celsius < 0)
    {
        printf("Freezing; Be careful on the roads!\n");
    }
    else if(0 <= celsius && celsius < 10)
    {
        printf("Comfortable; Enjoy the outdoors!\n");
    }
    else if(10 <= celsius && celsius <= 25)
    {
        printf("Cold; Throw on a jacket or coat.\n");
    }
    else if(25 < celsius && celsius <= 35)
    {
        printf("Hot; Drink lots of water.\n");
    }
    else
    {
        printf("Extreme Heat; Try to stay indoors.\n");
    }
}

int main()
{
    float userTemp;
    int initScale;
    int conversionScale;
    float conversionTemp;
    bool isCorrectInput = false;
    int err;
    /*Gets temperature to get converted, checks if the input is a number and prompts the user until the give one*/
    while(!isCorrectInput)
    {
        printf("Give a temperatur value: ");
        err = scanf("%f",&userTemp);
        if(err <= 0)
        {
            printf("That is not a number. Please enter a number\n");
            while(getchar() != '\n');
        }
        else
        {
            isCorrectInput = true;
        }
        
    }
    /*Gets the scale of the given temp. Checks to make sure the input corresponds to an option given*/
    isCorrectInput = false;
    while(!isCorrectInput)
    {
        printf("=============\nWhat scale is the temperature in? (1:Fahrenheit, 2:Celsius, 3:Kelvin): \n");
        err = scanf("%d", &initScale);

        if(initScale <= 3 && initScale > 0 && err >=0)
        {
            isCorrectInput = true;
        }
        else
        {
            printf("=============\nThe scale selected does not exist. Please choose one of the given options.\n\n");
            while(getchar() != '\n');
        }
    }
    /*Gets the scale for the conversion. Checks to make sure the input corresponds to an option given*/
    isCorrectInput = false;
    while(!isCorrectInput)
    {
        printf("=============\nWhat scale do you want to convert the temperature to? (1:Fahrenheit, 2:Celsius, 3:Kelvin): \n");
        err = scanf("%d", &conversionScale);

        if(initScale != conversionScale && conversionScale <= 3 && conversionScale > 0 && err >= 0)
        {   
            isCorrectInput = true;
        }
        else
        {
            printf("=============\nYou cannot convert to the same scale or a scale that does not exist. Please choose a different scale\n\n");
            while(getchar() != '\n');
        }
    }
    /*Checks each combination of initial scale and conversion scale, with 1=Fahrenheit, 2=Celsius, and 3=Kelvin*/
    if(initScale == 1 && conversionScale == 2)
    {
        conversionTemp = fahrenheit_to_celsius(userTemp);
        printf("=============\n%f C\n", conversionTemp);
    }
    else if(initScale == 1 && conversionScale == 3)
    {
        conversionTemp = fahrenheit_to_kelvin(userTemp);
        printf("=============\n%f K\n", conversionTemp);
    }
    else if(initScale == 2 && conversionScale == 1)
    {
        conversionTemp = celsius_to_fahrenheit(userTemp);
        printf("=============\n%f F\n", conversionTemp);
    }
    else if(initScale == 2 && conversionScale == 3)
    {
        conversionTemp = celsius_to_kelvin(userTemp);
        printf("=============\n%f K\n", conversionTemp);
    }
    else if(initScale == 3 && conversionScale == 1)
    {
        conversionTemp = kelvin_to_fahrenheit(userTemp);
        printf("=============\n%f F\n", conversionTemp);
    }
    else
    {
        conversionTemp = kelvin_to_celsius(userTemp);
        printf("=============\n%f C\n", conversionTemp);
    }
    /*Runs catagorize_temp, converting the userTemp to celsius if it is in Fahrenheit or Kelvin*/
    if(initScale == 1)
    {
        catagorize_temp(fahrenheit_to_celsius(userTemp));
    }
    else if(initScale == 3)
    {
        catagorize_temp(kelvin_to_celsius(userTemp));
    }
    else
    {
        catagorize_temp(userTemp);
    }
    return 0;
}