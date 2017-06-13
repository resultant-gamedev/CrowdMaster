#include <iostream>
#include "Brain.h"

int main() {
    Brain b(4);

    fuzzySet fa;
    fa[1] = 0.2;
    fa[2] = 0.4;
    b.outputs[0] = fa;

    fuzzySet fb;
    fb[2] = 0.5;
    fb[3] = 1;
    b.outputs[1] = fb;

    uint inputsAnd[] = {0, 1};
    b.newNeuronAnd(2, inputsAnd, 2);

    uint inputsOr[] = {0, 2};
    b.newNeuronOr(3, inputsOr, 2);

    b.evaluate();

    std::cout << b.outputs[0].at(2) << std::endl;
    std::cout << b.outputs[1].at(2) << std::endl;
    std::cout << b.outputs[2].at(2) << std::endl;
    std::cout << b.outputs[3].at(2) << std::endl;
}