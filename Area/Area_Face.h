#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Area.h"
#pragma once

extern double Time;
extern AOR recovery;
bool enterKey = true;
bool gen = false;



namespace Area {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ Area_Face
	/// </summary>
	public ref class Area_Face : public System::Windows::Forms::Form
	{
	public:
		Area_Face(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}
	private: System::Windows::Forms::TrackBar^  Key_Bar;
	private: System::Windows::Forms::Label^  Gen_lenght_label;

	private: System::Windows::Forms::Label^  Key_lenght;
	private: System::Windows::Forms::TrackBar^  Area_track;
	private: System::Windows::Forms::TrackBar^  Level_track;
	private: System::Windows::Forms::Label^  Area_label;
	private: System::Windows::Forms::Label^  Level_label;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;

	public:

	public:
		System::Resources::ResourceManager^ resourceManager = gcnew System::Resources::ResourceManager(
			"Area.Res", System::Reflection::Assembly::GetExecutingAssembly());
	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~Area_Face()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  open_button;
	private: System::Windows::Forms::Button^  close_button;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::TextBox^  File_patch_box;
	private: System::Windows::Forms::ProgressBar^  progressBar1;
	private: System::Windows::Forms::Button^  Play_button;
	private: System::Windows::Forms::Button^  Pause_button;
	private: System::Windows::Forms::Button^  Stop_button;
	private: System::Windows::Forms::Label^  Time_label;
	private: System::Windows::Forms::TextBox^  Key_box;
	private: System::Windows::Forms::Button^  Generate_button;
	private: System::Windows::Forms::RadioButton^  EnButton;
	private: System::Windows::Forms::RadioButton^  DeButton;
	private: System::ComponentModel::IContainer^  components;
	protected:
	protected:
	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Area_Face::typeid));
			this->open_button = (gcnew System::Windows::Forms::Button());
			this->close_button = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->File_patch_box = (gcnew System::Windows::Forms::TextBox());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->Play_button = (gcnew System::Windows::Forms::Button());
			this->Pause_button = (gcnew System::Windows::Forms::Button());
			this->Stop_button = (gcnew System::Windows::Forms::Button());
			this->Time_label = (gcnew System::Windows::Forms::Label());
			this->Key_box = (gcnew System::Windows::Forms::TextBox());
			this->Generate_button = (gcnew System::Windows::Forms::Button());
			this->EnButton = (gcnew System::Windows::Forms::RadioButton());
			this->DeButton = (gcnew System::Windows::Forms::RadioButton());
			this->Key_Bar = (gcnew System::Windows::Forms::TrackBar());
			this->Gen_lenght_label = (gcnew System::Windows::Forms::Label());
			this->Key_lenght = (gcnew System::Windows::Forms::Label());
			this->Area_track = (gcnew System::Windows::Forms::TrackBar());
			this->Level_track = (gcnew System::Windows::Forms::TrackBar());
			this->Area_label = (gcnew System::Windows::Forms::Label());
			this->Level_label = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Key_Bar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Area_track))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Level_track))->BeginInit();
			this->SuspendLayout();
			// 
			// open_button
			// 
			this->open_button->BackColor = System::Drawing::Color::Black;
			this->open_button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"open_button.BackgroundImage")));
			this->open_button->Cursor = System::Windows::Forms::Cursors::Hand;
			this->open_button->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->open_button->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->open_button->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Black;
			this->open_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->open_button->Location = System::Drawing::Point(12, 12);
			this->open_button->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->open_button->Name = L"open_button";
			this->open_button->Size = System::Drawing::Size(47, 43);
			this->open_button->TabIndex = 0;
			this->open_button->UseVisualStyleBackColor = false;
			this->open_button->Click += gcnew System::EventHandler(this, &Area_Face::open_button_Click);
			this->open_button->MouseLeave += gcnew System::EventHandler(this, &Area_Face::open_button_MouseLeave);
			this->open_button->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Area_Face::open_button_MouseMove);
			// 
			// close_button
			// 
			this->close_button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"close_button.BackgroundImage")));
			this->close_button->Cursor = System::Windows::Forms::Cursors::Hand;
			this->close_button->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->close_button->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->close_button->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Black;
			this->close_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->close_button->Location = System::Drawing::Point(185, 262);
			this->close_button->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->close_button->Name = L"close_button";
			this->close_button->Size = System::Drawing::Size(47, 43);
			this->close_button->TabIndex = 1;
			this->close_button->UseVisualStyleBackColor = true;
			this->close_button->Click += gcnew System::EventHandler(this, &Area_Face::close_button_Click);
			this->close_button->MouseLeave += gcnew System::EventHandler(this, &Area_Face::close_button_MouseLeave);
			this->close_button->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Area_Face::close_button_MouseMove);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"C:\\Windows\\explorer.exe";
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &Area_Face::timer1_Tick);
			// 
			// File_patch_box
			// 
			this->File_patch_box->BackColor = System::Drawing::Color::Black;
			this->File_patch_box->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->File_patch_box->Font = (gcnew System::Drawing::Font(L"Buxton Sketch", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->File_patch_box->ForeColor = System::Drawing::Color::White;
			this->File_patch_box->Location = System::Drawing::Point(66, 12);
			this->File_patch_box->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->File_patch_box->Multiline = true;
			this->File_patch_box->Name = L"File_patch_box";
			this->File_patch_box->ReadOnly = true;
			this->File_patch_box->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->File_patch_box->Size = System::Drawing::Size(166, 43);
			this->File_patch_box->TabIndex = 2;
			// 
			// progressBar1
			// 
			this->progressBar1->BackColor = System::Drawing::Color::Black;
			this->progressBar1->Location = System::Drawing::Point(20, 249);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(146, 10);
			this->progressBar1->TabIndex = 19;
			// 
			// Play_button
			// 
			this->Play_button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Play_button.BackgroundImage")));
			this->Play_button->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Play_button->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->Play_button->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->Play_button->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Black;
			this->Play_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Play_button->ForeColor = System::Drawing::Color::Black;
			this->Play_button->Location = System::Drawing::Point(12, 262);
			this->Play_button->Name = L"Play_button";
			this->Play_button->Size = System::Drawing::Size(46, 43);
			this->Play_button->TabIndex = 10;
			this->Play_button->UseVisualStyleBackColor = true;
			this->Play_button->Click += gcnew System::EventHandler(this, &Area_Face::Play_button_Click);
			// 
			// Pause_button
			// 
			this->Pause_button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Pause_button.BackgroundImage")));
			this->Pause_button->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Pause_button->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->Pause_button->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->Pause_button->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Black;
			this->Pause_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Pause_button->Location = System::Drawing::Point(66, 262);
			this->Pause_button->Name = L"Pause_button";
			this->Pause_button->Size = System::Drawing::Size(47, 43);
			this->Pause_button->TabIndex = 11;
			this->Pause_button->UseVisualStyleBackColor = true;
			this->Pause_button->Click += gcnew System::EventHandler(this, &Area_Face::Pause_button_Click);
			// 
			// Stop_button
			// 
			this->Stop_button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Stop_button.BackgroundImage")));
			this->Stop_button->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Stop_button->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->Stop_button->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->Stop_button->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Black;
			this->Stop_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Stop_button->Location = System::Drawing::Point(119, 262);
			this->Stop_button->Name = L"Stop_button";
			this->Stop_button->Size = System::Drawing::Size(47, 43);
			this->Stop_button->TabIndex = 12;
			this->Stop_button->UseVisualStyleBackColor = true;
			this->Stop_button->Click += gcnew System::EventHandler(this, &Area_Face::Stop_button_Click);
			// 
			// Time_label
			// 
			this->Time_label->AutoSize = true;
			this->Time_label->Font = (gcnew System::Drawing::Font(L"Buxton Sketch", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Time_label->ForeColor = System::Drawing::Color::White;
			this->Time_label->Location = System::Drawing::Point(189, 243);
			this->Time_label->Name = L"Time_label";
			this->Time_label->Size = System::Drawing::Size(31, 16);
			this->Time_label->TabIndex = 20;
			this->Time_label->Text = L"Time";
			// 
			// Key_box
			// 
			this->Key_box->BackColor = System::Drawing::Color::Black;
			this->Key_box->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->Key_box->Font = (gcnew System::Drawing::Font(L"Buxton Sketch", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Key_box->ForeColor = System::Drawing::Color::White;
			this->Key_box->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->Key_box->Location = System::Drawing::Point(72, 86);
			this->Key_box->Multiline = true;
			this->Key_box->Name = L"Key_box";
			this->Key_box->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->Key_box->Size = System::Drawing::Size(160, 128);
			this->Key_box->TabIndex = 5;
			this->Key_box->Text = L"Enter Key!";
			this->Key_box->Click += gcnew System::EventHandler(this, &Area_Face::Key_box_Click);
			this->Key_box->TextChanged += gcnew System::EventHandler(this, &Area_Face::Key_box_TextChanged);
			// 
			// Generate_button
			// 
			this->Generate_button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Generate_button.BackgroundImage")));
			this->Generate_button->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Generate_button->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->Generate_button->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->Generate_button->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Black;
			this->Generate_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Generate_button->Location = System::Drawing::Point(12, 86);
			this->Generate_button->Name = L"Generate_button";
			this->Generate_button->Size = System::Drawing::Size(47, 43);
			this->Generate_button->TabIndex = 4;
			this->Generate_button->UseVisualStyleBackColor = true;
			this->Generate_button->Click += gcnew System::EventHandler(this, &Area_Face::Generate_button_Click);
			this->Generate_button->MouseLeave += gcnew System::EventHandler(this, &Area_Face::Generate_button_MouseLeave);
			this->Generate_button->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Area_Face::Generate_button_MouseMove);
			// 
			// EnButton
			// 
			this->EnButton->AutoSize = true;
			this->EnButton->Checked = true;
			this->EnButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->EnButton->Font = (gcnew System::Drawing::Font(L"Buxton Sketch", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->EnButton->ForeColor = System::Drawing::Color::White;
			this->EnButton->Location = System::Drawing::Point(72, 220);
			this->EnButton->Name = L"EnButton";
			this->EnButton->Size = System::Drawing::Size(61, 20);
			this->EnButton->TabIndex = 8;
			this->EnButton->TabStop = true;
			this->EnButton->Text = L"Encrypt";
			this->EnButton->UseVisualStyleBackColor = true;
			// 
			// DeButton
			// 
			this->DeButton->AutoSize = true;
			this->DeButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->DeButton->Font = (gcnew System::Drawing::Font(L"Buxton Sketch", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->DeButton->ForeColor = System::Drawing::Color::White;
			this->DeButton->Location = System::Drawing::Point(168, 220);
			this->DeButton->Name = L"DeButton";
			this->DeButton->Size = System::Drawing::Size(64, 20);
			this->DeButton->TabIndex = 9;
			this->DeButton->Text = L"Decrypt";
			this->DeButton->UseVisualStyleBackColor = true;
			// 
			// Key_Bar
			// 
			this->Key_Bar->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Key_Bar->Location = System::Drawing::Point(12, 61);
			this->Key_Bar->Maximum = 32767;
			this->Key_Bar->Minimum = 3;
			this->Key_Bar->Name = L"Key_Bar";
			this->Key_Bar->Size = System::Drawing::Size(154, 45);
			this->Key_Bar->SmallChange = 10;
			this->Key_Bar->TabIndex = 3;
			this->Key_Bar->TickStyle = System::Windows::Forms::TickStyle::None;
			this->Key_Bar->Value = 3;
			this->Key_Bar->Scroll += gcnew System::EventHandler(this, &Area_Face::Key_Bar_Scroll);
			// 
			// Gen_lenght_label
			// 
			this->Gen_lenght_label->AutoSize = true;
			this->Gen_lenght_label->Font = (gcnew System::Drawing::Font(L"Buxton Sketch", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Gen_lenght_label->ForeColor = System::Drawing::Color::White;
			this->Gen_lenght_label->Location = System::Drawing::Point(182, 61);
			this->Gen_lenght_label->Name = L"Gen_lenght_label";
			this->Gen_lenght_label->Size = System::Drawing::Size(26, 16);
			this->Gen_lenght_label->TabIndex = 13;
			this->Gen_lenght_label->Text = L"3 c.";
			// 
			// Key_lenght
			// 
			this->Key_lenght->AutoSize = true;
			this->Key_lenght->Font = (gcnew System::Drawing::Font(L"Buxton Sketch", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Key_lenght->ForeColor = System::Drawing::Color::White;
			this->Key_lenght->Location = System::Drawing::Point(8, 132);
			this->Key_lenght->Name = L"Key_lenght";
			this->Key_lenght->Size = System::Drawing::Size(39, 16);
			this->Key_lenght->TabIndex = 14;
			this->Key_lenght->Text = L"Lenght";
			// 
			// Area_track
			// 
			this->Area_track->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Area_track->Location = System::Drawing::Point(12, 165);
			this->Area_track->Maximum = 999;
			this->Area_track->Minimum = 3;
			this->Area_track->Name = L"Area_track";
			this->Area_track->Orientation = System::Windows::Forms::Orientation::Vertical;
			this->Area_track->Size = System::Drawing::Size(45, 59);
			this->Area_track->TabIndex = 6;
			this->Area_track->TickStyle = System::Windows::Forms::TickStyle::None;
			this->Area_track->Value = 3;
			this->Area_track->Scroll += gcnew System::EventHandler(this, &Area_Face::Area_track_Scroll);
			// 
			// Level_track
			// 
			this->Level_track->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Level_track->Location = System::Drawing::Point(41, 165);
			this->Level_track->Maximum = 999;
			this->Level_track->Minimum = 3;
			this->Level_track->Name = L"Level_track";
			this->Level_track->Orientation = System::Windows::Forms::Orientation::Vertical;
			this->Level_track->Size = System::Drawing::Size(45, 59);
			this->Level_track->TabIndex = 7;
			this->Level_track->TickStyle = System::Windows::Forms::TickStyle::None;
			this->Level_track->Value = 3;
			this->Level_track->Scroll += gcnew System::EventHandler(this, &Area_Face::Level_track_Scroll);
			// 
			// Area_label
			// 
			this->Area_label->AutoSize = true;
			this->Area_label->Font = (gcnew System::Drawing::Font(L"Buxton Sketch", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Area_label->ForeColor = System::Drawing::Color::White;
			this->Area_label->Location = System::Drawing::Point(12, 222);
			this->Area_label->Name = L"Area_label";
			this->Area_label->Size = System::Drawing::Size(15, 16);
			this->Area_label->TabIndex = 17;
			this->Area_label->Text = L"3";
			// 
			// Level_label
			// 
			this->Level_label->AutoSize = true;
			this->Level_label->Font = (gcnew System::Drawing::Font(L"Buxton Sketch", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Level_label->ForeColor = System::Drawing::Color::White;
			this->Level_label->Location = System::Drawing::Point(38, 222);
			this->Level_label->Name = L"Level_label";
			this->Level_label->Size = System::Drawing::Size(15, 16);
			this->Level_label->TabIndex = 18;
			this->Level_label->Text = L"3";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Buxton Sketch", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(12, 148);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(13, 16);
			this->label1->TabIndex = 15;
			this->label1->Text = L"A";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Buxton Sketch", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(38, 148);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(13, 16);
			this->label2->TabIndex = 16;
			this->label2->Text = L"L";
			// 
			// Area_Face
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->ClientSize = System::Drawing::Size(244, 317);
			this->ControlBox = false;
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->Level_label);
			this->Controls->Add(this->Area_label);
			this->Controls->Add(this->Key_box);
			this->Controls->Add(this->Level_track);
			this->Controls->Add(this->Area_track);
			this->Controls->Add(this->Key_lenght);
			this->Controls->Add(this->Generate_button);
			this->Controls->Add(this->Gen_lenght_label);
			this->Controls->Add(this->Key_Bar);
			this->Controls->Add(this->DeButton);
			this->Controls->Add(this->EnButton);
			this->Controls->Add(this->Time_label);
			this->Controls->Add(this->Stop_button);
			this->Controls->Add(this->Pause_button);
			this->Controls->Add(this->Play_button);
			this->Controls->Add(this->progressBar1);
			this->Controls->Add(this->File_patch_box);
			this->Controls->Add(this->close_button);
			this->Controls->Add(this->open_button);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ForeColor = System::Drawing::Color::Black;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->Name = L"Area_Face";
			this->Text = L"Area";
			this->Load += gcnew System::EventHandler(this, &Area_Face::Area_Face_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Key_Bar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Area_track))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Level_track))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
public:void Play_button_off()
		{
			Play_button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>((Bitmap^)resourceManager->GetObject(L"4")));
			Play_button->FlatAppearance->MouseDownBackColor = System::Drawing::Color::White;
			Play_button->FlatAppearance->MouseOverBackColor = System::Drawing::Color::White;
		}
public:void Play_button_on()
	    {
	    	Play_button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>((Bitmap^)resourceManager->GetObject(L"40")));
		    Play_button->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
		    Play_button->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Black;
	    }
public:void Pause_button_off()
	    {
			Pause_button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>((Bitmap^)resourceManager->GetObject(L"5")));
			Pause_button->FlatAppearance->MouseDownBackColor = System::Drawing::Color::White;
			Pause_button->FlatAppearance->MouseOverBackColor = System::Drawing::Color::White;
	    }
public:void Pause_button_on()
	   {
		   Pause_button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>((Bitmap^)resourceManager->GetObject(L"50")));
		   Pause_button->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
		   Pause_button->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Black;
	   }
public:void Stop_button_off()
	   {
		   Stop_button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>((Bitmap^)resourceManager->GetObject(L"6")));
		   Stop_button->FlatAppearance->MouseDownBackColor = System::Drawing::Color::White;
		   Stop_button->FlatAppearance->MouseOverBackColor = System::Drawing::Color::White;
	   }
public:void Stop_button_on()
	   {
		   Stop_button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>((Bitmap^)resourceManager->GetObject(L"60")));
		   Stop_button->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
		   Stop_button->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Black;
	   }
public:void Disable()
		{
			this->ClientSize = System::Drawing::Size(121, 70);
			this->close_button->Location = System::Drawing::Point(65, 12);
			File_patch_box->Visible = false;
			Key_box->Visible = false;
			Play_button->Visible = false;
			Pause_button->Visible = false;
			Stop_button->Visible = false;
			Generate_button->Visible = false;
			progressBar1->Visible = false;
			Time_label->Visible = false;
			Time_label->Text = "Time";
			EnButton->Visible = false;
			DeButton->Visible = false;
			Key_Bar->Visible = false;
			Gen_lenght_label->Visible = false;
			Key_lenght->Visible = false;
			Area_track->Visible = false;
			Area_label->Visible = false;
			Level_track->Visible = false;
			Level_label->Visible = false;
			label1->Visible = false;
			label2->Visible = false;
		}
public:void Enable()
		{
			this->ClientSize = System::Drawing::Size(247, 318);
			this->close_button->Location = System::Drawing::Point(185, 262);
			File_patch_box->Visible = true;
			Key_box->Visible = true;
			Play_button->Visible = true;
			Pause_button->Visible = true;
			Stop_button->Visible = true;
			Generate_button->Visible = true;
			progressBar1->Visible = true;
			Time_label->Visible = true;
			EnButton->Visible = true;
			DeButton->Visible = true;
			Key_Bar->Visible = true;
			Gen_lenght_label->Visible = true;
			Key_lenght->Visible = true;
			Area_track->Visible = true;
			Area_label->Visible = true;
			Level_track->Visible = true;
			Level_label->Visible = true;
			label1->Visible = true;
			label2->Visible = true;
		}
public:void Position_Basic()
		{
			Play_button_on();
			Play_button->Enabled = true;
			Pause_button->Enabled = false;
			Pause_button_off();
			Stop_button->Enabled = false;
			Stop_button_off();
			Generate_button->Enabled = true;
			Generate_button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>((Bitmap^)resourceManager->GetObject(L"30")));
			open_button->Enabled = true;
			open_button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>((Bitmap^)resourceManager->GetObject(L"10")));
			close_button->Enabled = true;
			close_button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>((Bitmap^)resourceManager->GetObject(L"20")));
			Key_box->ReadOnly = false;
			EnButton->Enabled = true;
			DeButton->Enabled = true;
			Key_Bar->Enabled = true;
			Area_track->Enabled = true;
			Level_track->Enabled = true;
		}
public:void Position_Pause()
		{
			Play_button_on();
			Play_button->Enabled = true;
			Pause_button->Enabled = false;
			Pause_button_off();
			Stop_button_on();
			Stop_button->Enabled = true;
			Generate_button->Enabled = false;
			Generate_button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>((Bitmap^)resourceManager->GetObject(L"3")));
			open_button->Enabled = false;
			open_button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>((Bitmap^)resourceManager->GetObject(L"1")));
			close_button->Enabled = false;
			close_button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>((Bitmap^)resourceManager->GetObject(L"2")));
			Key_box->ReadOnly = true;
			EnButton->Enabled = false;
			DeButton->Enabled = false;
			Key_Bar->Enabled = false;
			Area_track->Enabled = false;
			Level_track->Enabled = false;
		}
public:void Position_Progress()
		{
			Play_button->Enabled = false;
			Play_button_off();
			Pause_button_on();
			Pause_button->Enabled = true;
			Stop_button_on();
			Stop_button->Enabled = true;
			Generate_button->Enabled = false;
			Generate_button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>((Bitmap^)resourceManager->GetObject(L"3")));
			open_button->Enabled = false;
			open_button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>((Bitmap^)resourceManager->GetObject(L"1")));
			close_button->Enabled = false;
			close_button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>((Bitmap^)resourceManager->GetObject(L"2")));
			Key_box->ReadOnly = true;
			EnButton->Enabled = false;
			DeButton->Enabled = false;
			Key_Bar->Enabled = false;
			Area_track->Enabled = false;
			Level_track->Enabled = false;
		}
public:void OverflowSizeModeOn()
		{
			progressBar1->Enabled = false;
		}
public:void OverflowSizeModeOff()
		{
			progressBar1->Enabled = true;
		}
public:System::String^ short_double(System::String^ number)
		{
			System::String^ short_number = "";
			for (int i = 0; i < number->Length; i++)
			{
				short_number += number[i];
				if ((number[i] == ',') && (i + 3 < number->Length))
				{
					short_number += number[i + 1];
					break;
				}
			}
			return short_number;
		}
#pragma endregion
private: System::Void Area_Face_Load(System::Object^  sender, System::EventArgs^  e) {
		Position_Basic();
		Disable();
	}
private: System::Void close_button_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Close();
	}
private: System::Void open_button_Click(System::Object^  sender, System::EventArgs^  e) {
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			Enable();
			Position_Basic();
			File_patch_box->Text = openFileDialog1->FileName;
			recovery.OpenFile(openFileDialog1->FileName);
		}
	}
private: System::Void Generate_button_Click(System::Object^  sender, System::EventArgs^  e) {
	srand((unsigned int)time(NULL));
	gen = true;
	Key_box->Text = "";
	enterKey = false;
	System::String^ tmp = "";
	for (int i = 0; i < Key_Bar->Value; i++)
	  tmp+=(wchar_t)(rand()+1);
	Key_box->AppendText(tmp);
	Key_lenght->Text = System::Convert::ToString(tmp->Length) + " c.";
	gen = false;
}
private: System::Void Play_button_Click(System::Object^  sender, System::EventArgs^  e) {
	if (!enterKey)
	{
		if (recovery.GetThreadStatus())
		{
			recovery.SetPauseOff();
			Position_Progress();
		}
		else
		{
			if (recovery.SetKey(Key_box->Text))
			{
				if (recovery.CheckFile())
				{
					if (recovery.OverflowSize())
						OverflowSizeModeOn();
					else
						OverflowSizeModeOff();
					Time = 0;
					Time_label->Text = System::Convert::ToString(Time) + " s.";
					progressBar1->Value = 0;
					recovery.SetArea(Area_track->Value);
					recovery.SetLevel(Level_track->Value);
					timer1->Start();
					Position_Progress();
					EnButton->Checked ? recovery.Action(0) : recovery.Action(1);
				}
				else
				{
					MessageBox::Show("FilePath crash!");
					Position_Basic();
					Disable();
				}
			}
			else
				MessageBox::Show("Key size exists in [3;32767]!");
		}
	}
	else
		MessageBox::Show("Enter Key!");
}
private: System::Void Pause_button_Click(System::Object^  sender, System::EventArgs^  e) {
	if (recovery.GetThreadStatus())
	{
		recovery.SetPauseOn();
		Position_Pause();
	}
}
private: System::Void Stop_button_Click(System::Object^  sender, System::EventArgs^  e) {
	if (recovery.GetThreadStatus())
	{
		recovery.SetStop();
		Time_label->Text = "Time";
		progressBar1->Value = 100;
		Position_Basic();
	}
}
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	if (recovery.GetThreadStatus() && !recovery.GetPauseStatus())
	{
		Time += 0.100;
		Time_label->Text = short_double(System::Convert::ToString(Time))+" s.";
		if (!recovery.OverflowSize())
			progressBar1->Value = recovery.GetProgress();
	}
	else
	{
		if (!recovery.GetThreadStatus() && !recovery.GetPauseStatus())
		{
			progressBar1->Value = 100;
			timer1->Stop();
			Position_Basic();
		}
	}

}
private: System::Void open_button_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	if (open_button->Enabled == true)
		open_button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>((Bitmap^)resourceManager->GetObject(L"1")));

}
private: System::Void open_button_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	if (open_button->Enabled == true)
		open_button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>((Bitmap^)resourceManager->GetObject(L"10")));
}
private: System::Void Generate_button_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	if (Generate_button->Enabled == true)
		Generate_button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>((Bitmap^)resourceManager->GetObject(L"30")));
}
private: System::Void Generate_button_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	if (Generate_button->Enabled == true)
		Generate_button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>((Bitmap^)resourceManager->GetObject(L"3")));
}
private: System::Void close_button_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	if (close_button->Enabled == true)
		close_button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>((Bitmap^)resourceManager->GetObject(L"20")));
}
private: System::Void close_button_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	if (close_button->Enabled == true)
		close_button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>((Bitmap^)resourceManager->GetObject(L"2")));
}
private: System::Void Key_Bar_Scroll(System::Object^  sender, System::EventArgs^  e) {
	Gen_lenght_label->Text = System::Convert::ToString(Key_Bar->Value)+ " c.";
}
private: System::Void Key_box_Click(System::Object^  sender, System::EventArgs^  e) {
	if (enterKey)
	{
		Key_box->Text = "";
		enterKey = false;
	}
}
private: System::Void Key_box_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	if(!gen)
	Key_lenght->Text = System::Convert::ToString(Key_box->Text->Length) + " c.";
}
private: System::Void Area_track_Scroll(System::Object^  sender, System::EventArgs^  e) {
	Area_label->Text = System::Convert::ToString(Area_track->Value);
}
private: System::Void Level_track_Scroll(System::Object^  sender, System::EventArgs^  e) {
	Level_label->Text = System::Convert::ToString(Level_track->Value);
}
};
}
