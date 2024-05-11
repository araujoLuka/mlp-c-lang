/** @file functions.c
 * @brief Implementation of the functions module
 *
 * This file implements the functions defined in functions.h.
 */

/* Author: Lucas C. Araujo
 * Date: 2024-05-11
 * Version: 1.0
 */

#include "functions.h"

/** @brief Computes the ReLU function
 *
 * This function computes the ReLU function for a given input.
 * Basically, it returns the input if it is positive, and 0 otherwise.
 *
 * @param x The input value
 * @return The output of the ReLU function
 */
float ReLU(float x) { return x > 0 ? x : 0; }

/** @brief Computes the derivative of the ReLU function
 *
 * This function computes the derivative of the ReLU function for a given input.
 * It returns 1 if the input is positive, and 0 otherwise.
 *
 * @param x The input value
 * @return The output of the derivative of the ReLU function
 */
float step(float x) { return x > 0 ? 1 : 0; }
