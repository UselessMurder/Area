#include "Area_Face.h"


double Time;
AOR recovery;

using namespace Area;



[STAThreadAttribute]
int main(array<System::String ^> ^args)
{

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Application::Run(gcnew Area_Face());
	return 0;
}
