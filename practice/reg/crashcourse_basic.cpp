#include <cstdio>
#include <iostream>
using namespace std;

int step_function(int x){
    int account = 0;
    for (size_t i = 0; i < x; i++)
    {
        account +=1;
    }
    return account;
    printf("Account: %d", account);
    
}

int abs_value(int x){
	if( x >= 0) printf("Vallue is positive already! \n");
	else  {
	x*=-1;
	}
	return x;
}

int main(){	
	std:: cout << "Hello World!";
//declaring variable
	int  account;
	account = 47000;
//	print(account);
//	printf(account);

	int x = 10;
	if(x /2 ==0) printf("Modulo 10/2== 0");
	else if(x/2 == 5) printf("Divisible by 2");
	else  printf("Not modulo \n");
    printf("\n");
//format specifiers
	printf("Tend %d, printed!", 10);
    int result = step_function(5);
    printf("Result: %d", result);

//Exercises
	//printf("Calculated the absval of %d", abs_value(-10));
    int user_input;
    std::cout << "Enter an integer: " <<endl;
    std::cin >> user_input;
    std::cout << "Absolute value is: " << abs_value(user_input) << endl;

    return 0;

}


