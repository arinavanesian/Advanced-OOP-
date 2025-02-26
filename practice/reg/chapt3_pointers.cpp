#include <iostream>
#include <cstdio>
using namespace std;

struct ClockOfTheLongNow {
    void add_year() {
        year++; } 
    bool set_year(int new_year) {
    if (new_year < 2019) return false;
     year = new_year; return true; }  
     int get_year() {
        return year; }  
    private: 
        int year; }; 

struct College
{
    char name[256];

};


void print_Colname(College* col_ptr){
    printf("%s College \n", col_ptr->name);
}

void print_Colname_(College* col_ptr, size_t n_col){
    for (size_t i = 0; i < n_col; i++)
    {
        printf("%s College\t", col_ptr[i].name);
    }
    cout<<"\n"<<endl;
}
int main(int argc, char const *argv[])  
{
    // int *p;
    // printf("Pointer Address: %p", p); //0x7fffffffdae8
    // printf("Pointer Value: %d\n", *p); //2
    // printf("Pointer Value: %d\n", &p); //-9808

    // int gettysburg{};
    // printf("gettysburg: %d\n", gettysburg);
    // int *gettysburg_address = &gettysburg;
    // printf("&gettysburg: %p\n", gettysburg_address);// 0x7fffffffd9a4
    // printf("&gettysburg: %p\n", *gettysburg_address);// nil
    // *gettysburg_address = 17325;
    // printf("gettysburg = %d",*gettysburg_address);

    ClockOfTheLongNow clock; 
    ClockOfTheLongNow* clock_ptr = &clock;
    clock_ptr->set_year(2020); 
    printf("Address of clock: %p\n", clock_ptr);  
    printf("Value of clock's year: %d\n", clock_ptr->get_year());
    printf("Value of clock's year: %d\n", (*clock_ptr).get_year());
// Pointers with Arrays

int arr[]{54,3, 6};
int* arr_ptr = arr;
cout<<*arr_ptr<<endl; //54 
cout<<&arr_ptr<<endl; //0x7fffffffd998
cout<<arr<<endl; //0x7fffffffd9ac
cout<<*arr<<endl; //54

    College aua[]{"Akian", "Public Health"};
    print_Colname(aua);
    cout<<"\n Printing the whole array using the name sizeof\n"<<endl;
    print_Colname_(aua, sizeof(aua)/sizeof(College)); //aua, 2

    cout<< sizeof(College)<< endl; //256
    // TODO:
    cout<< sizeof(aua)<< endl; //512

    College *ysu = &aua[1];
    cout << ysu->name<<endl; //Public Health
    cout << (*ysu).name<<endl; //Public Health
    return 0;
}
