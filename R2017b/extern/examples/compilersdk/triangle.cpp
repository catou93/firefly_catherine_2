/*=================================================================
 *
 * TRIANGLE.CPP
 *
 * Calculate the points in Sierpinski's triangle, an elementary
 * fractal. 
 *
 * This function calls a C++ shared library, libtrianglep, created
 * using MATLAB Compiler SDK.
 *
 * Copyright 1984-2016 The MathWorks, Inc.
 *
 *=================================================================*/

// library specific header file generated by MATLAB Compiler SDK 
// for the C++ shared library target
#include "libtrianglep.h"

void usage(const char *name)
{
    std::cout << "Usage: " << name << " [number of points; default=7500]" << std::endl; 
    exit (-1);
}

// MSVC compiles C files without name mangling and CPP files with name mangling.
// Due to this, the run_main symbol as generated in each of these files
// is different and thus gives a link time error. To resolve this issue,
// we force the Microsoft compiler to use C style linking for run_main.
// This is not needed on Linux/Mac because mbuild uses C++ compilers for both
// C and CPP files, so the symbol names are consistent.
#ifdef _MSC_VER
extern "C"
#endif
int run_main(int argc, const char ** argv)
{
    // Default number of iterations
    int num_points = 7500;
    
    // Validate the number of inputs
    if (argc < 1 || argc > 2)
    {
        fprintf(stderr, "Expecting 0 or 1 input(s). Found %d.\n", argc-1);
        usage((argc > 0) ? argv[0] : "trianglep");
    }

    // If we have an input, try to convert the input string to an integer, 
    // which should be positive.
    if (argc == 2)
    {
        num_points = atoi(argv[1]);
    }
    // Type-check input argument -- atoi() will return 0 if the input is
    // not an integer.
    if (num_points < 1)
    {
        std::cerr << "Argument must be a positive integer." << std::endl;
        usage((argc > 0) ? argv[0] : "trianglep");
        return -2;
    }

    if (!libtrianglepInitialize())
    {
        std::cerr << "Could not initialize the trianglep library properly" << std::endl;
        return -2;
    }
    else
    {
        // Create the input data
        // Input parameters:
        //
        // iterations: Number of points to draw in the triangle
        // draw: If true, draw the triangle in a figure window before returning.
        // In this code, the value of draw is always set to true.
        mwArray iterations((mxDouble)num_points);
        mwArray draw(1.0);
        // Create the output variables
        // The Sierpinski function returns the X and Y coordinates of the points
        // forming the pattern in the triangle.
        mwArray x;
        mwArray y;
        
        // Call the library function
        sierpinski(2, x, y, iterations, draw);

        // Display the return value of the library function
        //std::cout << "Calculated "  << x.NumberOfElements() << " points" << std::endl;
#ifdef _WIN32
        printf("\nCalculated %Iu points\n",x.NumberOfElements());
#else
        printf("\nCalculated %zu points\n",x.NumberOfElements());
#endif
        printf("Close the figure to continue\n");
        // Block until user dismisses the figure
        mclWaitForFiguresToDie(nullptr);
        
        // Call the library termination routine
        libtrianglepTerminate();
    }
    // Note that you should call mclTerminateApplication at the end of
    // your application to shut down all MATLAB Runtime instances.
    mclTerminateApplication();

    /* Success */
    return 0;
}

// The main routine. On the Mac, the main thread runs the system code, and
// user code must be processed by a secondary thread. On other platforms, 
// the main thread runs both the system code and the user code.
int main(int argc, const char ** argv)
{
    // Call the mclInitializeApplication routine once and only once. 
    // This initializes the MATLAB Runtime; if it fails, the application 
    // cannot run. Make sure that the application was initialized properly 
    // by checking the return value. This initialization must be done 
    // before calling any MATLAB APIs or MATLAB Compiler SDK generated 
    // shared library functions.
    if( !mclInitializeApplication(nullptr, 0) )
    {
        fprintf(stderr, "Could not initialize the application.\n");
        return -1;
    }
    return mclRunMain(static_cast<mclMainFcnType>(run_main), argc, argv);
}
