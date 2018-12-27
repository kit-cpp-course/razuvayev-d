#pragma once
#include "stdafx.h"
/*Абстрактный класс для работы с файлами -- work with the file*/
class wwfile {
public:	
	virtual void Createfile(string) = 0;
	virtual void WriteInFile(vector<size_t>, string) = 0;
	virtual string ReadFile(string) = 0;
};

