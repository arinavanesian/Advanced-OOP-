// Debug the whole thing
#include <iostream>
using namespace std;

const char lit[] = { 'I', 'V', 'X', 'L', 'C', 'D', 'M'};
const int lim[] = { 5, 2, 5, 2, 5, 2, 3 };
void print(int hist_arr[]);
void norm(int hist_arr[]);
void plus1(int hist_arr[]);
void add(int hist_arr1[], int hist_arr2[]);

int main()
{
int a1[7]{ 4, 1, 4, 1, 4, 1, 1 };
int a2[7]{ };
for (int one = 0; one < 26; one++)
plus1(a2);
add(a1, a2);
print(a1);
}

void print(int hist_arr[])
{
for (int i{ 6 }; i >= 0; i--)
for (int j{}; j < hist_arr[i]; j++)
cout << lit[i];
cout << endl;
}

void norm(int hist_arr[])
{
for (int i{ 0 }; i < 6; i++)
if (hist_arr[i] >= lim[i])
{
hist_arr[i] -= lim[i];
hist_arr[i + 1]++;
}
if (hist_arr[6] > lim[6])
hist_arr[6] = lim[6];
}

void plus1(int hist_arr[])
{
hist_arr[0]++;
norm(hist_arr);
}

void add(int hist_arr1[], int hist_arr2[])
{
for (int i{ 0 }; i < 7; i++)
hist_arr1[i] += hist_arr2[i];
norm(hist_arr1);
}

