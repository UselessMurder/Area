#include <vector>
#include <windows.h>
class Key {
private:
	std::vector <short int> key_line;
	unsigned int first;
	unsigned int second;
	unsigned int third;
	unsigned int fourth;
	unsigned int fifth;
	unsigned int sixth;
	unsigned int max;
public:
	Key();
	~Key();
	void operator =(Key &thisKey);
	void operator =(System::String^ str);
	unsigned int GetFirst();
	unsigned int GetSecond();
	unsigned int GetThird();
	unsigned int GetFourch();
	unsigned int GetFifth();
	unsigned int GetSixth();
	unsigned int GetRand(unsigned int seed);
	void Clear();
	unsigned int GetMax();
};

struct BasicData {
	bool de;
	long long fileSize;
	long long iterator;
	unsigned int progress;
	bool pause;
	bool stop;
	std::basic_string<wchar_t> way;
	std::basic_string<wchar_t> expansion;
	std::basic_string<wchar_t> name;
	std::basic_string<wchar_t> newname;
	Key primary;
	unsigned int level;
	unsigned int area;
};

struct ControlData 
{
	void *fileSize;
	void *iterator;
	void *pause;
    void *in_progress;
	void *progress;
};


class AOR {
private:
	HANDLE in_progress;
	BasicData parameters;
	ControlData date;
public:
	AOR();
	~AOR();
	bool OpenFile(System::String^ path);
	bool SetKey(System::String^ text);
	bool CheckFile();
	void Action(bool type);
	unsigned int GetProgress();
	HANDLE GetThreadStatus();
	bool OverflowSize();
	long long GetFileSize();
	System::String^ GetName();
	System::String^ GetExpansion();
	System::String^ GetWay();
	bool GetPauseStatus();
	void SetStop();
	void SetPauseOn();
	void SetPauseOff();
	void SetLevel(unsigned int l);
	void SetArea(unsigned int a);
};

class block {
private:
	unsigned int one;
	unsigned int two;
	unsigned int three;
	unsigned int four;
	unsigned int five;
	unsigned int six;
	unsigned int seven;
	bool flag;
	unsigned int area;
	unsigned int level;
	unsigned int over;
public:
	block(
		unsigned int on,
		unsigned int tw,
		unsigned int th,
		unsigned int fo,
		unsigned int fi,
		unsigned int si,
		unsigned int se,
		bool fl,
	    unsigned int ar,
	    unsigned int le);
	~block();
	inline void action(char &byte,int type);
};
