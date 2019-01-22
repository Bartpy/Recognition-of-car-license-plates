#pragma once
/*--------------------------------------------------------*/
#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/video/video.hpp>
#include <opencv2/objdetect/objdetect.hpp>
/*--------------------------------------------------------*/
#include <leptonica/allheaders.h>
#include <tesseract/baseapi.h>
/*--------------------------------------------------------*/
#include <msclr\marshal_cppstd.h>
/*--------------------------------------------------------*/
#include <iostream>
#include <string>
#include <stdint.h>
#include <stdlib.h>

const int fps = 30;
bool exitValue = false;
/*--------------------------------------------------------*/
int edgeThresh = 1;
int lowThreshold;
int const max_lowThreshold = 100;
int ratio2 = 3;
int kernel_size = 3;
/*--------------------------------------------------------*/

cv::CascadeClassifier Classifier;
tesseract::TessBaseAPI TesseractAPI;

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
	using namespace tesseract;

	VideoCapture* CAP = NULL;
	Mat gray;
	Mat dst;
	Mat detected_edges;
	Mat img_to_det;
	cv::Size size(900, 600);
	cv::Size small_size(150, 40);

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
	private: MetroFramework::Controls::MetroLabel^  PlateResultText;
	private: MetroFramework::Controls::MetroLabel^  CharResultText;
	private: MetroFramework::Controls::MetroButton^  LoadSourceButton;
	private: System::Windows::Forms::PictureBox^  SrcViewPanel;
	private: MetroFramework::Controls::MetroButton^  ProcessingButton;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::PictureBox^  PlateViewResultBox;
	private: System::Windows::Forms::Label^  CharResultLabel;
	private: MetroFramework::Controls::MetroButton^  StopProcessingButton;
	private: System::Windows::Forms::Label^  StatusMainLabel;
	private: MetroFramework::Controls::MetroPanel^  About_Panel;
	private: MetroFramework::Controls::MetroLabel^  Name_ect_Label;
	private: MetroFramework::Controls::MetroLabel^  Desc_label;
	private: MetroFramework::Controls::MetroPanel^  Contact_Panel;
	private: MetroFramework::Controls::MetroLabel^  Num_phone_label;
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
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(AppForm::typeid));
			this->LeftMenu = (gcnew MetroFramework::Controls::MetroPanel());
			this->Contact_Button = (gcnew MetroFramework::Controls::MetroButton());
			this->About_Button = (gcnew MetroFramework::Controls::MetroButton());
			this->Recognition_Button = (gcnew MetroFramework::Controls::MetroButton());
			this->Recognition_Panel = (gcnew MetroFramework::Controls::MetroPanel());
			this->About_Panel = (gcnew MetroFramework::Controls::MetroPanel());
			this->Desc_label = (gcnew MetroFramework::Controls::MetroLabel());
			this->Name_ect_Label = (gcnew MetroFramework::Controls::MetroLabel());
			this->StatusMainLabel = (gcnew System::Windows::Forms::Label());
			this->ControlBarPanel = (gcnew MetroFramework::Controls::MetroPanel());
			this->StopProcessingButton = (gcnew MetroFramework::Controls::MetroButton());
			this->ProcessingButton = (gcnew MetroFramework::Controls::MetroButton());
			this->LoadSourceButton = (gcnew MetroFramework::Controls::MetroButton());
			this->ImageRadioButton = (gcnew MetroFramework::Controls::MetroRadioButton());
			this->VideoRadioButton = (gcnew MetroFramework::Controls::MetroRadioButton());
			this->CameraRadioButton = (gcnew MetroFramework::Controls::MetroRadioButton());
			this->ControlBarText = (gcnew MetroFramework::Controls::MetroLabel());
			this->SrcViewPanel = (gcnew System::Windows::Forms::PictureBox());
			this->ResultPanel = (gcnew MetroFramework::Controls::MetroPanel());
			this->CharResultLabel = (gcnew System::Windows::Forms::Label());
			this->PlateViewResultBox = (gcnew System::Windows::Forms::PictureBox());
			this->CharResultText = (gcnew MetroFramework::Controls::MetroLabel());
			this->PlateResultText = (gcnew MetroFramework::Controls::MetroLabel());
			this->ResultText = (gcnew MetroFramework::Controls::MetroLabel());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->Contact_Panel = (gcnew MetroFramework::Controls::MetroPanel());
			this->Num_phone_label = (gcnew MetroFramework::Controls::MetroLabel());
			this->LeftMenu->SuspendLayout();
			this->Recognition_Panel->SuspendLayout();
			this->About_Panel->SuspendLayout();
			this->ControlBarPanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SrcViewPanel))->BeginInit();
			this->ResultPanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PlateViewResultBox))->BeginInit();
			this->Contact_Panel->SuspendLayout();
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
			this->Contact_Button->Click += gcnew System::EventHandler(this, &AppForm::Contact_Button_Click);
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
			this->About_Button->Click += gcnew System::EventHandler(this, &AppForm::About_Button_Click);
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
			this->Recognition_Button->Click += gcnew System::EventHandler(this, &AppForm::Recognition_Button_Click);
			// 
			// Recognition_Panel
			// 
			this->Recognition_Panel->Controls->Add(this->StatusMainLabel);
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
			this->Recognition_Panel->Size = System::Drawing::Size(1309, 698);
			this->Recognition_Panel->TabIndex = 1;
			this->Recognition_Panel->VerticalScrollbarBarColor = true;
			this->Recognition_Panel->VerticalScrollbarHighlightOnWheel = false;
			this->Recognition_Panel->VerticalScrollbarSize = 10;
			// 
			// About_Panel
			// 
			this->About_Panel->Controls->Add(this->Desc_label);
			this->About_Panel->Controls->Add(this->Name_ect_Label);
			this->About_Panel->HorizontalScrollbarBarColor = true;
			this->About_Panel->HorizontalScrollbarHighlightOnWheel = false;
			this->About_Panel->HorizontalScrollbarSize = 10;
			this->About_Panel->Location = System::Drawing::Point(226, 52);
			this->About_Panel->Name = L"About_Panel";
			this->About_Panel->Size = System::Drawing::Size(1309, 695);
			this->About_Panel->TabIndex = 2;
			this->About_Panel->VerticalScrollbarBarColor = true;
			this->About_Panel->VerticalScrollbarHighlightOnWheel = false;
			this->About_Panel->VerticalScrollbarSize = 10;
			// 
			// Desc_label
			// 
			this->Desc_label->AutoSize = true;
			this->Desc_label->BackColor = System::Drawing::Color::Silver;
			this->Desc_label->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Desc_label->FontSize = MetroFramework::MetroLabelSize::Tall;
			this->Desc_label->FontWeight = MetroFramework::MetroLabelWeight::Regular;
			this->Desc_label->Location = System::Drawing::Point(691, 484);
			this->Desc_label->Name = L"Desc_label";
			this->Desc_label->Size = System::Drawing::Size(555, 150);
			this->Desc_label->TabIndex = 3;
			this->Desc_label->Text = resources->GetString(L"Desc_label.Text");
			this->Desc_label->UseCustomBackColor = true;
			this->Desc_label->UseCustomForeColor = true;
			// 
			// Name_ect_Label
			// 
			this->Name_ect_Label->AutoSize = true;
			this->Name_ect_Label->BackColor = System::Drawing::Color::Silver;
			this->Name_ect_Label->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Name_ect_Label->FontSize = MetroFramework::MetroLabelSize::Tall;
			this->Name_ect_Label->FontWeight = MetroFramework::MetroLabelWeight::Regular;
			this->Name_ect_Label->Location = System::Drawing::Point(60, 59);
			this->Name_ect_Label->Name = L"Name_ect_Label";
			this->Name_ect_Label->Size = System::Drawing::Size(630, 175);
			this->Name_ect_Label->TabIndex = 2;
			this->Name_ect_Label->Text = resources->GetString(L"Name_ect_Label.Text");
			this->Name_ect_Label->UseCustomBackColor = true;
			this->Name_ect_Label->UseCustomForeColor = true;
			// 
			// StatusMainLabel
			// 
			this->StatusMainLabel->AutoSize = true;
			this->StatusMainLabel->Location = System::Drawing::Point(7, 678);
			this->StatusMainLabel->Name = L"StatusMainLabel";
			this->StatusMainLabel->Size = System::Drawing::Size(0, 20);
			this->StatusMainLabel->TabIndex = 9;
			// 
			// ControlBarPanel
			// 
			this->ControlBarPanel->AutoSize = true;
			this->ControlBarPanel->Controls->Add(this->StopProcessingButton);
			this->ControlBarPanel->Controls->Add(this->ProcessingButton);
			this->ControlBarPanel->Controls->Add(this->LoadSourceButton);
			this->ControlBarPanel->Controls->Add(this->ImageRadioButton);
			this->ControlBarPanel->Controls->Add(this->VideoRadioButton);
			this->ControlBarPanel->Controls->Add(this->CameraRadioButton);
			this->ControlBarPanel->Controls->Add(this->ControlBarText);
			this->ControlBarPanel->HorizontalScrollbarBarColor = true;
			this->ControlBarPanel->HorizontalScrollbarHighlightOnWheel = false;
			this->ControlBarPanel->HorizontalScrollbarSize = 14;
			this->ControlBarPanel->Location = System::Drawing::Point(975, 406);
			this->ControlBarPanel->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->ControlBarPanel->Name = L"ControlBarPanel";
			this->ControlBarPanel->Padding = System::Windows::Forms::Padding(5, 7, 5, 7);
			this->ControlBarPanel->Size = System::Drawing::Size(324, 283);
			this->ControlBarPanel->TabIndex = 5;
			this->ControlBarPanel->VerticalScrollbarBarColor = true;
			this->ControlBarPanel->VerticalScrollbarHighlightOnWheel = false;
			this->ControlBarPanel->VerticalScrollbarSize = 10;
			// 
			// StopProcessingButton
			// 
			this->StopProcessingButton->Location = System::Drawing::Point(66, 232);
			this->StopProcessingButton->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->StopProcessingButton->Name = L"StopProcessingButton";
			this->StopProcessingButton->Size = System::Drawing::Size(192, 40);
			this->StopProcessingButton->TabIndex = 9;
			this->StopProcessingButton->Text = L"Stop Processing";
			this->StopProcessingButton->UseSelectable = true;
			this->StopProcessingButton->Click += gcnew System::EventHandler(this, &AppForm::StopProcessingButton_Click);
			// 
			// ProcessingButton
			// 
			this->ProcessingButton->Location = System::Drawing::Point(66, 184);
			this->ProcessingButton->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->ProcessingButton->Name = L"ProcessingButton";
			this->ProcessingButton->Size = System::Drawing::Size(192, 40);
			this->ProcessingButton->TabIndex = 8;
			this->ProcessingButton->Text = L"Processing";
			this->ProcessingButton->UseSelectable = true;
			this->ProcessingButton->Click += gcnew System::EventHandler(this, &AppForm::ProcessingButton_Click);
			// 
			// LoadSourceButton
			// 
			this->LoadSourceButton->Location = System::Drawing::Point(66, 135);
			this->LoadSourceButton->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->LoadSourceButton->Name = L"LoadSourceButton";
			this->LoadSourceButton->Size = System::Drawing::Size(192, 40);
			this->LoadSourceButton->TabIndex = 7;
			this->LoadSourceButton->Text = L"Load Source";
			this->LoadSourceButton->UseSelectable = true;
			this->LoadSourceButton->Click += gcnew System::EventHandler(this, &AppForm::LoadSourceButton_Click);
			// 
			// ImageRadioButton
			// 
			this->ImageRadioButton->AutoSize = true;
			this->ImageRadioButton->Location = System::Drawing::Point(8, 35);
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
			this->VideoRadioButton->Location = System::Drawing::Point(8, 68);
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
			this->CameraRadioButton->Location = System::Drawing::Point(8, 100);
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
			this->SrcViewPanel->Size = System::Drawing::Size(962, 666);
			this->SrcViewPanel->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->SrcViewPanel->TabIndex = 8;
			this->SrcViewPanel->TabStop = false;
			this->SrcViewPanel->WaitOnLoad = true;
			// 
			// ResultPanel
			// 
			this->ResultPanel->AutoSize = true;
			this->ResultPanel->Controls->Add(this->CharResultLabel);
			this->ResultPanel->Controls->Add(this->PlateViewResultBox);
			this->ResultPanel->Controls->Add(this->CharResultText);
			this->ResultPanel->Controls->Add(this->PlateResultText);
			this->ResultPanel->Controls->Add(this->ResultText);
			this->ResultPanel->HorizontalScrollbarBarColor = true;
			this->ResultPanel->HorizontalScrollbarHighlightOnWheel = false;
			this->ResultPanel->HorizontalScrollbarSize = 14;
			this->ResultPanel->Location = System::Drawing::Point(975, 12);
			this->ResultPanel->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->ResultPanel->Name = L"ResultPanel";
			this->ResultPanel->Padding = System::Windows::Forms::Padding(5, 7, 5, 7);
			this->ResultPanel->Size = System::Drawing::Size(324, 386);
			this->ResultPanel->TabIndex = 7;
			this->ResultPanel->VerticalScrollbarBarColor = true;
			this->ResultPanel->VerticalScrollbarHighlightOnWheel = false;
			this->ResultPanel->VerticalScrollbarSize = 10;
			// 
			// CharResultLabel
			// 
			this->CharResultLabel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->CharResultLabel->Font = (gcnew System::Drawing::Font(L"Myanmar Text", 24, System::Drawing::FontStyle::Bold));
			this->CharResultLabel->Location = System::Drawing::Point(8, 257);
			this->CharResultLabel->Margin = System::Windows::Forms::Padding(3);
			this->CharResultLabel->Name = L"CharResultLabel";
			this->CharResultLabel->Padding = System::Windows::Forms::Padding(0, 18, 0, 0);
			this->CharResultLabel->Size = System::Drawing::Size(308, 81);
			this->CharResultLabel->TabIndex = 14;
			this->CharResultLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->CharResultLabel->UseCompatibleTextRendering = true;
			// 
			// PlateViewResultBox
			// 
			this->PlateViewResultBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->PlateViewResultBox->Location = System::Drawing::Point(8, 69);
			this->PlateViewResultBox->Name = L"PlateViewResultBox";
			this->PlateViewResultBox->Size = System::Drawing::Size(308, 81);
			this->PlateViewResultBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->PlateViewResultBox->TabIndex = 13;
			this->PlateViewResultBox->TabStop = false;
			this->PlateViewResultBox->WaitOnLoad = true;
			// 
			// CharResultText
			// 
			this->CharResultText->AutoSize = true;
			this->CharResultText->Location = System::Drawing::Point(8, 235);
			this->CharResultText->Name = L"CharResultText";
			this->CharResultText->Size = System::Drawing::Size(109, 19);
			this->CharResultText->TabIndex = 12;
			this->CharResultText->Text = L"Characters Result";
			// 
			// PlateResultText
			// 
			this->PlateResultText->AutoSize = true;
			this->PlateResultText->Location = System::Drawing::Point(8, 47);
			this->PlateResultText->Name = L"PlateResultText";
			this->PlateResultText->Size = System::Drawing::Size(38, 19);
			this->PlateResultText->TabIndex = 10;
			this->PlateResultText->Text = L"Plate";
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
			// timer1
			// 
			this->timer1->Interval = 10;
			this->timer1->Tick += gcnew System::EventHandler(this, &AppForm::timer1_Tick);
			// 
			// Contact_Panel
			// 
			this->Contact_Panel->Controls->Add(this->Num_phone_label);
			this->Contact_Panel->HorizontalScrollbarBarColor = true;
			this->Contact_Panel->HorizontalScrollbarHighlightOnWheel = false;
			this->Contact_Panel->HorizontalScrollbarSize = 10;
			this->Contact_Panel->Location = System::Drawing::Point(226, 52);
			this->Contact_Panel->Name = L"Contact_Panel";
			this->Contact_Panel->Size = System::Drawing::Size(1309, 695);
			this->Contact_Panel->TabIndex = 4;
			this->Contact_Panel->VerticalScrollbarBarColor = true;
			this->Contact_Panel->VerticalScrollbarHighlightOnWheel = false;
			this->Contact_Panel->VerticalScrollbarSize = 10;
			// 
			// Num_phone_label
			// 
			this->Num_phone_label->AutoSize = true;
			this->Num_phone_label->BackColor = System::Drawing::Color::Silver;
			this->Num_phone_label->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Num_phone_label->FontSize = MetroFramework::MetroLabelSize::Tall;
			this->Num_phone_label->FontWeight = MetroFramework::MetroLabelWeight::Regular;
			this->Num_phone_label->Location = System::Drawing::Point(495, 173);
			this->Num_phone_label->Name = L"Num_phone_label";
			this->Num_phone_label->Size = System::Drawing::Size(309, 225);
			this->Num_phone_label->TabIndex = 2;
			this->Num_phone_label->Text = L"\r\n\r\nBart³omiej Pyk\r\n\r\nphone: 732 011 300\r\ne-mail: pyk.bartlomiej@gmail.com  \r\n\r\n\r"
				L"\n";
			this->Num_phone_label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->Num_phone_label->UseCustomBackColor = true;
			this->Num_phone_label->UseCustomForeColor = true;
			// 
			// AppForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BorderStyle = MetroFramework::Forms::MetroFormBorderStyle::FixedSingle;
			this->ClientSize = System::Drawing::Size(1538, 755);
			this->Controls->Add(this->Contact_Panel);
			this->Controls->Add(this->Recognition_Panel);
			this->Controls->Add(this->About_Panel);
			this->Controls->Add(this->LeftMenu);
			this->Font = (gcnew System::Drawing::Font(L"Myanmar Text", 7.471698F));
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->MaximizeBox = false;
			this->Name = L"AppForm";
			this->Padding = System::Windows::Forms::Padding(0, 86, 0, 0);
			this->Style = MetroFramework::MetroColorStyle::Red;
			this->Text = L"RoLP";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &AppForm::AppForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &AppForm::AppForm_Load);
			this->LeftMenu->ResumeLayout(false);
			this->Recognition_Panel->ResumeLayout(false);
			this->Recognition_Panel->PerformLayout();
			this->About_Panel->ResumeLayout(false);
			this->About_Panel->PerformLayout();
			this->ControlBarPanel->ResumeLayout(false);
			this->ControlBarPanel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SrcViewPanel))->EndInit();
			this->ResultPanel->ResumeLayout(false);
			this->ResultPanel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PlateViewResultBox))->EndInit();
			this->Contact_Panel->ResumeLayout(false);
			this->Contact_Panel->PerformLayout();
			this->ResumeLayout(false);

		}


#pragma endregion

	private: System::Void AppForm_Load(System::Object^  sender, System::EventArgs^  e) {
		Contact_Panel->Hide();
		About_Panel->Hide();
		Recognition_Panel->Show();
	}
	private: System::Void metroPanel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
	}

			 void CannyThreshold(int, Mat image)
			 {
				 /// Reduce noise with a kernel 3x3
				 blur(gray, detected_edges, cv::Size(3, 3));

				 /// Canny detector

				 Canny(detected_edges, detected_edges, 80, 80 * ratio2, kernel_size);

				 /// Using Canny's output as a mask, we display our result
				 dst = Scalar::all(0);

				 image.copyTo(dst, detected_edges);
				 //imshow("Threshold", dst);
			 }
#pragma region buttonsOptions
	private: System::Void LoadSourceButton_Click(System::Object^  sender, System::EventArgs^  e) {

		if (ImageRadioButton->Checked == true) {

			timer1->Enabled = false;
			delete CAP;
			CAP = NULL;
			OpenFileDialog^ Open = gcnew OpenFileDialog();
			Open->ShowHelp = true;
			Open->RestoreDirectory = true;
			Open->Filter = "Image (*.bmp;*.jpg;*.png)|*.bmp;*.jpg;*.png|All files (*.*)|*.*||";

			if (Open->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				string init_file_path = msclr::interop::marshal_as<std::string>(Open->FileName);
				Mat read_src = cv::imread(init_file_path, 1);
				Mat init_src;
				resize(read_src, init_src, size);
				StatusMainLabel->Text = "The source has been successfully loaded";
				System::IntPtr init_main_frame(init_src.ptr());
				//SrcViewPanel->Width = (int)(init_src.cols);
				//SrcViewPanel->Height = (int)(init_src.rows);
				SrcViewPanel->ResetImeMode();
				SrcViewPanel->Image = gcnew System::Drawing::Bitmap(init_src.cols, init_src.rows, init_src.step, System::Drawing::Imaging::PixelFormat::Format24bppRgb, init_main_frame);
				SrcViewPanel->Refresh();
			}
			else
			{
				StatusMainLabel->Text = "The source has not been successfully loaded";
				return;
			}

			string file_path = msclr::interop::marshal_as<std::string>(Open->FileName);

			Mat src = cv::imread(file_path, 1);
			int tmp = 1;
			cv::Mat img2;

			dst.create(src.size(), src.type());

			cvtColor(src, gray, cv::COLOR_BGR2GRAY);
			equalizeHist(gray, img_to_det);
			CannyThreshold(0, img_to_det);
			//cv::imshow("Equalize Histogram",img_to_det);

			bool cascadeSymbolLoad = Classifier.load("D:/Studia/IV_rok/Praca_inz/Projekt/RoLP/x64/Debug/eu.xml");

			if (TesseractAPI.Init(NULL, "eng", tesseract::OEM_DEFAULT) < 0) return;
			TesseractAPI.SetPageSegMode(tesseract::PSM_AUTO_OSD);
			TesseractAPI.SetOutputName("out");

			if (!cascadeSymbolLoad)
			{
				std::cerr << "Cascade not load." << std::endl;
				MetroFramework::MetroMessageBox::Show(this, "RoLP can not upload Cascade Classifier file into application.", "RoLP",
					MessageBoxButtons::OK,
					MessageBoxIcon::Stop);
				return;
			}

			std::vector<cv::Rect> symbols;
			Classifier.detectMultiScale(img_to_det, symbols, 1.1, 2, 0); // Wyszukiwanie kaskadowe

			for (auto& p : symbols)
			{

				cv::Point symbolBegin = cv::Point(p.x, p.y);
				cv::Point symbolEnd = cv::Point(p.x + p.width, p.y + p.height);

				std::cout << "X: " << p.x << " Y: " << p.y << " Width: " << p.width << " Height: " << p.height << std::endl;

				rectangle(src, symbolBegin, symbolEnd, cv::Scalar(0, 255, 0), 2);

				img2 = src(Rect(p.x, p.y, p.width, p.height));
				//	cv::imshow(tmp_name, img2);
				//	tmp++;
				//	tmp_name += tmp;
			}

			//cv::imshow("Test", src);

			if (src.cols > PlateViewResultBox->Width && src.rows > PlateViewResultBox->Height)
			{
				Mat pic_src_tmp = src;
				resize(pic_src_tmp, src, size);
			}
			System::IntPtr main_frame(src.ptr());
			SrcViewPanel->ResetImeMode();
			SrcViewPanel->Image = gcnew System::Drawing::Bitmap(src.cols, src.rows, src.step, System::Drawing::Imaging::PixelFormat::Format24bppRgb, main_frame);
			SrcViewPanel->Refresh();

			if (img2.cols > PlateViewResultBox->Width && img2.rows > PlateViewResultBox->Height)
			{
				Mat src_tmp = img2;
				resize(src_tmp, img2, size);
			}
			System::IntPtr plate_frame(img2.ptr());
			PlateViewResultBox->ResetImeMode();
			//PlateViewResultBox->Image = gcnew System::Drawing::Bitmap(img2.cols, img2.rows, img2.step, System::Drawing::Imaging::PixelFormat::Format24bppRgb, plate_frame);
			//PlateViewResultBox->Refresh();
			imshow("Plate", img2);


			Mat img_to_tess;

			//cvtColor(img2, gray, cv::COLOR_BGR2GRAY); // zmiana na czarno bia³y obraz
			//equalizeHist(gray, img_to_tess);
			cv::Mat SubFrame = img2;

			char* Text_ret = NULL;
			int i = 0;

			while (!Text_ret || i == 5) {
				TesseractAPI.SetImage(SubFrame.data, SubFrame.cols, SubFrame.rows, 3, SubFrame.step);
				Text_ret = _strdup(TesseractAPI.GetUTF8Text());
				i++;
			}

			System::String^ result = msclr::interop::marshal_as<System::String^>(Text_ret);
			CharResultLabel->Text = result;

		}

		if (VideoRadioButton->Checked == true)
		{
			OpenFileDialog^ Open = gcnew OpenFileDialog();
			Open->ShowHelp = true;
			Open->RestoreDirectory = true;
			Open->Filter = "Video (*.avi;*.mp4;*.wmv;*.mpg)|*.avi;*.mp4;*.wmv;*.mpg|All files (*.*)|*.*||";

			if (Open->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				string file_path = msclr::interop::marshal_as<std::string>(Open->FileName);

				if (CAP) { delete CAP; CAP = NULL; }
				CAP = new VideoCapture(file_path);
				StatusMainLabel->Text = "The source has been successfully loaded";
			}
			else
			{
				StatusMainLabel->Text = "The source has not been successfully loaded";
				return;
			}

			if (Classifier.load("D:/Studia/IV_rok/Praca_inz/Projekt/RoLP/x64/Debug/eu.xml"))
				StatusMainLabel->Text = "Classifier has been successfully loaded";
			else
			{
				StatusMainLabel->Text = "Classifier has not been successfully loaded";
				return;
			}


			if (TesseractAPI.Init(NULL, "eng", tesseract::OEM_DEFAULT) >= 0)
				StatusMainLabel->Text = "Tesseract has been successfully loaded";
			else {
				StatusMainLabel->Text = "Tesseract has been successfully loaded";
				return;
			}
			TesseractAPI.SetPageSegMode(tesseract::PSM_AUTO_OSD);
			TesseractAPI.SetOutputName("out");

		}

		if (CameraRadioButton->Checked == true) {
			if (CAP) { delete CAP; CAP = NULL; }
			CAP = new VideoCapture(0);
			if (CAP) StatusMainLabel->Text = "The source has been successfully loaded";
			else
			{
				StatusMainLabel->Text = "The source has not been successfully loaded";
				return;
			}

			if (Classifier.load("D:/Studia/IV_rok/Praca_inz/Projekt/RoLP/x64/Debug/eu.xml"))
				StatusMainLabel->Text = "Classifier has been successfully loaded";
			else
			{
				StatusMainLabel->Text = "Classifier has not been successfully loaded";
				return;
			}


			if (TesseractAPI.Init(NULL, "eng", tesseract::OEM_DEFAULT) >= 0)
				StatusMainLabel->Text = "Tesseract has been successfully loaded";
			else {
				StatusMainLabel->Text = "Tesseract has been successfully loaded";
				return;
			}
			TesseractAPI.SetPageSegMode(tesseract::PSM_AUTO_OSD);
			TesseractAPI.SetOutputName("out");
		}
	}


#pragma endregion buttonsOptions
	private: System::Void AppForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {

		if (MetroFramework::MetroMessageBox::Show(this, "Do you really want to exit?", "RoLP",
			MessageBoxButtons::YesNo,
			MessageBoxIcon::Stop) == System::Windows::Forms::DialogResult::Yes) {
			exitValue = true;
			timer1->Enabled = false;
			delete CAP;
			CAP = NULL;
			cv::destroyWindow("Video stream");
			exit(0);
		}
		else {
			e->Cancel = true;
		}
	}
	private: System::Void ProcessingButton_Click(System::Object^  sender, System::EventArgs^  e) {
		timer1->Enabled = !timer1->Enabled;
	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		Mat Frame;
		// Capture frame-by-frame
		*CAP >> Frame;

		// If the frame is empty, break immediately
		if (Frame.empty()) { return; }

		//cv::imshow("Frame", Frame);
		if (Frame.cols <= SrcViewPanel->Width && Frame.rows <= SrcViewPanel->Height) {
			System::IntPtr camera_vid(Frame.ptr());
			SrcViewPanel->ResetImeMode();
			SrcViewPanel->Image = gcnew System::Drawing::Bitmap(Frame.cols, Frame.rows, Frame.step, System::Drawing::Imaging::PixelFormat::Format24bppRgb, camera_vid);
			SrcViewPanel->Refresh();
		}
		else
		{
			Mat src = Frame;
			resize(src, Frame, size);
			System::IntPtr camera_vid(Frame.ptr());
			SrcViewPanel->ResetImeMode();
			SrcViewPanel->Image = gcnew System::Drawing::Bitmap(Frame.cols, Frame.rows, Frame.step, System::Drawing::Imaging::PixelFormat::Format24bppRgb, camera_vid);
			SrcViewPanel->Refresh();
			//		imshow("Video stream", Frame);
		}

		std::vector<cv::Rect> Regions;

		//cvtColor(Frame, gray, cv::COLOR_BGR2GRAY);
		//CannyThreshold(0, gray);
		//equalizeHist(gray, img_to_det);

		//Frame = img_to_det;
		Classifier.detectMultiScale(Frame, Regions, 1.1, 2, 0);

		for (int i = 0; i < Regions.size(); ++i) {
			cv::Mat SubFrame = Frame(Regions[i]);
			//cv::Mat img_to_tess;
			//cv::imshow("SubFrame", SubFrame);
			TesseractAPI.SetImage(SubFrame.data, SubFrame.cols, SubFrame.rows, 3, SubFrame.step);
			if (!TesseractAPI.Recognize(0)) {
				const char* Text_result = _strdup(TesseractAPI.GetUTF8Text());
				//cv::imshow(Text_result, SubFrame);
				if (SubFrame.cols > PlateViewResultBox->Width && SubFrame.rows > PlateViewResultBox->Height)
				{
					Mat src_tmp = SubFrame;
					resize(src_tmp, SubFrame, size);
				}
				System::IntPtr plate_frame(SubFrame.ptr());
				PlateViewResultBox->ResetImeMode();
				PlateViewResultBox->BackgroundImage = gcnew System::Drawing::Bitmap
				(SubFrame.cols, SubFrame.rows, SubFrame.step, System::Drawing::Imaging::PixelFormat::Format24bppRgb, plate_frame);
				PlateViewResultBox->Refresh();

				System::String^ result = msclr::interop::marshal_as<System::String^>(Text_result);
				CharResultLabel->Text = result;

			}

		}
	}
	private: System::Void StopProcessingButton_Click(System::Object^  sender, System::EventArgs^  e) {
		timer1->Enabled = false;
		delete CAP;
		CAP = NULL;
		StatusMainLabel->Text = " ";
		return;
	}
	private: System::Void About_Button_Click(System::Object^  sender, System::EventArgs^  e) {
		timer1->Enabled = false;
		delete CAP;
		CAP = NULL;
		Recognition_Panel->Hide();
		Contact_Panel->Hide();
		About_Panel->Show();
	}
	private: System::Void Contact_Button_Click(System::Object^  sender, System::EventArgs^  e) {
		timer1->Enabled = false;
		delete CAP;
		CAP = NULL;
		Recognition_Panel->Hide();
		About_Panel->Hide();
		Contact_Panel->Show();
	}
	private: System::Void Recognition_Button_Click(System::Object^  sender, System::EventArgs^  e) {
		timer1->Enabled = false;
		delete CAP;
		CAP = NULL;
		Contact_Panel->Hide();
		About_Panel->Hide();
		Recognition_Panel->Show();
	}
	};
}