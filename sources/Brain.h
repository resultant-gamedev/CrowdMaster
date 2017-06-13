#ifndef SOURCES_BRAIN_H
#define SOURCES_BRAIN_H

#include <vector>
#include <map>
#include <bits/unique_ptr.h>
#include "Neuron.h"
class Neuron;

//typedef std::pair<int, double> fuzzyElement;
typedef unsigned int uint;
typedef std::map<uint, double> fuzzySet;


class Brain {
public:
    Brain(uint noNeurons);
    ~Brain();
    std::vector<fuzzySet> outputs;
    void evaluate();
    void newNeuronAnd(uint slot, uint inputs[], uint n);
private:
    void addNeuron(Neuron* n);
    std::vector<Neuron*> neurons;
};

#endif //SOURCES_BRAIN_H
