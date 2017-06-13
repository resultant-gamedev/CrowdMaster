#ifndef SOURCES_NEURON_H
#define SOURCES_NEURON_H

#include <set>
#include "Brain.h"

class Brain;

class Neuron {
public:
    Neuron();
    Neuron(Brain* brain, uint neuronIndex);
    virtual void calcOutput()= 0;
    Brain* brain;
    uint neuronIndex;
};

class NeuronSingleInput : public Neuron {
public:
    NeuronSingleInput(Brain* brain, uint neuronIndex) : Neuron(brain, neuronIndex) {};
    uint input;
};

class NeuronMultiInput : public Neuron {
public:
    NeuronMultiInput(Brain* brain, uint neuronIndex) : Neuron(brain, neuronIndex) {};
    std::vector<uint> inputs;
};

#endif //SOURCES_NEURON_H
