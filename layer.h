// HEADER FILE
// Layer structure and functions to manage the layer

/* Author: Lucas C. Araujo
 * Date: 2024-05-08
 * Version: 1.0
 */

#ifndef __LAYER_H__
#define __LAYER_H__

#include "functions.h"

// Forward declaration to avoid including neuron.h
typedef struct Neuron neuron_t;

typedef struct Layer {
    int n_neurons;
    neuron_t** neurons;
    // Activation function pointer
    // - Allowing to use different functions (future feature)
    float (*activation)(float input);
    float* outputs;
} layer_t;

/** @brief Create a layer of neurons
 *
 * This function creates a layer of neurons with the specified number of
 * inputs and neurons. The activation function is also set.
 *
 * @param n_inputs Number of inputs of the layer
 * @param n_neurons Number of neurons of the layer
 * @param activation Activation function of the layer
 * @return A pointer to the layer created
 */
layer_t* layer_create(int n_inputs, int n_neurons, float (*activation)(float));

/** @brief Destroy a layer
 *
 * This function frees the memory allocated for a layer and its neurons.
 *
 * @param layer Pointer to the layer to be destroyed
 */
void layer_destroy(layer_t* layer);

/** @brief Computes the output of a layer
 *
 * This function computes the output of a layer given the inputs.
 * The output of each neuron is computed using the activation function
 * that was set when the layer was created.
 * All outputs are stored in the layer.
 *
 * @param layer Pointer to the layer
 * @param inputs Array with the inputs
 * @return 0 if success, negative value otherwise
 */
int layer_forward(layer_t* layer, float* inputs);

#endif
