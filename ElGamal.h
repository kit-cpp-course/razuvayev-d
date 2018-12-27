#pragma once
#include "stdafx.h"
#include "file.h"
#include "shell.h"

using namespace ElGam;
/*�����, ����������, ���������� ������
 *������ -- ����������� ����, ��������� ��� � ���� ������ � ������������,
 *������������� �����-�����.
 *�������������� ������������� ����� ��� ������ ������-������
 */
class ElGamal : protected file, private shell {
	string FileAdress; //����� ��������� �����
	vector<string> Output; //������ ������-������������ � ������-������
public:
	/*����������� ��-���������
	* ������� ����� Crypt � �������� �������� ���������
	* ���� ��������� ��� �����
	*/
	ElGamal();
	/*����������� �� ���������� ������
	* ���������� ����� ���������� ����������� ����� 
	* � ��������� ��� ������� ����� ����
	*/
	ElGamal(string FileAdress);

	 /*����������*/
	void Encryption();

	 /*�������������*/
	void Decryption(string CrFileAdressA, string CrFileAdressB,
		string PubKeyFileAdress, string PrKeyFileAdress);

private:
	/*���������� ������ �����, � ������� ����� ����*/
	string LocatingDirectory(const string FileAdress);

	/*��������� ������ � �������� ����������*/
	vector<string> FileGen(string AdrDir);

	/*��������� ������ � ����� ��-���������*/
	vector<string> bydefault();
};