#include "Treatment.h"

using namespace std;

Treatment::Treatment(
    const string& description, 
    const string& date, 
    double cost
)
    : description(description), 
      date(date), 
      cost(cost) 
{
}
