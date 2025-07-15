#include <stdio.h>

float calculateBill(int units) {
    float bill = 0;

    if (units <= 50) {
        bill = units * 0.50;
    } else if (units <= 150) {
        bill = (50 * 0.50) + ((units - 50) * 0.75);
    } else if (units <= 250) {
        bill = (50 * 0.50) + (100 * 0.75) + ((units - 150) * 1.20);
    } else {
        bill = (50 * 0.50) + (100 * 0.75) + (100 * 1.20) + ((units - 250) * 1.50);
    }

    // Apply 20% surcharge
    bill += bill * 0.20;
    return bill;
}

int main() {
    int units;
    printf("Enter electricity units consumed: ");
    scanf("%d", &units);

    float totalBill = calculateBill(units);
    printf("Total Electricity Bill: $%.2f\n", totalBill);

    return 0;
}
