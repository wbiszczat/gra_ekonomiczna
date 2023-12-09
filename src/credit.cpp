#include "credit.hpp"

Credit::Credit(float credit_value, int number_of_months)
    : left_months{number_of_months}
      
{
    rata  = (credit_value * (1.0 + RRSO * number_of_months/ 12.0)) / number_of_months;
}

float Credit::payDebt()
{
    if(left_months == 0)
    {
        return 0.0f;
    }
    left_months--;
    return rata;
}

float Credit::getLeftDebtValue()
{
    return rata * left_months;
}
