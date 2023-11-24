#pragma once

#include <vector>
#include <string>
#include <random>
#include <ctime>
#include <format>
#include <cmath>

#include "MyQueue.h"
#include "ServiceTypes.h"
#include <set>

namespace CppWinForm1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	private: const size_t TABLE_COLUMS = 5;
	public:
		MyForm(void)
		{
			InitializeComponent();
			
			this->statistic = new Statistic();
			this->processors = new std::vector<Processor>;
			this->taskQueue = new TQueue<Task>(queueSize);
			
			this->colors = gcnew array<Color>(10) { Color::LightPink, Color::LightBlue, Color::LightGreen, Color::LightCoral, 
				Color::LightCyan, Color::LightGoldenrodYellow, Color::LightSalmon, Color::LightSeaGreen, Color::LightSkyBlue, Color::LightYellow };
			
			srand(time(0));
			
			updateStatistic();
		}

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

#pragma region Program Variable
	private: std::vector<Processor>* processors;
	private: TQueue<Task>* taskQueue;
	private: array<Color>^ colors;

	private: size_t processorCount;
	private: size_t tactTime;
	private: double taskProbability;
	private: size_t minRequiredProcessor;
	private: size_t maxRequiredProcessor;
	private: size_t minRequiredTact;
	private: size_t maxRequiredTact;
	private: size_t queueSize = 1;

	private: Statistic* statistic;
#pragma endregion

#pragma region WinForm components
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::GroupBox^ groupBox4;
	private: System::Windows::Forms::GroupBox^ groupBox5;

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;

	private: System::Windows::Forms::Timer^ timer1;

	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::TextBox^ textBox7;
	private: System::Windows::Forms::TextBox^ textBox8;

	private: System::Windows::Forms::ListBox^ listBox1;
	private: System::Windows::Forms::ListBox^ listBox2;
	private: System::Windows::Forms::ListBox^ listBox3;

	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;

	private: System::ComponentModel::IContainer^ components;

#pragma endregion

#pragma region Windows Form Designer generated code
	private:
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->listBox3 = (gcnew System::Windows::Forms::ListBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->listBox2 = (gcnew System::Windows::Forms::ListBox());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->groupBox5->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->textBox8);
			this->groupBox1->Controls->Add(this->label9);
			this->groupBox1->Controls->Add(this->textBox7);
			this->groupBox1->Controls->Add(this->textBox6);
			this->groupBox1->Controls->Add(this->textBox5);
			this->groupBox1->Controls->Add(this->textBox4);
			this->groupBox1->Controls->Add(this->textBox3);
			this->groupBox1->Controls->Add(this->textBox2);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(1162, 80);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(404, 376);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Настройки";
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(318, 197);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(68, 26);
			this->textBox7->TabIndex = 11;
			this->textBox7->Text = L"20";
			this->textBox7->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(235, 196);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(68, 26);
			this->textBox6->TabIndex = 10;
			this->textBox6->Text = L"5";
			this->textBox6->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(235, 164);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(68, 26);
			this->textBox5->TabIndex = 9;
			this->textBox5->Text = L"1";
			this->textBox5->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(318, 164);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(71, 26);
			this->textBox4->TabIndex = 8;
			this->textBox4->Text = L"20";
			this->textBox4->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(293, 100);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(96, 26);
			this->textBox3->TabIndex = 7;
			this->textBox3->Text = L"0.5";
			this->textBox3->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(294, 65);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(96, 26);
			this->textBox2->TabIndex = 6;
			this->textBox2->Text = L"1000";
			this->textBox2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(294, 33);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(96, 26);
			this->textBox1->TabIndex = 5;
			this->textBox1->Text = L"20";
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(18, 197);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(142, 20);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Требуемые такты";
			this->label5->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(18, 164);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(186, 20);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Требуемые процессоры";
			this->label4->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(18, 100);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(244, 20);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Вероятность создания задачи";
			this->label3->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(18, 68);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(203, 20);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Время выполнения такта";
			this->label2->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(18, 33);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(201, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Количество процессоров";
			this->label1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->label6);
			this->groupBox2->Location = System::Drawing::Point(1162, 462);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(404, 472);
			this->groupBox2->TabIndex = 1;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Статистика";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(22, 40);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(0, 20);
			this->label6->TabIndex = 0;
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->listBox1);
			this->groupBox3->Location = System::Drawing::Point(227, 770);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(929, 164);
			this->groupBox3->TabIndex = 2;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Лог";
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 20;
			this->listBox1->Location = System::Drawing::Point(6, 22);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(917, 124);
			this->listBox1->TabIndex = 0;
			// 
			// groupBox4
			// 
			this->groupBox4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->groupBox4->Controls->Add(this->label8);
			this->groupBox4->Controls->Add(this->listBox3);
			this->groupBox4->Controls->Add(this->label7);
			this->groupBox4->Controls->Add(this->listBox2);
			this->groupBox4->Location = System::Drawing::Point(2, 12);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(219, 1225);
			this->groupBox4->TabIndex = 3;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Задачи";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(120, 21);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(84, 20);
			this->label8->TabIndex = 3;
			this->label8->Text = L"Процессы";
			// 
			// listBox3
			// 
			this->listBox3->FormattingEnabled = true;
			this->listBox3->ItemHeight = 20;
			this->listBox3->Location = System::Drawing::Point(119, 45);
			this->listBox3->Name = L"listBox3";
			this->listBox3->Size = System::Drawing::Size(90, 864);
			this->listBox3->TabIndex = 2;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(15, 22);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(77, 20);
			this->label7->TabIndex = 1;
			this->label7->Text = L"Очередь";
			// 
			// listBox2
			// 
			this->listBox2->FormattingEnabled = true;
			this->listBox2->ItemHeight = 20;
			this->listBox2->Location = System::Drawing::Point(10, 45);
			this->listBox2->Name = L"listBox2";
			this->listBox2->Size = System::Drawing::Size(89, 864);
			this->listBox2->TabIndex = 0;
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->tableLayoutPanel1);
			this->groupBox5->Location = System::Drawing::Point(227, 12);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(929, 752);
			this->groupBox5->TabIndex = 4;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"Процессоры";
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->AutoScroll = true;
			this->tableLayoutPanel1->ColumnCount = 5;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				20)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				20)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				20)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				20)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				20)));
			this->tableLayoutPanel1->Location = System::Drawing::Point(6, 21);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->Size = System::Drawing::Size(917, 721);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(1162, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(131, 62);
			this->button1->TabIndex = 5;
			this->button1->Text = L"Старт";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(1299, 12);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(126, 62);
			this->button2->TabIndex = 6;
			this->button2->Text = L"Стоп";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::SystemColors::Control;
			this->button4->Location = System::Drawing::Point(1431, 12);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(112, 62);
			this->button4->TabIndex = 7;
			this->button4->Text = L"Очистить";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(18, 132);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(134, 20);
			this->label9->TabIndex = 12;
			this->label9->Text = L"Размер очереди";
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(294, 132);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(96, 26);
			this->textBox8->TabIndex = 13;
			this->textBox8->Text = L"100";
			this->textBox8->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1578, 946);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox5);
			this->Controls->Add(this->groupBox4);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"MyForm";
			this->Text = L"Эмулятор работы многопроцессорной системы";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			this->groupBox5->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion

#pragma region Service Functions
	private: void CenterGroupBoxTitle(GroupBox^ groupbox)
	{
		Label^ label = gcnew Label();
		label->Text = groupbox->Text;
		groupbox->Text = "";
		label->Left = groupbox->Left + (groupbox->Width - label->Width) / 2;
		label->Top = groupbox->Top;
		label->Parent = groupbox->Parent;
		label->BringToFront();
		this->Controls->Add(label);
	}

	private: Task popQueue() {
		Task tmp = this->taskQueue->Get();
		this->listBox2->Items->Remove(gcnew String(std::format("{}:{},{}", tmp.id, tmp.procCount, tmp.tactCount).c_str()));
		return tmp;
	}

	private: void PushQueue(const Task& task) {
		this->taskQueue->Push(task);
		this->listBox2->Items->Add(gcnew String(std::format("{}:{},{}", task.id, task.procCount, task.tactCount).c_str()));
	}

	private: void tryCreateNewTask() {
		// Создание задачи (по вероятности) id:кол-во процессоров, кол-во тактов
		if ((double)rand() / (RAND_MAX) <= this->taskProbability) {
			Task task;

			task.id = ++this->statistic->taskCount;
			task.procCount = minRequiredProcessor + rand() % (maxRequiredProcessor - minRequiredProcessor + 1);
			task.tactCount = minRequiredTact + rand() % (maxRequiredTact - minRequiredTact + 1);
			task.color = task.id % this->colors->GetLength(0);
			PushQueue(task);

			this->listBox1->Items->Add(gcnew String(
				std::format("Задача {}, состоящая из {} тактов, требующая {} процессоров, постуает в очередь", task.id, task.tactCount, task.procCount).c_str())
			);
			this->listBox1->TopIndex = this->listBox1->Items->Count - 1;
		}
	}

	private: void updateStatistic()
	{
		std::string formated =
			std::format("Выполнено тактов: {}\n", this->statistic->tactCount) +
			std::format("Среденее кол-во занятых процессоров: {:.2f}\n", this->statistic->middleBusyProcessor) +
			std::format("Общее кол-во тактов бездействия: {}\n", this->statistic->tactInactionCount) +
			std::format("Кол-во выполняемых задач: {}\n", this->statistic->taskInWorkCount) +
			std::format("Кол-во задач в очереди: {}\n", this->taskQueue->GetCount()) +
			std::format("Выполнено задач: {}\n", this->statistic->taskComplitedCount) +
			std::format("Всего задач поступило: {}", this->statistic->taskCount);

		label6->Text = gcnew String(formated.c_str());
	}

	private: void updateProcessorGraphics() {
		for (size_t i = 0; i < std::ceil(this->processorCount / (double)TABLE_COLUMS); i++) {
			for (size_t j = 0; j < TABLE_COLUMS; j++) {
				if (i * TABLE_COLUMS + j >= processorCount)
					break;
				Processor proc = this->processors->at(i * TABLE_COLUMS + j);
				auto element = this->tableLayoutPanel1->GetControlFromPosition(j, i);
				if (proc.isEmpty) {
					element->Text = "";
					element->BackColor = Color::LightGray;
				}
				else {
					element->Text = gcnew String(std::format("{}:{}", proc.task.id, proc.taskTactCount).c_str());
					element->BackColor = this->colors[proc.task.color];
				}
			}
		}
	}

	private: void updateDiagram() {
		Graphics^ gr = this->groupBox2->CreateGraphics();

		gr->Clear(SystemColors::Control);

		if (!this->taskQueue->IsEmpty()) {
			Pen^ bp = gcnew Pen(Color::Black);
			bp->Width = 10.0f;

			auto startAngle = this->taskQueue->GetInd() * 360.0 / this->taskQueue->GetSize();
			auto endAngle = (this->taskQueue->GetInd() + this->taskQueue->GetCount()) * 360.0 / this->taskQueue->GetSize();
		
			gr->DrawArc(bp, 60, 135, 150, 150, startAngle, endAngle - startAngle);
		}
	}
#pragma endregion

#pragma region Event Hendlers
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		size_t freeProcessors = 0;
		std::set<int> complited;
		for (auto proc = this->processors->begin(); proc < this->processors->end(); proc++) {
			proc->stepCount++;
			if (proc->isEmpty) {
				proc->emptyTactCount++;
				this->statistic->tactInactionCount++;
			}
			else {
				proc->taskTactCount--;
				if (proc->taskTactCount == 0) {
					complited.insert(proc->task.id);
					proc->isEmpty = true;
					listBox3->Items->Remove(gcnew String(
						std::format("{}:{},{}", proc->task.id, proc->task.procCount, proc->task.tactCount).c_str()
					));
				}
			}
			if (proc->isEmpty)
				freeProcessors++;
		}

		this->statistic->middleBusyProcessor = (this->statistic->middleBusyProcessor * this->statistic->tactCount + 
			(this->processorCount - freeProcessors)) / (this->statistic->tactCount + 1);
		this->statistic->taskComplitedCount += complited.size();
		this->statistic->taskInWorkCount -= complited.size();
		if (!this->taskQueue->IsFull())
			tryCreateNewTask();

		if (!this->taskQueue->IsEmpty()) {
			Task task = popQueue();
			
			std::string status;

			if (task.procCount <= freeProcessors) {
				status = std::format("Задача {}, требующая {} процессоров, поступает на процессоры",
					task.id, task.procCount);
				auto listBoxItem = gcnew String(
					std::format("{}:{},{}", task.id, task.procCount, task.tactCount).c_str()
				);
				this->listBox3->Items->Add(listBoxItem);
				this->statistic->taskInWorkCount++;
				for (auto proc = this->processors->begin(); proc < this->processors->end(); proc++) {
					if (task.procCount == 0) 
						break;
					if (proc->isEmpty) {
						proc->task = task;
						proc->taskTactCount = task.tactCount;
						proc->isEmpty = false;
						task.procCount--;
					}
				}
			}
			else {
				PushQueue(task);
				status = std::format("Задачу {}, требующую {} процессоров, невозможно выполнить, в данный момент свободных процессоров {}",
					task.id, task.procCount, freeProcessors);
			}
			this->listBox1->Items->Add(gcnew String(status.c_str()));
			this->listBox1->TopIndex = this->listBox1->Items->Count - 1;

			
		}

		this->statistic->tactCount++;
		updateProcessorGraphics();
		updateDiagram();
		updateStatistic();

	}

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		this->timer1->Enabled = false;
	}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->textBox1->ReadOnly == true) {
			this->timer1->Enabled = true;
			return;
		}

		try {
			this->processorCount = Int32::Parse(textBox1->Text);
			this->tactTime = Int32::Parse(textBox2->Text);
			this->taskProbability = Double::Parse(textBox3->Text);
			this->minRequiredProcessor = Int32::Parse(textBox5->Text);
			this->maxRequiredProcessor = Int32::Parse(textBox4->Text);
			this->minRequiredTact = Int32::Parse(textBox6->Text);
			this->maxRequiredTact = Int32::Parse(textBox7->Text);
			this->queueSize = Int32::Parse(textBox8->Text);

			this->taskQueue = new TQueue<Task>(queueSize);

			if (this->minRequiredProcessor > this->maxRequiredProcessor ||
				this->minRequiredTact > this->maxRequiredTact)
			{
				throw gcnew FormatException;
			}

			{
				this->textBox1->ReadOnly = true;
				this->textBox2->ReadOnly = true;
				this->textBox3->ReadOnly = true;
				this->textBox4->ReadOnly = true;
				this->textBox5->ReadOnly = true;
				this->textBox6->ReadOnly = true;
				this->textBox7->ReadOnly = true;
				this->textBox8->ReadOnly = true;
			}

			for (size_t i = 0; i < std::ceil(this->processorCount / (double)TABLE_COLUMS); i++) {
				for (size_t j = 0; j < TABLE_COLUMS; j++) {
					if (i * TABLE_COLUMS + j >= processorCount)
						break;
					processors->push_back(Processor());
					Button^ procButton = gcnew Button();
					procButton->BackColor = Color::LightGray;
					procButton->Size = System::Drawing::Size(100, 100);
					procButton->ForeColor = Color::Black;
					procButton->Font = gcnew System::Drawing::Font("Microsoft Sans Serif", 10);
					procButton->Text = "";
					this->tableLayoutPanel1->Controls->Add(procButton, j, i);
				}
			}

			this->timer1->Interval = this->tactTime;
			this->timer1->Enabled = true;
		}
		catch (FormatException^ e) {
			MessageBox::Show("Ошибка ввода");
		}
	}

	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		this->timer1->Enabled = false;

		{
			this->textBox1->ReadOnly = false;
			this->textBox2->ReadOnly = false;
			this->textBox3->ReadOnly = false;
			this->textBox4->ReadOnly = false;
			this->textBox5->ReadOnly = false;
			this->textBox6->ReadOnly = false;
			this->textBox7->ReadOnly = false;
			this->textBox8->ReadOnly = false;
		}

		this->listBox1->Items->Clear();
		this->listBox2->Items->Clear();
		this->listBox3->Items->Clear();
		
		this->tableLayoutPanel1->Controls->Clear();

		this->groupBox2->CreateGraphics()->Clear(SystemColors::Control);


		this->statistic = new Statistic();
		this->processors = new std::vector<Processor>;
		this->taskQueue = new TQueue<Task>(queueSize);
		updateStatistic();
	}
#pragma endregion
	};
}
