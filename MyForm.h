#pragma once

#include <vector>
#include <string>
#include <queue>

namespace IZgraf {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace System::Collections::Generic;
    using namespace std;

    public ref class MyForm : public System::Windows::Forms::Form
    {
    public:
        MyForm(void)
        {
            InitializeComponent();
            adjacencyTextBoxes = gcnew List<List<TextBox^>^>();
        }

    protected:
        ~MyForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        List<List<TextBox^>^>^ adjacencyTextBoxes;
        System::Windows::Forms::Label^ label1;

        System::Windows::Forms::TextBox^ textBoxU1;

        System::Windows::Forms::Button^ buttonCreateGraph;
        System::Windows::Forms::Button^ buttonCalculate;
        System::Windows::Forms::Panel^ adjacencyMatrixPanel;


    private:
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->textBoxU1 = (gcnew System::Windows::Forms::TextBox());
            this->buttonCreateGraph = (gcnew System::Windows::Forms::Button());
            this->buttonCalculate = (gcnew System::Windows::Forms::Button());
            this->adjacencyMatrixPanel = (gcnew System::Windows::Forms::Panel());
            this->SuspendLayout();
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->BackColor = System::Drawing::SystemColors::ButtonFace;
            this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label1->Location = System::Drawing::Point(30, 9);
            this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(290, 29);
            this->label1->TabIndex = 0;
            this->label1->Text = L"Введите кол-во вершин";
            // 
            // textBoxU1
            // 
            this->textBoxU1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->textBoxU1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->textBoxU1->Location = System::Drawing::Point(364, 10);
            this->textBoxU1->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
            this->textBoxU1->Name = L"textBoxU1";
            this->textBoxU1->Size = System::Drawing::Size(116, 34);
            this->textBoxU1->TabIndex = 2;
            this->textBoxU1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBoxU1_TextChanged);
            // 
            // buttonCreateGraph
            // 
            this->buttonCreateGraph->BackColor = System::Drawing::SystemColors::MenuText;
            this->buttonCreateGraph->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->buttonCreateGraph->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->buttonCreateGraph->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->buttonCreateGraph->Location = System::Drawing::Point(2, 72);
            this->buttonCreateGraph->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
            this->buttonCreateGraph->Name = L"buttonCreateGraph";
            this->buttonCreateGraph->Size = System::Drawing::Size(202, 52);
            this->buttonCreateGraph->TabIndex = 4;
            this->buttonCreateGraph->Text = L"Ввод инф";
            this->buttonCreateGraph->UseVisualStyleBackColor = false;
            this->buttonCreateGraph->Click += gcnew System::EventHandler(this, &MyForm::buttonCreateGraph_Click);
            // 
            // buttonCalculate
            // 
            this->buttonCalculate->BackColor = System::Drawing::SystemColors::InfoText;
            this->buttonCalculate->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->buttonCalculate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->buttonCalculate->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->buttonCalculate->Location = System::Drawing::Point(310, 72);
            this->buttonCalculate->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
            this->buttonCalculate->Name = L"buttonCalculate";
            this->buttonCalculate->Size = System::Drawing::Size(204, 52);
            this->buttonCalculate->TabIndex = 5;
            this->buttonCalculate->Text = L"Результат";
            this->buttonCalculate->UseVisualStyleBackColor = false;
            this->buttonCalculate->Click += gcnew System::EventHandler(this, &MyForm::buttonCalculate_Click);
            // 
            // adjacencyMatrixPanel
            // 
            this->adjacencyMatrixPanel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->adjacencyMatrixPanel->AutoScroll = true;
            this->adjacencyMatrixPanel->AutoSize = true;
            this->adjacencyMatrixPanel->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
            this->adjacencyMatrixPanel->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
            this->adjacencyMatrixPanel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
            this->adjacencyMatrixPanel->Location = System::Drawing::Point(35, 156);
            this->adjacencyMatrixPanel->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
            this->adjacencyMatrixPanel->Name = L"adjacencyMatrixPanel";
            this->adjacencyMatrixPanel->Size = System::Drawing::Size(4, 4);
            this->adjacencyMatrixPanel->TabIndex = 6;
            // 
            // MyForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::SystemColors::Control;
            this->ClientSize = System::Drawing::Size(512, 477);
            this->Controls->Add(this->adjacencyMatrixPanel);
            this->Controls->Add(this->buttonCalculate);
            this->Controls->Add(this->buttonCreateGraph);
            this->Controls->Add(this->textBoxU1);
            this->Controls->Add(this->label1);
            this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
            this->Name = L"MyForm";
            this->Text = L"Граф";
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion

    private:
        System::Void buttonCreateGraph_Click(System::Object^ sender, System::EventArgs^ e) {
            int V = Int32::Parse(textBoxU1->Text); // V - количество вершин в графе

            // Очищаем предыдущие текстовые поля (если они уже были созданы)
            adjacencyMatrixPanel->Controls->Clear();
            adjacencyTextBoxes->Clear();

            // Создаем новые текстовые поля для ввода матрицы смежности
            for (int i = 0; i < V; i++) {
                List<TextBox^>^ row = gcnew List<TextBox^>();
                for (int j = 0; j < V; j++) {
                    TextBox^ textBox = gcnew TextBox();
                    textBox->Location = Point(j * 40, i * 25);
                    textBox->Size = System::Drawing::Size(30, 20);
                    adjacencyMatrixPanel->Controls->Add(textBox);
                    row->Add(textBox);
                }
                adjacencyTextBoxes->Add(row);
            }
        }
        void addEdge(vector<vector<int>>& adj, int u, int v) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        void DFSUtil(int u, vector<bool>& visited, vector<vector<int>>& adj, List<int>^& component) {
            // Помечаем текущую вершину как посещенную и добавляем ее в компоненту
            visited[u] = true;
            component->Add(u);

            // Перебираем всех соседей вершины u
            for (int i = 0; i < adj[u].size(); i++) {
                int v = adj[u][i];
                if (!visited[v]) {
                    DFSUtil(v, visited, adj, component);
                }
            }
        }
        // Функция для поиска компонент связности
        void findComponents(vector<vector<int>>& adj, int V, String^& result) {

            vector<bool> visited(V, false);
            List<List<int>^>^ components = gcnew List<List<int>^>();

            for (int v = 0; v < V; v++) {
                if (!visited[v]) {
                    List<int>^ component = gcnew List<int>();
                    DFSUtil(v, visited, adj, component);
                    components->Add(component);
                }
            }

            // Формируем результат для вывода компонент связности
            result = "Компоненты связности:\n";
            for (int i = 0; i < components->Count; i++) {
                result += "Компонента " + (i + 1) + ": ";
                for (int j = 0; j < components[i]->Count; j++) {
                    result += components[i][j] + " ";
                }
                result += "\n";
            }
        }
    
   private:
       System::Void buttonCalculate_Click(System::Object^ sender, System::EventArgs^ e) {
           int V = Int32::Parse(textBoxU1->Text); // Используем V для количества вершин

           vector<vector<int>> adj(V); // Создаем список смежности для V вершин

           // Заполняем граф из текстовых полей
           for (int i = 0; i < V; i++) {
               for (int j = 0; j < V; j++) {
                   int value;
                   if (Int32::TryParse(adjacencyTextBoxes[i][j]->Text, value) && (value == 0 || value == 1)) {
                       if (value == 1 && i != j) { // Добавляем ребро, если i не равно j
                           addEdge(adj, i, j); // Добавляем ребро между вершинами i и j
                       }
                   }
                   else {
                       MessageBox::Show("Пожалуйста, введите 0 или 1 для всех значений матрицы.");
                       return;
                   }
               }
           }
           String^ result;
           findComponents(adj, V, result);

           MessageBox::Show(result);
       }
    private:
        System::Void textBoxU1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
        }

    private:
        System::Void textBoxU2_TextChanged(System::Object^ sender, System::EventArgs^ e) {    
        }
    };
}
