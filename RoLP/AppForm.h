#pragma once
#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/video/video.hpp>

#include <alpr.h>


#include <iostream>
#include <string>
#include <stdint.h>

const int fps = 30;
bool exitValue = false;

namespace RoLP {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MetroFramework::Forms;
	using namespace cv;
	using namespace std;
	using namespace alpr;

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
	private: MetroFramework::Controls::MetroButton^  Recognition_Button;

	private: MetroFramework::Controls::MetroPanel^  Recognition_Panel;
	private: MetroFramework::Controls::MetroRadioButton^  CameraRadioButton;

	private: MetroFramework::Controls::MetroRadioButton^  VideoRadioButton;
	private: MetroFramework::Controls::MetroRadioButton^  ImageRadioButton;
	private: MetroFramework::Controls::MetroPanel^  ControlBarPanel;
	private: MetroFramework::Controls::MetroLabel^  ControlBarText;
	private: MetroFramework::Controls::MetroButton^  Contact_Button;

	private: MetroFramework::Controls::MetroButton^  About_Button;


	private: MetroFramework::Controls::MetroPanel^  ResultPanel;
	private: MetroFramework::Controls::MetroLabel^  ResultText;
	private: MetroFramework::Controls::MetroPanel^  PlateViewResultPanel;
	private: MetroFramework::Controls::MetroLabel^  PlateResultText;
	private: MetroFramework::Controls::MetroPanel^  CharResultPanel;
	private: MetroFramework::Controls::MetroPanel^  DetectedCharResultPanel;
	private: MetroFramework::Controls::MetroLabel^  DetectedCharResultText;
	private: MetroFramework::Controls::MetroLabel^  CharResultText;

	private: MetroFramework::Controls::MetroButton^  LoadSourceButton;
	private: System::Windows::Forms::PictureBox^  SrcViewPanel;
	private: MetroFramework::Controls::MetroButton^  ProcessingButton;



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
			this->Contact_Button = (gcnew MetroFramework::Controls::MetroButton());
			this->About_Button = (gcnew MetroFramework::Controls::MetroButton());
			this->Recognition_Button = (gcnew MetroFramework::Controls::MetroButton());
			this->Recognition_Panel = (gcnew MetroFramework::Controls::MetroPanel());
			this->ControlBarPanel = (gcnew MetroFramework::Controls::MetroPanel());
			this->ProcessingButton = (gcnew MetroFramework::Controls::MetroButton());
			this->LoadSourceButton = (gcnew MetroFramework::Controls::MetroButton());
			this->ImageRadioButton = (gcnew MetroFramework::Controls::MetroRadioButton());
			this->VideoRadioButton = (gcnew MetroFramework::Controls::MetroRadioButton());
			this->CameraRadioButton = (gcnew MetroFramework::Controls::MetroRadioButton());
			this->ControlBarText = (gcnew MetroFramework::Controls::MetroLabel());
			this->SrcViewPanel = (gcnew System::Windows::Forms::PictureBox());
			this->ResultPanel = (gcnew MetroFramework::Controls::MetroPanel());
			this->CharResultText = (gcnew MetroFramework::Controls::MetroLabel());
			this->DetectedCharResultText = (gcnew MetroFramework::Controls::MetroLabel());
			this->PlateResultText = (gcnew MetroFramework::Controls::MetroLabel());
			this->CharResultPanel = (gcnew MetroFramework::Controls::MetroPanel());
			this->DetectedCharResultPanel = (gcnew MetroFramework::Controls::MetroPanel());
			this->PlateViewResultPanel = (gcnew MetroFramework::Controls::MetroPanel());
			this->ResultText = (gcnew MetroFramework::Controls::MetroLabel());
			this->LeftMenu->SuspendLayout();
			this->Recognition_Panel->SuspendLayout();
			this->ControlBarPanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SrcViewPanel))->BeginInit();
			this->ResultPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// LeftMenu
			// 
			this->LeftMenu->AutoScroll = true;
			this->LeftMenu->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->LeftMenu->Controls->Add(this->Contact_Button);
			this->LeftMenu->Controls->Add(this->About_Button);
			this->LeftMenu->Controls->Add(this->Recognition_Button);
			this->LeftMenu->HorizontalScrollbar = true;
			this->LeftMenu->HorizontalScrollbarBarColor = true;
			this->LeftMenu->HorizontalScrollbarHighlightOnWheel = false;
			this->LeftMenu->HorizontalScrollbarSize = 16;
			this->LeftMenu->Location = System::Drawing::Point(0, 0);
			this->LeftMenu->Margin = System::Windows::Forms::Padding(10, 14, 10, 14);
			this->LeftMenu->Name = L"LeftMenu";
			this->LeftMenu->Size = System::Drawing::Size(220, 1114);
			this->LeftMenu->TabIndex = 0;
			this->LeftMenu->Theme = MetroFramework::MetroThemeStyle::Dark;
			this->LeftMenu->VerticalScrollbar = true;
			this->LeftMenu->VerticalScrollbarBarColor = true;
			this->LeftMenu->VerticalScrollbarHighlightOnWheel = false;
			this->LeftMenu->VerticalScrollbarSize = 10;
			this->LeftMenu->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &AppForm::metroPanel1_Paint);
			// 
			// Contact_Button
			// 
			this->Contact_Button->AccessibleRole = System::Windows::Forms::AccessibleRole::MenuBar;
			this->Contact_Button->BackColor = System::Drawing::Color::Transparent;
			this->Contact_Button->CausesValidation = false;
			this->Contact_Button->FontSize = MetroFramework::MetroButtonSize::Tall;
			this->Contact_Button->FontWeight = MetroFramework::MetroButtonWeight::Regular;
			this->Contact_Button->ForeColor = System::Drawing::Color::Silver;
			this->Contact_Button->Location = System::Drawing::Point(-3, 292);
			this->Contact_Button->Margin = System::Windows::Forms::Padding(3, 14, 3, 14);
			this->Contact_Button->Name = L"Contact_Button";
			this->Contact_Button->Size = System::Drawing::Size(223, 86);
			this->Contact_Button->TabIndex = 3;
			this->Contact_Button->Text = L"Contact";
			this->Contact_Button->Theme = MetroFramework::MetroThemeStyle::Dark;
			this->Contact_Button->UseCustomBackColor = true;
			this->Contact_Button->UseCustomForeColor = true;
			this->Contact_Button->UseSelectable = true;
			// 
			// About_Button
			// 
			this->About_Button->AccessibleRole = System::Windows::Forms::AccessibleRole::MenuBar;
			this->About_Button->BackColor = System::Drawing::Color::Transparent;
			this->About_Button->CausesValidation = false;
			this->About_Button->FontSize = MetroFramework::MetroButtonSize::Tall;
			this->About_Button->FontWeight = MetroFramework::MetroButtonWeight::Regular;
			this->About_Button->ForeColor = System::Drawing::Color::Silver;
			this->About_Button->Location = System::Drawing::Point(-3, 178);
			this->About_Button->Margin = System::Windows::Forms::Padding(3, 14, 3, 14);
			this->About_Button->Name = L"About_Button";
			this->About_Button->Size = System::Drawing::Size(223, 86);
			this->About_Button->TabIndex = 2;
			this->About_Button->Text = L"About";
			this->About_Button->Theme = MetroFramework::MetroThemeStyle::Dark;
			this->About_Button->UseCustomBackColor = true;
			this->About_Button->UseCustomForeColor = true;
			this->About_Button->UseSelectable = true;
			// 
			// Recognition_Button
			// 
			this->Recognition_Button->AccessibleRole = System::Windows::Forms::AccessibleRole::MenuBar;
			this->Recognition_Button->BackColor = System::Drawing::Color::Transparent;
			this->Recognition_Button->CausesValidation = false;
			this->Recognition_Button->FontSize = MetroFramework::MetroButtonSize::Tall;
			this->Recognition_Button->FontWeight = MetroFramework::MetroButtonWeight::Regular;
			this->Recognition_Button->ForeColor = System::Drawing::Color::Silver;
			this->Recognition_Button->Location = System::Drawing::Point(-3, 64);
			this->Recognition_Button->Margin = System::Windows::Forms::Padding(3, 14, 3, 14);
			this->Recognition_Button->Name = L"Recognition_Button";
			this->Recognition_Button->Size = System::Drawing::Size(223, 86);
			this->Recognition_Button->TabIndex = 1;
			this->Recognition_Button->Text = L"Recognition";
			this->Recognition_Button->Theme = MetroFramework::MetroThemeStyle::Dark;
			this->Recognition_Button->UseCustomBackColor = true;
			this->Recognition_Button->UseCustomForeColor = true;
			this->Recognition_Button->UseSelectable = true;
			// 
			// Recognition_Panel
			// 
			this->Recognition_Panel->Controls->Add(this->ControlBarPanel);
			this->Recognition_Panel->Controls->Add(this->SrcViewPanel);
			this->Recognition_Panel->Controls->Add(this->ResultPanel);
			this->Recognition_Panel->HorizontalScrollbarBarColor = true;
			this->Recognition_Panel->HorizontalScrollbarHighlightOnWheel = false;
			this->Recognition_Panel->HorizontalScrollbarSize = 14;
			this->Recognition_Panel->Location = System::Drawing::Point(226, 52);
			this->Recognition_Panel->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->Recognition_Panel->Name = L"Recognition_Panel";
			this->Recognition_Panel->Padding = System::Windows::Forms::Padding(15, 21, 15, 21);
			this->Recognition_Panel->Size = System::Drawing::Size(1211, 698);
			this->Recognition_Panel->TabIndex = 1;
			this->Recognition_Panel->VerticalScrollbarBarColor = true;
			this->Recognition_Panel->VerticalScrollbarHighlightOnWheel = false;
			this->Recognition_Panel->VerticalScrollbarSize = 10;
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
			this->ControlBarPanel->HorizontalScrollbarSize = 14;
			this->ControlBarPanel->Location = System::Drawing::Point(998, 417);
			this->ControlBarPanel->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->ControlBarPanel->Name = L"ControlBarPanel";
			this->ControlBarPanel->Padding = System::Windows::Forms::Padding(5, 7, 5, 7);
			this->ControlBarPanel->Size = System::Drawing::Size(195, 277);
			this->ControlBarPanel->TabIndex = 5;
			this->ControlBarPanel->VerticalScrollbarBarColor = true;
			this->ControlBarPanel->VerticalScrollbarHighlightOnWheel = false;
			this->ControlBarPanel->VerticalScrollbarSize = 10;
			// 
			// ProcessingButton
			// 
			this->ProcessingButton->Location = System::Drawing::Point(8, 215);
			this->ProcessingButton->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->ProcessingButton->Name = L"ProcessingButton";
			this->ProcessingButton->Size = System::Drawing::Size(179, 51);
			this->ProcessingButton->TabIndex = 8;
			this->ProcessingButton->Text = L"Processing";
			this->ProcessingButton->UseSelectable = true;
			// 
			// LoadSourceButton
			// 
			this->LoadSourceButton->Location = System::Drawing::Point(8, 156);
			this->LoadSourceButton->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->LoadSourceButton->Name = L"LoadSourceButton";
			this->LoadSourceButton->Size = System::Drawing::Size(179, 51);
			this->LoadSourceButton->TabIndex = 7;
			this->LoadSourceButton->Text = L"Load Source";
			this->LoadSourceButton->UseSelectable = true;
			this->LoadSourceButton->Click += gcnew System::EventHandler(this, &AppForm::LoadSourceButton_Click);
			// 
			// ImageRadioButton
			// 
			this->ImageRadioButton->AutoSize = true;
			this->ImageRadioButton->Location = System::Drawing::Point(8, 46);
			this->ImageRadioButton->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->ImageRadioButton->Name = L"ImageRadioButton";
			this->ImageRadioButton->Size = System::Drawing::Size(60, 17);
			this->ImageRadioButton->TabIndex = 2;
			this->ImageRadioButton->Text = L"Image";
			this->ImageRadioButton->UseSelectable = true;
			// 
			// VideoRadioButton
			// 
			this->VideoRadioButton->AutoSize = true;
			this->VideoRadioButton->Location = System::Drawing::Point(8, 79);
			this->VideoRadioButton->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->VideoRadioButton->Name = L"VideoRadioButton";
			this->VideoRadioButton->Size = System::Drawing::Size(58, 17);
			this->VideoRadioButton->TabIndex = 3;
			this->VideoRadioButton->Text = L"Video";
			this->VideoRadioButton->UseSelectable = true;
			// 
			// CameraRadioButton
			// 
			this->CameraRadioButton->AutoSize = true;
			this->CameraRadioButton->Location = System::Drawing::Point(8, 111);
			this->CameraRadioButton->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
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
			// SrcViewPanel
			// 
			this->SrcViewPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->SrcViewPanel->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->SrcViewPanel->Location = System::Drawing::Point(7, 12);
			this->SrcViewPanel->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->SrcViewPanel->Name = L"SrcViewPanel";
			this->SrcViewPanel->Size = System::Drawing::Size(985, 671);
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
			this->ResultPanel->HorizontalScrollbarSize = 14;
			this->ResultPanel->Location = System::Drawing::Point(998, 12);
			this->ResultPanel->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->ResultPanel->Name = L"ResultPanel";
			this->ResultPanel->Padding = System::Windows::Forms::Padding(5, 7, 5, 7);
			this->ResultPanel->Size = System::Drawing::Size(195, 397);
			this->ResultPanel->TabIndex = 7;
			this->ResultPanel->VerticalScrollbarBarColor = true;
			this->ResultPanel->VerticalScrollbarHighlightOnWheel = false;
			this->ResultPanel->VerticalScrollbarSize = 10;
			// 
			// CharResultText
			// 
			this->CharResultText->AutoSize = true;
			this->CharResultText->Location = System::Drawing::Point(8, 281);
			this->CharResultText->Name = L"CharResultText";
			this->CharResultText->Size = System::Drawing::Size(109, 19);
			this->CharResultText->TabIndex = 12;
			this->CharResultText->Text = L"Characters Result";
			// 
			// DetectedCharResultText
			// 
			this->DetectedCharResultText->AutoSize = true;
			this->DetectedCharResultText->Location = System::Drawing::Point(8, 159);
			this->DetectedCharResultText->Name = L"DetectedCharResultText";
			this->DetectedCharResultText->Size = System::Drawing::Size(127, 19);
			this->DetectedCharResultText->TabIndex = 11;
			this->DetectedCharResultText->Text = L"Detected Characters";
			// 
			// PlateResultText
			// 
			this->PlateResultText->AutoSize = true;
			this->PlateResultText->Location = System::Drawing::Point(8, 39);
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
			this->CharResultPanel->HorizontalScrollbarSize = 14;
			this->CharResultPanel->Location = System::Drawing::Point(8, 313);
			this->CharResultPanel->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->CharResultPanel->Name = L"CharResultPanel";
			this->CharResultPanel->Padding = System::Windows::Forms::Padding(5, 29, 5, 29);
			this->CharResultPanel->Size = System::Drawing::Size(179, 73);
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
			this->DetectedCharResultPanel->HorizontalScrollbarSize = 14;
			this->DetectedCharResultPanel->Location = System::Drawing::Point(8, 190);
			this->DetectedCharResultPanel->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->DetectedCharResultPanel->Name = L"DetectedCharResultPanel";
			this->DetectedCharResultPanel->Padding = System::Windows::Forms::Padding(5, 29, 5, 29);
			this->DetectedCharResultPanel->Size = System::Drawing::Size(179, 73);
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
			this->PlateViewResultPanel->HorizontalScrollbarSize = 14;
			this->PlateViewResultPanel->Location = System::Drawing::Point(8, 70);
			this->PlateViewResultPanel->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->PlateViewResultPanel->Name = L"PlateViewResultPanel";
			this->PlateViewResultPanel->Padding = System::Windows::Forms::Padding(5, 29, 5, 29);
			this->PlateViewResultPanel->Size = System::Drawing::Size(179, 73);
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
			// AppForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BorderStyle = MetroFramework::Forms::MetroFormBorderStyle::FixedSingle;
			this->ClientSize = System::Drawing::Size(1440, 755);
			this->Controls->Add(this->Recognition_Panel);
			this->Controls->Add(this->LeftMenu);
			this->Font = (gcnew System::Drawing::Font(L"Myanmar Text", 7.471698F));
			this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->MaximizeBox = false;
			this->Name = L"AppForm";
			this->Padding = System::Windows::Forms::Padding(0, 86, 0, 0);
			this->Style = MetroFramework::MetroColorStyle::Red;
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &AppForm::AppForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &AppForm::AppForm_Load);
			this->LeftMenu->ResumeLayout(false);
			this->Recognition_Panel->ResumeLayout(false);
			this->Recognition_Panel->PerformLayout();
			this->ControlBarPanel->ResumeLayout(false);
			this->ControlBarPanel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SrcViewPanel))->EndInit();
			this->ResultPanel->ResumeLayout(false);
			this->ResultPanel->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void AppForm_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void metroPanel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
	}
#pragma region buttonsOptions
	private: System::Void LoadSourceButton_Click(System::Object^  sender, System::EventArgs^  e) {

		if (ImageRadioButton->Checked == true) {

			OpenFileDialog^ Open = gcnew OpenFileDialog();
			Open->ShowHelp = true;
			Open->RestoreDirectory = true;
			Open->Filter = "Image (*.bmp;*.jpg;*.png)|*.bmp;*.jpg;*.png|All files (*.*)|*.*||";

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

		if (VideoRadioButton->Checked == true) 
		{

			//VideoCapture cap("c://123.mp4");
			//// cap is the object of class video capture that tries to capture Bumpy.mp4
			//if (!cap.isOpened())  // isOpened() returns true if capturing has been initialized.
			//{
			//	cout << "Cannot open the video file. \n";
			//	return ;
			//}

			//double fps = 30;

			//while (1)
			//{
				//	Mat frame;
				//	// Mat object is a basic image container. frame is an object of Mat.

				//	if (!cap.read(frame)) // if not success, break loop
				//	// read() decodes and captures the next frame.
				//	{
				//		cout << "\n Cannot read the video file. \n";
				//		break;
				//	}

				//	("A_good_name", frame);
				//	// first argument: name of the window.
				//	// second argument: image to be shown(Mat object).

				//	if (waitKey(30) == 27) // Wait for 'esc' key press to exit
				//	{
				//		break;
				//	}
				//}

				//return ;

				OpenFileDialog^ Open = gcnew OpenFileDialog();
				Open->ShowHelp = true;
				Open->RestoreDirectory = true;
				Open->Filter = "Video (*.avi;*.mp4;*.wmv;*.mpg)|*.avi;*.mp4;*.wmv;*.mpg|All files (*.*)|*.*||";

				if (Open->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				{
					while (1){
					Bitmap^ bmpSrc = gcnew Bitmap(Open->FileName);
					SrcViewPanel->Image = bmpSrc;
					SrcViewPanel->Refresh();
				}
				}
				else
				{
					return;
				}

			//}

		}

		if (CameraRadioButton->Checked == true) {

			Mat frame;
			VideoCapture cap(0);

			if (!cap.isOpened())
			{
				std::cout << "change the camera port number";
			}

			while (cap.read(frame) & CameraRadioButton->Checked == true & exitValue == false) {

				if (frame.empty()) return; // end of video stream

				System::IntPtr ptr2(frame.ptr());

				SrcViewPanel->Width = 1.5 * frame.cols;
				SrcViewPanel->Height = 1.4 * frame.rows;
				SrcViewPanel->Image = gcnew System::Drawing::Bitmap(frame.cols, frame.rows, frame.step, System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr2);
				SrcViewPanel->Refresh();

				if (waitKey(1000 / fps) >= 0) {
					frame.release();
					cap.release();
					break;
				}

			}

		}
	}
#pragma endregion buttonsOptions
	private: System::Void AppForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {

		if (MetroFramework::MetroMessageBox::Show(this, "Do you really want to exit?", "RoLP",
			MessageBoxButtons::YesNo,
			MessageBoxIcon::Stop) == System::Windows::Forms::DialogResult::Yes) {
			exitValue = true;
			exit(0);
		}
		else {
			e->Cancel = true;
		}
	}
	};
}
