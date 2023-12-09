#pragma once
#include <msclr\marshal_cppstd.h>
#include <regex>
#include <map>
#include <set>
#include "Polinom.h"

namespace CppWinForm1 {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			
		}
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::GroupBox^ groupBox4;
	private: System::Windows::Forms::RichTextBox^ richTextBox1;


	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
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
            this->textBox1 = (gcnew System::Windows::Forms::TextBox());
            this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
            this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
            this->textBox2 = (gcnew System::Windows::Forms::TextBox());
            this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
            this->button3 = (gcnew System::Windows::Forms::Button());
            this->button2 = (gcnew System::Windows::Forms::Button());
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
            this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
            this->groupBox1->SuspendLayout();
            this->groupBox2->SuspendLayout();
            this->groupBox3->SuspendLayout();
            this->groupBox4->SuspendLayout();
            this->SuspendLayout();
            // 
            // textBox1
            // 
            this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->textBox1->Location = System::Drawing::Point(11, 29);
            this->textBox1->Name = L"textBox1";
            this->textBox1->Size = System::Drawing::Size(466, 30);
            this->textBox1->TabIndex = 1;
            this->textBox1->Text = L"5*x0^7*x1^3*x2^4 + 3*x0^5*x1*x2 + 1*x0*x1";
            // 
            // groupBox1
            // 
            this->groupBox1->Controls->Add(this->textBox1);
            this->groupBox1->Location = System::Drawing::Point(20, 17);
            this->groupBox1->Name = L"groupBox1";
            this->groupBox1->Size = System::Drawing::Size(483, 81);
            this->groupBox1->TabIndex = 4;
            this->groupBox1->TabStop = false;
            this->groupBox1->Text = L"1";
            // 
            // groupBox2
            // 
            this->groupBox2->Controls->Add(this->textBox2);
            this->groupBox2->Location = System::Drawing::Point(20, 109);
            this->groupBox2->Name = L"groupBox2";
            this->groupBox2->Size = System::Drawing::Size(483, 80);
            this->groupBox2->TabIndex = 5;
            this->groupBox2->TabStop = false;
            this->groupBox2->Text = L"2";
            // 
            // textBox2
            // 
            this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->textBox2->Location = System::Drawing::Point(11, 31);
            this->textBox2->Name = L"textBox2";
            this->textBox2->Size = System::Drawing::Size(466, 30);
            this->textBox2->TabIndex = 1;
            this->textBox2->Text = L"9*x0^7*x1^3*x2^4 + 3*x0^3*x1^5";
            // 
            // groupBox3
            // 
            this->groupBox3->Controls->Add(this->button3);
            this->groupBox3->Controls->Add(this->button2);
            this->groupBox3->Controls->Add(this->button1);
            this->groupBox3->Location = System::Drawing::Point(509, 17);
            this->groupBox3->Name = L"groupBox3";
            this->groupBox3->Size = System::Drawing::Size(147, 172);
            this->groupBox3->TabIndex = 6;
            this->groupBox3->TabStop = false;
            this->groupBox3->Text = L"3";
            // 
            // button3
            // 
            this->button3->Location = System::Drawing::Point(6, 119);
            this->button3->Name = L"button3";
            this->button3->Size = System::Drawing::Size(135, 34);
            this->button3->TabIndex = 2;
            this->button3->Text = L"Mult";
            this->button3->UseVisualStyleBackColor = true;
            this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
            // 
            // button2
            // 
            this->button2->Location = System::Drawing::Point(6, 73);
            this->button2->Name = L"button2";
            this->button2->Size = System::Drawing::Size(135, 34);
            this->button2->TabIndex = 1;
            this->button2->Text = L"Minus";
            this->button2->UseVisualStyleBackColor = true;
            this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
            // 
            // button1
            // 
            this->button1->Location = System::Drawing::Point(6, 25);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(135, 34);
            this->button1->TabIndex = 0;
            this->button1->Text = L"Plus";
            this->button1->UseVisualStyleBackColor = true;
            this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
            // 
            // groupBox4
            // 
            this->groupBox4->Controls->Add(this->richTextBox1);
            this->groupBox4->Location = System::Drawing::Point(20, 195);
            this->groupBox4->Name = L"groupBox4";
            this->groupBox4->Size = System::Drawing::Size(636, 156);
            this->groupBox4->TabIndex = 7;
            this->groupBox4->TabStop = false;
            this->groupBox4->Text = L"4";
            // 
            // richTextBox1
            // 
            this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->richTextBox1->Location = System::Drawing::Point(11, 25);
            this->richTextBox1->Name = L"richTextBox1";
            this->richTextBox1->ReadOnly = true;
            this->richTextBox1->Size = System::Drawing::Size(619, 125);
            this->richTextBox1->TabIndex = 0;
            this->richTextBox1->Text = L"";
            // 
            // MyForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(672, 363);
            this->Controls->Add(this->groupBox4);
            this->Controls->Add(this->groupBox3);
            this->Controls->Add(this->groupBox2);
            this->Controls->Add(this->groupBox1);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
            this->Name = L"MyForm";
            this->Text = L"Polinom";
            this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
            this->groupBox1->ResumeLayout(false);
            this->groupBox1->PerformLayout();
            this->groupBox2->ResumeLayout(false);
            this->groupBox2->PerformLayout();
            this->groupBox3->ResumeLayout(false);
            this->groupBox4->ResumeLayout(false);
            this->ResumeLayout(false);

        }
#pragma endregion


	private: std::vector<std::string> find_str(std::string s, std::string del) {
		std::vector<std::string> res;
		int end = s.find(del);
		while (end != -1) {
			res.push_back(s.substr(0, end));
			s.erase(s.begin(), s.begin() + end + del.size());
			end = s.find(del);
		}
		res.push_back(s.substr(0, end));

		return res; 
	}

	private: void parsePol(TPolinom& pol1, TPolinom& pol2) {
		   msclr::interop::marshal_context context;

		   std::vector<std::string> s_inp;

		   s_inp.push_back(context.marshal_as<std::string>(textBox1->Text));
		   s_inp.push_back(context.marshal_as<std::string>(textBox2->Text));

		   for (auto it = s_inp.begin(); it < s_inp.end(); it++) {
			   std::set<std::string> params;
			   std::vector<std::pair<double, std::map<std::string, int>>> monoms;
			   std::string str = std::regex_replace(*it, std::regex("\\ *"), "");
			   str = std::regex_replace(str, std::regex("\\-"), "+-");
			   auto v_monoms = find_str(str, "+");


               for (auto monom : v_monoms) {
                   if (monom != "") {
                       auto comp = find_str(monom, "*");
                       std::pair<double, std::map<std::string, int>> p_monom;

                       p_monom.first = std::stod(comp.at(0));
                       for (auto it = ++comp.begin(); it < comp.end(); it++) {
                           std::string str = *it;
                           int deg;
                           auto tmp = find_str(str, "^");
                           if (tmp.size() == 1)
                               deg = 1;
                           else
                               deg = std::stoi(tmp.at(1));
                           params.insert(tmp.at(0));
                           p_monom.second[tmp.at(0)] = deg;
                       }

                       monoms.push_back(p_monom);
                   }
               }

			   TPolinom tmp(params.size());
			   for (auto pr : monoms) {
				   for (auto param : params) {
					   if (pr.second.find(param) == pr.second.end()) {
						   pr.second[param] = 0;
					   }
				   }
				   std::vector<int> deg;
				   for (auto it = pr.second.begin(); it != pr.second.end(); ++it) {
					   deg.push_back(it->second);
				   }
				   tmp.AddMonom(TMonom(pr.first, params.size(), &deg[0]));
			   }

			   if (it == s_inp.begin())
				   pol1 = tmp;
			   else
				   pol2 = tmp;
		   }
	}

private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		TPolinom pol1, pol2, res;
		parsePol(pol1, pol2);
		res = pol1 + pol2;
		richTextBox1->Text = gcnew String(res.ToString().c_str());
	}
	catch (std::exception e) {
		MessageBox::Show(gcnew String(e.what()));
	}
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		TPolinom pol1, pol2, res;
		parsePol(pol1, pol2);
		res = pol1 - pol2;		
		richTextBox1->Text = gcnew String(res.ToString().c_str());

	}
	catch (std::exception e) {
		MessageBox::Show(gcnew String(e.what()));
	}
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		TPolinom pol1, pol2, res;
		parsePol(pol1, pol2);
		res = pol1 * pol2;
		richTextBox1->Text = gcnew String(res.ToString().c_str());

	}
	catch (std::exception e) {
		MessageBox::Show(gcnew String(e.what()));
	}
}
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
};
}
