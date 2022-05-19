#include "calculator.h"

/**
 * Print Calculator to a stream.
 */
std::ostream& operator<<(std::ostream& os, const Calculator& calc)
{
    calc.print(os);
    return os;
}


CalculatorPrinter::CalculatorPrinter(const Calculator& calc, Calculator::TraversalType t) :
    calculator(&calc), type(t)
{}

std::ostream& operator<<(std::ostream& os, const CalculatorPrinter& cp)
{
    cp.calculator->print(os, cp.type);
    return os;
}


LeafCalculator::LeafCalculator(size_t i) : idx(i) {}

bool LeafCalculator::calculate(const std::vector<bool>& input) const
{
    return input[this->idx];
}

void LeafCalculator::print(std::ostream& os, TraversalType) const
{
    os << this->idx;
}


UnaryCalculator::UnaryCalculator(std::unique_ptr<Calculator> in, std::string opSymbol) :
    inner(std::move(in)), op(std::move(opSymbol))
{}

bool UnaryCalculator::calculate(const std::vector<bool>& input) const
{
    return this->operate(this->inner->calculate(input));
}

void UnaryCalculator::print(std::ostream& os, TraversalType type) const
{
    // TODO: Print according to given TraversalType.
}

NotCalculator::NotCalculator(std::unique_ptr<Calculator> inner) :
    UnaryCalculator(std::move(inner), "~")
{}

// TODO: Implement missing overrides of NotCalculator here


// TODO: Implement members of classes for handling AND and OR


