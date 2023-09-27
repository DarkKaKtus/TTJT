#include <iostream>
#include <ctime>
using namespace std;

int AgeCalc (int year)
{
    if (year <= 0)
    {
        throw "ERROR: negative value of the birth year!!";
    }

    struct tm *CDate;
    time_t tt = time (NULL);
    CDate = localtime (&tt);

    if (year > (1900 + CDate->tm_year) )
    {
        throw "ERROR: The birth year value is greater than current year value!!";
    }

    return 1900 + CDate->tm_year - year;
}

int main ()
{
    int BYear = 1980;
    int PAge = 0;

    try{
        PAge = AgeCalc(BYear);
    }
    catch (const char * s)
    {
        cout << s << endl<<endl;
    }
    catch(...)
    {
        cout << "Unknown exception" << endl<<endl;
    }


    cout << "For birth year" << BYear << " the age is " << PAge << endl;

    return 0;
}
