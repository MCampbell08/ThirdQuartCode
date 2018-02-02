#pragma once
#include <string>
#include <fstream>
#include <vector>

class TempData
{
public: // public ctor/dtor
	TempData();
	~TempData();

public: // public methods
	bool ProcessTemperatures (std::string fileName);

private: // private methods
	bool Initialize();
	bool Openfile(std::string fileName);
	bool ReadData();
	bool ProcessData();
	bool DisplayResults();
	bool Closefile();

private: // private data
	std::string          m_filename;
	std::ifstream        m_filestream;
	std::vector <double> m_temperatures;
	int                  m_numTemp;
	double               m_avgTemp;
	double               m_sumTemp;
	double               m_lowTemp;
	double               m_highTemp;
};

