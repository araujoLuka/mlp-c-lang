// HEADER FILE
// Network structure and functions to manage the network

/* Author: Lucas C. Araujo
 * Date: 2024-05-06
 * Version: 1.0
 */

#ifndef __NETWORK_H__
#define __NETWORK_H__

#include "layer.h"

typedef struct Network {
    int n_layers;
    layer_t** layers;
    int layers_capacity;
    float** p_last_output; // Pointer to the last layer's outputs
} network_t;

/** @brief Create an empty network
 *
 * This function creates an empty network with no layers.
 *
 * @return A pointer to the network created
 */
network_t* network_create();

/** @bried Create a network from layers
 *
 * This function creates a network from an array of layers.
 *
 * @param layers The array of layers to create the network from
 * @param n_layers The number of layers in the array
 * @return A pointer to the network created
 */
network_t* network_create_from_layers(layer_t** layers, int n_layers);

/** @brief Add a layer to the network
 *
 * This function adds a layer to the network. The layer is created with the
 * specified number of inputs, neurons and activation function.
 *
 * @param network The network to add the layer to
 * @param n_inputs The number of inputs to the layer
 * @param n_neurons The number of neurons in the layer
 * @param activation The activation function of the layer
 * @return 0 if added successfully, -1 if memory allocation failed for the
 * layer, -2 if memory reallocation failed for the layers array
 */
int network_add_layer(network_t* network, int n_neurons, int n_inputs, float (*activation)(float));

// Feed forward the inputs through the network and store the outputs
float* network_forward(network_t* network, float* inputs);

#endif
