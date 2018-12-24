#pragma once
#include "stdafx.h"
#include "kernel.h"

namespace ElGamal{
	/*Класс подготовки шифрования методом Эль-Гамаля
	* Задача -- разбить сообщение на буквы, найти их числовой код
	* и передать его на зашифровку классу kernel
	*/
	class shell : private kernel{
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
		shell() {PlainText = "";}

		/*Конструктор по введенной строке
		* param PlainText -- сообщение, которое необходимо зашифровать
		*/
		shell(const string PlainText) : PlainText(PlainText) {}
		~shell() {}

		/* Шифровщик
		* Осуществляет побуквенное шифрование при помощи класса kernel
		*/
		void Encryption() {
			for (size_t i = 0; i < Len; i++) {
				SText[i].Encryption(); //Побуквенная шифровка
				A[i] = SText[i].GetA();
				B[i] = SText[i].GetB();
			}
		}

		vector<size_t> GetPrivateKey() const {return PrivateKey;}
		vector<size_t> GetA() const {return A;}
		vector<size_t> GetB() const { return B;}
		vector<size_t> GetPublicKey() const {return PublicKey;}
		
		/*Дешифровщик строки
		* @param A -- массив шифротекста А
		* @param B -- массив шифротекста B
		* @param P -- массив открытых ключей
		* @param X -- массив закрытых ключей
		* Возвращает открытый текст
		*/
		string Decryption(vector<size_t> A, vector<size_t> B, vector<size_t> P, vector<size_t> X ) {			
			size_t x, p, a, b;		
			size_t Len = A.size();
			vector<size_t> Mess(Len); string S = "";
			for (size_t i = 0; i < Len; i++) {
				a = A[i], b = B[i]; 
				p = P[i], x = X[i];
				Mess[i] = kernel::Decryption(a, b, p, x);
				S = S + static_cast<char>(Mess[i]);
			}
			return S;
		}

	private:
		/*Переводчик открытого текста в числовую форму
		* @param PlainText -- исходный текст, подлежащий шифрованию
		* Возвращает побуквенный массив из кодов символов
		*/
		vector<size_t> Convert(const string PlainText) {
			vector<size_t> mes(Len);
			for (size_t i = 0; i < Len; i++) {
				mes[i] = (int)PlainText[i];
			}
			return mes;
		}
		/*Собирает отдельные зашифрованные буквы в массив*/
		vector<kernel> Link() {
			/*Побуквенно конвертированный в числовую форму открытый текст (УБРАТЬ В Link()*/
			vector<size_t> Message = Convert(PlainText);
			vector<kernel> D;
			D.reserve(Len);			
			for (size_t i = 0; i < Len; i++) {
				kernel Z(Message[i]);
				D.push_back(Z);
			}
			return D;
		}

		/*Массив шифротекста А*/
		vector<size_t> LinkA(){
			vector<size_t> A(Len);	
			for (size_t i = 0; i < Len; i++) {
				A[i] = SText[i].GetA();				
			}
			return A;
		}
		
		/*Массив шифротекста В*/
		vector<size_t> LinkB() {
			vector<size_t> B(Len);
			for (size_t i = 0; i < Len; i++) {
				B[i] = SText[i].GetB();
			}
			return B;
		}
		/*Создает массив закртых ключей*/
		vector<size_t> VecPrivateKey() {
			vector<size_t> PK(Len);
			for (size_t i = 0; i < Len; i++) {
				PK[i] = SText[i].GetPrivateKey();
			}
			return PK;
		}
		/*Создает массив открытых ключей*/
		vector<size_t> VecPublicKey() {
			vector<size_t> PK(Len);
			for (size_t i = 0; i < Len; i++) {
				PK[i] = SText[i].GetPublicKey();
			}
			return PK;
		}		
	};

}
