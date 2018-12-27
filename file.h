#pragma once
#include "stdafx.h"
#include "wwfile.h"

/*����������� �����, ����������� �������� ������� ��� ������ � �������
* ����������� ������ ElGamal
*/
class file : private wwfile {
public:
	/*��������� ���������� �� ���� �� ������ ������
    * ������� �� ������������ ������ ���������� ����� �� ��� ���, 
	* ���� ��� �� �������
    */
	static string ExCheck(string Adress){
		ifstream file(Adress);
		while (true) {
			if (!file) {
				file.close();
				cout << "���� � ������� " << Adress << " �� ������.";
			}
			else break;
			cout << " ������� ����� �����... ";
			cin >> Adress;
			file.open(Adress);
		}
		return Adress;
	}
	/*������ ����� (��� ��������� ������)*/
	string ReadFile(const string FileAdress);
	/*������ � ���� ������� �����
	* @param Cryp -- ������ �����
	* @param FileAdress -- ����� �����
	*/
	void WriteInFile(const vector<size_t> Cryp, const string FileAdress);
	
	/*������ � ���� ������*/
	void WriteInFile(const string Text, const string FileAdress);
	/*������ ������������� ������
	* @param FileAdress -- ����� �����, ������� ���������� ���������
	* ���������� ������ ����� ������������� �����
	*/
	vector<size_t> ReadCryptFile(const string FileAdress);

	/*������� ��� �������� �����*/
	void Createfile(const string FileAdress);
 };