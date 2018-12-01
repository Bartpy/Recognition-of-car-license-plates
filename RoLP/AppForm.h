#pragma once

namespace RoLP {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MetroFramework::Forms;

	/// <summary>
	/// Summary for AppForm
	/// </summary>
	public ref class AppForm : public MetroForm
	{
	public:
		AppForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AppForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->SuspendLayout();
			// 
			// AppForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(869, 491);
			this->Name = L"AppForm";
			this->Padding = System::Windows::Forms::Padding(0, 60, 0, 0);
			this->Style = MetroFramework::MetroColorStyle::Red;
			this->Text = L"AppForm";
			this->Theme = MetroFramework::MetroThemeStyle::Dark;
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
