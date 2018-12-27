#pragma once
#include "stdafx.h"
#include "wwfile.h"

/*Абстрактный класс, реализующий основные функции для работы с файлами
* необходимые классу ElGamal
*/
class file : private wwfile {
public:
	/*Проверяет существует ли файл по такому адресу
    * Требует от пользователя ввести корректный адрес до тех пор, 
	* пока тот не сдастся
    */
	static string ExCheck(string Adress){
		ifstream file(Adress);
		while (true) {
			if (!file) {
				file.close();
				cout << "Файл с адресом " << Adress << " не открыт.";
			}
			else break;
			cout << " Введите адрес файла... ";
			cin >> Adress;
			file.open(Adress);
		}
		return Adress;
	}
	/*Чтение файла (для открытого текста)*/
	string ReadFile(const string FileAdress);
	/*Запись в файл массива чисел
	* @param Cryp -- массив чисел
	* @param FileAdress -- адрес файла
	*/
	void WriteInFile(const vector<size_t> Cryp, const string FileAdress);
	
	/*Запись в файл текста*/
	void WriteInFile(const string Text, const string FileAdress);
	/*Чтение зашифрованных файлов
	* @param FileAdress -- адрес файла, который необходимо прочитать
	* возвращает массив целых положительных чисел
	*/
	vector<size_t> ReadCryptFile(const string FileAdress);

	/*Функция для создания файла*/
	void Createfile(const string FileAdress);
 };