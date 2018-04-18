// Read a text file into a string

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

#ifndef UTILITIES
#define UTILITIES

//Sending a file to a string
string fileToString (string fileName){
	string line;
	string result = "";
	ifstream ifs(fileName.c_str());
	
	if (ifs.is_open()){
		while (getline(ifs,line)) {
			result += line;
		}
		ifs.close();
	}
	
	return result;
}

//Cleaning the text (removing punctuation, spaces, etc.)
string cleanText (string res){
	string data = res;
	string result;
	
	remove_copy_if(data.begin(), data.end(), back_inserter(result), ptr_fun<int, int>(ispunct));
	
	return result;
	
}

//Sending the file converted to a string Array
vector<string> fileToStringArray(string fileName){

	vector<string> vstr;
	string data = fileToString(fileName);
	string str = cleanText(data);
	stringstream ssin(str);
	string word;
	
	while (ssin.good()) {
		ssin >> word;
		vstr.push_back(word);
	}

	// for (int i = 0; i < vstr.size(); i++ ) {
		// cout << vstr[i] << endl;
	// }
	
	return vstr;
	
}

//This is the hashing function, it hashes the called value and returns the hash.
size_t hash_string(string s){
	hash<string> myHash;
	string s1 = s;
	size_t h = myHash(s1);
	return h;
}

#endif