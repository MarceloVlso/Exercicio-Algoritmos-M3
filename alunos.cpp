#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

const int    MAX_ALUNOS   = 5;
const double MEDIA_MINIMA = 7.0;

// agrupa os dados de um aluno em um único lugar
struct Aluno {
    string nome;
    double nota1, nota2, nota3;
    double media;
    string situacao;
};

double calculaMedia(double n1, double n2, double n3) {
    return (n1 + n2 + n3) / 3.0;
}

string determinaSituacao(double media) {
    if (media >= MEDIA_MINIMA)
        return "Aprovado";
    else
        return "Reprovado";
}

// lê os dados de cada aluno e preenche o vetor
void cadastrarAlunos(vector<Aluno>& turma, int quantidade) {
    for (int i = 0; i < quantidade; i++) {
        Aluno a;
        cout << "\nDigite o nome do aluno " << (i + 1) << ": ";
        cin.ignore();
        getline(cin, a.nome);
        cout << "Digite as 3 notas de " << a.nome << ": ";
        cin >> a.nota1 >> a.nota2 >> a.nota3;
        a.media    = calculaMedia(a.nota1, a.nota2, a.nota3);
        a.situacao = determinaSituacao(a.media);
        turma.push_back(a);
    }
}

// imprime a tabela formatada com todos os resultados
void exibirTabela(const vector<Aluno>& turma) {
    cout << "\n";
    cout << left  << setw(15) << "ALUNO"
         << right << setw(6)  << "N1"
                  << setw(6)  << "N2"
                  << setw(6)  << "N3"
                  << setw(8)  << "MEDIA"
         << left  << setw(12) << "  SITUACAO" << "\n";
    cout << string(55, '-') << "\n";

    for (const Aluno& a : turma) {
        cout << fixed << setprecision(1);
        cout << left  << setw(15) << a.nome
             << right << setw(6)  << a.nota1
                      << setw(6)  << a.nota2
                      << setw(6)  << a.nota3
                      << setw(8)  << a.media
             << left  << setw(12) << ("  " + a.situacao) << "\n";
    }
}

int encontrarMaiorMedia(const vector<Aluno>& turma) {
    int indiceMaior = 0;
    for (int i = 1; i < (int)turma.size(); i++) {
        if (turma[i].media > turma[indiceMaior].media)
            indiceMaior = i;
    }
    return indiceMaior;
}

int main() {
    cout << "========================================\n";
    cout << "   SISTEMA DE CADASTRO DE ALUNOS\n";
    cout << "========================================\n";

    int quantidade;
    cout << "Quantos alunos deseja cadastrar? (maximo " << MAX_ALUNOS << "): ";
    cin >> quantidade;

    if (quantidade < 1 || quantidade > MAX_ALUNOS) {
        cout << "Numero invalido! Usando o maximo de " << MAX_ALUNOS << " alunos.\n";
        quantidade = MAX_ALUNOS;
    }

    vector<Aluno> turma;
    cadastrarAlunos(turma, quantidade);

    cout << "\n========================================\n";
    cout << "         RESULTADO DA TURMA\n";
    cout << "========================================";
    exibirTabela(turma);

    int idx = encontrarMaiorMedia(turma);
    cout << "\nAluno com maior media: "
         << turma[idx].nome
         << " (" << fixed << setprecision(1) << turma[idx].media << ")\n";
    cout << "========================================\n";

    return 0;
}
