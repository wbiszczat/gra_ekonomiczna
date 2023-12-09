#pragma once

class Credit
{
public:
    Credit(float credit_value, int number_of_months);

    float payDebt();

    float getLeftDebtValue();

    bool isFinish() {return left_months <= 0;}

    static constexpr float RRSO = 0.2;

    static constexpr float max_debt = 30000;
private:
    int left_months;
    float rata;
};