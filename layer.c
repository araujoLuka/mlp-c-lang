// Implementation of layer.c

/* Author: Lucas C. Araujo
 * Date: 2024-05-08
 * Version: 1.0
 */

#include "layer.h"

#include <stdio.h>
#include <stdlib.h>

// Private functions
neuron_t** layer_create_neurons(int n_inputs, int n_neurons);
layer_t* layer_alloc(int n_inputs, int n_neurons);
void layer_init(layer_t* layer, int n_neurons, float (*activation)(float));
int validate_params(layer_t* layer, float* inputs);

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
layer_t* layer_create(int n_inputs, int n_neurons, float (*activation)(float)) {
    layer_t* layer = layer_alloc(n_inputs, n_neurons);
    if (layer == NULL) return NULL;

    layer_init(layer, n_neurons, activation);

    return layer;
}

/** @brief Destroy a layer
 *
 * This function frees the memory allocated for a layer and its neurons.
 *
 * @param layer Pointer to the layer to be destroyed
 */
void layer_destroy(layer_t* layer) {
    for (int i = 0; i < layer->n_neurons; ++i)
        neuron_destroy(layer->neurons[i]);
    free(layer->neurons);
    free(layer->outputs);
    free(layer);
}

/** @brief Computes the output of a layer
 *
 * This function computes the output of a layer given the inputs.
 * The output of each neuron is computed using the activation function
 * that was set when the layer was created.
 * All outputs are stored in the layer.
 *
 * @param layer Pointer to the layer
 * @param inputs Array with the inputs
 * @return the output of the layer
 */
float* layer_forward(layer_t* layer, float* inputs) {
    int val = validate_params(layer, inputs);
    if (val < 0) return NULL;

    for (int i = 0; i < layer->n_neurons; ++i)
        layer->outputs[i] =
            neuron_output(layer->neurons[i], inputs, layer->activation);

    return layer->outputs;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Private functions implementation
 */

/** @brief Allocates memory for a layer
 *
 * This function allocates memory for a layer and its neurons and outputs.
 *
 * @param n_inputs Number of inputs of the layer
 * @param n_neurons Number of neurons of the layer
 * @return A pointer to the layer allocated
 */
layer_t* layer_alloc(int n_inputs, int n_neurons) {
    layer_t* layer = (layer_t*)malloc(sizeof(layer_t));
    if (layer == NULL) {
        fprintf(stderr, "Error: failed to allocate memory for layer\n");
        return NULL;
    }

    layer->neurons = layer_create_neurons(n_inputs, n_neurons);
    if (layer->neurons == NULL) {
        free(layer);
        fprintf(stderr,
                "Error: failed to allocate memory for layer's neurons\n");
        return NULL;
    }

    layer->outputs = (float*)malloc(n_neurons * sizeof(float));
    if (layer->outputs == NULL) {
        free(layer->neurons);
        free(layer);
        fprintf(stderr,
                "Error: failed to allocate memory for layer's outputs\n");
        return NULL;
    }

    return layer;
}

/** @brief Creates the neurons of a layer
 *
 * This function creates the neurons of a layer.
 *
 * @param n_inputs Number of inputs of the neurons
 * @param n_neurons Number of neurons to be created
 * @return An array with the neurons created
 */
neuron_t** layer_create_neurons(int n_inputs, int n_neurons) {
    neuron_t** neurons = (neuron_t**)malloc(n_neurons * sizeof(neuron_t*));
    if (neurons == NULL) return NULL;

    for (int i = 0; i < n_neurons; ++i) {
        neurons[i] = neuron_create(n_inputs);
        if (neurons[i] == NULL) {
            fprintf(stderr, "Error: failed to create neuron %d for layer\n", i);
            for (int j = 0; j < i; ++j) neuron_destroy(neurons[j]);
            free(neurons);
            return NULL;
        }
    }

    return neurons;
}

/** @brief Initializes a layer
 *
 * This function initializes a layer with the number of neurons and the
 * activation function.
 *
 * @param layer Pointer to the layer to be initialized
 * @param n_neurons Number of neurons of the layer
 * @param activation Activation function of the layer
 */
void layer_init(layer_t* layer, int n_neurons, float (*activation)(float)) {
    layer->n_neurons = n_neurons;
    layer->activation = activation;
}

int validate_params(layer_t* layer, float* inputs) {
    if (layer == NULL) {
        fprintf(stderr, "Error: invalid layer\n");
        return -1;
    }

    if (inputs == NULL) {
        fprintf(stderr, "Error: invalid inputs\n");
        return -2;
    }

    size_t n_inputs = sizeof(inputs) * 1 / sizeof(*inputs);
    if (n_inputs != layer->neurons[0]->n_inputs) {
        fprintf(stderr, "Error: number of inputs does not match\n");
        return -3;
    }

    return 0;
}
