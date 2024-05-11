/** @file network.c
 * @brief Implementation of the network module
 *
 * This file implements the functions defined in network.h.
 */

#include "network.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

static const int8_t INIT_LAYER_SIZE = 8;

// Private functions
network_t* network_alloc(int n_layers);
layer_t** network_alloc_layers(int n_layers);
layer_t** network_realloc_layers(network_t* network);
void network_update_last_output(network_t* network, int index);

/** @brief Create an empty network
 *
 * This function creates an empty network with no layers.
 *
 * @return A pointer to the network created
 */
network_t* network_create() {
    network_t* network = network_alloc(0);
    if (network == NULL) return NULL;
    network->n_layers = 0;
    network->p_last_output = NULL;
    return network;
}

/** @bried Create a network from layers
 *
 * This function creates a network from an array of layers.
 *
 * @param layers The array of layers to create the network from
 * @param n_layers The number of layers in the array
 * @return A pointer to the network created
 */
network_t* network_create_from_layers(layer_t** layers, int n_layers) {
    network_t* network = network_alloc(n_layers);
    if (network == NULL) return NULL;
    network->n_layers = n_layers;
    network->layers = layers;
    network_update_last_output(network, n_layers - 1);
    return network;
}

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
int network_add_layer(network_t* network, int n_inputs, int n_neurons,
                      float (*activation)(float)) {
    layer_t* layer = layer_create(n_inputs, n_neurons, activation);
    if (layer == NULL) return -1;

    if (network->n_layers == network->layers_capacity) {
        if (network_realloc_layers(network) == NULL) {
            layer_destroy(layer);
            return -2;
        }
    }

    network->layers[network->n_layers++] = layer; /* Use post-increment to
                                                     increment after the
                                                     assignment */

    return 0;
}

/** @brief Forward propagate the network
 *
 * This function forward propagates the network. The input is passed through
 * each layer and the output of each layer is passed as input to the next layer.
 *
 * @param network The network to forward propagate
 * @param input The input to the network
 * @return The output of the network
 */
float* network_forward(network_t* network, float* input) {
    float* output = input;
    for (int i = 0; i < network->n_layers; ++i) {
        output = layer_forward(network->layers[i], output);
        if (output == NULL) {
            fprintf(stderr, "Error: failed to forward propagate network\n");
            return NULL;
        }
    }
    network->p_last_output = &output;
    return output;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Private functions implementation
 */

/** @brief Allocate memory for a network
 *
 * This function allocates memory for a network and its layers.
 *
 * @param n_layers The number of layers to allocate memory for
 * @return A pointer to the network created
 */
network_t* network_alloc(int n_layers) {
    network_t* network = (network_t*)malloc(sizeof(network_t));
    if (network == NULL) {
        fprintf(stderr, "Error: failed to allocate memory for network\n");
        return NULL;
    }
    network->layers_capacity = n_layers == 0 ? INIT_LAYER_SIZE : n_layers;
    network->layers = network_alloc_layers(network->layers_capacity);
    if (network->layers == NULL) {
        free(network);
        fprintf(stderr,
                "Error: failed to allocate memory for network's layers\n");
        return NULL;
    }
    return network;
}

/** @brief Allocate memory for an array of layers
 *
 * This function allocates memory for an array of layers.
 *
 * @param n_layers The number of layers to allocate memory for
 * @return A pointer to the array of layers created
 */
layer_t** network_alloc_layers(int n_layers) {
    layer_t** layers = (layer_t**)malloc(n_layers * sizeof(layer_t*));
    if (layers == NULL) return NULL;
    return layers;
}

/** @brief Reallocate memory for the layers array of a network
 *
 * This function reallocates memory for the layers array of a network.
 *
 * @param network The network to reallocate memory for
 * @return A pointer to the reallocated array of layers
 */
layer_t** network_realloc_layers(network_t* network) {
    network->layers_capacity *= 2;
    network->layers =
        realloc(network->layers, network->layers_capacity * sizeof(layer_t*));
    if (network->layers == NULL) {
        fprintf(stderr,
                "Error: failed to reallocate memory for network's layers\n");
        return NULL;
    }
    return network->layers;
}

/** @brief Update the last output of the network
 *
 * This function updates the last output of the network to the output of the
 * last layer.
 *
 * @param network The network to update the last output of
 * @param index The index of the last layer
 */
void network_update_last_output(network_t* network, int index) {
    network->p_last_output = &network->layers[index]->outputs;
}
