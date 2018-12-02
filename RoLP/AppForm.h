#pragma once
//#include <opencv2/opencv.hpp>
//#include <opencv2/highgui/highgui.hpp>

namespace RoLP {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MetroFramework::Forms;
	//using namespace cv;

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
	private: MetroFramework::Controls::MetroPanel^  LeftMenu;
	private: MetroFramework::Controls::MetroButton^  Button1;
	private: MetroFramework::Controls::MetroPanel^  Recognition_Panel;
	private: MetroFramework::Controls::MetroRadioButton^  CameraRadioButton;

	private: MetroFramework::Controls::MetroRadioButton^  VideoRadioButton;
	private: MetroFramework::Controls::MetroRadioButton^  ImageRadioButton;
	private: MetroFramework::Controls::MetroPanel^  ControlBarPanel;
	private: MetroFramework::Controls::MetroLabel^  ControlBarText;
	private: MetroFramework::Controls::MetroButton^  Button3;
	private: MetroFramework::Controls::MetroButton^  Button2;

	private: MetroFramework::Controls::MetroPanel^  ResultPanel;
	private: MetroFramework::Controls::MetroLabel^  ResultText;
	private: MetroFramework::Controls::MetroPanel^  PlateViewResultPanel;
	private: MetroFramework::Controls::MetroLabel^  PlateResultText;
	private: MetroFramework::Controls::MetroPanel^  CharResultPanel;
	private: MetroFramework::Controls::MetroPanel^  DetectedCharResultPanel;
	private: MetroFramework::Controls::MetroLabel^  DetectedCharResultText;
	private: MetroFramework::Controls::MetroLabel^  CharResultText;
	private: MetroFramework::Controls::MetroButton^  ProcessingButton;
	private: MetroFramework::Controls::MetroButton^  LoadSourceButton;
	private: System::Windows::Forms::PictureBox^  SrcViewPanel;



	private: System::ComponentModel::IContainer^  components;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->LeftMenu = (gcnew MetroFramework::Controls::MetroPanel());
			this->Button3 = (gcnew MetroFramework::Controls::MetroButton());
			this->Button2 = (gcnew MetroFramework::Controls::MetroButton());
			this->Button1 = (gcnew MetroFramework::Controls::MetroButton());
			this->Recognition_Panel = (gcnew MetroFramework::Controls::MetroPanel());
			this->SrcViewPanel = (gcnew System::Windows::Forms::PictureBox());
			this->ResultPanel = (gcnew MetroFramework::Controls::MetroPanel());
			this->CharResultText = (gcnew MetroFramework::Controls::MetroLabel());
			this->DetectedCharResultText = (gcnew MetroFramework::Controls::MetroLabel());
			this->PlateResultText = (gcnew MetroFramework::Controls::MetroLabel());
			this->CharResultPanel = (gcnew MetroFramework::Controls::MetroPanel());
			this->DetectedCharResultPanel = (gcnew MetroFramework::Controls::MetroPanel());
			this->PlateViewResultPanel = (gcnew MetroFramework::Controls::MetroPanel());
			this->ResultText = (gcnew MetroFramework::Controls::MetroLabel());
			this->ControlBarPanel = (gcnew MetroFramework::Controls::MetroPanel());
			this->ProcessingButton = (gcnew MetroFramework::Controls::MetroButton());
			this->LoadSourceButton = (gcnew MetroFramework::Controls::MetroButton());
			this->ImageRadioButton = (gcnew MetroFramework::Controls::MetroRadioButton());
			this->VideoRadioButton = (gcnew MetroFramework::Controls::MetroRadioButton());
			this->CameraRadioButton = (gcnew MetroFramework::Controls::MetroRadioButton());
			this->ControlBarText = (gcnew MetroFramework::Controls::MetroLabel());
			this->LeftMenu->SuspendLayout();
			this->Recognition_Panel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SrcViewPanel))->BeginInit();
			this->ResultPanel->SuspendLayout();
			this->ControlBarPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// LeftMenu
			// 
			this->LeftMenu->AutoScroll = true;
			this->LeftMenu->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->LeftMenu->Controls->Add(this->Button3);
			this->LeftMenu->Controls->Add(this->Button2);
			this->LeftMenu->Controls->Add(this->Button1);
			this->LeftMenu->HorizontalScrollbar = true;
			this->LeftMenu->HorizontalScrollbarBarColor = true;
			this->LeftMenu->HorizontalScrollbarHighlightOnWheel = false;
			this->LeftMenu->HorizontalScrollbarSize = 11;
			this->LeftMenu->Location = System::Drawing::Point(0, 0);
			this->LeftMenu->Margin = System::Windows::Forms::Padding(10);
			this->LeftMenu->Name = L"LeftMenu";
			this->LeftMenu->Size = System::Drawing::Size(220, 780);
			this->LeftMenu->TabIndex = 0;
			this->LeftMenu->Theme = MetroFramework::MetroThemeStyle::Dark;
			this->LeftMenu->VerticalScrollbar = true;
			this->LeftMenu->VerticalScrollbarBarColor = true;
			this->LeftMenu->VerticalScrollbarHighlightOnWheel = false;
			this->LeftMenu->VerticalScrollbarSize = 10;
			this->LeftMenu->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &AppForm::metroPanel1_Paint);
			// 
			// Button3
			// 
			this->Button3->AccessibleRole = System::Windows::Forms::AccessibleRole::MenuBar;
			this->Button3->BackColor = System::Drawing::Color::Transparent;
			this->Button3->CausesValidation = false;
			this->Button3->FontSize = MetroFramework::MetroButtonSize::Tall;
			this->Button3->FontWeight = MetroFramework::MetroButtonWeight::Regular;
			this->Button3->ForeColor = System::Drawing::Color::Silver;
			this->Button3->Location = System::Drawing::Point(-3, 246);
			this->Button3->Margin = System::Windows::Forms::Padding(3, 10, 3, 10);
			this->Button3->Name = L"Button3";
			this->Button3->Size = System::Drawing::Size(223, 60);
			this->Button3->TabIndex = 3;
			this->Button3->Text = L"Contact";
			this->Button3->Theme = MetroFramework::MetroThemeStyle::Dark;
			this->Button3->UseCustomBackColor = true;
			this->Button3->UseCustomForeColor = true;
			this->Button3->UseSelectable = true;
			// 
			// Button2
			// 
			this->Button2->AccessibleRole = System::Windows::Forms::AccessibleRole::MenuBar;
			this->Button2->BackColor = System::Drawing::Color::Transparent;
			this->Button2->CausesValidation = false;
			this->Button2->FontSize = MetroFramework::MetroButtonSize::Tall;
			this->Button2->FontWeight = MetroFramework::MetroButtonWeight::Regular;
			this->Button2->ForeColor = System::Drawing::Color::Silver;
			this->Button2->Location = System::Drawing::Point(-3, 166);
			this->Button2->Margin = System::Windows::Forms::Padding(3, 10, 3, 10);
			this->Button2->Name = L"Button2";
			this->Button2->Size = System::Drawing::Size(223, 60);
			this->Button2->TabIndex = 2;
			this->Button2->Text = L"About";
			this->Button2->Theme = MetroFramework::MetroThemeStyle::Dark;
			this->Button2->UseCustomBackColor = true;
			this->Button2->UseCustomForeColor = true;
			this->Button2->UseSelectable = true;
			// 
			// Button1
			// 
			this->Button1->AccessibleRole = System::Windows::Forms::AccessibleRole::MenuBar;
			this->Button1->BackColor = System::Drawing::Color::Transparent;
			this->Button1->CausesValidation = false;
			this->Button1->FontSize = MetroFramework::MetroButtonSize::Tall;
			this->Button1->FontWeight = MetroFramework::MetroButtonWeight::Regular;
			this->Button1->ForeColor = System::Drawing::Color::Silver;
			this->Button1->Location = System::Drawing::Point(-3, 86);
			this->Button1->Margin = System::Windows::Forms::Padding(3, 10, 3, 10);
			this->Button1->Name = L"Button1";
			this->Button1->Size = System::Drawing::Size(223, 60);
			this->Button1->TabIndex = 1;
			this->Button1->Text = L"Recognition";
			this->Button1->Theme = MetroFramework::MetroThemeStyle::Dark;
			this->Button1->UseCustomBackColor = true;
			this->Button1->UseCustomForeColor = true;
			this->Button1->UseSelectable = true;
			// 
			// Recognition_Panel
			// 
			this->Recognition_Panel->Controls->Add(this->SrcViewPanel);
			this->Recognition_Panel->Controls->Add(this->ResultPanel);
			this->Recognition_Panel->Controls->Add(this->ControlBarPanel);
			this->Recognition_Panel->HorizontalScrollbarBarColor = true;
			this->Recognition_Panel->HorizontalScrollbarHighlightOnWheel = false;
			this->Recognition_Panel->HorizontalScrollbarSize = 10;
			this->Recognition_Panel->Location = System::Drawing::Point(226, 68);
			this->Recognition_Panel->Name = L"Recognition_Panel";
			this->Recognition_Panel->Padding = System::Windows::Forms::Padding(15);
			this->Recognition_Panel->Size = System::Drawing::Size(1211, 704);
			this->Recognition_Panel->TabIndex = 1;
			this->Recognition_Panel->VerticalScrollbarBarColor = true;
			this->Recognition_Panel->VerticalScrollbarHighlightOnWheel = false;
			this->Recognition_Panel->VerticalScrollbarSize = 10;
			// 
			// SrcViewPanel
			// 
			this->SrcViewPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->SrcViewPanel->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->SrcViewPanel->Location = System::Drawing::Point(7, 18);
			this->SrcViewPanel->Name = L"SrcViewPanel";
			this->SrcViewPanel->Size = System::Drawing::Size(985, 668);
			this->SrcViewPanel->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->SrcViewPanel->TabIndex = 8;
			this->SrcViewPanel->TabStop = false;
			this->SrcViewPanel->WaitOnLoad = true;
			// 
			// ResultPanel
			// 
			this->ResultPanel->AutoSize = true;
			this->ResultPanel->Controls->Add(this->CharResultText);
			this->ResultPanel->Controls->Add(this->DetectedCharResultText);
			this->ResultPanel->Controls->Add(this->PlateResultText);
			this->ResultPanel->Controls->Add(this->CharResultPanel);
			this->ResultPanel->Controls->Add(this->DetectedCharResultPanel);
			this->ResultPanel->Controls->Add(this->PlateViewResultPanel);
			this->ResultPanel->Controls->Add(this->ResultText);
			this->ResultPanel->HorizontalScrollbarBarColor = true;
			this->ResultPanel->HorizontalScrollbarHighlightOnWheel = false;
			this->ResultPanel->HorizontalScrollbarSize = 10;
			this->ResultPanel->Location = System::Drawing::Point(998, 18);
			this->ResultPanel->Name = L"ResultPanel";
			this->ResultPanel->Padding = System::Windows::Forms::Padding(5);
			this->ResultPanel->Size = System::Drawing::Size(195, 279);
			this->ResultPanel->TabIndex = 7;
			this->ResultPanel->VerticalScrollbarBarColor = true;
			this->ResultPanel->VerticalScrollbarHighlightOnWheel = false;
			this->ResultPanel->VerticalScrollbarSize = 10;
			// 
			// CharResultText
			// 
			this->CharResultText->AutoSize = true;
			this->CharResultText->Location = System::Drawing::Point(8, 197);
			this->CharResultText->Name = L"CharResultText";
			this->CharResultText->Size = System::Drawing::Size(109, 19);
			this->CharResultText->TabIndex = 12;
			this->CharResultText->Text = L"Characters Result";
			// 
			// DetectedCharResultText
			// 
			this->DetectedCharResultText->AutoSize = true;
			this->DetectedCharResultText->Location = System::Drawing::Point(8, 111);
			this->DetectedCharResultText->Name = L"DetectedCharResultText";
			this->DetectedCharResultText->Size = System::Drawing::Size(127, 19);
			this->DetectedCharResultText->TabIndex = 11;
			this->DetectedCharResultText->Text = L"Detected Characters";
			// 
			// PlateResultText
			// 
			this->PlateResultText->AutoSize = true;
			this->PlateResultText->Location = System::Drawing::Point(8, 27);
			this->PlateResultText->Name = L"PlateResultText";
			this->PlateResultText->Size = System::Drawing::Size(38, 19);
			this->PlateResultText->TabIndex = 10;
			this->PlateResultText->Text = L"Plate";
			// 
			// CharResultPanel
			// 
			this->CharResultPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->CharResultPanel->HorizontalScrollbarBarColor = true;
			this->CharResultPanel->HorizontalScrollbarHighlightOnWheel = false;
			this->CharResultPanel->HorizontalScrollbarSize = 10;
			this->CharResultPanel->Location = System::Drawing::Point(8, 219);
			this->CharResultPanel->Name = L"CharResultPanel";
			this->CharResultPanel->Padding = System::Windows::Forms::Padding(5, 20, 5, 20);
			this->CharResultPanel->Size = System::Drawing::Size(179, 52);
			this->CharResultPanel->TabIndex = 9;
			this->CharResultPanel->VerticalScrollbarBarColor = true;
			this->CharResultPanel->VerticalScrollbarHighlightOnWheel = false;
			this->CharResultPanel->VerticalScrollbarSize = 10;
			// 
			// DetectedCharResultPanel
			// 
			this->DetectedCharResultPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->DetectedCharResultPanel->HorizontalScrollbarBarColor = true;
			this->DetectedCharResultPanel->HorizontalScrollbarHighlightOnWheel = false;
			this->DetectedCharResultPanel->HorizontalScrollbarSize = 10;
			this->DetectedCharResultPanel->Location = System::Drawing::Point(8, 133);
			this->DetectedCharResultPanel->Name = L"DetectedCharResultPanel";
			this->DetectedCharResultPanel->Padding = System::Windows::Forms::Padding(5, 20, 5, 20);
			this->DetectedCharResultPanel->Size = System::Drawing::Size(179, 52);
			this->DetectedCharResultPanel->TabIndex = 8;
			this->DetectedCharResultPanel->VerticalScrollbarBarColor = true;
			this->DetectedCharResultPanel->VerticalScrollbarHighlightOnWheel = false;
			this->DetectedCharResultPanel->VerticalScrollbarSize = 10;
			// 
			// PlateViewResultPanel
			// 
			this->PlateViewResultPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->PlateViewResultPanel->HorizontalScrollbarBarColor = true;
			this->PlateViewResultPanel->HorizontalScrollbarHighlightOnWheel = false;
			this->PlateViewResultPanel->HorizontalScrollbarSize = 10;
			this->PlateViewResultPanel->Location = System::Drawing::Point(8, 49);
			this->PlateViewResultPanel->Name = L"PlateViewResultPanel";
			this->PlateViewResultPanel->Padding = System::Windows::Forms::Padding(5, 20, 5, 20);
			this->PlateViewResultPanel->Size = System::Drawing::Size(179, 52);
			this->PlateViewResultPanel->TabIndex = 7;
			this->PlateViewResultPanel->VerticalScrollbarBarColor = true;
			this->PlateViewResultPanel->VerticalScrollbarHighlightOnWheel = false;
			this->PlateViewResultPanel->VerticalScrollbarSize = 10;
			// 
			// ResultText
			// 
			this->ResultText->AutoSize = true;
			this->ResultText->FontWeight = MetroFramework::MetroLabelWeight::Bold;
			this->ResultText->Location = System::Drawing::Point(0, 0);
			this->ResultText->Name = L"ResultText";
			this->ResultText->Size = System::Drawing::Size(49, 19);
			this->ResultText->Style = MetroFramework::MetroColorStyle::Black;
			this->ResultText->TabIndex = 6;
			this->ResultText->Text = L"Result";
			this->ResultText->UseStyleColors = true;
			// 
			// ControlBarPanel
			// 
			this->ControlBarPanel->AutoSize = true;
			this->ControlBarPanel->Controls->Add(this->ProcessingButton);
			this->ControlBarPanel->Controls->Add(this->LoadSourceButton);
			this->ControlBarPanel->Controls->Add(this->ImageRadioButton);
			this->ControlBarPanel->Controls->Add(this->VideoRadioButton);
			this->ControlBarPanel->Controls->Add(this->CameraRadioButton);
			this->ControlBarPanel->Controls->Add(this->ControlBarText);
			this->ControlBarPanel->HorizontalScrollbarBarColor = true;
			this->ControlBarPanel->HorizontalScrollbarHighlightOnWheel = false;
			this->ControlBarPanel->HorizontalScrollbarSize = 10;
			this->ControlBarPanel->Location = System::Drawing::Point(998, 472);
			this->ControlBarPanel->Name = L"ControlBarPanel";
			this->ControlBarPanel->Padding = System::Windows::Forms::Padding(5);
			this->ControlBarPanel->Size = System::Drawing::Size(195, 214);
			this->ControlBarPanel->TabIndex = 5;
			this->ControlBarPanel->VerticalScrollbarBarColor = true;
			this->ControlBarPanel->VerticalScrollbarHighlightOnWheel = false;
			this->ControlBarPanel->VerticalScrollbarSize = 10;
			// 
			// ProcessingButton
			// 
			this->ProcessingButton->Location = System::Drawing::Point(8, 164);
			this->ProcessingButton->Name = L"ProcessingButton";
			this->ProcessingButton->Size = System::Drawing::Size(179, 41);
			this->ProcessingButton->TabIndex = 8;
			this->ProcessingButton->Text = L"Processing";
			this->ProcessingButton->UseSelectable = true;
			// 
			// LoadSourceButton
			// 
			this->LoadSourceButton->Location = System::Drawing::Point(8, 109);
			this->LoadSourceButton->Name = L"LoadSourceButton";
			this->LoadSourceButton->Size = System::Drawing::Size(179, 41);
			this->LoadSourceButton->TabIndex = 7;
			this->LoadSourceButton->Text = L"Load Source";
			this->LoadSourceButton->UseSelectable = true;
			this->LoadSourceButton->Click += gcnew System::EventHandler(this, &AppForm::LoadSourceButton_Click);
			// 
			// ImageRadioButton
			// 
			this->ImageRadioButton->AutoSize = true;
			this->ImageRadioButton->Location = System::Drawing::Point(8, 32);
			this->ImageRadioButton->Name = L"ImageRadioButton";
			this->ImageRadioButton->Size = System::Drawing::Size(60, 17);
			this->ImageRadioButton->TabIndex = 2;
			this->ImageRadioButton->Text = L"Image";
			this->ImageRadioButton->UseSelectable = true;
			// 
			// VideoRadioButton
			// 
			this->VideoRadioButton->AutoSize = true;
			this->VideoRadioButton->Location = System::Drawing::Point(8, 55);
			this->VideoRadioButton->Name = L"VideoRadioButton";
			this->VideoRadioButton->Size = System::Drawing::Size(58, 17);
			this->VideoRadioButton->TabIndex = 3;
			this->VideoRadioButton->Text = L"Video";
			this->VideoRadioButton->UseSelectable = true;
			// 
			// CameraRadioButton
			// 
			this->CameraRadioButton->AutoSize = true;
			this->CameraRadioButton->Location = System::Drawing::Point(8, 78);
			this->CameraRadioButton->Name = L"CameraRadioButton";
			this->CameraRadioButton->Size = System::Drawing::Size(69, 17);
			this->CameraRadioButton->TabIndex = 4;
			this->CameraRadioButton->Text = L"Camera";
			this->CameraRadioButton->UseSelectable = true;
			// 
			// ControlBarText
			// 
			this->ControlBarText->AutoSize = true;
			this->ControlBarText->FontWeight = MetroFramework::MetroLabelWeight::Bold;
			this->ControlBarText->Location = System::Drawing::Point(0, 0);
			this->ControlBarText->Name = L"ControlBarText";
			this->ControlBarText->Size = System::Drawing::Size(86, 19);
			this->ControlBarText->Style = MetroFramework::MetroColorStyle::Black;
			this->ControlBarText->TabIndex = 6;
			this->ControlBarText->Text = L"Control Bar";
			this->ControlBarText->UseStyleColors = true;
			// 
			// AppForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 14);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BorderStyle = MetroFramework::Forms::MetroFormBorderStyle::FixedSingle;
			this->ClientSize = System::Drawing::Size(1440, 775);
			this->Controls->Add(this->Recognition_Panel);
			this->Controls->Add(this->LeftMenu);
			this->Font = (gcnew System::Drawing::Font(L"Myanmar Text", 7.471698F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->MaximizeBox = false;
			this->Name = L"AppForm";
			this->Padding = System::Windows::Forms::Padding(0, 60, 0, 0);
			this->Style = MetroFramework::MetroColorStyle::Red;
			this->Load += gcnew System::EventHandler(this, &AppForm::AppForm_Load);
			this->LeftMenu->ResumeLayout(false);
			this->Recognition_Panel->ResumeLayout(false);
			this->Recognition_Panel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SrcViewPanel))->EndInit();
			this->ResultPanel->ResumeLayout(false);
			this->ResultPanel->PerformLayout();
			this->ControlBarPanel->ResumeLayout(false);
			this->ControlBarPanel->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void AppForm_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void metroPanel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
	}
	private: System::Void LoadSourceButton_Click(System::Object^  sender, System::EventArgs^  e) {

		if (ImageRadioButton->Checked == true) {

			OpenFileDialog^ Open = gcnew OpenFileDialog();
			Open->ShowHelp = true;
			Open->RestoreDirectory = true;
			Open->Filter = "Image (*.bmp;*.jpg;*.png)|*.bmp;*.jpg;*.png|All files (*.*)|*.*||";

			if (Open->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				//Bitmap^ bmpSrc = gcnew Bitmap(Open->FileName);
				SrcViewPanel->ImageLocation = Open->FileName;
				SrcViewPanel->Refresh();
			}
			else
			{
				return;
			}

		}

		if (VideoRadioButton->Checked == true) {

			OpenFileDialog^ Open = gcnew OpenFileDialog();
			Open->ShowHelp = true;
			Open->RestoreDirectory = true;
			Open->Filter = "Video (*.avi;*.mp4;*.wmv;*.mpg)|*.avi;*.mp4;*.wmv;*.mpg|All files (*.*)|*.*||";

			if (Open->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				SrcViewPanel->ImageLocation = Open->FileName;
				SrcViewPanel->Refresh();
			}
			else
			{
				return;
			}

		}

		if (CameraRadioButton->Checked == true) {

			/*VideoCapture cap(0);
			if (!cap.isOpened())
			{
				std::cout << "change the camera port number";
			}
			while (true)
			{
				Mat frame;
				cap.read(frame);
				imshow("camera", frame);
				if (waitKey(30) == 27)
				{
					return;
				}
			}*/
		}
	}

	};
}
