#include <iostream>
#include <string>
#include <vector>
#include <random>

using namespace std;

int pow_of_10(const int& exp);
vector<char> int2vector(int num, int length);
int traverse(vector<char>& target, vector<char>& guess);
int evaluate(vector<char> target, int guess_int);

int main()
{
    int num_of_digits, random_target, next_guess, score = -1;
    cout << "Enter the number of digits: ";
    cin >> num_of_digits;
    const int MAX_SCORE = num_of_digits * 10;

    random_device generator;
    uniform_int_distribution<int> dist(0, pow_of_10(num_of_digits) - 1);
    random_target = dist(generator);
    vector<char> secret_target = int2vector(random_target, num_of_digits);

    while (score != MAX_SCORE)
    {
        cin >> next_guess;
        score = evaluate(secret_target, next_guess);
        cout << "Score for " << next_guess << " is\t" << score << endl;
    } 
}

int pow_of_10(const int & exp)
{
    if (exp == 1)
        return 10;

    int semi_result = pow_of_10(exp >> 1);
    semi_result *= semi_result;
    
    if ((exp & 1) == 1)
        semi_result *= 10;

    return semi_result;
}

vector<char> int2vector(int num, int num_length)
{
    vector<char> result;
    for (; num_length > 0; num_length--, num /= 10)
        result.insert(result.begin(), static_cast<char>(num % 10));

    return result;
}

int traverse(vector<char>& target, vector<char>& guess)
{
    int result = 0;
    auto target_digit = target.begin(), guess_digit = guess.begin();
    
    while (target_digit != target.end())
    {
        if (*target_digit == *guess_digit)
        {
            result++;
            target_digit = target.erase(target_digit);
            guess_digit = guess.erase(guess_digit);
        }
        else
        {
            ++target_digit;
            ++guess_digit;
        }
    }

    return result;
}

int evaluate(vector<char> target, int guess_int)
{
    int traversals = target.size() - 1;
    vector<char> guess = int2vector(guess_int, traversals + 1);

    int result = 10 * traverse(target, guess);
    for (; !guess.empty() && traversals > 0; traversals--)
    {
        guess.insert(guess.begin(), guess.back());
        guess.pop_back();
        result += traverse(target, guess);
    }
        
    return result;
}