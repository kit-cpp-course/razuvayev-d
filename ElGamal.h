/*ElGamal.h*/
#pragma once
#include "stdafx.h"
#include "file.h"
#include "shell.h"

using namespace ElGam;
/*Класс, собственно, шифрования файлов
 *Задача -- зашифровать файл, превратив его в пару файлов с шифротекстом,
 *сгенерировать файлы-ключи.
 *Расшифровывать зашифрованные файлы при помощи файлов-ключей
 */
class ElGamal : protected file, private shell {
	string FileAdress; //Адрес исходного файла
	vector<string> Output; //адреса файлов-шифротекстов и файлов-ключей
public:
	/*Конструктор по-умолчанию
	* Создает папку Crypt в корневом каталоге программы
	* куда сохраняет все файлы
	*/
	ElGamal();
	/*Конструктор по введенному адресу
	* Определяет адрес директории переданного файла 
	* и сохраняет все рабочие файлы туда
	*/
	ElGamal(string FileAdress);
	/*Конструктор по введенному массиву адресов
	* Определяет адрес директории первого переданного файла
	* и сохраняет все рабочие файлы туда
	*/
	ElGamal(vector<string>);

	 /*Шифрование*/
	void Encryption();

	 /*Расшифрование*/
	void Decryption(string CrFileAdressA, string CrFileAdressB,
		string PubKeyFileAdress, string PrKeyFileAdress);

private:
	/*Нахождение адреса папки, в которой лежит файл*/
	string LocatingDirectory(const string FileAdress);

	/*Генерация файлов в заданной директории*/
	vector<string> FileGen(string AdrDir);

	/*Генерация файлов в папке по-умолчанию*/
	vector<string> bydefault();
};