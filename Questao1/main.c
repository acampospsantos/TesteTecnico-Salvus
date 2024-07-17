#include <stdio.h>

// Variáveis
int folhaPagamento; //Total a se pagar para os funcionários
int mes;

//Struct's
struct funcionarioCLT
{
    char nome[20];
    char contrato[4]; //=CLT
    int contratosAssinadosClt;
    int comissaoContratoClt;
    int salarioFixoClt;
    //int salarioFinalClt; 
};

struct funcionarioTerceirizado
{
    char nome[20];
    char contrato[13]; //=Terceirizado
    int valorHora;
    int horasTrabalhadas;
    int contratosAssinadosTerceirizado;
    int comissaoContratoTerceirizado;
    //int salarioFinalTerceirizado; 
};

//Função para calcular e retornar o pagamento de UM funcionario CLT
int calcularPagamentoCLT(struct funcionarioCLT funcionario){
    int salarioFixo = funcionario.salarioFixoClt;
    int comissao = funcionario.contratosAssinadosClt * funcionario.comissaoContratoClt;
    //funcionario.salarioFinalClt = salarioFixo + comissao;
    return salarioFixo + comissao;
}

// Função para calcular e retornar o pagamento de UM funcionário terceirizado
int calcularPagamentoTerceirizado(struct funcionarioTerceirizado funcionario) {
    int valorReceber = funcionario.valorHora * funcionario.horasTrabalhadas;
    int comissao = funcionario.contratosAssinadosTerceirizado * funcionario.comissaoContratoTerceirizado;
    //funcionario.salarioFinalTerceirizado = valorReceber + comissao;
    return valorReceber + comissao;
}

//Função para calcular o total da folha de pagamento da Empresa
int calcularTotalFolha(struct funcionarioCLT clts[], int numCLTs, struct funcionarioTerceirizado terceirizados[], int numTerceirizados){
    int total=0;
    int i;
    
    //Calculando para os funcionários CLT
    for(i=0; i < numCLTs; i++){
        total = total + calcularPagamentoCLT(clts[i]);
    }
    //Calculando para os funcionários terceirizados
    for(i=0; i < numTerceirizados; i++){
        total = total + calcularPagamentoTerceirizado(terceirizados[i]);
    }
    folhaPagamento = total;
    return folhaPagamento;
}


//Função Extra: Imprime as informações individuais de um CLT
void imprimeInfoClt(struct funcionarioCLT clt){
    printf("---------- Informacoes ----------\n");
    printf("Nome: %s \n", clt.nome);
    printf("Contrato: %s \n", clt.contrato);
    printf("Contratos assinados: %i \n", clt.contratosAssinadosClt);
    printf("Comissao por contrato: %i \n", clt.comissaoContratoClt);
    printf("Salario fixo: R$%i \n", clt.salarioFixoClt);
    printf("Salario com bonus dos contratos: R$%i \n", calcularPagamentoCLT(clt));
    printf("---------------------------------- \n");
}

//Função Extra: Imprime as informações individuais de um terceirizado
void imprimeInfoTerceirizado(struct funcionarioTerceirizado terceirizado){
    printf("---------- Informacoes ----------\n");
    printf("Nome: %s \n", terceirizado.nome);
    printf("Contrato: %s \n", terceirizado.contrato);
    printf("Valor por hora: R$%i \n", terceirizado.valorHora);
    printf("Horas trabalhadas: %i horas \n", terceirizado.horasTrabalhadas);
    printf("Contratos assinados: %i \n", terceirizado.contratosAssinadosTerceirizado);
    printf("Comissao por contrato: R$%i \n", terceirizado.comissaoContratoTerceirizado);
    printf("Total a receber: R$%i \n", calcularPagamentoTerceirizado(terceirizado));
    printf("---------------------------------- \n");
}


int main(){
    mes = 12;

    //Funcionários CLT
    struct funcionarioCLT clt1 = {"Anderson", "CLT", 10, 200, 3000};
    struct funcionarioCLT clt2 = {"Vinicius", "CLT", 8, 180, 2500};
    struct funcionarioCLT clts[] = {clt1, clt2};
    int numCLTs = 2;

    //Funcionários Terceirizados
    struct funcionarioTerceirizado terceirizado1 = {"João", "Terceirizado", 50, 100, 5, 150};
    struct funcionarioTerceirizado terceirizado2 = {"Lucas", "Terceirizado", 30, 180, 12, 200};
    struct funcionarioTerceirizado terceirizados[] = {terceirizado1, terceirizado2};
    int numTerceirizados = 2;

    //imprimeInfoClt(); //--> Imprime uma tabela de informações de um CLT
    //imprimeInfoTerceirizado(); //--> Imprime uma tabela de informações de um Terceirizado

    //Calcula total da folha de pagamento
    int totalFolha = calcularTotalFolha(clts, numCLTs, terceirizados, numTerceirizados);

    //Exibir total da folha de pagamento
    printf("Total da folha de pagamento (mes %i): R$%i", mes, totalFolha);

    return 0;
}