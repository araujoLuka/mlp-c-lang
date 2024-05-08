// HEADER FILE
// Layer structure and functions to manage the layer

/* Author: Lucas C. Araujo
 * Date: 2024-05-06
 * Version: 1.0
 */

#ifndef __LAYER_H__
#define __LAYER_H__

#include "functions.h"

// Forward declaration to avoid including neuron.h
typedef struct Neuron neuron_t;

typedef struct Layer {
    int n_neurons;
    neuron_t* neurons;
    // Activation function pointer
    // - Allowing to use different functions (future feature)
    void (*activation)(struct Layer* layer, float* inputs);
    float* outputs;
} layer_t;

/*
 * Create a new layer with n_neurons and storing the activation function
 * - If no activation function is provided, the default is ReLU
 *   > There's some functions implemented in functions.h
 * - If a custom activation function is provided, the user is responsible for
 *   implementing the function and passing it as a parameter
 * - If n_neurons is 0 or lower, the neurons' list will be NULL
 */
layer_t* layer_create(int n_neurons, void (*activation)(layer_t*, float*));

// Feed forward the inputs through the layer and store the outputs
void layer_forward(layer_t* layer, float* inputs);

// Insert a neuron in the layer at the end of the list
void layer_insert_neuron(layer_t* layer, neuron_t* neuron);

// Insert a neuron in the layer at the specified index
void layer_insert_at(layer_t* layer, neuron_t* neuron, int index);

/*
 * Print the layer's information
 * - Layer's address
 * - Number of neurons
 * - Output values
 * Use the index parameter to print the layer's index in the network
 */
void layer_print(layer_t* layer, int index);

// Free the memory allocated for the layer
void layer_destroy(layer_t* layer);

#endif
