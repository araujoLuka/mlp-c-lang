// HEADER FILE
// Network structure and functions to manage the network

/* Author: Lucas C. Araujo
 * Date: 2024-05-06
 * Version: 1.0
 */

#ifndef __NETWORK_H__
#define __NETWORK_H__

// Forward declaration to avoid including layer.h
struct layer_t;

typedef struct Network {
    int n_layers;
    layer_t* layers;
    float* outputs; // Only to point to the last layer's outputs
} network_t;

network_t* network_create(int n_layers, int* n_neurons);

// Feed forward the inputs through the network and store the outputs
void network_forward(network_t* network, float* inputs);

#endif
