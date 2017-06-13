cmake_minimum_required(VERSION 3.7)
project(sources)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES Brain.cpp Brain.h main.cpp Neuron.cpp Neuron.h neurons/NeuronAnd.cpp neurons/NeuronAnd.h neurons/NeuronOr.cpp neurons/NeuronOr.h)

add_executable(sources ${SOURCE_FILES})