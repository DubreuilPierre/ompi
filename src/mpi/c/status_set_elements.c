/*
 * $HEADERS$
 */
#include "lam_config.h"
#include <stdio.h>

#include "mpi.h"
#include "mpi/c/bindings.h"

#if LAM_HAVE_WEAK_SYMBOLS && LAM_PROFILING_DEFINES
#pragma weak MPI_Status_set_elements = PMPI_Status_set_elements
#endif

#if LAM_PROFILING_DEFINES
#include "mpi/c/profile/defines.h"
#endif

int MPI_Status_set_elements(MPI_Status *status, MPI_Datatype *datatype,
                            int count) {
    return MPI_SUCCESS;
}
