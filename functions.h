/** @file functions.h
 * @brief Activation functions
 * @details This file contains the definition of the ReLU activation function.
 */

/* Author: Lucas C. Araujo
 * Date: 2024-05-06
 * Version: 1.0
 */

#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__

/** @brief Computes the ReLU function
 *
 * This function computes the ReLU function for a given input.
 * Basically, it returns the input if it is positive, and 0 otherwise.
 *
 * @param x The input value
 * @return The output of the ReLU function
 */
float ReLU(float input);

/** @brief Computes the derivative of the ReLU function
 *
 * This function computes the derivative of the ReLU function for a given input.
 * It returns 1 if the input is positive, and 0 otherwise.
 *
 * @param x The input value
 * @return The output of the derivative of the ReLU function
 */
float step(float input);

#endif
