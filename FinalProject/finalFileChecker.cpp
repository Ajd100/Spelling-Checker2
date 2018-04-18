// g++ fileChecker.cpp -std=c++11

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
	//Dictionary map
	vector<string> words = fileToStringArray("./dictionary.txt");
	unordered_map<string, size_t> dictMap;
	unordered_map<string, size_t>::iterator it;
	
		//File map
		vector<string> fileWords = fileToStringArray("./test.txt");
		unordered_map<string, size_t> fileMap;
		unordered_map<string, size_t>::iterator it2;
	//	unordered_map<string, size_t>::iterator it3; //I don't think I need this... Uncomment if needed
	
	string key;
	int value;
	string s1;
	string key1;
	size_t hash;
	bool isIn = false;
	int wordCount;
	
	//Populating the Dictionary with the string pointing to an unsigned int
	for (int i = 0; i < words.size(); ++i){
		key = words[i];
		int j = 0;
		//Sending everything to lowercase
		while(key[j]){
			key[j] = tolower(key[j]);
			++j;
		}
		
		hash = hash_string(key);
		it = dictMap.find(key);
		//Checking if the end of the map is there, if so and there's still things to insert (i), insert them.
			if(it == dictMap.end()){
				dictMap.insert(pair<string, size_t>(key, hash));
			}
		}
		
	//Converting the file to a map with the string pointing to an unsigned int	
	wordCount = fileWords.size();
	//string wordArray[100]; More unnecessary code
	//Populating the file array to compare against the dictionary
	cout << "Checking... This make take a minute. " << endl;
	for (int i = 0; i < fileWords.size(); ++i){
		key1 = fileWords[i];
		int j = 0;
		while(key1[j]){
			key1[j] = tolower(key1[j]);
			++j;
		}
		
		hash = hash_string(key1);
		it = fileMap.find(key1);
		//Checking if the end of the map is there, if so and there's still things to insert (i), insert them.
			if(it == fileMap.end()){
				fileMap.insert(pair<string, size_t>(key1, hash));
			}
			
			//Checking every value in the new fileMap to a hash value in the dictionary
			for(it2 = dictMap.begin(); it2 != dictMap.end(); ++it2){
				//Checking if the hash gained from the file is equal to the second value in the dictionary
				if(hash == it2->second){
				fileMap.erase(key1); // This line of code is our saving grace - Deleting the entry point so that the only words left are misspelled
					wordCount--;
					break;
				}
			} 
		}
		//Printing the misspelled words to the console
		for(it = fileMap.begin(); it != fileMap.end(); ++it){
			cout << it->first << " is spelled incorrectly" << endl;
		}
	//Adding an integer value to the misspelled words in the file
	cout << endl << "There are this many misspelled words: " << wordCount << endl << "These words could be used more than once" << endl;
}