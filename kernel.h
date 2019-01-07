/*kernel.h*/
#pragma once
#include "stdafx.h"
typedef unsigned long long ull;
namespace ElGam {
	
	/*Класс шифрования методом Эль-Гамаля
	* Задача -- зашифровать число, превратив его в двойку шифротекста
	*/
	class kernel {
		/*Открытый текст*/
		size_t M;
		/*Открытый ключ p>M*/
		ull p = SimpleGen(M);//Генератор простого числа больше чем М
		/*Первообразный корень по модулю p*/
		size_t g = PrimeRoot(p);
		/*Закрытый ключ*/
		ull x = 2 + (rand() % (p - 1)); //целое число в интервале(1; p - 1)
		/*Открытый ключ*/
		ull y = powmod(g, x, p); //g^x mod p
		/*Элемент двойки шифротекста*/
		ull a, b;
	public:
		kernel();
		kernel(size_t M);

		ull GetA() const;
		ull GetB() const;
		ull GetPrivateKey() const;
		ull GetPublicKey() const;

		/*Шифратор
		* Преобразует сообщение M в упорядоченную пару <a, b>
		*/
		void Encryption();

		/*Дешифратор
		* params a, b -- зашифрованное сообщение
		* param p -- откртый ключ
		* param x -- закрытый ключ
		* возвращает открытый текст
		*/
		ull Decryption(ull a, ull b, ull p, ull x) const;

	private:
		/*Генератор псевдослучайного простого числа
		* @param M -- числовое сообщение (сгенерированное число больше М)
		* возвращает псевдослучайное простое число
		*/
		ull SimpleGen(const size_t M) const;

		/*Возведение в степень по модулю
		* @param base -- основание степени
		* @param exp -- показатель степени
		* @param mod -- число, по которому ищется остаток от деления
		*/
		ull powmod(ull base, ull exp, ull mod) const;

		/*Генератор первообразного корня по модулю р
		* @paran p -- число, по модулю которого ищется первообразный корень
		*/
		size_t PrimeRoot(const ull p) const;
	};
}
