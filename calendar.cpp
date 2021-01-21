#include <iostream>
#include <stdio.h>

using namespace std;

//declare a function that will print months of a year
void printYear(int year);

//declare a function that will print a month of a year
void printMonth(int y, int m);

//declare a function that will identify what weekday January starts from
int firstDayOfJanuary(int year);

//check if a year is a leap year
int leapYear(int year);

//The number of leap year
int leapYears(int year);

//The number of days since the beginning of the year
int todayOf(int y, int m, int d);

//Total number of days
long daysTotal(int y, int m, int d);

int main(void)
{
    char userResponse;
    cout << "Enter 'm' for a month calendar, enter 'y' for a year calendar" << endl;
    cin >> userResponse;

    if (userResponse == 'y')
    {
        //prompt
        int year;
        cout << "Enter year: " << endl;
        cin >> year;

        //prints a calendar of a given year
        printYear(year);
    }
    else if (userResponse == 'm')
    {

        int year, month;

        printf("Enter the month and year: ");
        scanf("%d %d", &month, &year);

        printMonth(year, month);
    }
    else
    {
        cout << "Invalid input" << endl;
    }

    return 0;
}

void printYear(int year)
{

    int day;
    int weekDay = 0;
    int startDay;

    string months[] = {"JANUARY", "FEBRUARY", "MARCH", "APRIL", "MAY", "JUNE",
                       "JULY", "AUGUST", "SEPTEMBER", "OCTOBER", "NOVEMBER", "DECEMBER"};
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    //check if a year is a leap year

    if (leapYear(year))
    {
        days[1] = 29;
    }
    // if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
    // {
    //     days[1] = 29;
    // }

    //determine what day January starts from
    startDay = firstDayOfJanuary(year);

    //loop for printing months
    for (int i = 0; i < 12; i++)
    {
        cout << endl;
        cout << months[i] << " " << year << endl;

        printf("\n  S  M Tu  W Th  F  S \n");

        //shift days so that they align with weekdays
        for (weekDay = 0; weekDay < startDay; weekDay++)
        {
            cout << "   ";
        }

        //loop for printing days in months
        for (int j = 1; j <= days[i]; j++)
        {
            printf("%3d", j);

            weekDay++;
            //make a new line after all of the weekdays are printer
            if (weekDay > 6)
            {
                printf("\n");
                weekDay = 0;
            }
        }
        cout << endl;
        cout << endl;

        startDay = weekDay;
    }
}

void printMonth(int y, int m)
{

    const char *months[] = {NULL, "JANUARY", "FEBRUARY", "MARCH", "APRIL", "MAY", "JUNE",
                            "JULY", "AUGUST", "SEPTEMBER", "OCTOBER", "NOVEMBER", "DECEMBER"};
    char Week[] = " S  M Tu  W Th  F  S ";
    int days[] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int weekOfTopDay;
    int i, day;

    weekOfTopDay = daysTotal(y, m, 1) % 7;

    //check if year is a leap year, if so change num of days of february
    if (leapYear(y))
    {
        days[2] = 29;
    }

    cout << months[m] << " " << y << endl;
    cout << endl;
    cout << Week << endl;

    //shift days so that they align with weekdays
    for (i = 0; i < weekOfTopDay; i++)
    {
        printf("   ");
    }

    //loop through the days
    for (i = weekOfTopDay, day = 1; day <= days[m]; i++, day++)
    {
        printf("%2d ", day);

        //make a new line after all of the weekdays are printer
        if (i % 7 == 6)
        {
            printf("\n");
        }
    }

    printf("\n");
}

//Identifying the day of the week January starts from, Sunday is 0 and Saturday is 6
int firstDayOfJanuary(int year)
{
    int day;
    day = (((year - 1) * 365) + ((year - 1) / 4) - ((year - 1) / 100) + ((year) / 400) + 1) % 7;
    return day;
}

//check if a year is a leap year
int leapYear(int y)
{
    return (y % 4 == 0 && y % 100 != 0 || y % 400 == 0);
}

//The number of leap year
int leapYears(int y)
{
    return y / 4 - y / 100 + y / 400;
}

//The number of days since the beginning of the year
int todayOf(int y, int m, int d)
{
    static int days[] =
        {-1, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};

    return days[m] + d + ((m > 2 && leapYear(y)) ? 1 : 0);
}

//Total number of days
long daysTotal(int y, int m, int d)
{
    int lastYear;

    lastYear = y - 1;

    return 365L * lastYear + leapYears(lastYear) + todayOf(y, m, d);
}
