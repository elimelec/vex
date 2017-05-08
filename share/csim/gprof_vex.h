typedef enum { GPROF_TOTAL = 0, GPROF_DCACHE, GPROF_ICACHE, GPROF_NOCACHE } gprof_mode;

extern void sim_gprof_mcleanup(gprof_mode mode, double granularity);
extern void sim_gprof_dump_flat(FILE * flog);
extern int sim_gprof_active;
