/*
 * $HEADER$
 */

#include "lam_config.h"

#include <stdio.h>

#include "mpi.h"
#include "mpi/f77/bindings.h"

#if LAM_HAVE_WEAK_SYMBOLS && LAM_PROFILE_LAYER
#pragma weak PMPI_TYPE_DUP = mpi_type_dup_f
#pragma weak pmpi_type_dup = mpi_type_dup_f
#pragma weak pmpi_type_dup_ = mpi_type_dup_f
#pragma weak pmpi_type_dup__ = mpi_type_dup_f
#elif LAM_PROFILE_LAYER
LAM_GENERATE_F77_BINDINGS (PMPI_TYPE_DUP,
                           pmpi_type_dup,
                           pmpi_type_dup_,
                           pmpi_type_dup__,
                           pmpi_type_dup_f,
                           (MPI_Fint *type, MPI_Fint *newtype, MPI_Fint *ierr),
                           (type, newtype, ierr) )
#endif

#if LAM_HAVE_WEAK_SYMBOLS
#pragma weak MPI_TYPE_DUP = mpi_type_dup_f
#pragma weak mpi_type_dup = mpi_type_dup_f
#pragma weak mpi_type_dup_ = mpi_type_dup_f
#pragma weak mpi_type_dup__ = mpi_type_dup_f
#endif

#if ! LAM_HAVE_WEAK_SYMBOLS && ! LAM_PROFILE_LAYER
LAM_GENERATE_F77_BINDINGS (MPI_TYPE_DUP,
                           mpi_type_dup,
                           mpi_type_dup_,
                           mpi_type_dup__,
                           mpi_type_dup_f,
                           (MPI_Fint *type, MPI_Fint *newtype, MPI_Fint *ierr),
                           (type, newtype, ierr) )
#endif


#if LAM_PROFILE_LAYER && ! LAM_HAVE_WEAK_SYMBOLS
#include "mpi/c/profile/defines.h"
#endif

void mpi_type_dup_f(MPI_Fint *type, MPI_Fint *newtype, MPI_Fint *ierr)
{

}
