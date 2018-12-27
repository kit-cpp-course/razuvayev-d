#include "shell.h"
using namespace ElGam;

	
shell::shell() { PlainText = ""; }
shell::shell(const string PlainText) : PlainText(PlainText) {}
shell::~shell() {}

		void shell::Encryption() {
			for (size_t i = 0; i < Len; i++) {
				SText[i].Encryption(); //Побуквенная шифровка
				A[i] = SText[i].GetA();
				B[i] = SText[i].GetB();
			}
		}

		vector<size_t> shell::GetPrivateKey() const { return PrivateKey; }
		vector<size_t> shell::GetA() const { return A; }
		vector<size_t> shell::GetB() const { return B; }
		vector<size_t> shell::GetPublicKey() const { return PublicKey; }

		string shell::Decryption(vector<size_t> A, vector<size_t> B, vector<size_t> P, vector<size_t> X) {
			size_t x, p, a, b;
			size_t Len = A.size();
			vector<int> Mess(Len); string S = "";
			for (size_t i = 0; i < Len; i++) {
				a = A[i], b = B[i];
				p = P[i], x = X[i];
				Mess[i] = kernel::Decryption(a, b, p, x);
				S = S + static_cast<char>(Mess[i]);
			}
			return S;
		}

		vector<size_t> shell::Convert(const string PlainText) {
			vector<size_t> mes(Len);
			for (size_t i = 0; i < Len; i++) {
				mes[i] = (byte)PlainText[i];
			}
			return mes;
		}
		
		vector<kernel> shell::Link() {
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

		vector<size_t> shell::LinkA() {
			vector<size_t> A(Len);
			for (size_t i = 0; i < Len; i++) {
				A[i] = SText[i].GetA();
			}
			return A;
		}

		vector<size_t> shell::LinkB() {
			vector<size_t> B(Len);
			for (size_t i = 0; i < Len; i++) {
				B[i] = SText[i].GetB();
			}
			return B;
		}

		vector<size_t> shell::VecPrivateKey() {
			vector<size_t> PK(Len);
			for (size_t i = 0; i < Len; i++) {
				PK[i] = SText[i].GetPrivateKey();
			}
			return PK;
		}

		vector<size_t> shell::VecPublicKey() {
			vector<size_t> PK(Len);
			for (size_t i = 0; i < Len; i++) {
				PK[i] = SText[i].GetPublicKey();
			}
			return PK;
		}
