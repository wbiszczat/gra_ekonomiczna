//
// Created by jgalecki on 13.11.2020.
// Modified by wbiszczat on 15.12.2023.
//

#pragma once

#include <array>
#include <random>
#include <string>
#include <sstream>

struct RandomIntGenerator{
    static std::mt19937 prng;
};

std::mt19937 RandomIntGenerator::prng = std::mt19937{std::random_device{}()};

constexpr std::array first_names{
    "Ann",
    "Andrew",
    "John",
    "Jane",
    "Bob",
    "Alice",
    "Bertram",
    "Monica",
    "Laura",
    "Eric",
    "Richard",
    "Karen",
    "Clara",
    "Rupert",
    "Bruce",
    "Martha",
    "Elizabeth",
    "Corey",
    "Nancy",
    "Joe",
    "Amy",
    "Mike",
};

constexpr std::array last_names{
    "Hendricks",
    "Smith",
    "Gates",
    "Stein",
    "Warren",
    "Booker",
    "Williamson",
    "Walters",
    "Dunn",
    "Swanson",
    "Knope",
    "Haverford",
    "Ludgate",
    "Meagle",
    "Favreau",
    "Vietor",
    "Lovett",
    "Pfeifer",
    "Rhodes",
    "Abrams",
    "McFaul",
    "Stone",
    "Sisley",
    "Hanneman",
};

constexpr std::array universities{
    "Wydział Administracji i Nauk Społecznych",
    "Wydział Architektury",
    "Wydział Chemiczny",
    "Wydział Elektroniki i Technik Informacyjnych",
    "Wydział Elektryczny",
    "Wydział Fizyki",
    "Wydział Geodezji i Kartografii",
    "Wydział Instalacji Budowlanych, Hydrotechniki i Inżynierii Środowiska",
    "Wydział Inżynierii Chemicznej i Procesowej",
    "Wydział Inżynierii Lądowej",
    "Wydział Inżynierii Materiałowej",
    "Wydział Matematyki i Nauk Informacyjnych",
    "Wydział Mechaniczny Energetyki i Lotnictwa",
    "Wydział Mechaniczny Technologiczny",
    "Wydział Mechatroniki",
    "Wydział Samochodów i Maszyn Roboczych",
    "Wydział Transportu",
    "Wydział Zarządzania",

};

std::string get_random_name(){
    std::uniform_int_distribution<std::size_t> fnd{0, first_names.size() - 1};
    std::uniform_int_distribution<std::size_t> lnd{0, last_names.size() - 1};
    std::stringstream name;
    name << first_names[fnd(RandomIntGenerator::prng)] << ' ' <<
        last_names[lnd(RandomIntGenerator::prng)];
    return name.str();
}

std::string get_alma_mater(){
    std::uniform_int_distribution<std::size_t> und{0, universities.size() - 1};
    std::stringstream alma_mater;
    alma_mater << universities[und(RandomIntGenerator::prng)];
    return alma_mater.str();
}
