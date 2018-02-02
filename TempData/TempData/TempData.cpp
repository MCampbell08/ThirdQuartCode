#include "TempData.h"
#include <iostream>

TempData::TempData()
{
}

TempData::~TempData()
{
}

bool TempData::ProcessTemperatures(std::string filename)
{
	if (!Initialize())       return false;
	if (!Openfile(filename)) return false;
	if (!ReadData())         return false;
	if (!Closefile())        return false;
	if (!ProcessData())      return false;
	if (!DisplayResults())   return false;
}

bool TempData::Initialize()
{
	m_temperatures.clear ();
	return true;
}

bool TempData::Openfile(std::string filename)
{
	m_filename = filename;
	m_filestream.open(filename);

	if (!m_filestream.good()) // First way of making sure file is good
	{
		std::cout << "ERROR: Unable to open file [" << filename << "].\n";
		return false;
	}
	//if (!m_filestream.is_open()) // second way of making sure file is good
	//{
	//	std::cout << "error: unable to open file [" << filename << "].\n";
	//	return false;
	//}
	return true;
}

bool TempData::ReadData()
{
	//double currentTemp;
	//while (m_filestream >> currentTemp) // First way of reading file
	for (double currentTemp; m_filestream >> currentTemp;) // Second way of reading file
	{
		m_temperatures.push_back(currentTemp);
	}
	return true;
}

bool TempData::ProcessData()
{
	m_numTemp = m_temperatures.size();
	if (m_numTemp == 0)
	{
		m_lowTemp = m_highTemp;
		m_avgTemp = 0;
		return true;
	}
	m_lowTemp = m_temperatures[0];
	m_highTemp = m_temperatures[0];
	m_sumTemp = 0;

	for (int j = 0; j < m_numTemp; ++j)
	{
		double currentTemp = m_temperatures[j];
		m_sumTemp += currentTemp;
		if (currentTemp < m_lowTemp)
		{
			m_lowTemp = currentTemp;
		}
		else if (currentTemp > m_highTemp)
		{
			m_highTemp = currentTemp;
		}
	}
	m_avgTemp = m_sumTemp / m_numTemp;
	return true;
}

bool TempData::DisplayResults()
{
	std::cout << "Temperature Statistics for File[" << m_filename << "].\n";
	return true;
}

bool TempData::Closefile()
{
	m_filestream.close();
	return true;
}
