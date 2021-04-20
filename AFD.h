#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

class AFD{

    private:

        int N, M, T, ei, num_ef; // N = Numero de estados do automato, M = numero de simbolos, T = Numero de palavras testadas
                                 // ei = estado inicial do automato, num_ef = numero de estados finais
        int **transicoes; //matriz contendo todas as transicoes feitas no automato
        int *ef;          // vetor contendo os estados finais do automato
        
        vector<string> palavras;    // vetor contendo as palavras que serao testadas

        string nomeArquivo()
        {
            string nome;
            cout << "Entre com o nome do arquivo: ";
            cin >> nome;
            
            return nome;
        }

        bool abreArquivo(ifstream &ifs, string nome)
        {
            ifs.open(nome, ifstream::in);
            return ifs.is_open();
        }

        void reset(char *p)
        {
            delete[] p;
            p = new(nothrow) char[256*sizeof(char)];
        }

        void leValor(ifstream &ifs, char *linha, int &valor)
        {
            ifs.getline(linha, 256);
            valor = atoi(linha);
            this->reset(linha);
        }
                                                                    // i =estado inicial, F = vetor de estados finais 
        bool testaPalavra(int i, int *F, int **D,  string palavra)  // **D = matriz contendo as transicoes, palavra = palavra
        {
            int e =i;       //estado inicial do automato
            string::iterator s = palavra.begin();// iterador para percorrer a palavra a ser testada
            
            while(s != palavra.end())   //enquanto o iterador e diferente do final da palavra
            {
                e = D[e-1][*s - 'a'];   // a matriz e do 
                s++;                    //s = prox()
            }
            
            for(int i=0; i < sizeof(F)/sizeof(F[0]); i++)  //verifica se o estado final (e) esta contido no vetor de estados finais (F)
            {
                if (e == F[i])
                    return true;    //retorna verdadeiro caso a palavra seja valida
            }
            return false;   // retorna falso caso a palavra nao seja valida
        }   

    public:
        AFD(ifstream &ifs)
        {
            string nome = this->nomeArquivo();
            
            if (this->abreArquivo(ifs, nome))
            {
                
                char *linha = new(nothrow) char[256*sizeof(char)]; //recebera linha por linha do arquivo
                char *buffer = new(nothrow) char[256*sizeof(char)];// sera usado para extrair cada estado
                  
                leValor(ifs, linha, this->N); //le o valor de N
                leValor(ifs, linha, this->M);// Le o valor de M

                this->transicoes = (int**)malloc(this->N*sizeof(int)); //aloca N linhas para a matriz
                for (int i =0; i < this->N; i++)
                {
                    this->transicoes[i] = (int *)malloc(this->M*sizeof(int)); // aloca M colunas
                }                                                                   

                int v;
                int j = 0;
                bool flag;
                string aux;
                
                for(int k = 0; k < this->N ; k++)
                {  
                    v =0;
                    this->reset(linha);
                    ifs.getline(linha, 256);
                    aux =linha;

                    //antes tinha colocado sizeof(linha)/sizeof(linha[0]) para tentar indicar o tamanho, 
                    // nao deu certo, entao essa foi a forma que achei de fazer funcionar: usa uma string para contar o numero.
                    for (int i =0; i < aux.length()+1; i++)
                    {
                        if( (int)linha[i] >=48 && (int)linha[i] <= 57) // 48 = 0 na tabela ascii e 57 = 9
                        {
                            buffer[j] = linha[i];
                            j++;
                            flag = false;    
                        }
                    
                        else if (((int)linha[i] == 32 || (int)linha[i] == 10 || (int)linha[i] == 0) && flag == false)
                        {
                            buffer[j] = '\0';
                            transicoes[k][v] =atoi(buffer);
                            this->reset(buffer);
                            j = 0;
                            v++;
                            flag = true;
                        }
                    }
                }
                this->reset(linha);
                leValor(ifs, linha, this->ei);
                leValor(ifs, linha, this->num_ef);

                ef = (int *)malloc(this->num_ef*sizeof(int));
               
                ifs.getline(linha, 256);
                
                j = 0;
                v=0;
                for (int i =0; i < sizeof(linha)/sizeof(linha[0]); i++)
                {
                    if( (int)linha[i] >=48 && (int)linha[i] <= 57) // 48 = 0 na tabela ascii e 57 = 9
                    {   
                        buffer[j] = linha[i];
                        j++;
                        flag = false;    
                    }
                
                    else if (((int)linha[i] == 32 || (int)linha[i] == 10 || (int)linha[i] == 0) && flag == false)
                    {   
                        ef[v] =atoi(buffer);
                        this->reset(buffer);
                        j = 0;
                        v++;
                        flag = true;                        
                    }
                }
                
                this->reset(linha);
                leValor(ifs, linha, this->T);
                
                for (int i =0; i < this->T; i++)
                {   
                    this->reset(linha);
                    ifs.getline(linha, 256);
                    this->palavras.push_back(linha);
                }
            }
    
        };
        
        void mostra(){
            cout << endl << endl <<this->N << endl <<this-> M << endl;

            for(int i =0; i < this->N; i++)
            {
                for (int j = 0; j < this->M; j++)
                {
                    cout  << this->transicoes[i][j] << " ";
                }
                cout<< endl;
            }

            cout <<this->ei << endl << this-> num_ef << endl;

            for(int i =0; i < this->num_ef; i++)
            {
                cout  <<this->ef[i]<< " ";
            }

            cout << endl << this->T << endl;
            
            for(int i =0; i < this->T; i++)
            {
                cout << this->palavras[i] << endl;
            }
            cout << endl<< endl;
        }

        int getN()
        {
            return this->N;               
        }
        int getM()
        {
            return this->M;               
        }
        int **getTransicoes()
        {
            return this->transicoes;               
        }
        int getNum_ef()
        {
            return this->num_ef;               
        }
        int *getEf()
        {
            return this->ef;               
        }
        int getT()
        {
            return this->T;               
        }
        vector<string> getPalavras()
        {
            return this->palavras;               
        }

        void testarPalavras()
        {
            cout << "Testando as palavras do arquivo..." << endl;            
            for(int i = 0; i < this->T; i++)
            {   
                cout << endl;
                if (this->testaPalavra(this->ei, this->ef, this->transicoes, this->palavras[i]))
                {
                    cout << "A palavra " << this->palavras[i] << " e valida!"; 
                }
                else
                {
                    cout << "A palavra " << this->palavras[i] << " nao e valida!!!"; 
                }
            }
        }
};
