#ifndef SOURCES_NEURONOR_H
#define SOURCES_NEURONOR_H

#include "../Neuron.h"

class NeuronOr : public NeuronMultiInput {
    using Neuron::Neuron;
public:
    NeuronOr(Brain* brain, uint neuronIndex) : NeuronMultiInput(brain, neuronIndex) {};
    virtual void calcOutput();
};

#endif //SOURCES_NEURONOR_H
