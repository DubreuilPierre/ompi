/*
 * $HEADERS$
 */
#include "lam_config.h"
#include <stdio.h>

#include "mpi.h"
#include "mpi/c/bindings.h"
#include "group/group.h"
#include "errhandler/errhandler.h"
#include "communicator/communicator.h"

#if LAM_HAVE_WEAK_SYMBOLS && LAM_PROFILING_DEFINES
#pragma weak MPI_Group_union = PMPI_Group_union
#endif

#if LAM_PROFILING_DEFINES
#include "mpi/c/profile/defines.h"
#endif

int MPI_Group_union(MPI_Group group1, MPI_Group group2, MPI_Group *new_group) 
{
    /* local variables */
    int new_group_size, proc1, proc2, found_in_group;
    int my_group_rank, cnt;
    lam_group_t *group1_pointer, *group2_pointer, *new_group_pointer;
    lam_proc_t *proc1_pointer, *proc2_pointer, *my_proc_pointer;

    /* check for errors */
    if (MPI_PARAM_CHECK) {
        if ((MPI_GROUP_NULL == group1) || (MPI_GROUP_NULL == group2) ||
                (NULL == group1) || (NULL == group2) ) {
            return 
                LAM_ERRHANDLER_INVOKE(MPI_COMM_WORLD, MPI_ERR_GROUP,
                        "MPI_Group_union");
        }
    }

    group1_pointer = (lam_group_t *) group1;
    group2_pointer = (lam_group_t *) group2;

    /*
     * form union
     */

    /* get new group size */
    new_group_size = group1_pointer->grp_proc_count;

    /* check group2 elements to see if they need to be included in the list */
    for (proc2 = 0; proc2 < group2_pointer->grp_proc_count; proc2++) {
        proc2_pointer = group2_pointer->grp_proc_pointers[proc2];

        /* check to see if this proc2 is alread in the group */
        found_in_group = 0;
        for (proc1 = 0; proc1 < group1_pointer->grp_proc_count; proc1++) {
            proc1_pointer = group1_pointer->grp_proc_pointers[proc1];
            if (proc2_pointer == proc2_pointer) {
                /* proc2 is in group1 - don't double count */
                found_in_group = 1;
                break;
            }
        }                       /* end proc1 loop */

        if (found_in_group)
            continue;

        new_group_size++;
    }                           /* end proc loop */

    /* get new group struct */
    new_group_pointer = lam_group_allocate(new_group_size);
    if (NULL == new_group_pointer) {
        return 
            LAM_ERRHANDLER_INVOKE(MPI_COMM_WORLD, MPI_ERR_GROUP,
                    "MPI_Group_union - II");
    }

    /* fill in the new group list */

    /* put group1 elements in the list */
    for (proc1 = 0; proc1 < group1_pointer->grp_proc_count; proc1++) {
        new_group_pointer->grp_proc_pointers[proc1] =
            group1_pointer->grp_proc_pointers[proc1];
    }
    cnt = group1_pointer->grp_proc_count;

    /* check group2 elements to see if they need to be included in the list */
    for (proc2 = 0; proc2 < group2_pointer->grp_proc_count; proc2++) {
        proc2_pointer = group2_pointer->grp_proc_pointers[proc2];

        /* check to see if this proc2 is alread in the group */
        found_in_group = 0;
        for (proc1 = 0; proc1 < group1_pointer->grp_proc_count; proc1++) {
            proc1_pointer = group1_pointer->grp_proc_pointers[proc1];
            if (proc2_pointer == proc2_pointer) {
                /* proc2 is in group1 - don't double count */
                found_in_group = 1;
                break;
            }
        }                       /* end proc1 loop */

        if (found_in_group)
            continue;

        new_group_pointer->grp_proc_pointers[cnt] =
            group2_pointer->grp_proc_pointers[proc2];
        cnt++;
    }                           /* end proc loop */

    /* increment proc reference counters */
    lam_group_increment_proc_count(new_group_pointer);

    /* find my rank */
    my_group_rank = group1_pointer->grp_my_rank;
    if (MPI_PROC_NULL == my_group_rank) {
        my_group_rank = group2_pointer->grp_my_rank;
        my_proc_pointer = group2_pointer->grp_proc_pointers[my_group_rank];
    } else {
        my_proc_pointer = group1_pointer->grp_proc_pointers[my_group_rank];
    }

    lam_set_group_rank(new_group_pointer, my_proc_pointer);

    *new_group = (MPI_Group) new_group_pointer;

    /* return */
    return MPI_SUCCESS;
}
