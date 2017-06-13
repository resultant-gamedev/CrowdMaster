#include "NeuronOr.h"

void NeuronOr::calcOutput() {
    fuzzySet result;
    bool first = true;
    for (uint i : inputs) {
        fuzzySet fs = brain->outputs[i];
        if (first) {
            for (auto const& e : fs) {
                result[e.first] = 1 - e.second;
            }
            first = false;
        } else {
            fuzzySet::iterator iter;
            for (iter = result.begin(); iter != result.end(); ) {
                bool found = false;
                for (auto const& fe : fs) {
                    if (fe.first == iter->first) {
                        iter->second = iter->second * (1 - fe.second);
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
    for (auto& x : result) {
        x.second = 1 - x.second;
    }
    brain->outputs[neuronIndex] = result;
}