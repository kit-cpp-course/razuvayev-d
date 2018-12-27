#include "file.h"

	string file::ReadFile(const string FileAdress) {
		ifstream file(FileAdress);
		string line, message = "";
		while (getline(file, line)) {
			message += line;
		}
		file.close();
		return message;
	}
	
	void file::WriteInFile(const vector<size_t> Cryp, const string FileAdress) {
		fstream file;
		file.open(FileAdress, fstream::in | fstream::out);
		size_t s = Cryp.size();
		for (size_t i = 0; i < s; i++)
			file << Cryp[i] << endl;
		file.close();
	}
	
	void file::WriteInFile(const string Text, const string FileAdress) {
		fstream file;
		file.open(FileAdress, fstream::in | fstream::out);
		file << Text;
	}
	
	vector<size_t> file::ReadCryptFile(const string FileAdress) {
		ifstream file(FileAdress);
		string line;
		vector<size_t> Result; Result.reserve(1000);
		while (getline(file, line)) {
			Result.push_back(stoi(line));
		}
		file.close();
		return Result;
	}
	
	void file::Createfile(const string FileAdress) {
		ofstream file(FileAdress);
		file.close();
	}
