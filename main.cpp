#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
//#include <string.h>
using namespace std;

#define PLI "\"tty2\""\

#define mli "loginctl | awk '{if($5!="PLI") print $1}' > lgn.txt" \

int main(int argc,char** argv)
{
	vector<string> results;

	ifstream in("lgn.txt");
	string line;
	string mlk;
	string llk;

    mlk.clear();
    llk.clear();

    llk+='"';
    llk+=argv[1];
    llk+='"';
    mlk+="loginctl | awk '{if($5!= " +  llk + " ) print $1}' > lgn.txt";
    cout<<mlk <<"\n";
    system(mlk.c_str());

	while(getline(in, line)){
      // xs=line.find("TTY",0);
      // tt_y2=line.find("tty2",0);
	  // if(tt_y2== string::npos){
	      cout<<line << "\n" ;
	    // }
       results.push_back(line);
      // x+=1;
    }
        line.clear();
        line+="loginctl kill-session ";
        cout<<"\n";
        for(int i=0;i<=results.size()-3;i++){
          cout<<"with ID " << results.at(i)<<" ---> ";
          line+=results.at(i);
          cout<<"da line to kill " << line <<"\n";
          system(line.c_str());
          line.clear();
          line+="loginctl kill-session ";
        }
        system("exit");

        return 0;
}
