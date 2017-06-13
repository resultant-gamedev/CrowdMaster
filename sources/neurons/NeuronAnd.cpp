#include <iostream>
#include "NeuronAnd.h"
#include "../Brain.h"

void NeuronAnd::calcOutput() {
    fuzzySet result;
    bool first = true;
    for (uint i : inputs) {
        fuzzySet fs = brain->outputs[i];
        if (first) {
            for (auto const& e : fs) {
                result[e.first] = e.second;
            }
            first = false;
        } else {
            fuzzySet::iterator iter;
            for (iter = result.begin(); iter != result.end(); ) {
                bool found = false;
                for (auto const& fe : fs) {
                    if (fe.first == iter->first) {
                        iter->second = iter->second * fe.second;
                        found = true;
                        continue;
                    }
                }
                if (!found) {
                    iter = result.erase(iter);
                } else {
                    ++iter;
                }
            }
        }
    }
    brain->outputs[neuronIndex] = result;
}