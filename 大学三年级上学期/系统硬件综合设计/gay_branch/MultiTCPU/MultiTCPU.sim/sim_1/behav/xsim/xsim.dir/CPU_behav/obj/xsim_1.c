/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                         */
/*  \   \        Copyright (c) 2003-2013 Xilinx, Inc.                 */
/*  /   /        All Right Reserved.                                  */
/* /---/   /\                                                         */
/* \   \  /  \                                                        */
/*  \___\/\___\                                                       */
/**********************************************************************/


#include "iki.h"
#include <string.h>
#include <math.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                         */
/*  \   \        Copyright (c) 2003-2013 Xilinx, Inc.                 */
/*  /   /        All Right Reserved.                                  */
/* /---/   /\                                                         */
/* \   \  /  \                                                        */
/*  \___\/\___\                                                       */
/**********************************************************************/


#include "iki.h"
#include <string.h>
#include <math.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
typedef void (*funcp)(char *, char *);
extern int main(int, char**);
extern void execute_45(char*, char *);
extern void execute_46(char*, char *);
extern void execute_47(char*, char *);
extern void execute_48(char*, char *);
extern void execute_49(char*, char *);
extern void execute_50(char*, char *);
extern void execute_51(char*, char *);
extern void execute_52(char*, char *);
extern void execute_53(char*, char *);
extern void execute_54(char*, char *);
extern void execute_55(char*, char *);
extern void execute_56(char*, char *);
extern void execute_57(char*, char *);
extern void execute_58(char*, char *);
extern void execute_59(char*, char *);
extern void execute_60(char*, char *);
extern void execute_61(char*, char *);
extern void execute_62(char*, char *);
extern void execute_63(char*, char *);
extern void execute_64(char*, char *);
extern void execute_65(char*, char *);
extern void execute_66(char*, char *);
extern void execute_67(char*, char *);
extern void execute_68(char*, char *);
extern void execute_69(char*, char *);
extern void execute_70(char*, char *);
extern void execute_3(char*, char *);
extern void execute_4(char*, char *);
extern void execute_5(char*, char *);
extern void execute_7(char*, char *);
extern void execute_8(char*, char *);
extern void execute_10(char*, char *);
extern void execute_14(char*, char *);
extern void execute_15(char*, char *);
extern void execute_41(char*, char *);
extern void execute_42(char*, char *);
extern void execute_43(char*, char *);
extern void execute_19(char*, char *);
extern void execute_20(char*, char *);
extern void execute_21(char*, char *);
extern void execute_25(char*, char *);
extern void execute_27(char*, char *);
extern void execute_44(char*, char *);
extern void execute_29(char*, char *);
extern void execute_30(char*, char *);
extern void execute_31(char*, char *);
extern void execute_33(char*, char *);
extern void execute_34(char*, char *);
extern void execute_35(char*, char *);
extern void execute_36(char*, char *);
extern void execute_38(char*, char *);
extern void execute_39(char*, char *);
extern void execute_40(char*, char *);
extern void execute_71(char*, char *);
extern void execute_72(char*, char *);
extern void execute_73(char*, char *);
extern void execute_74(char*, char *);
extern void execute_75(char*, char *);
extern void transaction_2(char*, char*, unsigned, unsigned, unsigned);
extern void vlog_transfunc_eventcallback(char*, char*, unsigned, unsigned, unsigned, char *);
extern void transaction_28(char*, char*, unsigned, unsigned, unsigned);
funcp funcTab[61] = {(funcp)execute_45, (funcp)execute_46, (funcp)execute_47, (funcp)execute_48, (funcp)execute_49, (funcp)execute_50, (funcp)execute_51, (funcp)execute_52, (funcp)execute_53, (funcp)execute_54, (funcp)execute_55, (funcp)execute_56, (funcp)execute_57, (funcp)execute_58, (funcp)execute_59, (funcp)execute_60, (funcp)execute_61, (funcp)execute_62, (funcp)execute_63, (funcp)execute_64, (funcp)execute_65, (funcp)execute_66, (funcp)execute_67, (funcp)execute_68, (funcp)execute_69, (funcp)execute_70, (funcp)execute_3, (funcp)execute_4, (funcp)execute_5, (funcp)execute_7, (funcp)execute_8, (funcp)execute_10, (funcp)execute_14, (funcp)execute_15, (funcp)execute_41, (funcp)execute_42, (funcp)execute_43, (funcp)execute_19, (funcp)execute_20, (funcp)execute_21, (funcp)execute_25, (funcp)execute_27, (funcp)execute_44, (funcp)execute_29, (funcp)execute_30, (funcp)execute_31, (funcp)execute_33, (funcp)execute_34, (funcp)execute_35, (funcp)execute_36, (funcp)execute_38, (funcp)execute_39, (funcp)execute_40, (funcp)execute_71, (funcp)execute_72, (funcp)execute_73, (funcp)execute_74, (funcp)execute_75, (funcp)transaction_2, (funcp)vlog_transfunc_eventcallback, (funcp)transaction_28};
const int NumRelocateId= 61;

void relocate(char *dp)
{
	iki_relocate(dp, "xsim.dir/CPU_behav/xsim.reloc",  (void **)funcTab, 61);

	/*Populate the transaction function pointer field in the whole net structure */
}

void sensitize(char *dp)
{
	iki_sensitize(dp, "xsim.dir/CPU_behav/xsim.reloc");
}

void simulate(char *dp)
{
		iki_schedule_processes_at_time_zero(dp, "xsim.dir/CPU_behav/xsim.reloc");
	// Initialize Verilog nets in mixed simulation, for the cases when the value at time 0 should be propagated from the mixed language Vhdl net
	iki_execute_processes();

	// Schedule resolution functions for the multiply driven Verilog nets that have strength
	// Schedule transaction functions for the singly driven Verilog nets that have strength

}
#include "iki_bridge.h"
void relocate(char *);

void sensitize(char *);

void simulate(char *);

extern SYSTEMCLIB_IMP_DLLSPEC void local_register_implicit_channel(int, char*);
extern void implicit_HDL_SCinstatiate();

extern SYSTEMCLIB_IMP_DLLSPEC int xsim_argc_copy ;
extern SYSTEMCLIB_IMP_DLLSPEC char** xsim_argv_copy ;

int main(int argc, char **argv)
{
    iki_heap_initialize("ms", "isimmm", 0, 2147483648) ;
    iki_set_sv_type_file_path_name("xsim.dir/CPU_behav/xsim.svtype");
    iki_set_crvs_dump_file_path_name("xsim.dir/CPU_behav/xsim.crvsdump");
    void* design_handle = iki_create_design("xsim.dir/CPU_behav/xsim.mem", (void *)relocate, (void *)sensitize, (void *)simulate, 0, isimBridge_getWdbWriter(), 0, argc, argv);
     iki_set_rc_trial_count(100);
    (void) design_handle;
    return iki_simulate_design();
}
