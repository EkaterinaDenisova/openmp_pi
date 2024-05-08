// author: �������� ���������

#include "PiCircle.h"

// ������� ��� ���������� �������� pi, ��������� ���������� OpenMP
double count_pi_parallel(const int num_points) {

    int num_inside = 0;
    //double x, y;

    // parallel - ��������� ���, ������� ����� ����������� ����������� ����������� ��������
    // for - ����������������� �����
    // reduction(+:sum) - ����� + ��� ��������, sum - ����� ����������, ��������� ��������� ������� �������� ��� ������� ������
    // reduction ������ ��������, ��������� � ���������������� ������������
#pragma omp parallel for reduction(+:num_inside)
    for (int i = 0; i < num_points; ++i) {
        double x = (double)rand() / RAND_MAX;
        double y = (double)rand() / RAND_MAX;

        //cout << x << " " << y << endl;

        if (x * x + y * y <= 1) {
            num_inside++;
        }
    }

    double pi = 4.0 * ((double)num_inside / num_points);
    return pi;
}

// ������� ��� ���������� �������� pi � ����� ������
double count_pi(const int num_points) {

    int num_inside = 0;
    double x, y;

    for (int i = 0; i < num_points; ++i) {
        x = (double)rand() / RAND_MAX;
        y = (double)rand() / RAND_MAX;

        //cout << x << " " << y << endl;

        if (x * x + y * y <= 1) {
            num_inside++;
        }
    }

    double pi = 4.0 * ((double)num_inside / num_points);
    return pi;
}