#pragma once
#include <iostream> 
#include <stdio.h>
#include <cmath>
#include <math.h>
#include <vector>
#include <random>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

vector<bool> lcg() {
    vector<bool> arr(128);
    
    srand(time(0));

    ofstream out;
    out.open("sequence.txt",'a');
    if (out.is_open()) {
        for (auto i : arr)
        {
            i = (rand() + rand()) % 2;
            cout << i;
            out << i;
        }
    }
    out.close();
    return arr;
}

double frequency_bitwisе_test(vector<int>& arr)
{
    double Sn = 0;
    for (auto i : arr)
    {
        if (i == 1)
        {
            Sn++ ;
        }
        else
        {
            Sn--;
        }
    }
    Sn = ((Sn) / sqrt(128))/sqrt(2);
    double result = erfc(Sn);
   // ofstream out;
    //out.open("sequence.txt", 'a');
    //if (out.is_open()) { out << result; }
    return result;
}
double test_2(const vector<int> &arr)
{
    double s=0;
    for (auto i : arr)
    {
        s += i;
    }
    s = s / 128;
    if (abs(s - 0.5) < (2 / sqrt(128)))
    {
        int v = 0;
        for (int i = 0; i < arr.size() - 1; ++i) {
            if (arr[i] != arr[i + 1]) ++v;
        }
        double chisl = abs(v - 2 * arr.size() * s * (1 - s));
        double znam = 2 * sqrt(2 * arr.size()) * s * (1 - s);
        chisl = chisl / znam;
        return erfc(chisl);
    }
    else { return 0; }

}
int max_length_of_units(const vector<int> &array)
{
    int result = 0, temp=0;
    for (int j = 0; j < array.size()-1; j++)
    {
        if (array[j] == array[j + 1])temp++;
        else temp = 0;
        if (temp > result) result = temp;
    }
    return result;
}
void filling_the_array(const vector<vector<int>>& matrix, int* array_of_counters)
{
   
    for (int i = 0; i < matrix.size(); i++)
    {
        if (max_length_of_units(matrix[i]) <= 1)    array_of_counters[0]++;
        if (max_length_of_units(matrix[i]) == 2)    array_of_counters[1]++;
        if (max_length_of_units(matrix[i]) == 3)    array_of_counters[2]++;
        if (max_length_of_units(matrix[i]) >= 4)    array_of_counters[3]++;
    }
   
}
double test_3(const vector<int> &arr)

{   
    int count=0;
    vector<vector<int>> matrix;
    vector<int> row_in_the_matrix;
    for (auto i : arr)// Заполнение вектора или массива 
    {      
       
        row_in_the_matrix.push_back(i);
        count++;
        if (count == 8)
        {
            count = 0;
            matrix.push_back(row_in_the_matrix);
            row_in_the_matrix.clear();
        }
        //cout << i;
    }
    // вывод для наглядности разделения     
    /*for (int k = 0; k < matrix.size(); k++)
    {
        for (int j = 0; j < matrix[k].size(); j++)
        {
            cout << matrix[k][j];
        }
        cout << "\n";
    }*/
    double constants[] = {0.2148,0.3672,0.2305,0.1875};
    int array_of_counters[] = {0,0,0,0};
    filling_the_array(matrix, array_of_counters);
    cout << "\nзаполненныый массив \n";
    double result = 0;
    for (int i = 0; i < 4; i++)
    {
        /*cout << array_of_counters[i];*/
        result += (pow((array_of_counters[i] - 16 * constants[i]), 2) / (16 * constants[i]));
        cout << result;
    }
    //result = igamc(1.5, result / 2);
    return result;
}
