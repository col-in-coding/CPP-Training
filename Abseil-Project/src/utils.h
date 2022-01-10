

double Factorial(int num)
{
    double result {1};
    for (int i = num; i > 0; i--)
    {
        result *= i;
    }
    return result;
}