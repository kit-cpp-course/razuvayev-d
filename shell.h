#pragma once
/*shell.h*/
#include "stdafx.h"
#include "kernel.h"

namespace ElGam{
	/*Класс подготовки шифрования методом Эль-Гамаля
	* Задача -- разбить сообщение на буквы, найти их числовой код
	* и передать его на зашифровку классу kernel
	*/
	class shell : private kernel {
		/*Открытый текст -- сообщение, которое необходимо зашифровать*/
		string PlainText;
		/*Длина сообщения*/
		size_t Len = PlainText.length();
		/*Шифротекст -- зашифрованное сообщение*/
		vector<kernel> SText = Link();
		/*Массив закрытых ключей*/
		vector<size_t> PrivateKey = VecPrivateKey();
		/*Массив открытых ключей*/
		vector<size_t> PublicKey = VecPublicKey();
		/*Массивы пар шифротекста <a,b>*/
		vector<size_t> A = LinkA(), B = LinkB();
	public:
		/*Конструктор по умолчанию*/
		shell();

		/*Конструктор по введенной строке
		* param PlainText -- сообщение, которое необходимо зашифровать
		*/
		shell(const string PlainText);

		/* Шифровщик
		* Осуществляет побуквенное шифрование при помощи класса kernel
		*/
		void Encryption();

		vector<size_t> GetPrivateKey() const;
		vector<size_t> GetA() const;
		vector<size_t> GetB() const;
		vector<size_t> GetPublicKey() const;
		
		/*Дешифровщик строки
		* @param A -- массив шифротекста А
		* @param B -- массив шифротекста B
		* @param P -- массив открытых ключей
		* @param X -- массив закрытых ключей
		* Возвращает открытый текст
		*/
		string Decryption(vector<size_t> A, vector<size_t> B, vector<size_t> P, vector<size_t> X);

	private:
		 
		/*Переводчик открытого текста в числовую форму
		* @param PlainText -- исходный текст, подлежащий шифрованию
		* Возвращает побуквенный массив из кодов символов
		*/
		vector<size_t> Convert(const string PlainText);
		/*Собирает отдельные зашифрованные буквы в массив*/
		vector<kernel> Link();

		/*Массив шифротекста А*/
		vector<size_t> LinkA();
		
		/*Массив шифротекста В*/
		vector<size_t> LinkB();
		
		/*Создает массив закртых ключей*/
	vector<size_t> VecPrivateKey();
		/*Создает массив открытых ключей*/
	vector<size_t> VecPublicKey();
	};
}
