/*main.cpp*/
#include <sstream>
#include "kernel.h"
#include "file.h"
#include "ElGamal.h"

/*Демонстрация работы и общение с пользователем через консоль*/
void Encryption(string);
int main(int arg, char *Argsval[]) {
	setlocale(LC_ALL, "RUSSIAN");
	if (arg == 3) {
		stringstream Com(Argsval[1]), Fname(Argsval[2]);
		string Comman, FileAdress;
		Com >> Comman; Fname >> FileAdress;
		if (Comman == "Encryption")  Encryption(FileAdress);
		else cout << "Command undefined";
	}
	else {
		if (arg == 6) {
			vector<string> Val(arg);
			for (size_t i = 1; i < arg; i++) {
				stringstream S(Argsval[i]);
				S >> Val[i];
			}
			if (Val[1] == "Decryption") {
				ElGamal Z(Val[2]);
				Z.Decryption(Val[2], Val[3], Val[4], Val[5]);
				}
			else cout << "Command undefined";
		}
	}	
}

void Encryption(string FileAdress) {
	if (FileAdress == "bydefault"){
		ElGamal S;
		cout << "В каталоге программы была создана папка Crypt." << endl
			<< "Найдите в ней файл OpenText.txt и запишите туда ваше сообщение" << endl;
		system("pause");
		cin.get();
		S.Encryption();
		cout << "Файл был зашифрован." << endl
			<< "В каталоге Crypt созданы файлы:" << endl
			<< "CryptoTextA.txt и CryptoTextB.txt -- зашифрованное сообщение" << endl
			<< "PublicKey.txt и PrivateKey.txt -- открытый и закртый ключ соответственно" << endl;
		system("pause");	
	}
	else {
		ElGamal M(FileAdress);
		M.Encryption();
		cout << "Файл был зашифрован." << endl
			<< "В каталоге нахождения исходного файла созданы файлы:" << endl
			<< "CryptoTextA.txt и CryptoTextB.txt -- зашифрованное сообщение" << endl
			<< "PublicKey.txt и PrivateKey.txt -- открытый и закртый ключ соответственно" << endl;
	}
}
	
		

	