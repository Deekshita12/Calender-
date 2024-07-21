#include <stdio.h>

// Function to determine if a year is a leap year
int isLeapYear(int year) {
    if (year % 400 == 0) return 1;
    if (year % 100 == 0) return 0;
    if (year % 4 == 0) return 1;
    return 0;
}

// Function to determine the number of days in a month
int getDaysInMonth(int month, int year) {
    switch (month) {
        case 1: return 31; // January
        case 2: return isLeapYear(year) ? 29 : 28; // February
        case 3: return 31; // March
        case 4: return 30; // April
        case 5: return 31; // May
        case 6: return 30; // June
        case 7: return 31; // July
        case 8: return 31; // August
        case 9: return 30; // September
        case 10: return 31; // October
        case 11: return 30; // November
        case 12: return 31; // December
        default: return 0;
    }
}

// Function to determine the day of the week for the first day of a month
int getFirstDayOfMonth(int month, int year) {
    int day = 1; // Assuming the first day of the month
    int y = year - (14 - month) / 12;
    int m = month + 12 * ((14 - month) / 12) - 2;
    return (day + y + y/4 - y/100 + y/400 + (31*m)/12) % 7;
}

// Function to print the calendar for a given month and year
void printCalendar(int month, int year) {
    char *months[] = {"January", "February", "March", "April", "May", "June",
                      "July", "August", "September", "October", "November", "December"};
    int daysInMonth = getDaysInMonth(month, year);
    int firstDay = getFirstDayOfMonth(month, year);

    printf("\n  %s %d\n", months[month-1], year);
    printf("  Su  Mo  Tu  We  Th  Fr  Sa\n");

    for (int i = 0; i < firstDay; i++) {
        printf("    ");
    }

    for (int day = 1; day <= daysInMonth; day++) {
        printf("%4d", day);
        if ((day + firstDay) % 7 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

int main() {
    int month, year;

    printf("Enter month (1-12): ");
    scanf("%d", &month);
    printf("Enter year: ");
    scanf("%d", &year);

    if (month < 1 || month > 12 || year < 1) {
        printf("Invalid month or year. Please enter a valid month (1-12) and year.\n");
    } else {
        printCalendar(month, year);
    }

    return 0;
}
