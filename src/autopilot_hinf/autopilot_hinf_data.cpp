/*
 * autopilot_hinf_data.cpp
 *
 * Code generation for model "autopilot_hinf".
 *
 * Model version              : 1.460
 * Simulink Coder version : 8.11 (R2016b) 25-Aug-2016
 * C++ source code generated on : Thu Aug 02 13:27:01 2018
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objective: Execution efficiency
 * Validation result: Passed (9), Warnings (3), Error (0)
 */

#include "autopilot_hinf.h"
#include "autopilot_hinf_private.h"

/* Constant parameters (auto storage) */
const ConstP_autopilot_hinf_T autopilot_hinf_ConstP = {
  /* Expression: Kp
   * Referenced by: '<Root>/Constant1'
   */
  { 0.0, 0.0, 4.3455021518231947, 0.0, 0.0, -3.076628656669548, 0.0, 0.0,
    0.1315853588959231, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 4.7421683482455244 },

  /* Expression: Ki
   * Referenced by: '<Root>/Constant2'
   */
  { 0.0, 0.0, 32.130260887789035, 0.0, 0.0, -21.939127192502305, 0.0, 0.0,
    5.0630147060520017, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 2.3803554046260103 },

  /* Expression: SOF
   * Referenced by: '<Root>/Constant4'
   */
  { 0.0, 0.0, 39.512413100082611, 0.0, 0.0, -27.160351193914188, 0.0, 0.0,
    5.2519581091233309, 0.0, 0.0, 0.0, 0.0, 3.7913919476860412, 0.0, 0.0, 0.0,
    0.0, 5.4545048695690452, 0.0, 0.0, 0.0, 0.0, 45.057071601301075, 0.0, 0.0,
    50.122638999499955, 0.0, 0.0, -34.23587558096812, 0.0, 0.0,
    7.9078106464490654, 0.0, 0.0, 0.0, 0.0, 30.758972118500218, 0.0, 0.0, 0.0,
    0.0, 43.268255321250848, 0.0, 0.0, 0.0, 0.0, 11.001265910830089 },

  /* Expression: T
   * Referenced by: '<Root>/Gain5'
   */
  { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.1075, 0.215, 0.1075, -0.1075, -0.215,
    -0.1075, -0.18619546181365429, 0.0, 0.18619546181365429, 0.18619546181365429,
    0.0, -0.18619546181365429, -0.016, 0.016, -0.016, 0.016, -0.016, 0.016 }
};
