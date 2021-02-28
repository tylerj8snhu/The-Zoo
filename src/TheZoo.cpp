/*
 * TheZoo.cpp
 *
 *  Date: 02/27/21
 *  Author: Tyler Johnson
 */
#include <iostream>
#include <fstream>
#include <iterator>
#include <jni.h>
#include <vector>
#include <algorithm>

#include "AnimalHierarchy/Animal.h"
#include "AnimalHierarchy/SubTypes/Bat.h"
#include "AnimalHierarchy/SubTypes/Whale.h"
#include "AnimalHierarchy/SubTypes/SeaLion.h"
#include "AnimalHierarchy/SubTypes/Crocodile.h"
#include "AnimalHierarchy/SubTypes/Goose.h"
#include "AnimalHierarchy/SubTypes/Pelican.h"

using namespace std;

void GenerateData()               //DO NOT TOUCH CODE IN THIS METHOD
{
	JavaVM *jvm;                    // Pointer to the JVM (Java Virtual Machine)
	JNIEnv *env;                      // Pointer to native interface
									  //================== prepare loading of Java VM ============================
	JavaVMInitArgs vm_args;                        // Initialization arguments
	JavaVMOption* options = new JavaVMOption[1];   // JVM invocation options
	options[0].optionString = (char*) "-Djava.class.path="; // where to find java .class
	vm_args.version = JNI_VERSION_1_6;             // minimum Java version
	vm_args.nOptions = 1;                          // number of options
	vm_args.options = options;
	vm_args.ignoreUnrecognized = false; // invalid options make the JVM init fail
										//=============== load and initialize Java VM and JNI interface =============
	jint rc = JNI_CreateJavaVM(&jvm, (void**) &env, &vm_args);  // YES !!
	delete options;    // we then no longer need the initialisation options.
	if (rc != JNI_OK) {
		// TO DO: error processing...
		cin.get();
		exit(EXIT_FAILURE);
	}
	//=============== Display JVM version =======================================
	cout << "JVM load succeeded: Version ";
	jint ver = env->GetVersion();
	cout << ((ver >> 16) & 0x0f) << "." << (ver & 0x0f) << endl;

	jclass cls2 = env->FindClass("ZooFileWriter");  // try to find the class
	if (cls2 == nullptr) {
		cerr << "ERROR: class not found !";
	} else {                                  // if class found, continue
		cout << "Class MyTest found" << endl;
		jmethodID mid = env->GetStaticMethodID(cls2, "createZooFile", "()V"); // find method
		if (mid == nullptr)
			cerr << "ERROR: method void createZooFile() not found !" << endl;
		else {
			env->CallStaticVoidMethod(cls2, mid);                 // call method
			cout << endl;
		}
	}

	jvm->DestroyJavaVM();
	cin.get();
}

void AddAnimal(vector<Animal*> *animalVector) {
	string name;
	int trackNum, eggsOrNurse, type, subType;
	bool exit = false;

	cout << "Tack Number: " << endl;
	while (exit != true) {
		cin >> trackNum;
		if (to_string(trackNum).length() != 6) {
			cout << "Track Number must be 6 digits: ";
		} else
			exit = true;
	}

	exit = false;

	cout << "Name: " << endl;
	while (exit != true) {
		cin >> name;
		if (name.length() > 15) {
			cout << "Name must be no more than 15 characters: ";
		} else
			exit = true;
	}

	exit = false;

	cout << "Type (1) for Mammal or (2) for Oviparous: " << endl;
	cin >> type;

	while (exit != true) {

		if (type == 1) {
			cout << "(1)Bat, (2)Whale, or (3)Sea Lion: ";

			while (exit != true) {
				cin >> subType;
				if (subType < 1 || subType > 3) {
					cout
							<< "Please select (1) for Bat, (2) for Whale, or (3) for Sea Lion: ";
				} else
					exit = true;
			}

			cout
					<< "Select (0) if animal is not nursing, or select (1) if animal is currently nursing: ";
			exit = false;

			while (exit != true) {
				cin >> eggsOrNurse;
				if (eggsOrNurse < 0 || eggsOrNurse > 1) {
					cout
							<< "Please select (0) if animal is not nursing, or select (1) if animal is currently nursing: ";
				} else
					exit = true;
			}

		}

		else if (type == 2) {
			cout << "(1)Crocodile, (2)Goose, or (3)Pelican: ";

			while (exit != true) {
				cin >> subType;
				if (subType < 1 || subType > 3) {
					cout
							<< "Please select (1) for Crocodile, (2) for Goose, or (3) for Pelican: ";
				} else
					exit = true;
			}

			cout << "Number of Eggs: ";
			cin >> eggsOrNurse;
		}

		else {
			cout
					<< "Please select either (1) for Mammal or (2) for Oviparous: ";
			cin >> type;
		}
	}

	cout << endl;
	cout << "New Animal" << endl;
	cout << "====================" << endl;
	cout << "Track Number: " << trackNum << endl;
	cout << "Name: " << name << endl;
	cout << "Type: ";

	if (type == 1) {
		cout << "Mammal" << endl;
		cout << "Sub Type: ";
		if (subType == 1)
			cout << "Bat" << endl;
		else if (subType == 2)
			cout << "Whale" << endl;
		else if (subType == 3)
			cout << "Sea Lion" << endl;
		cout << "Nursing: ";
		if (eggsOrNurse == 0) {
			cout << "No" << endl;
		} else {
			cout << "Yes" << endl;
		}
	}

	else if (type == 2) {
		cout << "Mammal" << endl;
		cout << "Sub Type: ";
		if (subType == 1)
			cout << "Crocodile" << endl;
		else if (subType == 2)
			cout << "Goose" << endl;
		else if (subType == 3)
			cout << "Pelican" << endl;
		cout << "Eggs: " << eggsOrNurse << endl;
	}

	char save;
	cout << "Hit Y(yes) to save, Would You Like to Save? ";
	cin >> save;
	if (save != 'y')
		return;

	if (type == 1) {
		if (subType == 1)
			animalVector->push_back(new Bat(name, trackNum, eggsOrNurse));
		else if (subType == 2)
			animalVector->push_back(new Whale(name, trackNum, eggsOrNurse));
		else if (subType == 3)
			animalVector->push_back(new SeaLion(name, trackNum, eggsOrNurse));
	}

	else if (type == 2) {
		if (subType == 1)
			animalVector->push_back(new Crocodile(name, trackNum, eggsOrNurse));
		else if (subType == 2)
			animalVector->push_back(new Goose(name, trackNum, eggsOrNurse));
		else if (subType == 3)
			animalVector->push_back(new Pelican(name, trackNum, eggsOrNurse));
	}

}

void RemoveAnimal(vector<Animal*> *animalVector) {
	int animalToErase, index = 0;
	cout << "Enter the Track Number of the Animal you would like to remove: ";
	cin >> animalToErase;

	for (int i = 0; i < animalVector->size(); i++) {
		if (animalVector->at(i)->getTrackNum() == animalToErase) {
			index = i;
		}
	}
	animalVector->erase(animalVector->begin() + index);
}

string& trimLeft(string& str, const string& chars = "\t\n\v\f\r ") {
	str.erase(str.find_last_not_of(chars) + 1);
	return str;
}

void LoadDataFromFile(vector<Animal*> *animalVector) {
	//TODO make multi line work
	string fileOutput;
	string name, type, subType, trackNumStr, eggsStr, nurseStr;
	int trackNum, nurse, eggs;

	ifstream zooFile("zoodata.txt");

	while (!zooFile.eof()) {

		trackNumStr.resize(6, ' ');
		name.resize(15, ' ');
		type.resize(15, ' ');
		subType.resize(15, ' ');
		eggsStr.resize(1, ' ');
		nurseStr.resize(1, ' ');

		char* begin = &*trackNumStr.begin();
		zooFile.read(begin, 6);

		begin = &*name.begin();
		zooFile.read(begin, 15);

		begin = &*type.begin();
		zooFile.read(begin, 15);

		begin = &*subType.begin();
		zooFile.read(begin, 15);

		begin = &*eggsStr.begin();
		zooFile.read(begin, 2);

		begin = &*nurseStr.begin();
		zooFile.read(begin, 1);

		trimLeft(name);
		trimLeft(type);
		trimLeft(subType);
		trimLeft(eggsStr);
		trimLeft(nurseStr);

//		cout << "track:" << trackNumStr << "::" << endl;
//		cout << "eggs:" << eggsStr << "::" << endl;
//		cout << "nurse:" << nurseStr << "::" << endl;
		trackNum = stoi(trackNumStr);
		eggs = stoi(eggsStr);
		nurse = stoi(nurseStr);

		if (type == "Mammal") {
			if (subType == "Bat")
				animalVector->push_back(new Bat(name, trackNum, nurse));
			else if (subType == "Whale")
				animalVector->push_back(new Whale(name, trackNum, nurse));
			else if (subType == "Sea Lion")
				animalVector->push_back(new SeaLion(name, trackNum, nurse));
		}
		else if (type == "Oviparous") {
			if (subType == "Crocodile")
				animalVector->push_back(new Crocodile(name, trackNum, eggs));
			else if (subType == "Goose")
				animalVector->push_back(new Goose(name, trackNum, eggs));
			else if (subType == "Pelican")
				animalVector->push_back(new Pelican(name, trackNum, eggs));

		}
		string str;
		getline(zooFile, str);

	}
	zooFile.close();

}

string addWhiteSpace(string str, int length) {
	while (str.length() < length) {
		str.push_back(' ');
	}
	return str;
}

void SaveDataToFile(vector<Animal*> *animalVector) {
	string name, type, subType, eggs, nurse;
	ofstream zooFile("zoodata.txt", ofstream::out | ofstream::trunc);

	for (int i = 0; i < animalVector->size(); i++) {
		zooFile << animalVector->at(i)->getTrackNum();

		name = animalVector->at(i)->getName();
		name = addWhiteSpace(name, 15);
		zooFile << name;

		type = animalVector->at(i)->getType();
		type = addWhiteSpace(type, 15);
		zooFile << type;

		subType = animalVector->at(i)->getSubType();
		subType = addWhiteSpace(subType, 15);
		zooFile << subType;

		eggs = to_string(animalVector->at(i)->getEggs());
		eggs = addWhiteSpace(eggs, 2);
		zooFile << eggs;

		zooFile << animalVector->at(i)->getNurse();
		if (i + 1 != animalVector->size()) {
			zooFile << "\n";
		}


	}
	zooFile.close();
}
void DisplayData(vector<Animal*> *animalVector) {
	for (int i = 0; i < animalVector->size(); i++) {
		cout << endl;
		cout << "Animal #" << i+1 << endl;
		cout << "============" << endl;
		cout << "Track Number: " << animalVector->at(i)->getTrackNum() << endl;
		cout << "Name: " << animalVector->at(i)->getName() << endl;
		cout << "Type: " << animalVector->at(i)->getType() << endl;
		cout << "Sub Type: " << animalVector->at(i)->getSubType() << endl;
		cout << "Eggs: " << animalVector->at(i)->getEggs() << endl;
		cout << "Nurse: " << animalVector->at(i)->getNurse() << endl;
	}
	cout << endl << endl;

}

void DisplayMenu() {
	vector<Animal*> animalVector;
	int userOption;
	bool exit = false;

	while (exit != true) {
		cout << "Select Menu" << endl;
		cout << "==================" << endl;
		cout << "1) Load Animal Data" << endl;
		cout << "2) Generate Data" << endl;
		cout << "3) Display Animal Data" << endl;
		cout << "4) Add Record" << endl;
		cout << "5) Delete Record" << endl;
		cout << "6) Save Animal Data" << endl;
		cout << "7) Exit" << endl;
		cout << "==================" << endl;
		cout << "Select from list above: ";
		cin >> userOption;
		cout << endl << endl;

		switch (userOption) {
		case 1:
			LoadDataFromFile(&animalVector);
			break;
		case 2:
			GenerateData();
			break;
		case 3:
			DisplayData(&animalVector);
			break;
		case 4:
			AddAnimal(&animalVector);
			break;
		case 5:
			RemoveAnimal(&animalVector);
			break;
		case 6:
			SaveDataToFile(&animalVector);
			break;
		case 7:
			exit = true;
			break;
		default:
			break;

		}
	}

}

int main() {

	DisplayMenu();
	return 1;
}
