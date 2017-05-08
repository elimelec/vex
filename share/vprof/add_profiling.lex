/*
  License Terms:

  Copyright (c) 2007, Marco Paolieri - Ivano Bonesana
  All rights reserved.
  
  Redistribution and use in source and binary forms, with or without modification, 
  are permitted provided that the following conditions are met:

  * Redistributions of source code must retain the above copyright notice, 
  this list of conditions and the following disclaimer.
  * Redistributions in binary form must reproduce the above copyright notice, 
  this list of conditions and the following disclaimer in the documentation and/or 
  other materials provided with the distribution.
  
  * Neither the name of the organization nor the names of its contributors may be used to endorse 
  or promote products derived from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY 
  EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES 
  OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT 
  SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT 
  OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) 
  HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, 
  EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
/*   
     Static and Dynamic profiling information about 
     executed operations on VEX simulation 
  
     developers: MARCO PAOLIERI (marco.paolieri@gmail.com)
     IVANO BONESANA (ivano.bonesana@gmail.com)
  
     last update: 13-02-07
*/

%x OPERATION
%option noyywrap

DEFINE "#define" 
DECLARATION_POINT "extern unsigned int __vex_main("
OP_SEPARATOR "__"
SPACE " "|\t
OPEN_PAR "("
SEMICOLON ";"
CLOSE_PAR ")"
VAR [a-zA-Z_][a-zA-Z0-9_]*

%{

#include <map>
#include <string>
#include <iostream>
#include <fstream>

#define OP_SEP "__"
  /* macros used to insert an operation to be profiled: */

  /* INSERT_OP(x) where x is the operation, is profiled independently from the others*/
#define INSERT_OP(x) m->insert( make_pair (string(#x), CountP( "__dyn_count_" #x, NULL, #x)))
  /* INSERT_OP(x,y) as the previous one, to profile one single operation, but specifying a different label */
#define INSERT_OP_L(x,y) m->insert( make_pair (string(#x), CountP( "__dyn_count_" #x, NULL, #y)))
  /* INSERT_OP(x,y) to profile operation x grouping it with y, i.e. to sum all the x operations in y counter */
#define INSERT_OP_G(x,y) m->insert( make_pair (string(#x), CountP( "__dyn_count_" #y, &((*m)[#y].st_cnt), #x)))

  using namespace std;

  /* struct used to store one operation */

  struct CountP {
    unsigned int st_cnt;     // internal counter for static profiling, i.e. it counts how many ops there are in the .s
    string dyn_cnt; // name of the variable for the dynamic profiling, if two or more operations need to be grouped
                    // it is enough to specify the same string so that the same var counter will be used

    unsigned int * st_cnt_p; // pointer to an int var that is the counter of another op, used to group operation
    string label; // string that is print in the output files

    CountP(){}
    CountP ( string dyn, unsigned int * stp , string l) : st_cnt (0), dyn_cnt (dyn), st_cnt_p(stp), label(l) {}
  };


  // declare the hash-table storing all the operations 
  map<string, CountP> m;

  
  void generate_var_declaration(map<string, CountP>* m)
    {
      // generate in the simulator source code the declaration of the functions
      // used to write in the output file
      cout << "extern void __dyn_prof_write(char * str, unsigned int n);" << endl;
      cout << "extern void __dyn_prof_init_file();" << endl;
      cout << "extern void __dyn_prof_close_file();" << endl;

      // dynamically declare the variable for couting the operations
      map<string, CountP>::iterator it;
      for(it = m->begin(); it!= m->end(); ++it)
	{
	  if (it->second.st_cnt_p == NULL)
	    {
	      cout << "unsigned int  " << it->second.dyn_cnt  << " = 0 ;" << endl;
	    }
	}


    }

  void generate_print_profiling(map<string, CountP>* m)
    {
      // generate the __dyn_prof_generate function, that will be declared in the 
      // simulator source code and will be called using the -at_exit parameter

      cout << "void __dyn_prof_generate () {" << endl;
      // it will init the file, i.e. it creates the output file
      cout << "__dyn_prof_init_file();" << endl;

      // it writes all the entries of the hash table
      map<string, CountP>::iterator it;
      for(it = m->begin(); it!= m->end(); ++it)
	{
	  if (it->second.st_cnt_p == NULL)
	    {
	      cout << "__dyn_prof_write(\"operation:  \\t" << it->second.label << "\\t n. times: \\t%d \\n\", " << it->second.dyn_cnt << ");" << endl;
	    }
	}
      // close the output file
      cout << "__dyn_prof_close_file();" << endl;
      cout << "}" << endl;
 
    }

  void init_hash_table(map<string, CountP> *m)
    {
      /* this is the function that can be modified by the user 
         in order to profile in different and custom way a certain operation */
      
      /* In order to provide an example where we want to group three operations, 
	 ADD, RETURN, MOV
	 we declare a main operation with the following macro call
	 
	 INSERT_OP_L(ADD,ADD MOV RETURN);
	 
	 specifying a different label so that in the output file the label recall us 
	 that the three operations are grouped.
	 and then we declare in the following way the others operations:
	 
	 INSERT_OP_G(RETURN, ADD);
	 INSERT_OP_G(MOV, ADD);

         where it is clear that they are referring to ADD as main one.
	 
	 or we could specify MOV without using a macro 
	  
	 m->insert( make_pair (string("MOV"), CountP( "__dyn_count_ADD", &((*m)["ADD"].st_cnt), "ADD MOV")));	 

      */

      // an example of inserting an operation in the hash_table without using the macro
      m->insert( make_pair (string("ADD"), CountP( "__dyn_count_ADD", NULL, "ADD MOV")));
    
      // normal operations that are profiled separately
      // if a user does not need to profile an operation it is enough to delete the corresponding macro call
      INSERT_OP(MULL);
      INSERT_OP(MULLU);
      INSERT_OP(MULH);
      INSERT_OP(MULHU);
      INSERT_OP(MULHS);
      INSERT_OP(MULLL);
      INSERT_OP(MULLLU);
      INSERT_OP(MULLH);
      INSERT_OP(MULLHU);
      INSERT_OP(MULLHHU);
      INSERT_OP(STW);
      INSERT_OP(RETURN);
      INSERT_OP(CALL);
      INSERT_OP(MOV);
      INSERT_OP(LDBs);
      INSERT_OP(LDB);
      INSERT_OP(LDBUs);
      INSERT_OP(LDBU);
      INSERT_OP(LDHs);
      INSERT_OP(LDH);
      INSERT_OP(LDHUs);
      INSERT_OP(LDHU);
      INSERT_OP(LDWs);
      INSERT_OP(LDW);
      INSERT_OP(STB);
      INSERT_OP(STH);
      INSERT_OP(STW);
      INSERT_OP(AND);
      INSERT_OP(ANDC);
      INSERT_OP(ANDL);
      INSERT_OP(CMPEQ);
      INSERT_OP(CMPGE);
      INSERT_OP(CMPGEU);
      INSERT_OP(CMPGT);
      INSERT_OP(CMPGTU);
      INSERT_OP(CMPLE);
      INSERT_OP(CMPLEU);
      INSERT_OP(CMPLT);
      INSERT_OP(CMPLTU);
      INSERT_OP(CMPNE);
      INSERT_OP(MAX);
      INSERT_OP(MAXU);
      INSERT_OP(MIN);
      INSERT_OP(MINU);
      INSERT_OP(MFB);
      INSERT_OP(MFL);
      INSERT_OP(MTL);
      INSERT_OP(MTB);
      INSERT_OP(MTBINV);
      INSERT_OP(MUL);
      INSERT_OP(NANDL);
      INSERT_OP(NOP);
      INSERT_OP(NORL);
      INSERT_OP(ORL);
      INSERT_OP(OR);
      INSERT_OP(ORC);
      INSERT_OP(PFT);
      INSERT_OP(SBIT);
      INSERT_OP(SBITF);
      INSERT_OP(SH1ADD);
      INSERT_OP(SH2ADD);
      INSERT_OP(SH3ADD);
      INSERT_OP(SH4ADD);
      INSERT_OP(SHL);
      INSERT_OP(SHR);
      INSERT_OP(SHRU);
      INSERT_OP(SLCT);
      INSERT_OP(SLCTF);
      INSERT_OP(SUB);
      INSERT_OP(SXTB);
      INSERT_OP(SXTH);
      INSERT_OP(TBIT);
      INSERT_OP(TBITF);
      INSERT_OP(XNOP);
      INSERT_OP(XOR);
      INSERT_OP(ZXTB);
      INSERT_OP(ZXTH);
      INSERT_OP(ADDCG);
      INSERT_OP(DIVS);
    }

  void generate_static_profiling(  map<string, CountP> *m, string filename)
    {
      // generate the output file of the static profiling
      ofstream f;
      f.open(filename.c_str(), ios::out);

      map<string, CountP>::iterator it;
      for(it = m->begin(); it!= m->end(); ++it)
	{
	  if (it->second.st_cnt_p == NULL)
	    {
	      f << "operation: \t" << it->second.label << "\t n. times: \t" << it->second.st_cnt << endl;
	    }
	}
      f.close();
    }

%}

%%

<INITIAL>{DECLARATION_POINT}.*{CLOSE_PAR}{SEMICOLON} {
  // identify the point for the declaration of the variables 
  // and the function for generating the output file 
  // right after the prototype of __vex_main()
  cout << "/* DYN PROFILER COUNTERS  */" << endl;
  generate_var_declaration(&m);
  cout << "/* DYN PROFILER COUNTERS END  */" << endl;
  cout << "/* DYN PROFILER PRINT  */" << endl;
  generate_print_profiling(&m);
  cout << "/* DYN PROFILER PRINT END  */" << endl;
  cout << yytext;

}

<INITIAL>{DEFINE}{SPACE}*{OP_SEPARATOR} {
  // in order to not process the declaration of the op. macro
  cout << yytext;
}

<INITIAL>^{SPACE}*{OP_SEPARATOR} {
  // possible operation to be processed
  BEGIN(OPERATION);
}


<OPERATION>{VAR}{OPEN_PAR} {
  // process the possible operation
  string s = yytext;
  s = s.substr(0,s.length()-1); // removes the OPEN_PAR, to retrieve only the name
  map<string, CountP>::iterator i = m.find(s);

  if (i != m.end())
    {
      if (i->second.st_cnt_p == NULL)
	i->second.st_cnt++;
      else
	(*(i->second.st_cnt_p))++;
      
      cout << " " << i->second.dyn_cnt << "++; " << OP_SEP << yytext;
      
    }
  else
    cout << OP_SEP << yytext;

  BEGIN(INITIAL);
}

<OPERATION>. {
  cout << yytext;
  BEGIN(INITIAL);
}

%%

int main () {

  /* create the hash table, filling it with the operations that need to be traced */
  init_hash_table(&m);
  
  /* parse the file */
  yylex();
 
  /* write the statistics about static profiler */
  generate_static_profiling(&m, "static_prof_file.txt");
  return 1;
}

