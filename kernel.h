#pragma once
#include "stdafx.h"
#include "kernel.h"

namespace ElGamal {
	typedef unsigned long long ull;

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
		kernel() {}
		kernel(size_t M) : M(M) {}
		~kernel() {}

		size_t GetA() const { return a; }
		size_t GetB() const { return b; }
		size_t GetPrivateKey() const { return x; }
		size_t GetPublicKey() const { return p; }

		/*Шифратор
		* Преобразует сообщение M в упорядоченную пару <a, b>
		*/
		void Encryption() {
			size_t k = 2 + (rand() % (p - 1));//Сессионнй ключ -- целое число в интервале (1; p - 1) 
			a = powmod(g, k, p); //g^k mod p
			b = (M*powmod(y, k, p)) % p; //M*y^k mod p 
		}

		/*Дешифратор
		* params a, b -- зашифрованное сообщение
		* param p -- откртый ключ
		* param x -- закрытый ключ
		* возвращает открытый текст
		*/
		ull Decryption(size_t a, size_t b, size_t p, size_t x) const {
			return  (b*powmod(a, p - 1 - x, p)) % p;//b*a^(p-1-x) mod p
		}

	private:
		/*Генератор псевдослучайного простого числа
		* @param M -- числовое сообщение (сгенерированное число больше М)
		* возвращает псевдослучайное простое число
		*/
		ull SimpleGen(const size_t M) const {
			srand(time(NULL));
			ull Simple;
			bool f = true;
			while (f) {
				Simple = 2 + M + rand();
				if (Simple % 2 == 0) continue;
				f = false;
				for (size_t i = 3; i*i <= Simple; i = i + 2) {
					if (Simple % i == 0) {
						f = true;
						break;
					}
				}
			}
			return Simple;
		}

		/*Возведение в степень по модулю
		* @param base -- основание степени
		* @param exp -- показатель степени
		* @param mod -- число, по которому ищется остаток от деления
		*/
		ull powmod(ull base, ull exp, ull mod) const {
			ull res = 1;
			while (exp)
				if (exp & 1)
					res = ull(res * 1ll * base % mod), exp--;
				else
					base = ull(base * 1ll * base % mod), exp >>= 1;
			return res;
		}

		/*Генератор первообразного корня по модулю р
		* @paran p -- число, по модулю которого ищется первообразный корень
		*/
		size_t PrimeRoot(const ull p) const {
			size_t phi = p - 1; //Функция Эйлера для простых чисел
			size_t g = 2; bool f;
			while (true) {
				if (powmod(g, phi, p) == 1) { //g^phi mod p = 1
					for (size_t i = 1; i < g; i++) {
						if (powmod(g, i, p) == 1) { f = false; break; }// g^i mod p != 1 	при i<phi				
						f = true;
					}
					if (f) return g;
				}
				g++;
			}
		}
	};
}
