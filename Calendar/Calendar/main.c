//
//  main.c
//  Calendar
//
//  Created by KH HSU on 2022/7/9.
//

#include <stdio.h>
#include <stdbool.h>

#define MAX_LEN 100
#define NUM_DAY 7

int u32_Day_In_Month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int u32_Day_In_Leap_Month[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char u8_Week[MAX_LEN][NUM_DAY] = {{"Sun"}, {"Mon"}, {"Tue"}, {"Wed"}, {"Thu"}, {"Fri"}, {"Sat"}};

// Find Leap Year //
bool bLeapYear(int year)
{
    if((year%4) != 0)
    {
        return false;
    }
    else if(((year%4) == 0) && (year%100) != 0)
    {
        return true;
    }
    else if(((year%100) == 0) && ((year%400) != 0))
    {
        return false;
    }
    else if((year%400) == 0)
    {
        return true;
    }
    printf("other condition");
    return false;
}

// Calculate how many day from 1900/01/01 to today //
int LwCalculate_day(int year, int month)
{
    int u32_Total_Day = 0;
    for(int i = 1900; i < year; i++)
    {
        if(bLeapYear(i))
        {
            u32_Total_Day += 366;
        }
        else
        {
            u32_Total_Day += 365;
        }
    }
    
    for(int j = 0; j < month; j++)
    {
        if(bLeapYear(year))
        {
            u32_Total_Day += u32_Day_In_Leap_Month[j-1];
        }
        else
        {
            u32_Total_Day += u32_Day_In_Month[j-1];
        }
    }
    return u32_Total_Day;
}

// Draw calendar frame //
void vCalendar_Frame(void)
{
    for(int i = 0; i < 14; i++)
    {
        printf(" ");
    }
    printf("Calendar\n");
    for(int j=0; j < 35; j++)
    {
        printf("-");
    }
    printf("\n");
    for (int l = 0; l < NUM_DAY; l++)
    {
        printf(" ");
        printf("%s", u8_Week[l]);
        printf(" ");
    }
}

// Build calendar //
void vCalendar_Building(int u32_Total_Day, bool bLeapYear, int u32_month)
{
    int u32_Week_Day = u32_Total_Day%7+1; // starts from 1900 1/1 which is Mon
    int u32_Day_In_One_Month;
    if(bLeapYear)
    {
        u32_Day_In_One_Month = u32_Day_In_Leap_Month[u32_month-1];
    }
    else
    {
        u32_Day_In_One_Month = u32_Day_In_Month[u32_month-1];
    }

    for(int i = 0; i < (2+(u32_Week_Day*5)); i++)
    {
        printf(" ");
    }
    for(int j = 1; j <= u32_Day_In_One_Month; j++)
    {
        printf("%d", j);
        if(j < 10)
        {
            for(int k = 0; k < 4; k++)
            {
                printf(" ");
            }
        }
        else
        {
            for(int l = 0; l < 3; l++)
            {
                printf(" ");
            }
        }
        
        if((u32_Week_Day+(j%7)) == 7)
        {
            printf("\n");
            for(int k = 0; k < 2; k++)
            {
                printf(" ");
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    int year, month;
    printf("Input year and month, and calendar will show up:");
    scanf("%d %d", &year, &month);
    if((year<1900) || (month<1) || (month>12))
    {
        printf("Input Out of Range\n");
        return 0;
    }
    vCalendar_Frame();
    printf("\n");
    vCalendar_Building(LwCalculate_day(year, month), bLeapYear(year), month);
    printf("\n");
    return 0;
}
