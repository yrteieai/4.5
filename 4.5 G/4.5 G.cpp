#include <iostream>
#include <iomanip>   
#include <cmath>   

using namespace std;

int main() {
    double x, y;
    double R1, R2;
    double distance;

    cout << "R1: ";
    cin >> R1;
    cout << "R2: ";
    cin >> R2;

    if (R1 <= 0 || R2 <= 0 || R1 >= R2) {
        cout << "Error: R1 must be positive and less than R2" << endl;
        return 1;  // завершення програми 
    }


    // перевірка перших 10 точок введених вручну
    for (int i = 0; i < 10; i++) {
        cout << " x = ";
        cin >> x;
        cout << " y = ";

        cin >> y;
        distance = sqrt(x * x + y * y);

        // Перевірка попадання в кільце
        if (distance >= R1 && distance <= R2) {
            if ((x <= 0 && y <= 0) || (x >= 0 && y >= 0)) {
                cout << "yes" << endl;
            }
            else {
                cout << "no" << endl;
            }
        }
        else {
            cout << "no" << endl;
        }
    }

    cout << endl << fixed;

    // випадкова генерація 10 точок в межах [-R1, R1]
    for (int i = 0; i < 10; i++) {
        x = 2.0 * R1 * rand() / RAND_MAX - R1;
        y = 2.0 * R1 * rand() / RAND_MAX - R1;

        distance = sqrt(x * x + y * y);

        // перевірка попадання в сіру зону
        if (distance >= R1 && distance <= R2) {
            if ((x <= 0 && y <= 0) || (x >= 0 && y >= 0)) {
                cout << setw(8) << setprecision(4) << x << " "
                    << setw(8) << setprecision(4) << y << " " << "yes" << endl;
            }
            else {
                cout << setw(8) << setprecision(4) << x << " "
                    << setw(8) << setprecision(4) << y << " " << "no" << endl;
            }
        }
        else {
            cout << setw(8) << setprecision(4) << x << " "
                << setw(8) << setprecision(4) << y << " " << "no" << endl;
        }
    }

    return 0;
}
