/*
 * $HEADER$
 */

#include "lam_config.h"

#include <stdio.h>

#include "mpi.h"
#include "mpi/f77/bindings.h"

#if LAM_HAVE_WEAK_SYMBOLS && LAM_PROFILE_LAYER
#pragma weak PMPI_FILE_WRITE_ORDERED = mpi_file_write_ordered_f
#pragma weak pmpi_file_write_ordered = mpi_file_write_ordered_f
#pragma weak pmpi_file_write_ordered_ = mpi_file_write_ordered_f
#pragma weak pmpi_file_write_ordered__ = mpi_file_write_ordered_f
#elif LAM_PROFILE_LAYER
LAM_GENERATE_F77_BINDINGS (PMPI_FILE_WRITE_ORDERED,
                           pmpi_file_write_ordered,
                           pmpi_file_write_ordered_,
                           pmpi_file_write_ordered__,
                           pmpi_file_write_ordered_f,
                           (MPI_Fint *fh, char *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *status, MPI_Fint *ierr),
                           (fh, buf, count, datatype, status, ierr) )
#endif

#if LAM_HAVE_WEAK_SYMBOLS
#pragma weak MPI_FILE_WRITE_ORDERED = mpi_file_write_ordered_f
#pragma weak mpi_file_write_ordered = mpi_file_write_ordered_f
#pragma weak mpi_file_write_ordered_ = mpi_file_write_ordered_f
#pragma weak mpi_file_write_ordered__ = mpi_file_write_ordered_f
#endif

#if ! LAM_HAVE_WEAK_SYMBOLS && ! LAM_PROFILE_LAYER
LAM_GENERATE_F77_BINDINGS (MPI_FILE_WRITE_ORDERED,
                           mpi_file_write_ordered,
                           mpi_file_write_ordered_,
                           mpi_file_write_ordered__,
                           mpi_file_write_ordered_f,
                           (MPI_Fint *fh, char *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *status, MPI_Fint *ierr),
                           (fh, buf, count, datatype, status, ierr) )
#endif


#if LAM_PROFILE_LAYER && ! LAM_HAVE_WEAK_SYMBOLS
#include "mpi/c/profile/defines.h"
#endif

void mpi_file_write_ordered_f(MPI_Fint *fh, char *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *status, MPI_Fint *ierr)
{

}
