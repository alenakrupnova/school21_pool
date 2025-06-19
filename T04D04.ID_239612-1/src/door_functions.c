#include <math.h>
#include <stdio.h>

double agnesi(double x);
double lemniscata(double x);
double gip(double x);

int main() {
    FILE *fp;
    fp = fopen("data/door_data.txt", "w");
    double x;
    for (int i = 0; i < 42; i++) {
        x = -M_PI + M_PI * i / 21;
        double agn = agnesi(x);
        double lemn = lemniscata(x);
        double giperb = gip(x);
        fprintf(fp, "%.7f |", x);
        fprintf(fp, " %.7f |", agn);
        if (lemn == 1 || x == 0) {
            fprintf(fp, " - |");
        } else {
            fprintf(fp, " %.7f |", giperb);
        }

        if (giperb == 1 || giperb == INFINITY) {
            fprintf(fp, " -\n");
        } else {
            fprintf(fp, " %.7f\n", giperb);
        }
    }
    fclose(fp);
    return 0;
}

double agnesi(double x) { return 1.0 / (1 + pow(x, 2)); }

double lemniscata(double x) {
    double res = sqrt(sqrt(1.0 + 4 * pow(x, 2)) - pow(x, 2) - 1);
    if (isnan(res)) {
        return 1;
    }
    return res;
}

double gip(double x) {
    double res = 1.0 / pow(x, 2);
    if (isnan(res)) {
        return 1;
    }
    return res;
}