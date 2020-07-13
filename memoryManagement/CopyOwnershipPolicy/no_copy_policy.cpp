class NoCopyClass1
{
private:
    int *_myInt;
    // to prevent the resource copying out that may be freed in distruction
    NoCopyClass1(const NoCopyClass1 &);
    NoCopyClass1 &operator=(const NoCopyClass1 &);

public:
    NoCopyClass1() {
        _myInt = (int *)malloc(sizeof(int));
    };
    ~NoCopyClass1() {
        free(_myInt);
    }
};

class NoCopyClass2
{
public:
    NoCopyClass2(){}
    NoCopyClass2(const NoCopyClass2 &) = delete; // deleted function
    NoCopyClass2 &operator=(const NoCopyClass2 &) = delete;
};


int main()
{
    NoCopyClass1 original1;
    NoCopyClass1 copy1a(original1); // copy c’tor
    NoCopyClass1 copy1b = original1; // assigment operator

    NoCopyClass2 original2;
    NoCopyClass2 copy2a(original2); // copy c’tor
    NoCopyClass2 copy2b = original2; // assigment operator

    return 0;
}