#include "AppForm.h"


using namespace System;
using namespace System::Windows::Forms;


int main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	RoLP::AppForm form;
	Threading::Thread::CurrentThread->ApartmentState = Threading::ApartmentState::STA;
	Application::Run(%form);
	return 0;
}
