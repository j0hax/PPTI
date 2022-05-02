/**
 * @file nutri.cpp
 */
#include "nutri.h"

using Meal = std::tuple<std::string, char, size_t>;

const Meal &getUnhealthier(const Meal &mealA, const Meal &mealB) {
  // Determine if a meal is twice as "bad"
  const int aMult = std::get<1>(mealA) == 'E' ? 2 : 1;
  const int bMult = std::get<1>(mealB) == 'E' ? 2 : 1;

  if (aMult * std::get<2>(mealA) >= bMult * std::get<2>(mealB)) {
    return mealA;
  } else {
    return mealB;
  }
}

void analyzeMeals(std::ostream &os, const std::vector<Meal> &meals) {
  size_t healthyCount = 0;
  Meal unhealthiest = meals.front();

  for (const Meal &meal : meals) {
    char n = std::get<1>(meal);
    if (n == 'A' || n == 'B') {
      healthyCount++;
    } else if (n == 'D' || n == 'E') {
      unhealthiest = getUnhealthier(unhealthiest, meal);
    }
  }

  os << "Von " << meals.size() << " Lebensmitteln waren " << healthyCount
     << " gesund" << std::endl;

  // Analyze unhealthiest meal
  char n = std::get<1>(unhealthiest);
  if (n == 'D' || n == 'E') {
    std::string &name = std::get<0>(unhealthiest);
    size_t &count = std::get<2>(unhealthiest);

    os << "Es sollte lieber auf das Lebensmittel " << name
       << " verzichtet werden, es wurde " << count << " mal verzehrt"
       << std::endl;
  } else {
    os << "Super, es waren keine ungesunden Lebensmittel dabei!" << std::endl;
  }
}