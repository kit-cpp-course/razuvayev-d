#include "ElGamal.h"
using namespace ElGam;

ElGamal::ElGamal() {
		CreateDirectory(L"Crypt", NULL);
		FileAdress = "Crypt/OpenText.txt";
		Createfile(FileAdress);
		Output = bydefault();
	}
	
ElGamal::ElGamal(string FileAdress) {
		ElGamal::FileAdress = ExCheck(FileAdress);
		Output = FileGen(LocatingDirectory(FileAdress));
	}
	
	void ElGamal::Encryption() {
		FileAdress = ExCheck(FileAdress);
		string OpenText = ReadFile(FileAdress);
		shell S(OpenText);
		S.Encryption();
		WriteInFile(S.GetA(), Output[0]);
		WriteInFile(S.GetB(), Output[1]);
		WriteInFile(S.GetPublicKey(), Output[2]);
		WriteInFile(S.GetPrivateKey(), Output[3]);
	}
	
	void ElGamal::Decryption(string CrFileAdressA, string CrFileAdressB,
		string PubKeyFileAdress, string PrKeyFileAdress) {
		vector<size_t> A = ReadCryptFile(CrFileAdressA);
		vector<size_t> B = ReadCryptFile(CrFileAdressB);
		vector<size_t> Priv = ReadCryptFile(PrKeyFileAdress);
		vector<size_t> Pub = ReadCryptFile(PubKeyFileAdress);
		string DecrText = shell::Decryption(A, B, Pub, Priv);
		string Adress = "Crypt/Decr.txt";
		Createfile(Adress);
		WriteInFile(DecrText, Adress);
	}

	string ElGamal::LocatingDirectory(const string FileAdress) {
		string str = FileAdress.substr(0, FileAdress.find_last_of("/"));
		return (str == FileAdress ? "" : str);
	}
	
	vector<string> ElGamal::FileGen(string AdrDir) {
		vector<string> S(4);
		S[0] = AdrDir + "CryptoTextA.txt";
		Createfile(S[0]);//файл шифротекста А
		S[1] = AdrDir + "CryptoTextB.txt";
		Createfile(S[1]);//файл шифротекста В
		S[2] = AdrDir + "PublicKey.txt";
		Createfile(S[2]);//файл открытого ключа
		S[3] = AdrDir + "PrivateKey.txt";
		Createfile(S[3]);//файл закрытого ключа
		return S;
	}
	
	vector<string> ElGamal::bydefault() {
		vector<string> S(4);
		S[0] = "Crypt/CryptoTextA.txt";
		Createfile(S[0]);
		S[1] = "Crypt/CryptoTextB.txt";
		Createfile(S[1]);
		S[2] = "Crypt/PublicKey.txt";
		Createfile(S[2]);
		S[3] = "Crypt/PrivateKey.txt";
		Createfile(S[3]);
		return S;
	}
