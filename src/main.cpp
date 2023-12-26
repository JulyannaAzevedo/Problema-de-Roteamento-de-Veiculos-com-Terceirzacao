#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "datatype.h"
#include "data_loader.h"
#include "build_solution.h"
#include "check_solution.h"
#include "vnd.h"
#include "ils.h"
#include "n1.h"
#include "n2.h"
#include "n3.h"
#include "n4.h"
#include "n5.h"
#include "save_solution.h"

using namespace std;

int main(void){

    // Nome da instancia
    string nome_arquivo = "n199k17_A";

    // Carrega os dados da instancia
    InstanceData* dados_instancia = readAndExtractData(nome_arquivo);
    
    // Constrói a solução inicial
    Solution* solucao_inicial = buildSolution(dados_instancia);
    cout << "Solucao inicial: " << solucao_inicial->totalCost << "\n";

    // VND
    Solution* afterVND = vnd(solucao_inicial, dados_instancia);
    cout << "VND: " << afterVND->totalCost << "\n";

    // ILS
    Solution* afterILS = ils(afterVND, dados_instancia);
    cout << "ILS: " << afterILS->totalCost << "\n";

    // Escreve no arquivo de saída
    saveSolutionToFile(nome_arquivo, afterILS, dados_instancia);

    // Libera a memória alocada
    delete dados_instancia;
    delete afterILS;    

    return 0;
}