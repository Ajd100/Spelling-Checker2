// g++ dicGrab.cpp -std=c++11

//NOTE: All words input will be lowercased
//The hash_string() method was created and put into the header file "utilities.h"


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
#include "utilities.h"
using namespace std;


int main() {
	vector<string> words = fileToStringArray("./dictionary.txt");
	unordered_map<string, size_t> dictMap;
	unordered_map<string, size_t>::iterator it;
	string key;
	int value;
	string s1;
	
	//Populating the Dictionary with the string pointing to an unsigned int
	for (int i = 0; i < words.size(); ++i){
		key = words[i];
		int j = 0;
		//Converting all letters to lowercase
		while(key[j]){
			key[j] = tolower(key[j]);
			++j;
		}
		
		size_t hash = hash_string(key);
		it = dictMap.find(key);
		//Checking if the end of the map is there, if so and there's still things to insert (i), insert them.
			if(it == dictMap.end()){
				dictMap.insert(pair<string, size_t>(key, hash));
			}
		}
		
	 //Converting each input into a hash then checking that hash against the dictionary
	 s1 = " ";
	 //Creates an "infinite" loop until we tell it to exit
	 cout << "Type 'close checker' to exit the loop " << endl;
	 while(!s1.empty()){
 	 cout << "Please enter a word we can check with the dictionary: " << endl;
	 getline(cin, s1);
	 
	 //This is the exit statement
	  if(s1 == "close checker"){
		  cout << "Closing..." << endl;
			 break;
		 }
	 //Converting the characters given to lowercase
	 for(int i = 0; i < s1.length(); ++i ){
		 s1[i] = tolower(s1[i]);
	 }
	 //Hashing the string given and setting a boolean to false until we find a hash in the dictionary
	 size_t spellHash = hash_string(s1);
	 bool isIn = false;
	
	//Iterating and checking if the hashed value is in the dictionary
	for(it = dictMap.begin(); it != dictMap.end(); ++it){
		if(spellHash == it->second){
			isIn = true;
			break;
		}
	}
	//Printing the results
	if(isIn == true){
		cout << s1 << " | is spelled correctly" << endl << endl;
	}else
		cout << s1 << " | is not spelled correctly" << endl << endl;
		 
	}
	//This is for checking the dictionary. (Prints out a easy to understand statement String -> Hash)
 	 for(it = dictMap.begin(); it != dictMap.end(); it++){
		 cout << it->first << " -> " << it->second << endl;
	 }
 		 
}