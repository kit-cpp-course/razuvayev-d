#include "kernel.h"
#include "file.h"
#include "ElGamal.h"

/*Демонстрация работы и общение с пользователем через консоль*/
	void Encryption();
	void Decryption();

	int main() {
		setlocale(LC_ALL, "RUSSIAN");
		int g;
		cout << "Выберите режим работы 1 -- шифрование, 0 -- расшифрование" << endl;
		cin >> g;
		switch (g)
		{
		case 1: Encryption(); break;
		case 0: Decryption(); break;
		default:
			cout << "Такого режима не существует";
			break;
		}
	}

	void Encryption() {
		int g; string FileAdr;
		cout << "Чтобы ввести адрес файла с открытым текстом нажмите 1. Чтобы использовать адрес по-умолчанию нажмите 0";
		cin >> g;
		if (g) {
			cout << "Введит адрес файла с открытым текстом: " << endl;
			cin >> FileAdr; cout << endl;
			ElGamal M(FileAdr);
			M.Encryption();
			cout << "Файл был зашифрован." << endl
				<< "В каталоге нахождения исходного файла созданы файлы:" << endl
				<< "CryptoTextA.txt и CryptoTextB.txt -- зашифрованное сообщение" << endl
				<< "PublicKey.txt и PrivateKey.txt -- открытый и закртый ключ соответственно" << endl;
		}
		else {
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
	}
	void Decryption() {
		string A, B, Pub, Pr;
		cout << "Введите адрес файла CryptoTextA.txt" << endl;
		cin >> A; A = file::ExCheck(A);
		cout << "Введите адрес файла CryptoTextB.txt" << endl;
		cin >> B; B = file::ExCheck(B);
		cout << "Введите адрес файла PublicKey.txt" << endl;
		cin >> Pub; Pub = file::ExCheck(Pub);
		cout << "Введите адрес файла PrivateKey.txt" << endl;
		cin >> Pr; Pr = file::ExCheck(Pr);
		ElGamal P; P.Decryption(A, B, Pub, Pr);
		cout << "Адрес расшифровки: Crypt/Decr.txt";
		system("pause");
	}

	