#include "NeuralNetwork.h"
#pragma once
//#include <stdio.h>
//#using <system.drawing.dll>
//#include <iostream>
#include <fstream>
#include <vector>


struct DigitPicture
{
	float thePicture[784];
	int theLabel;
};

namespace DigitRecognition {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for DigitRecognition
	/// </summary>
	public ref class DigitRecognition : public System::Windows::Forms::Form
	{
	public:
		DigitRecognition(void)
		{
			InitializeComponent();
			InitializeUserData();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~DigitRecognition()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::PictureBox^ DrawingBoard;
	private: System::Windows::Forms::Label^ DrawingBoardLabel;
	private: System::Windows::Forms::Label^ DrawingBoardDetails;

	//   User Data Members
	// ---------------------
	private:
		int m_result;
		DigitPicture* m_digitPicture = new DigitPicture;
		//DigitPicture* m_picture = new DigitPicture[100];
		int m_pictureIndex = 0;
		bool m_mouseButtonPressed = false;
		int m_mousex;
		int m_mouseY;



	private: System::Windows::Forms::Button^ ReadButton;
	private: System::Windows::Forms::Button^ NextButton;
	private: System::Windows::Forms::Label^ DisplayResultLabel;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ LogoLabel;
	private: System::Windows::Forms::PictureBox^ pictureBox2;



	protected:


	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(DigitRecognition::typeid));
			this->DrawingBoard = (gcnew System::Windows::Forms::PictureBox());
			this->DrawingBoardLabel = (gcnew System::Windows::Forms::Label());
			this->DrawingBoardDetails = (gcnew System::Windows::Forms::Label());
			this->ReadButton = (gcnew System::Windows::Forms::Button());
			this->NextButton = (gcnew System::Windows::Forms::Button());
			this->DisplayResultLabel = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->LogoLabel = (gcnew System::Windows::Forms::Label());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DrawingBoard))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// DrawingBoard
			// 
			this->DrawingBoard->BackColor = System::Drawing::Color::Transparent;
			this->DrawingBoard->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->DrawingBoard->Cursor = System::Windows::Forms::Cursors::Cross;
			this->DrawingBoard->Location = System::Drawing::Point(82, 101);
			this->DrawingBoard->Margin = System::Windows::Forms::Padding(0);
			this->DrawingBoard->Name = L"DrawingBoard";
			this->DrawingBoard->Size = System::Drawing::Size(285, 285);
			this->DrawingBoard->TabIndex = 1;
			this->DrawingBoard->TabStop = false;
			this->DrawingBoard->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &DigitRecognition::DrawingBoard_Paint);
			this->DrawingBoard->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &DigitRecognition::DrawingBoard_MouseDown);
			this->DrawingBoard->MouseLeave += gcnew System::EventHandler(this, &DigitRecognition::DrawingBoard_MouseLeave);
			this->DrawingBoard->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &DigitRecognition::DrawingBoard_MouseMove);
			this->DrawingBoard->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &DigitRecognition::DrawingBoard_MouseUp);
			// 
			// DrawingBoardLabel
			// 
			this->DrawingBoardLabel->AutoSize = true;
			this->DrawingBoardLabel->Font = (gcnew System::Drawing::Font(L"Kristen ITC", 18, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->DrawingBoardLabel->ForeColor = System::Drawing::Color::SaddleBrown;
			this->DrawingBoardLabel->Location = System::Drawing::Point(114, 58);
			this->DrawingBoardLabel->Name = L"DrawingBoardLabel";
			this->DrawingBoardLabel->Size = System::Drawing::Size(221, 33);
			this->DrawingBoardLabel->TabIndex = 2;
			this->DrawingBoardLabel->Text = L"Drawing   Board";
			this->DrawingBoardLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// DrawingBoardDetails
			// 
			this->DrawingBoardDetails->AutoSize = true;
			this->DrawingBoardDetails->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Italic,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->DrawingBoardDetails->ForeColor = System::Drawing::Color::SaddleBrown;
			this->DrawingBoardDetails->Location = System::Drawing::Point(159, 397);
			this->DrawingBoardDetails->Name = L"DrawingBoardDetails";
			this->DrawingBoardDetails->Size = System::Drawing::Size(108, 16);
			this->DrawingBoardDetails->TabIndex = 3;
			this->DrawingBoardDetails->Text = L"Draw a digit here";
			// 
			// ReadButton
			// 
			this->ReadButton->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->ReadButton->FlatAppearance->BorderSize = 0;
			this->ReadButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->ReadButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ReadButton->ForeColor = System::Drawing::Color::SaddleBrown;
			this->ReadButton->Location = System::Drawing::Point(384, 167);
			this->ReadButton->Margin = System::Windows::Forms::Padding(0);
			this->ReadButton->Name = L"ReadButton";
			this->ReadButton->Size = System::Drawing::Size(89, 34);
			this->ReadButton->TabIndex = 4;
			this->ReadButton->Text = L"Read";
			this->ReadButton->UseVisualStyleBackColor = true;
			this->ReadButton->Click += gcnew System::EventHandler(this, &DigitRecognition::ReadButton_Click);
			// 
			// NextButton
			// 
			this->NextButton->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->NextButton->FlatAppearance->BorderSize = 0;
			this->NextButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->NextButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->NextButton->ForeColor = System::Drawing::Color::SaddleBrown;
			this->NextButton->Location = System::Drawing::Point(384, 234);
			this->NextButton->Margin = System::Windows::Forms::Padding(0);
			this->NextButton->Name = L"NextButton";
			this->NextButton->Size = System::Drawing::Size(89, 34);
			this->NextButton->TabIndex = 5;
			this->NextButton->Text = L"Next";
			this->NextButton->UseVisualStyleBackColor = true;
			this->NextButton->Click += gcnew System::EventHandler(this, &DigitRecognition::NextButton_Click);
			// 
			// DisplayResultLabel
			// 
			this->DisplayResultLabel->AutoSize = true;
			this->DisplayResultLabel->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->DisplayResultLabel->Font = (gcnew System::Drawing::Font(L"Adobe Fan Heiti Std B", 48, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->DisplayResultLabel->Location = System::Drawing::Point(621, 192);
			this->DisplayResultLabel->Margin = System::Windows::Forms::Padding(0);
			this->DisplayResultLabel->Name = L"DisplayResultLabel";
			this->DisplayResultLabel->Size = System::Drawing::Size(82, 80);
			this->DisplayResultLabel->TabIndex = 6;
			this->DisplayResultLabel->Text = L"...";
			// 
			// pictureBox1
			// 
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox1->Location = System::Drawing::Point(611, 178);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(100, 100);
			this->pictureBox1->TabIndex = 7;
			this->pictureBox1->TabStop = false;
			// 
			// LogoLabel
			// 
			this->LogoLabel->AutoSize = true;
			this->LogoLabel->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LogoLabel->ForeColor = System::Drawing::Color::SaddleBrown;
			this->LogoLabel->Location = System::Drawing::Point(678, 475);
			this->LogoLabel->Name = L"LogoLabel";
			this->LogoLabel->Size = System::Drawing::Size(151, 14);
			this->LogoLabel->TabIndex = 8;
			this->LogoLabel->Text = L"Created by Catalin ANDREI";
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(657, 475);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(15, 21);
			this->pictureBox2->TabIndex = 9;
			this->pictureBox2->TabStop = false;
			// 
			// DigitRecognition
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(862, 515);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->LogoLabel);
			this->Controls->Add(this->DisplayResultLabel);
			this->Controls->Add(this->NextButton);
			this->Controls->Add(this->ReadButton);
			this->Controls->Add(this->DrawingBoardDetails);
			this->Controls->Add(this->DrawingBoardLabel);
			this->Controls->Add(this->DrawingBoard);
			this->Controls->Add(this->pictureBox1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->Name = L"DigitRecognition";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Digit Recognition";
			this->Load += gcnew System::EventHandler(this, &DigitRecognition::DigitRecognition_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DrawingBoard))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void DigitRecognition_Load(System::Object^ sender, System::EventArgs^ e) 
	{

	}
	private: System::Void DrawingBoard_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e)
	{
		SolidBrush^ brush = gcnew SolidBrush(Color::Black);
		bool firstAcces = true;
		for (int i = 1; i < 28; i++)
		{
			e->Graphics->DrawLine(Pens::LightGray, i * 10, 0, i * 10, 280);
			e->Graphics->DrawLine(Pens::LightGray, 0, i * 10, 280, i * 10);
		}
		if (m_mousex != 0 && m_mouseY != 0)
		{
			/*
			m_digitPicture->thePicture[(int)(m_mouseY + 20) / 10 * 28 + (int)(m_mousex + 20) / 10] = 1.0;
			if ((int)m_mouseY > 10) m_digitPicture->thePicture[(int)((m_mouseY + 20) / 10 - 1) * 28 + (int)(m_mousex + 20) / 10] = 1.0;
			if ((int)m_mouseY < 270) m_digitPicture->thePicture[(int)((m_mouseY + 20) / 10 + 1) * 28 + (int)(m_mousex + 20) / 10] = 1.0;
			if ((int)m_mousex > 10) m_digitPicture->thePicture[(int)(m_mouseY + 20) / 10 * 28 + (int)(m_mousex + 20) / 10 - 1] = 1.0;
			if ((int)m_mousex < 270) m_digitPicture->thePicture[(int)(m_mouseY + 20) / 10 * 28 + (int)(m_mousex + 20) / 10 + 1] = 1.0;
			if ((int)m_mouseY < 270 && (int)m_mousex < 270) m_digitPicture->thePicture[(int)((m_mouseY + 20) / 10 + 1) * 28 + (int)(m_mousex + 20) / 10 + 1] = 1.0;
			if ((int)m_mouseY > 10 && (int)m_mousex > 10) m_digitPicture->thePicture[(int)((m_mouseY + 20) / 10 - 1) * 28 + (int)(m_mousex + 20) / 10 - 1] = 1.0;
			if ((int)m_mouseY > 10 && (int)m_mousex < 270) m_digitPicture->thePicture[(int)((m_mouseY + 20) / 10 - 1) * 28 + (int)(m_mousex + 20) / 10 + 1] = 1.0;
			if ((int)m_mouseY < 270 && (int)m_mousex > 10) m_digitPicture->thePicture[(int)((m_mouseY + 20) / 10 + 1) * 28 + (int)(m_mousex + 20) / 10 - 1] = 1.0;
			*/

			m_digitPicture->thePicture[(int)m_mouseY / 10 * 28 + (int)m_mousex / 10] = 1.0;
			if ((int)m_mouseY > 10) m_digitPicture->thePicture[(int)(m_mouseY / 10 - 1) * 28 + (int)m_mousex / 10] = 1.0;
			if ((int)m_mouseY < 270) m_digitPicture->thePicture[(int)(m_mouseY / 10 + 1) * 28 + (int)m_mousex / 10] = 1.0;
			if ((int)m_mousex > 10) m_digitPicture->thePicture[(int)m_mouseY / 10 * 28 + (int)m_mousex / 10 - 1] = 1.0;
			if ((int)m_mousex < 270) m_digitPicture->thePicture[(int)m_mouseY / 10 * 28 + (int)m_mousex / 10 + 1] = 1.0;
			if ((int)m_mouseY < 270 && (int)m_mousex < 270) m_digitPicture->thePicture[(int)(m_mouseY / 10 + 1) * 28 + (int)m_mousex / 10 + 1] = 1.0;
			if ((int)m_mouseY > 10 && (int)m_mousex > 10) m_digitPicture->thePicture[(int)(m_mouseY / 10 - 1) * 28 + (int)m_mousex / 10 - 1] = 1.0;
			if ((int)m_mouseY > 10 && (int)m_mousex < 270) m_digitPicture->thePicture[(int)(m_mouseY / 10 - 1) * 28 + (int)m_mousex / 10 + 1] = 1.0;
			if ((int)m_mouseY < 270 && (int)m_mousex > 10) m_digitPicture->thePicture[(int)(m_mouseY / 10 + 1) * 28 + (int)m_mousex / 10 - 1] = 1.0;
		}
		for (int i = 0; i < 784; i++)
		{
			if (m_digitPicture->thePicture[i]) // != 0 && (i % 28) < 2 && (int)(i / 28) < 2)
			{
				Rectangle rect = Rectangle(((int)i % 28) * 10, ((int)i / 28) * 10, 10, 10);
				e->Graphics->FillRectangle(brush, rect);
			}
		}
	}

	private: void InitializeUserData()
	{
		for (int i = 0; i < 784;i++)
		{
			m_digitPicture->thePicture[i] = 0;
		}
		m_digitPicture->theLabel = 0;
	}
	private: System::Void DrawingBoard_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) 
	{
		m_mousex = e->X;
		m_mouseY = e->Y;
		DrawingBoard->Refresh();
		m_mouseButtonPressed = true;
	}
	private: System::Void DrawingBoard_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) 
	{
		if (m_mouseButtonPressed)
		{
			m_mousex = e->X;
			m_mouseY = e->Y;
			DrawingBoard->Refresh();
		}
	}
	private: System::Void DrawingBoard_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) 
	{
		m_mouseButtonPressed = false;
	}
	private: System::Void DrawingBoard_MouseLeave(System::Object^ sender, System::EventArgs^ e)
	{
		m_mousex = 0;
		m_mouseY = 0;
	}
	private: System::Void ReadButton_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		float learningIndex = 2;
		int minibatchLength = 10;
		float outputVector[10];
		std::vector<int> neuralNerworkStructure = { 784, 500, 10 };
		neural_network::NeuralNetwork network(neuralNerworkStructure, learningIndex, minibatchLength);
		network.LoadTheNetworkFromFile();
		m_result = network.getTestResult(m_digitPicture->thePicture, outputVector);
		float total = 0;
		//int value;
		//for (int i = 0;i < 10;i++)
		//{
		//	total += outputVector[i];
		//}
		//for (int i = 0;i < 10;i++)
		//{
		//	this->ProbabilityChart->Series["Digit"]->Points->AddXY(i, (int)100 * (float)outputVector[i] / total);
		//}
		this->DisplayResultLabel->Text = " " + m_result.ToString();
	}
	private: System::Void NextButton_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		for (int i = 0;i < 784;i++)
		{
			m_digitPicture->thePicture[i] = 0;
		}
		this->DisplayResultLabel->Text = "...";
		DrawingBoard->Refresh();
	}
};
}
