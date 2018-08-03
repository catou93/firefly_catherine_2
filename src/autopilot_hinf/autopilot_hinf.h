/*
 * autopilot_hinf.h
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

#ifndef RTW_HEADER_autopilot_hinf_h_
#define RTW_HEADER_autopilot_hinf_h_
#include <string.h>
#ifndef autopilot_hinf_COMMON_INCLUDES_
# define autopilot_hinf_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* autopilot_hinf_COMMON_INCLUDES_ */

#include "autopilot_hinf_types.h"

/* Shared type includes */
#include "multiword_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlkStateChangeFlag
# define rtmGetBlkStateChangeFlag(rtm) ((rtm)->blkStateChange)
#endif

#ifndef rtmSetBlkStateChangeFlag
# define rtmSetBlkStateChangeFlag(rtm, val) ((rtm)->blkStateChange = (val))
#endif

#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->contStates = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
# define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
# define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
# define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
# define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T e[4];                         /* '<Root>/Sum' */
  real_T Gain1[6];                     /* '<S1>/Gain1' */
  real_T Gain7[6];                     /* '<S1>/Gain7' */
} B_autopilot_hinf_T;

/* Continuous states (auto storage) */
typedef struct {
  real_T omega_e_CSTATE[6];            /* '<S1>/omega_e' */
  real_T Integrator1_CSTATE[4];        /* '<Root>/Integrator1' */
  real_T Ia_e_CSTATE[6];               /* '<S1>/Ia_e' */
} X_autopilot_hinf_T;

/* State derivatives (auto storage) */
typedef struct {
  real_T omega_e_CSTATE[6];            /* '<S1>/omega_e' */
  real_T Integrator1_CSTATE[4];        /* '<Root>/Integrator1' */
  real_T Ia_e_CSTATE[6];               /* '<S1>/Ia_e' */
} XDot_autopilot_hinf_T;

/* State disabled  */
typedef struct {
  boolean_T omega_e_CSTATE[6];         /* '<S1>/omega_e' */
  boolean_T Integrator1_CSTATE[4];     /* '<Root>/Integrator1' */
  boolean_T Ia_e_CSTATE[6];            /* '<S1>/Ia_e' */
} XDis_autopilot_hinf_T;

#ifndef ODE5_INTG
#define ODE5_INTG

/* ODE5 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[6];                        /* derivatives */
} ODE5_IntgData;

#endif

/* Constant parameters (auto storage) */
typedef struct {
  /* Expression: Kp
   * Referenced by: '<Root>/Constant1'
   */
  real_T Constant1_Value[16];

  /* Expression: Ki
   * Referenced by: '<Root>/Constant2'
   */
  real_T Constant2_Value[16];

  /* Expression: SOF
   * Referenced by: '<Root>/Constant4'
   */
  real_T Constant4_Value[48];

  /* Expression: T
   * Referenced by: '<Root>/Gain5'
   */
  real_T Gain5_Gain[24];
} ConstP_autopilot_hinf_T;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T ref[4];                       /* '<Root>/ref' */
  real_T X[12];                        /* '<Root>/X' */
} ExtU_autopilot_hinf_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T omega[6];                     /* '<Root>/omega' */
} ExtY_autopilot_hinf_T;

/* Real-time Model Data Structure */
struct tag_RTM_autopilot_hinf_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X_autopilot_hinf_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T blkStateChange;
  real_T odeY[16];
  real_T odeF[6][16];
  ODE5_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

#ifdef __cplusplus

extern "C" {

#endif

#ifdef __cplusplus

}
#endif

/* Constant parameters (auto storage) */
extern const ConstP_autopilot_hinf_T autopilot_hinf_ConstP;

/* Class declaration for model autopilot_hinf */
class autopilot_hinfModelClass {
  /* public data and function members */
 public:
  /* External inputs */
  ExtU_autopilot_hinf_T autopilot_hinf_U;

  /* External outputs */
  ExtY_autopilot_hinf_T autopilot_hinf_Y;

  /* model initialize function */
  void initialize();

  /* model step function */
  void step();

  /* model terminate function */
  void terminate();

  /* Constructor */
  autopilot_hinfModelClass();

  /* Destructor */
  ~autopilot_hinfModelClass();

  /* Real-Time Model get method */
  RT_MODEL_autopilot_hinf_T * getRTM();

  /* private data and function members */
 private:
  /* Block signals */
  B_autopilot_hinf_T autopilot_hinf_B;
  X_autopilot_hinf_T autopilot_hinf_X; /* Block continuous states */

  /* Real-Time Model */
  RT_MODEL_autopilot_hinf_T autopilot_hinf_M;

  /* Continuous states update member function*/
  void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si );

  /* Derivatives member function */
  void autopilot_hinf_derivatives();
};

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'autopilot_hinf'
 * '<S1>'   : 'autopilot_hinf/Motor'
 */
#endif                                 /* RTW_HEADER_autopilot_hinf_h_ */
