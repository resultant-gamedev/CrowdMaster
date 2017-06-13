#include <iostream>
#include "Brain.h"
#include "neurons/NeuronAnd.h"

Brain::Brain(uint noNeurons) {
    outputs.resize(noNeurons);
}

Brain::~Brain() {
    for (auto itr = neurons.begin(); itr != neurons.end(); ++itr) {
        (*itr)->calcOutput();
    }
}

void Brain::addNeuron(Neuron* n) {
    neurons.push_back(n);
}

void Brain::evaluate() {
    for (auto itr = neurons.begin(); itr != neurons.end(); ++itr) {
        (*itr)->calcOutput();
    }
}

void Brain::newNeuronAnd(uint slot, uint *inputs, uint n) {
    NeuronAnd* np = new NeuronAnd(this, slot);
    for (int i=0; i<n; i++) {
        np->inputs.push_back(*inputs);
        inputs++;
    }
    addNeuron(np);
}
