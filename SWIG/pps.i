/* name of module to use*/
%module pps
%{
    /* Every thing in this file is being copied in 
     wrapper file. We include the C header file necessary
     to compile the interface */
    #include "./src/rdp.h"
    #include "./src/monitor.h"
    #include "./src/cpuProcess.h"
    // libreria de pthread??
%}
  
//estructuras??

int new_monitor(monitor_o *p_monitor, pthread_mutex_t mutex, pthread_cond_t *espera, int *boolQuesWait, rdp_o *rdp);
int new_rdp(rdp_o *p_rdp);
void new_cpuProcess(cpuProcess_o *p_cpuProcess, int *processList, int processNum, monitor_o *monitor, int id);
