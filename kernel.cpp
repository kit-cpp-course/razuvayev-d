#include "kernel.h"
using namespace ElGam;
	
kernel::kernel() {}
kernel::kernel(size_t M) : M(M) {}
kernel::~kernel() {}

ull kernel::GetA() const { return a; }
ull kernel::GetB() const { return b; }
ull kernel::GetPrivateKey() const { return x; }
ull kernel::GetPublicKey() const { return p; }

void kernel::Encryption() {
			ull k = 2 + (rand() % (p - 1));//Сессионнй ключ -- целое число в интервале (1; p - 1) 
			a = powmod(g, k, p); //g^k mod p
			b = (M*powmod(y, k, p)) % p; //M*y^k mod p 
		}

ull kernel::Decryption(ull a, ull b, ull p, ull x) const {
			return  (b*powmod(a, p - 1 - x, p)) % p;//b*a^(p-1-x) mod p
		}

	
ull kernel::SimpleGen(const size_t M) const {
			srand(time(NULL));
			ull Simple;
			bool f = true;
			while (f) {
				Simple = 1 + M + rand() % 100;
				if (Simple % 2 == 0) continue;
				f = false;
				for (ull i = 3; i*i <= Simple; i = i + 2) {
					if (Simple % i == 0) {
						f = true;
						break;
					}
				}
			}
			return Simple;
		}

		
ull kernel::powmod(ull base, ull exp, ull mod) const {
			ull res = 1;
			while (exp)
				if (exp & 1)
					res = ull(res * 1ll * base % mod), exp--;
				else
					base = ull(base * 1ll * base % mod), exp >>= 1;
			return res;
		}

		
size_t kernel::PrimeRoot(const ull p) const {
			ull phi = p - 1; //Функция Эйлера для простых чисел
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
	
