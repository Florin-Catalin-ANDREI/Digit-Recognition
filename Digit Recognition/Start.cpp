#include "DigitRecognition.h"
using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void Main(array<String^>^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    DigitRecognition::DigitRecognition form;
    Application::Run(% form);
}
