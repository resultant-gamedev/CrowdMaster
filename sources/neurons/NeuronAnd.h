#ifndef SOURCES_NEURONAND_H
#define SOURCES_NEURONAND_H

#include "../Neuron.h"

class NeuronAnd : public NeuronMultiInput {
    using Neuron::Neuron;
public:
    NeuronAnd(Brain* brain, uint neuronIndex) : NeuronMultiInput(brain, neuronIndex) {};
    virtual void calcOutput();
};

#endif //SOURCES_NEURONAND_H
