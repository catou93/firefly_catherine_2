/*
 * autopilot_hinf.cpp
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

/*
 * This function updates continuous states using the ODE5 fixed-step
 * solver algorithm
 */
void autopilot_hinfModelClass::rt_ertODEUpdateContinuousStates(RTWSolverInfo *si
  )
{
  /* Solver Matrices */
  static const real_T rt_ODE5_A[6] = {
    1.0/5.0, 3.0/10.0, 4.0/5.0, 8.0/9.0, 1.0, 1.0
  };

  static const real_T rt_ODE5_B[6][6] = {
    { 1.0/5.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

    { 3.0/40.0, 9.0/40.0, 0.0, 0.0, 0.0, 0.0 },

    { 44.0/45.0, -56.0/15.0, 32.0/9.0, 0.0, 0.0, 0.0 },

    { 19372.0/6561.0, -25360.0/2187.0, 64448.0/6561.0, -212.0/729.0, 0.0, 0.0 },

    { 9017.0/3168.0, -355.0/33.0, 46732.0/5247.0, 49.0/176.0, -5103.0/18656.0,
      0.0 },

    { 35.0/384.0, 0.0, 500.0/1113.0, 125.0/192.0, -2187.0/6784.0, 11.0/84.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE5_IntgData *id = (ODE5_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T *f3 = id->f[3];
  real_T *f4 = id->f[4];
  real_T *f5 = id->f[5];
  real_T hB[6];
  int_T i;
  int_T nXc = 16;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  autopilot_hinf_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE5_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[0]);
  rtsiSetdX(si, f1);
  this->step();
  autopilot_hinf_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE5_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[1]);
  rtsiSetdX(si, f2);
  this->step();
  autopilot_hinf_derivatives();

  /* f(:,4) = feval(odefile, t + hA(3), y + f*hB(:,3), args(:)(*)); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE5_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[2]);
  rtsiSetdX(si, f3);
  this->step();
  autopilot_hinf_derivatives();

  /* f(:,5) = feval(odefile, t + hA(4), y + f*hB(:,4), args(:)(*)); */
  for (i = 0; i <= 3; i++) {
    hB[i] = h * rt_ODE5_B[3][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2] +
                   f3[i]*hB[3]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[3]);
  rtsiSetdX(si, f4);
  this->step();
  autopilot_hinf_derivatives();

  /* f(:,6) = feval(odefile, t + hA(5), y + f*hB(:,5), args(:)(*)); */
  for (i = 0; i <= 4; i++) {
    hB[i] = h * rt_ODE5_B[4][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2] +
                   f3[i]*hB[3] + f4[i]*hB[4]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f5);
  this->step();
  autopilot_hinf_derivatives();

  /* tnew = t + hA(6);
     ynew = y + f*hB(:,6); */
  for (i = 0; i <= 5; i++) {
    hB[i] = h * rt_ODE5_B[5][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2] +
                   f3[i]*hB[3] + f4[i]*hB[4] + f5[i]*hB[5]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function */
void autopilot_hinfModelClass::step()
{
  int32_T i;
  real_T tmp[4];
  int32_T i_0;
  real_T tmp_0[4];
  real_T tmp_1;
  if (rtmIsMajorTimeStep((&autopilot_hinf_M))) {
    /* set solver stop time */
    if (!((&autopilot_hinf_M)->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&(&autopilot_hinf_M)->solverInfo,
                            (((&autopilot_hinf_M)->Timing.clockTickH0 + 1) *
        (&autopilot_hinf_M)->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&(&autopilot_hinf_M)->solverInfo,
                            (((&autopilot_hinf_M)->Timing.clockTick0 + 1) *
        (&autopilot_hinf_M)->Timing.stepSize0 + (&autopilot_hinf_M)
        ->Timing.clockTickH0 * (&autopilot_hinf_M)->Timing.stepSize0 *
        4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep((&autopilot_hinf_M))) {
    (&autopilot_hinf_M)->Timing.t[0] = rtsiGetT(&(&autopilot_hinf_M)->solverInfo);
  }

  /* Sum: '<Root>/Sum' incorporates:
   *  Inport: '<Root>/X'
   *  Inport: '<Root>/ref'
   */
  autopilot_hinf_B.e[0] = autopilot_hinf_U.ref[0] - autopilot_hinf_U.X[6];
  autopilot_hinf_B.e[1] = autopilot_hinf_U.ref[1] - autopilot_hinf_U.X[7];
  autopilot_hinf_B.e[2] = autopilot_hinf_U.ref[2] - autopilot_hinf_U.X[8];
  autopilot_hinf_B.e[3] = autopilot_hinf_U.ref[3] - autopilot_hinf_U.X[11];
  for (i = 0; i < 6; i++) {
    /* Outport: '<Root>/omega' incorporates:
     *  Integrator: '<S1>/omega_e'
     */
    autopilot_hinf_Y.omega[i] = autopilot_hinf_X.omega_e_CSTATE[i];

    /* Gain: '<S1>/Gain1' incorporates:
     *  Gain: '<S1>/Gain2'
     *  Gain: '<S1>/Gain6'
     *  Integrator: '<S1>/Ia_e'
     *  Integrator: '<S1>/omega_e'
     *  Product: '<S1>/Product'
     *  Sum: '<S1>/Sum'
     */
    autopilot_hinf_B.Gain1[i] = (0.00419 * autopilot_hinf_X.Ia_e_CSTATE[i] -
      autopilot_hinf_X.omega_e_CSTATE[i] * autopilot_hinf_X.omega_e_CSTATE[i] *
      1.3677728E-7) * 59664.387818520809;
  }

  for (i = 0; i < 4; i++) {
    /* Product: '<Root>/Product1' incorporates:
     *  Constant: '<Root>/Constant1'
     *  Sum: '<Root>/Sum2'
     */
    tmp_1 = autopilot_hinf_ConstP.Constant1_Value[i + 12] * autopilot_hinf_B.e[3]
      + (autopilot_hinf_ConstP.Constant1_Value[i + 8] * autopilot_hinf_B.e[2] +
         (autopilot_hinf_ConstP.Constant1_Value[i + 4] * autopilot_hinf_B.e[1] +
          autopilot_hinf_ConstP.Constant1_Value[i] * autopilot_hinf_B.e[0]));

    /* Product: '<Root>/Product3' incorporates:
     *  Constant: '<Root>/Constant4'
     *  Inport: '<Root>/X'
     *  Sum: '<Root>/Sum2'
     */
    tmp[i] = 0.0;
    for (i_0 = 0; i_0 < 12; i_0++) {
      tmp[i] += autopilot_hinf_ConstP.Constant4_Value[(i_0 << 2) + i] *
        autopilot_hinf_U.X[i_0];
    }

    /* End of Product: '<Root>/Product3' */

    /* Sum: '<Root>/Sum2' incorporates:
     *  Constant: '<Root>/Constant2'
     *  Gain: '<Root>/Gain5'
     *  Integrator: '<Root>/Integrator1'
     *  Product: '<Root>/Product2'
     */
    tmp_0[i] = (((autopilot_hinf_ConstP.Constant2_Value[i + 4] *
                  autopilot_hinf_X.Integrator1_CSTATE[1] +
                  autopilot_hinf_ConstP.Constant2_Value[i] *
                  autopilot_hinf_X.Integrator1_CSTATE[0]) +
                 autopilot_hinf_ConstP.Constant2_Value[i + 8] *
                 autopilot_hinf_X.Integrator1_CSTATE[2]) +
                autopilot_hinf_ConstP.Constant2_Value[i + 12] *
                autopilot_hinf_X.Integrator1_CSTATE[3]) + (tmp_1 - tmp[i]);
  }

  for (i = 0; i < 6; i++) {
    /* Gain: '<S1>/Gain7' incorporates:
     *  Gain: '<Root>/Gain5'
     *  Gain: '<S1>/Gain3'
     *  Gain: '<S1>/Gain4'
     *  Integrator: '<S1>/Ia_e'
     *  Integrator: '<S1>/omega_e'
     *  Sum: '<Root>/Sum9'
     *  Sum: '<S1>/Sum1'
     */
    autopilot_hinf_B.Gain7[i] = ((((((autopilot_hinf_ConstP.Gain5_Gain[i + 6] *
      tmp_0[1] + autopilot_hinf_ConstP.Gain5_Gain[i] * tmp_0[0]) +
      autopilot_hinf_ConstP.Gain5_Gain[i + 12] * tmp_0[2]) +
      autopilot_hinf_ConstP.Gain5_Gain[i + 18] * tmp_0[3]) + 2.71196621288962) -
      0.05 * autopilot_hinf_X.Ia_e_CSTATE[i]) - 0.00419 *
      autopilot_hinf_X.omega_e_CSTATE[i]) * 2000.0;
  }

  if (rtmIsMajorTimeStep((&autopilot_hinf_M))) {
    rt_ertODEUpdateContinuousStates(&(&autopilot_hinf_M)->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++(&autopilot_hinf_M)->Timing.clockTick0)) {
      ++(&autopilot_hinf_M)->Timing.clockTickH0;
    }

    (&autopilot_hinf_M)->Timing.t[0] = rtsiGetSolverStopTime(&(&autopilot_hinf_M)
      ->solverInfo);

    {
      /* Update absolute timer for sample time: [0.002s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.002, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      (&autopilot_hinf_M)->Timing.clockTick1++;
      if (!(&autopilot_hinf_M)->Timing.clockTick1) {
        (&autopilot_hinf_M)->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void autopilot_hinfModelClass::autopilot_hinf_derivatives()
{
  int32_T i;
  XDot_autopilot_hinf_T *_rtXdot;
  _rtXdot = ((XDot_autopilot_hinf_T *) (&autopilot_hinf_M)->derivs);

  /* Derivatives for Integrator: '<Root>/Integrator1' */
  _rtXdot->Integrator1_CSTATE[0] = autopilot_hinf_B.e[0];
  _rtXdot->Integrator1_CSTATE[1] = autopilot_hinf_B.e[1];
  _rtXdot->Integrator1_CSTATE[2] = autopilot_hinf_B.e[2];
  _rtXdot->Integrator1_CSTATE[3] = autopilot_hinf_B.e[3];
  for (i = 0; i < 6; i++) {
    /* Derivatives for Integrator: '<S1>/omega_e' */
    _rtXdot->omega_e_CSTATE[i] = autopilot_hinf_B.Gain1[i];

    /* Derivatives for Integrator: '<S1>/Ia_e' */
    _rtXdot->Ia_e_CSTATE[i] = autopilot_hinf_B.Gain7[i];
  }
}

/* Model initialize function */
void autopilot_hinfModelClass::initialize()
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)(&autopilot_hinf_M), 0,
                sizeof(RT_MODEL_autopilot_hinf_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&(&autopilot_hinf_M)->solverInfo, &(&autopilot_hinf_M
                          )->Timing.simTimeStep);
    rtsiSetTPtr(&(&autopilot_hinf_M)->solverInfo, &rtmGetTPtr((&autopilot_hinf_M)));
    rtsiSetStepSizePtr(&(&autopilot_hinf_M)->solverInfo, &(&autopilot_hinf_M)
                       ->Timing.stepSize0);
    rtsiSetdXPtr(&(&autopilot_hinf_M)->solverInfo, &(&autopilot_hinf_M)->derivs);
    rtsiSetContStatesPtr(&(&autopilot_hinf_M)->solverInfo, (real_T **)
                         &(&autopilot_hinf_M)->contStates);
    rtsiSetNumContStatesPtr(&(&autopilot_hinf_M)->solverInfo,
      &(&autopilot_hinf_M)->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&(&autopilot_hinf_M)->solverInfo,
      &(&autopilot_hinf_M)->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&(&autopilot_hinf_M)->solverInfo,
      &(&autopilot_hinf_M)->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&(&autopilot_hinf_M)->solverInfo,
      &(&autopilot_hinf_M)->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&(&autopilot_hinf_M)->solverInfo, (&rtmGetErrorStatus
      ((&autopilot_hinf_M))));
    rtsiSetRTModelPtr(&(&autopilot_hinf_M)->solverInfo, (&autopilot_hinf_M));
  }

  rtsiSetSimTimeStep(&(&autopilot_hinf_M)->solverInfo, MAJOR_TIME_STEP);
  (&autopilot_hinf_M)->intgData.y = (&autopilot_hinf_M)->odeY;
  (&autopilot_hinf_M)->intgData.f[0] = (&autopilot_hinf_M)->odeF[0];
  (&autopilot_hinf_M)->intgData.f[1] = (&autopilot_hinf_M)->odeF[1];
  (&autopilot_hinf_M)->intgData.f[2] = (&autopilot_hinf_M)->odeF[2];
  (&autopilot_hinf_M)->intgData.f[3] = (&autopilot_hinf_M)->odeF[3];
  (&autopilot_hinf_M)->intgData.f[4] = (&autopilot_hinf_M)->odeF[4];
  (&autopilot_hinf_M)->intgData.f[5] = (&autopilot_hinf_M)->odeF[5];
  (&autopilot_hinf_M)->contStates = ((X_autopilot_hinf_T *) &autopilot_hinf_X);
  rtsiSetSolverData(&(&autopilot_hinf_M)->solverInfo, (void *)
                    &(&autopilot_hinf_M)->intgData);
  rtsiSetSolverName(&(&autopilot_hinf_M)->solverInfo,"ode5");
  rtmSetTPtr((&autopilot_hinf_M), &(&autopilot_hinf_M)->Timing.tArray[0]);
  (&autopilot_hinf_M)->Timing.stepSize0 = 0.002;

  /* block I/O */
  (void) memset(((void *) &autopilot_hinf_B), 0,
                sizeof(B_autopilot_hinf_T));

  /* states (continuous) */
  {
    (void) memset((void *)&autopilot_hinf_X, 0,
                  sizeof(X_autopilot_hinf_T));
  }

  /* external inputs */
  (void)memset((void *)&autopilot_hinf_U, 0, sizeof(ExtU_autopilot_hinf_T));

  /* external outputs */
  (void) memset(&autopilot_hinf_Y.omega[0], 0,
                6U*sizeof(real_T));

  {
    int32_T i;

    /* InitializeConditions for Integrator: '<Root>/Integrator1' */
    autopilot_hinf_X.Integrator1_CSTATE[0] = 0.0;
    autopilot_hinf_X.Integrator1_CSTATE[1] = 0.0;
    autopilot_hinf_X.Integrator1_CSTATE[2] = 0.0;
    autopilot_hinf_X.Integrator1_CSTATE[3] = 0.0;
    for (i = 0; i < 6; i++) {
      /* InitializeConditions for Integrator: '<S1>/omega_e' */
      autopilot_hinf_X.omega_e_CSTATE[i] = 535.52944173293076;

      /* InitializeConditions for Integrator: '<S1>/Ia_e' */
      autopilot_hinf_X.Ia_e_CSTATE[i] = 9.3619570405727917;
    }
  }
}

/* Model terminate function */
void autopilot_hinfModelClass::terminate()
{
  /* (no terminate code required) */
}

/* Constructor */
autopilot_hinfModelClass::autopilot_hinfModelClass()
{
}

/* Destructor */
autopilot_hinfModelClass::~autopilot_hinfModelClass()
{
  /* Currently there is no destructor body generated.*/
}

/* Real-Time Model get method */
RT_MODEL_autopilot_hinf_T * autopilot_hinfModelClass::getRTM()
{
  return (&autopilot_hinf_M);
}
