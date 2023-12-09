#include "company.hpp"
#include <iostream>

Company::Company():
    number_of_employees{0}, employees{new Employee*[MAX_EMPLOYEES]}
{
    for (int i = 0; i < MAX_EMPLOYEES; i++)
    {
        employees[i] = nullptr;
    }
    
}

Company::~Company()
{
    for (int i = 0; i < number_of_employees; i++)
    {
        delete employees[i];
    }
}

void Company::list_employee()
{
    std::cout << "Lista pracowników firmy:" << std::endl;
    for (int i = 0; i < number_of_employees; i++)
    {
        std::cout << i+1 << ": ";
        employees[i]->print();
    }
    
}

void Company::hire(std::unique_ptr<Employee>&& e)
{
    employees[number_of_employees++] = e.release();
}

void Company::take_credit(double debt_size, int return_time_in_months)
{
    float sum_of_debt = 0.0f;
    for (auto& c: credits)
    {
        sum_of_debt += c.getLeftDebtValue();
    }

    if(sum_of_debt + debt_size > Credit::max_debt)
    {
        std::cout << "Suma kredytów (" << sum_of_debt << " + " << debt_size <<
         ") przekroczyłaby dozwolony limit (" << Credit::max_debt << ")" << std::endl;
        return;
    }
    credits.push_back(Credit(debt_size,return_time_in_months));
    money += debt_size;
    std::cout << "Uzyskano kredyt w wysokości " << debt_size << " PLN" << std::endl;
}

void Company::calc()
{
    std::cout << "Zamykam miesiąc" << std::endl;

    int number_of_enginners = 0;
    int number_of_marketers = 0;
    int number_of_warehousemans = 0;
    int number_of_workers = 0;

    for (int i = 0; i < number_of_employees; i++)
    {
        if(dynamic_cast<Engineer*>(employees[i]) != nullptr)
        {
            number_of_enginners++;
            continue;
        }
        if(dynamic_cast<Marketer*>(employees[i]) != nullptr)
        {
            number_of_marketers++;
            continue;
        }
        if(dynamic_cast<Warehouseman*>(employees[i]) != nullptr)
        {
            number_of_warehousemans++;
            continue;
        }
        if(dynamic_cast<Worker*>(employees[i]) != nullptr)
        {
            number_of_workers++;
            continue;
        }
    }


    std::cout << "Liczba inżynierów: " << number_of_enginners << std::endl;
    std::cout << "Liczba marketingowców: " << number_of_marketers << std::endl;
    std::cout << "Liczba magazynierów: " << number_of_warehousemans << std::endl;
    std::cout << "Liczba robotników: " << number_of_workers << std::endl;

    float WarehouseCapacity;
    WarehouseCapacity = number_of_warehousemans * Warehouseman::CMag;

    float Price;
    Price = number_of_enginners * Engineer::CI;

    //Demand = Popyt
    float Demand;
    Demand = number_of_marketers * Marketer::CMkt;

    //TheoreticalSalesAllowed = teoretyczna możliwa ilość produktów do wytworzenia
    int TheoreticalSalesAllowed;
    TheoreticalSalesAllowed = number_of_workers * Worker::CR;

    //RealSalesAllowed = faktyczna możliwa ilość produktów do wytworzenia
    int RealSalesAllowed = TheoreticalSalesAllowed;

    if (RealSalesAllowed > WarehouseCapacity)
    {
        RealSalesAllowed = WarehouseCapacity;
    }
    
    //ProductsSold = ilość sprzedanych produnktów
    int ProductSold = RealSalesAllowed;

    if (ProductSold > Demand)
    {
        ProductSold = Demand;
    }
    
    //Obliczanie przychodu firmy.
    float Revenue = RealSalesAllowed * Price;    

    //Payouts = wyplaty
    float Payouts = 0.0f;

    for (int i = 0; i < number_of_employees; i++)
    {
        Payouts += employees[i]->get_payment();
    }

    float sum_of_credits = 0.0;
    for (auto& c: credits)
    {
        sum_of_credits += c.payDebt();
    }
    credits.erase(std::remove_if(credits.begin(), 
                                 credits.end(),
                                 [](Credit& c) { return c.isFinish(); }),
                                 credits.end());

    // Obliczanie dochodu firmy.
    float Income = Revenue - Payouts - sum_of_credits;

    money += Income;

    float average_company_value = get_average_company_value(money);

    std::cout << "Gotówka w firmie: " << money << " PLN" << std::endl;
    std::cout << "Wartość firmy w ostatnich " << N << " miesiącach: " << average_company_value << " PLN" << std::endl;
}
//Obliczanie wartości spółki. Jedna runda jest traktowana jako jeden miesiąc istnienia firmy.
float Company::get_average_company_value(float company_value)
{
    company_value_history[company_value_history_iter] = company_value;
    company_value_history_iter = (company_value_history_iter + 1) % N;
    float value = 0.0f;
    for (int i = 0; i < N; i++)
    {
        value += company_value_history[i];
    }
    
    return value / N;
}


