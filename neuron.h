// HEADER FILE
// Neuron structure and functions to manage the neuron

/* Author: Lucas C. Araujo
 * Date: 2024-05-06
 * Version: 1.0
 */

#ifndef __NEURON_H__
#define __NEURON_H__

/* Neuron structure
 * - n_inputs: number of inputs
 * - weights: array with the weights for each input
 * - bias: bias value
 * - delta: delta value for the neuron
 */
typedef struct Neuron {
    int n_inputs;
    float* weights;
    float bias;
    float delta;
} neuron_t;

/* Creates a neuron with n_inputs inputs
 * @param n_inputs: number of inputs
 * @return: pointer to the created neuron
 */
neuron_t* neuron_create(int n_inputs);

/* Computes the output of a neuron
 * @param neuron: pointer to the neuron
 * @param inputs: array with the inputs
 * @param activation: pointer to the activation function
 * @return: output of the neuron
 */
float neuron_output(neuron_t* neuron, float* inputs, float (*activation)(float));

/* Frees the memory allocated for a neuron
 * @param neuron: pointer to the neuron to be destroyed
 */
void neuron_destroy(neuron_t* neuron);

#endif
