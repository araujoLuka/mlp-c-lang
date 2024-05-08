// Implementation of neuron.h

/* Author: Lucas C. Araujo
 * Date: 2024-05-06
 * Version: 1.0
 */

#include "neuron.h"

#include <stdio.h>
#include <stdlib.h>

// Private functions
neuron_t* neuron_alloc(int n_inputs);
void neuron_init(neuron_t* neuron, int n_inputs);

/* Creates a neuron with n_inputs inputs
 * @param n_inputs: number of inputs
 * @return: pointer to the created neuron
 */
neuron_t* neuron_create(int n_inputs) {
    neuron_t* neuron = neuron_alloc(n_inputs);
    if (neuron == NULL) 
        return NULL;
    neuron_init(neuron, n_inputs);

    return neuron;
}

/* Computes the output of a neuron
 * @param neuron: pointer to the neuron
 * @param inputs: array with the inputs
 * @param activation: pointer to the activation function
 * @return: output of the neuron
 */
float neuron_output(neuron_t* neuron, float* inputs,
                    float (*activation)(float)) {
    float output = neuron->bias;
    for (int i = 0; i < neuron->n_inputs; ++i)
        output += neuron->weights[i] * inputs[i];
    return activation(output);
}

/* Frees the memory allocated for a neuron
 * @param neuron: pointer to the neuron to be destroyed
 */
void neuron_destroy(neuron_t* neuron) {
    free(neuron->weights);
    neuron->weights = NULL;
    free(neuron);
    neuron = NULL;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Private functions implementation
 */

/* Allocates memory for a neuron and its weights
 * @param n_inputs: number of inputs
 * @return: pointer to the allocated neuron
 */
neuron_t* neuron_alloc(int n_inputs) {
    if (n_inputs < 0) {
        fprintf(stderr, "Error: invalid number of inputs\n");
        return NULL;
    }

    neuron_t* neuron = (neuron_t*)malloc(sizeof(neuron_t));
    if (neuron == NULL) {
        fprintf(stderr, "Error: failed to allocate memory for neuron\n");
        return NULL;
    }

    neuron->weights = (float*)malloc(n_inputs * sizeof(float));
    if (neuron->weights == NULL) {
        fprintf(stderr, "Error: failed to allocate memory for weights\n");
        free(neuron);
        return NULL;
    }

    return neuron;
}

/* Initializes a neuron with default values
 * @param neuron: pointer to the neuron to be initialized
 * @param n_inputs: number of inputs
 */
void neuron_init(neuron_t* neuron, int n_inputs) {
    neuron->n_inputs = n_inputs;
    neuron->bias = 1.f;
    for (int i = 0; i < neuron->n_inputs; ++i) neuron->weights[i] = 1.f;
}
