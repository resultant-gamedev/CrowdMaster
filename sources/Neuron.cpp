#include <iostream>
#include "Neuron.h"

Neuron::Neuron() {}

Neuron::Neuron(Brain* brain, uint neuronIndex) {
    this->brain = brain;
    this->neuronIndex = neuronIndex;
}
