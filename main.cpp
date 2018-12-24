#include "kernel.h";
#include "shell.h";


using namespace ElGamal;

int main() {
		cout << "Enter the message" << endl;
		string Message;
		cin >> Message;
		shell T(Message);
		T.Encryption();
		vector<size_t> A = T.GetA(),
			B = T.GetB(),
			X = T.GetPrivateKey(),
			P = T.GetPublicKey();
		cout << "Message encrypted" << endl;
		cout << "The Ciphertext A:" << endl;
		for (int i = 0; i < A.size(); i++)
			cout << A[i] << " "; cout << endl;
		cout << "The Ciphertext B:" << endl;
		for (int i = 0; i < B.size(); i++)
			cout << B[i] << " "; cout << endl;
		cout << "Publuc key:" << endl;
		for (int i = 0; i < P.size(); i++)
				cout << P[i] << " "; cout << endl;
		cout << "Private key:" << endl;
		for (int i = 0; i < X.size(); i++)
			cout << X[i] << " "; cout << endl;
		T.~shell();
		shell Decr;
		
		cout << "The decrypted message:" << endl;
		cout << Decr.Decryption(A, B, P, X) << endl;	

}