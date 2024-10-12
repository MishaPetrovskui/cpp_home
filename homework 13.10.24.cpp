#include <iostream>
#include <time.h>

using namespace std;

int randint(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

void displayStatistics(double* sales, int totalMonths) {
    double minSales = sales[0];
    double maxSales = sales[0];
    double totalSales = 0;

    for (int i = 0; i < totalMonths; i++) {
        if (sales[i] < minSales) {
            minSales = sales[i];
        }
        if (sales[i] > maxSales) {
            maxSales = sales[i];
        }
        totalSales += sales[i];
    }

    double sumSales = 0;
    for (int i = 0; i < totalMonths; i++) {
        sumSales += sales[i];
    }
    double avgSales = sumSales / totalMonths;
    cout << "Months: " << totalMonths << endl;
    for (int i = 0; i < totalMonths; i++) {
        cout << sales[i] << "$ ";
    }
    cout << endl;
    cout << "MIN: " << minSales << "$   MAX: " << maxSales << "$   AVG: " << (avgSales) << "$" << endl;
}

int main() {
    srand(time(NULL));
    cout << "Enter the months: ";
    int inputMonths;
    cin >> inputMonths;
    double* sales = new double[inputMonths];

    for (int i = 0; i < inputMonths; i++) {
        sales[i] = randint(1, 500);
    }

    displayStatistics(sales, inputMonths);

    while (true) {
        char choice;
        cout << "Enter 'a' to add or 'q' to quit: ";
        cin >> choice;

        if (choice == 'a' || choice == 'A') {
            inputMonths++;
            for (int i = inputMonths-1; i < inputMonths; i++) {
                sales[i] = randint(1, 500);
            }

            displayStatistics(sales, inputMonths);
        }
        else if (choice == 'q' || choice == 'Q') {
            cout << "Exiting the program." << endl;
            break;
        }
        else {
            cout << "Invalid choice, please try again." << endl;
        }
    }

    delete[] sales;
    return 0;
}
