#include <iostream>
#include "Brain.h"

int main() {
    Brain b(3);

    fuzzySet fa;
    fa[1] = 0.2;
    fa[2] = 0.4;
    b.outputs[0] = fa;

    fuzzySet fb;
    fb[2] = 0.5;
    fb[3] = 1;
    b.outputs[1] = fb;

    uint input[] = {0, 1};
    b.newNeuronAnd(2, input, 2);

    b.evaluate();

    std::cout << b.outputs[2].begin()->first << ", " << b.outputs[2].begin()->second << std::endl;
}