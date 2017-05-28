#include "Area.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <fstream>
#include <process.h>


//####Function
std::vector<DWORD> NT;
struct Thread_data {
	Key TKey;
	char * buffer;
	unsigned int size;
	int mask;
	unsigned int area;
	unsigned int level;
	long long iter;
	bool flag;
};
inline unsigned int retNT(DWORD ThisThread)
{
	unsigned int number = 0;
	for (unsigned int i = 0;i < NT.size();i++)
	{
		if (ThisThread == NT[i])
			number = i;
	}
	return number;
}
inline unsigned int getRand(unsigned int seed)
{
	srand(seed);
	unsigned int s = rand() + 1  % 3;
	__asm
	{
		push ecx
		mov ecx, s
		metka:
		push ecx
	}
    rand();
	__asm
	{
		pop ecx
		loop metka
		pop ecx
	}
	return rand() + 1;
}
inline unsigned int mean(std::vector<short int> v)
{
	double me = 0;
	unsigned int i = 0;
	unsigned int s = v.size();
	__asm
	{
	 push ecx
	 mov ecx,s
	 metka:
	 push ecx
	}
		me += (double)v[i];
	__asm
	{
	  pop ecx
	  inc i
	  loop metka
	  pop ecx
	}
	return (unsigned int)(me / s);
}
inline unsigned int median(std::vector<short int> v)
{
	double med = 0;
	if (v.size() % 2 == 0)
		med = 0.5*(v[v.size() / 2] + v[(v.size() / 2) - 1]);
	else
		med = v[v.size() / 2];
	return (unsigned int)med;
}
inline unsigned int variance(std::vector <short int> v, unsigned int me)
{
	double var = 0;
	unsigned int i = 0;
	unsigned int s = v.size();
	__asm
	{
		push ecx
		mov ecx, s
		metka:
		push ecx
	}
		var += (double)pow((double)v[i] - (double)me,2);
	__asm
	{
		pop ecx
		inc i
		loop metka
		pop ecx
	}
	return (unsigned int)(var / s);
}
inline double ConfidenceProbability(unsigned int i)
{
	i = i % 100 + 1;
	double d = (double)i;
	d = d * 0.01;
	return d;
}
inline unsigned int up(std::vector <short int> v, double ver)
{
	unsigned int  u = unsigned int((v.size()*(1 + ver) / 2) - 1);
	return (unsigned int)v[u];
}
inline unsigned int down(std::vector <short int> v, double ver)
{
	unsigned int d = unsigned int((v.size()*(1 - ver) / 2) - 1);
	return (unsigned int)v[d];
}
inline unsigned int findMax(std::vector <short int> v)
{
	short int max = 0;
	for (unsigned int i = 0; i < v.size();i++)
	{
		if (max < v[i])
			max = v[i];
	}
	return (unsigned int)max;
}
inline unsigned int RandCount(std::vector <short int> v)
{
	srand(v.size());
	unsigned int s = v.size();
	unsigned int number = v[rand() % s];
	unsigned int Probability = 0;
	unsigned int i = 0;
	__asm
	{
		push ecx
		mov ecx, s
		metka:
		push ecx
	}
		if (v[i] == number)
			Probability++;
	__asm
	{
		pop ecx
		inc i
		loop metka
		pop ecx
	}
	return v[s - Probability];
}
inline DWORD WINAPI progress_update(void *prm)
{
	ControlData *data_ptr = (ControlData *)prm;
	ControlData &data = *data_ptr;
	long long *it = (long long *)data.iterator;
	long long &iterator = *it;
	long long *fs = (long long *)data.fileSize;
	long long &fileSize = *fs;
	bool *p = (bool *)data.pause;
	bool &pause = *p;
	HANDLE *ip = (HANDLE  *)data.in_progress;
	HANDLE &in_progress = *ip;
	unsigned int *pr = (unsigned int   *)data.progress;
	unsigned int &progress = *pr;
	double prog = 0;
	while (data.in_progress)
	{
		prog = ((double)iterator / (double)fileSize) * 100;
		if (prog <= 100)
			progress = (int)prog;
		if (in_progress == false)
			break;
		Sleep(100);
		progress = 100;
	}
	return 0;
}
DWORD WINAPI wait(void *prm)
{
	HANDLE *ip = (HANDLE  *)prm;
	HANDLE &in_progress = *ip;
	WaitForSingleObject(in_progress, INFINITE);
	CloseHandle(in_progress);
	in_progress = 0;
	return 0;
}
inline void spent(std::basic_string<wchar_t> str)
{
	wchar_t *text = new wchar_t[MAX_PATH];
	for (unsigned int i = 0;i < MAX_PATH;i++)
		i < str.size() ? text[i] = str[i] : text[i] = 0;
	DeleteFileW(text);
	delete[] text;
	return;
}
inline void iterLimit(long long fsize, long long &iter, long long &residue, long long blockSize)
{
	long long size = fsize;
	if (size < blockSize)
	{
		residue = size;
		iter = 0;
	}
	else
	{
		while (size > blockSize)
		{
			size -= blockSize;
			iter++;
		}
		residue = size;
	}
}
inline void pause(bool &pause, bool &stop)
{
	while (pause)
	{
		Sleep(100);
		if (stop)
			break;
	}
}
inline DWORD WINAPI utilization(void *prm)
{ 
	unsigned int  n = retNT(GetCurrentThreadId());
	Thread_data **data_ptr = (Thread_data**)prm;
	Thread_data *&data = *data_ptr;
	block chip(
		data[n].TKey.GetFirst() ^ data[n].TKey.GetRand((unsigned int)data[n].iter) + 1,
		data[n].TKey.GetSecond() ^ data[n].TKey.GetRand((unsigned int)data[n].iter) + 1,
		(data[n].TKey.GetThird() ^ data[n].TKey.GetRand((unsigned int)data[n].iter) + 1) * data[n].TKey.GetMax(),
		(data[n].TKey.GetFourch() ^ data[n].TKey.GetRand((unsigned int)data[n].iter) + 1) * data[n].TKey.GetMax(),
		(data[n].TKey.GetFifth() ^ data[n].TKey.GetRand((unsigned int)data[n].iter) + 1) % data[n].area + 1,
		(data[n].TKey.GetSixth() ^ data[n].TKey.GetRand((unsigned int)data[n].iter) + 1) % data[n].level + 1,
		(data[n].TKey.GetMax() ^ data[n].TKey.GetRand((unsigned int)data[n].iter) + 1) % data[n].area + 1,
		data[n].flag,
		data[n].area,
	    data[n].level);
	unsigned int i = 0;
	unsigned int j = data[n].size;
	__asm
		{
			push ecx
			mov ecx, j
			metka:
			push ecx
		}
	chip.action(data[n].buffer[i],0);
	__asm
		{
			pop ecx
			inc i
			loop metka
			pop ecx
		}
	return 0;
}
long long blokBuilder(long long fs)
{
	long long blockSize = fs / 20;
	if (!blockSize)
	{
		blockSize = 64;
	}
	return blockSize;
}
inline DWORD WINAPI recycling(void *prm)
{
	BasicData *data_ptr = (BasicData*)prm;
	BasicData &data = *data_ptr;
	data.stop = false;
	data.progress = 0;
	data.iterator = 0;
	std::ifstream readable(data.way + data.name + data.expansion, std::ios::binary | std::ios::in);
	std::ofstream recordable(data.way + data.newname + data.expansion, std::ios::binary | std::ios::out);
	long long iter = 0;
	long long residue = 0;
	long long blockSize = blokBuilder(data.fileSize);
	iterLimit(data.fileSize, iter, residue, blockSize);
	SYSTEM_INFO sysinfo;
	GetSystemInfo(&sysinfo);
	DWORD_PTR processAffinityMask;
	DWORD_PTR systemAffinityMask;
	GetProcessAffinityMask(GetCurrentProcess(), &processAffinityMask, &systemAffinityMask);
	Thread_data *dates = new Thread_data[sysinfo.dwNumberOfProcessors];
	HANDLE *threads = new HANDLE[sysinfo.dwNumberOfProcessors];
	int use = 0;
	for (unsigned int i = 0;i < sysinfo.dwNumberOfProcessors;i++)
	{
		dates[i].mask = systemAffinityMask;
		dates[i].TKey = data.primary;
		dates[i].buffer = 0;
		dates[i].size = 0;
		dates[i].flag = data.de;
		dates[i].area = data.area;
		dates[i].level = data.level;
		dates[i].iter = iter;
		systemAffinityMask = systemAffinityMask >> 1;
	}
	while (residue)
	{
		NT.clear();
		use = 0;
		for (unsigned int i = 0;i <sysinfo.dwNumberOfProcessors;i++)
		{
			if (!iter)
			{
				blockSize = residue;
				residue = 0;
			}
			dates[i].buffer = new char[(unsigned int)blockSize];
			dates[i].iter = iter;
			dates[i].size =(unsigned int) blockSize;
			readable.read(dates[i].buffer, blockSize);
			void *param = &dates;
			DWORD tID = 0;
			threads[i] = CreateThread(0, 0, utilization, param, CREATE_SUSPENDED,(LPDWORD)&tID);
			NT.push_back(tID);
			SetThreadAffinityMask(threads[i], dates[i].mask);
			ResumeThread(threads[i]);
			use++;
			if (!residue)
				break;
			iter--;
		}
		WaitForMultipleObjects(use, threads, true, INFINITE);
		if (data.stop)
		{
			for (int i = 0;i < use;i++)
			delete[] dates[i].buffer;
			break;
		}
		if (data.pause)
			pause(data.pause, data.stop);
		for (int i = 0;i < use;i++)
		{
			recordable.write(dates[i].buffer, dates[i].size);
			delete[] dates[i].buffer;
			CloseHandle(threads[i]);
		}
		for (int i = 0;i < use;i++)
		data.iterator += (long long)dates[i].size;
	}
	delete [] dates;
	delete [] threads;
	data.progress = 100;
	readable.close();
	recordable.close();
	if (data.stop)
		spent(data.way + data.newname + data.expansion);
	data.pause = false;
	data.stop = false;
	return 0;
}
//####EndFunction
//####Key
Key::Key()
{
	key_line.clear();
	first = 0;
	second = 0;
	third = 0;
	fourth = 0;
	fifth = 0;
	sixth = 0;
	max = 0;
}
void Key::operator =(Key &thisKey)
{
	this->key_line.clear();
	for (unsigned int i = 0;i <thisKey.key_line.size();i++)
		this->key_line.push_back(thisKey.key_line[i]);
	first = thisKey.first;
	second = thisKey.second;
	third = thisKey.third;
	fourth = thisKey.fourth;
	fifth = thisKey.fifth;
	sixth = thisKey.sixth;
	max = thisKey.max;
}
Key::~Key()
{
	key_line.clear();
}
void Key::operator =(System::String^ str)
{
	this->key_line.clear();
	for (int i = 0;i < str->Length;i++)
		this->key_line.push_back((short int)str[i] % 100);
	first = mean(key_line);
	second = getRand(RandCount(key_line));
	third = getRand(median(key_line));
	fourth = getRand(variance(key_line, first));
	first = getRand(first);
	fifth = getRand(up(key_line, ConfidenceProbability(getRand(second))));
	sixth = getRand(down(key_line, ConfidenceProbability(getRand(third))));
	max = findMax(key_line);
}
unsigned int Key::GetFirst()
{
	return first;
}
unsigned int Key::GetSecond()
{
	return second;
}
unsigned int Key::GetThird()
{
	return third;
}
unsigned int Key::GetFourch()
{
	return fourth;
}
unsigned int Key::GetFifth()
{
	return fifth;
}
unsigned int Key::GetSixth()
{
	return sixth;
}
unsigned int Key::GetRand(unsigned int seed)
{
	srand(seed);
	unsigned int i = key_line.size();
	return getRand(key_line[(rand()+1)%i]);
}
void Key::Clear()
{
	key_line.clear();
	first = 0;
	second = 0;
	third = 0;
	fourth = 0;
	fifth = 0;
	sixth = 0;
}
unsigned int Key::GetMax()
{
	return max;
}
//####EndKey
//####AOR
AOR::AOR()
{
	parameters.fileSize = 0;
	parameters.iterator = 0;
	parameters.progress = 0;
	parameters.area = 0;
	parameters.level = 0;
	parameters.progress = false;
	parameters.pause = false;
	parameters.stop = false;
	parameters.de = false;
	parameters.way = L"";
	parameters.expansion = L"";
	parameters.name = L"";
	parameters.newname = L"";
	parameters.primary.Clear();
	in_progress = 0;
}
AOR::~AOR()
{
	parameters.primary.Clear();
	parameters.way.clear();
	parameters.expansion.clear();
	parameters.name.clear();
	parameters.newname.clear();
}
bool AOR::OpenFile(System::String^ path)
{
	std::basic_string<wchar_t> word = L"";
	for (int i = 0; i < path->Length; i++)
	{
		word += (wchar_t)path[i];
	}
	bool result = false;
	std::fstream fp(word, std::fstream::in);
	if (fp.good())
	{
		result = true;
		fp.seekp(0, std::ios::end);
		parameters.fileSize = fp.tellp();
		fp.close();
		parameters.iterator = 0;
		parameters.progress = 0;
		parameters.area = 0;
		parameters.level = 0;
		parameters.progress = false;
		parameters.pause = false;
		parameters.stop = false;
		parameters.de = false;
		parameters.way = L"";
		parameters.expansion = L"";
		parameters.name = L"";
		parameters.newname = L"";
		parameters.primary.Clear();
		in_progress = 0;
		int expansionlength = 0;
		std::basic_string<wchar_t>  point = L".";
		int size = (int)word.size();
		for (int i = size; i > 0; i--)
		{
			if (word[i] == point[0])
			{
				break;
			}
			expansionlength++;
			if (word[i] == word[2])
			{
				expansionlength = 0;
				break;
			}
		}
		if (expansionlength != 0)
		{
			for (int i = size - expansionlength; i < size; i++)
			{
				parameters.expansion += word[i];
			}
		}
		int namelength = 0;
		int j = size - (expansionlength + 1);
		while (true)
		{
			if (word[j] == word[2])
			{
				break;
			}
			namelength++;
			j--;
		}
		for (int g = size - (namelength + expansionlength); g < size - expansionlength; g++)
		{
			parameters.name += word[g];
		}
		for (int p = 0; p < size - (namelength + expansionlength); p++)
		{
			parameters.way += word[p];
		}
		parameters.newname = parameters.name + L"_AOR";
	}
	else
	{
		result = false;
	}
	return result;
}
bool AOR::SetKey(System::String^ text)
{
	bool result = false;

	if ((text->Length >= 3) && (text->Length <= 32767))
	{
		parameters.primary = text;
		result = true;
	}
	else
	{
		result = false;
	}
	return result;
}
bool AOR::CheckFile()
{
	bool fileStatus = false;
	std::ifstream file(parameters.way + parameters.name + parameters.expansion);
	if (file.good())
	{
		fileStatus = true;
	}
	return fileStatus;
}
void AOR::Action(bool type)
{
	if (!in_progress)
	{
		parameters.de = type;
		void *param = &parameters;
		in_progress = CreateThread(0, 0, recycling, param, 0, 0);
		void *pr = &in_progress;
		CreateThread(0, 0,wait, pr, 0, 0);
		date.fileSize = &parameters.fileSize;
		date.in_progress = &in_progress;
		date.iterator = &parameters.iterator;
		date.pause = &parameters.pause;
		date.progress = &parameters.progress;
		void *prm = &date;
		CreateThread(0, 0, progress_update, prm, 0, 0);
	}
	return;
}
unsigned int AOR::GetProgress()
{
	return parameters.progress;
}
HANDLE AOR::GetThreadStatus()
{
	return in_progress;
}
long long AOR::GetFileSize()
{
	return parameters.fileSize;
}
bool AOR::OverflowSize()
{
	bool result = false;
	if (parameters.fileSize >= ULLONG_MAX)
	{
		result = true;
	}
	return result;
}
System::String ^ AOR::GetName()
{
	System::String^ name = "";
	for (unsigned int i = 0;i < parameters.name.size();i++)
	{
		name += parameters.name[i];
	}
	return name;
}
System::String ^ AOR::GetExpansion()
{
	System::String^ Expansion = "";
	for (unsigned int i = 0;i < parameters.expansion.size();i++)
	{
		Expansion += parameters.expansion[i];
	}
	return Expansion;
}
System::String ^ AOR::GetWay()
{
	System::String^ Way = "";
	for (unsigned int i = 0;i < parameters.way.size();i++)
	{
		Way += parameters.way[i];
	}
	return Way;
}
void AOR::SetStop()
{
	parameters.stop = true;
}
void AOR::SetPauseOn()
{
	parameters.pause = true;
}
void AOR::SetPauseOff()
{
	parameters.pause = false;
}
bool AOR::GetPauseStatus()
{
	return parameters.pause;
}
void AOR::SetLevel(unsigned int l)
{
	parameters.level = l;
}
void AOR::SetArea(unsigned int a)
{
	parameters.area = a;
}
//####EndAOR
//####block
block::block(
	unsigned int on,
	unsigned int tw,
	unsigned int th,
	unsigned int fo,
	unsigned int fi,
	unsigned int si,
	unsigned int se,
	bool fl,
	unsigned int ar,
	unsigned int le)
{
	one = on;
	two = tw;
	three = th;
	four = fo;
	five = fo;
	six = si;
	seven = se;
	flag = fl;
	area = ar;
	level = le;
	over = 0;
}
block::~block()
{}
inline void block::action(char &byte,int type)
{
	if (!type)
	{
		char hbyte = 0;
		if (flag)
			hbyte = byte;
		unsigned int j = seven;
		__asm
		{
			push ecx
			mov ecx, j
				metka :
			push ecx
		}
		this->action(byte, 1);
		__asm
		{
			pop ecx
			loop metka
				pop ecx
		}
		five = (five ^ rand()) % area + 1;
		six = (six ^ rand()) % level + 1;
		this->action(byte, 3);
		flag ? one = hbyte : one = byte;
	}
	else if (type == 1)
	{
		this->action(byte, 2);
		srand((unsigned int)one);
		unsigned int j = over;
		short int r = 0;
		char a = byte;
		__asm
		{
			push ecx
			mov ecx, j
			metka_:
			push ecx
		}
		r = rand();
		__asm
		{
			push ax
			mov ax, r
				xor a, al
				xor a, ah
				pop ax
				pop ecx
				loop metka_
				pop ecx
		}
		byte = a;
		one = rand();
	}
	else if (type == 2)
	{
		srand((unsigned int)one);
		over = (unsigned int)(abs(cos(rand()) * (three*six)) + 1) % six + 1;
	}
	else if (type == 3)
	{
		srand((unsigned int)one);
		seven = rand();
		seven = (unsigned int)(abs(sin(seven) * four) + 1) % five + 1;
	}
}
//####Endblock
