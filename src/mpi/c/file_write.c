/*
 * $HEADER$
 */

#include "lam_config.h"

#include "mpi.h"
#include "mpi/c/bindings.h"

#if LAM_HAVE_WEAK_SYMBOLS && LAM_PROFILING_DEFINES
#pragma weak MPI_File_write = PMPI_File_write
#endif

#if LAM_PROFILING_DEFINES
#include "mpi/c/profile/defines.h"
#endif

int MPI_File_write(MPI_File fh, void *buf, int count, MPI_Datatype
		           datatype, MPI_Status *status) {
    return MPI_SUCCESS;
}
