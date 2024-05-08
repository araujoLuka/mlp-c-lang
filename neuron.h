// HEADER FILE
// Neuron structure and functions to manage the neuron

/* Author: Lucas C. Araujo
 * Date: 2024-05-06
 * Version: 1.0
 */

#ifndef __NEURON_H__
#define __NEURON_H__

typedef struct Neuron {
    float* weights;
    float bias;
    float delta;
} neuron_t;

// Compute the output of the neuron based on the inputs
float neuron_output(neuron_t* neuron, float* inputs, int n_inputs);

#endif
