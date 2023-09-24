/**
 * 
 * Author: withtahmid
 * Created: 16-07-22 23:59
 * Updated: 09-08-22 02:52
 * Updated: 30-08-22 20:40
 * Updated: 23-10-22 03:45
 * Updated: 14-12-22 03:17
 * 
 * */
#include<bits/stdc++.h>
#include<ctime>
#include <sys/stat.h>
#include<unistd.h> 
#include <fstream>
#include<debug.h>
using namespace std;
string dateNtime = " * Created: ";
const string date_signature = " * Created: dd-mm-yy hh:mm";
void generate_date()
{
	time_t rawtime;
  	struct tm * timeinfo;
  	char buffer[80], rand[50];
 	time (&rawtime);
  	timeinfo = localtime(&rawtime);
  	strftime(buffer,sizeof(buffer),"%d-%m-%Y %H:%M:%S",timeinfo);
  	strftime(rand,sizeof(buffer),"%d-%m-%Y-%H-%M-%S",timeinfo);
  	string str(buffer);
  	string randd(rand);
  	dateNtime += str;
}
void create_files(int numOfFile){	
	for(int i = 0; i < numOfFile; i++){
		char name = 'A' + i;
	    string fileName;
	    fileName += name;
	    fileName += ".cpp";
		string line;
	    ifstream ini_file{
	        "Template.cpp"
	    };
	    
	    ofstream out_file{ fileName};
	    if (ini_file and out_file) {
	  
	        while (getline(ini_file, line)) {
	        	while(line.size() and line[line.size()-1] == 13){
	        		line.pop_back();
	        	}
	        	if(line == date_signature)
	        		line = dateNtime;
	            out_file << line << "\n";
	        }
	    }
	    else {
	       cout<< "Cannot create file: "<<i<<endl;
	    	return;
	    }
	    ini_file.close();
	    out_file.close();
	}

}

int main(){
	init(0);

	create_files(5);

	init(1);
}