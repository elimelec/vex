This directory contains the source code for the VEX dynamic and static profiler.

The profiler has been developed by 

     Marco Paolieri             	      Ivano Bonesana
  marco.paolieri@gmail.com		 ivano.bonesana@gmail.com

during the VLIW course project at ALaRI Institute (USI, LUGANO)

For license terms please refer to the file LICENSE.txt

With static profiler we identify the count of the instructions composing 
the program, the output of the profiler is generated in a file called:
static_prof_file.txt

With dynamic profiler we identify the count of the instructions executed 
by VEX architecture running a certain benchmark. This will be generated 
every execution in the output file called dyn_prof_file.txt

It is possible to modify the operations to be profiled and to group them
as for instance (to group all the ALU operations) modifying the flex file
add_profiling.lex. Please refer to the comment on the source code to know 
how to proceed or contact the authors via email.


The authors don't assume any responsability on the results provide by this tool.

To see the result for the testfilter example, just execute the following commands:
make
./testfilter 
and look at the output files.

